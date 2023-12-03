from http import HTTPStatus

from fastapi import (
    Depends, 
    HTTPException, 
    Query, 
    Request, 
    WebSocket,
    WebSocketDisconnect
)
from loguru import logger

from lnbits.core.crud import get_user, update_payment_extra
from lnbits.decorators import (
    WalletTypeInfo,
    check_admin,
    get_key_type,
    require_admin_key,
)
from lnbits.utils.exchange_rates import (
    currencies
)
from lnbits.core.services import (
    websocketManager,
    websocketUpdater
)

from . import bliksembier_ext, scheduled_tasks
from .crud import (
    create_device,
    delete_device,
    get_device,
    get_devices,
    update_device,
    get_payment
)
from .tasks import (
    task_create_invoice,
    task_send_switches
)
from .models import CreateLnurldevice

import json

@bliksembier_ext.websocket("/api/v1/ws/{item_id}")
async def websocket_connect(websocket: WebSocket, item_id: str):
    device = await get_device(item_id)
    if not device:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="device does not exist"
        )
    await websocketManager.connect(websocket, item_id)
    try:
        await task_send_switches(item_id)
        while True:
            message = await websocket.receive_text()
            logger.info(f"Received message from websocket: {message}")
            try:
                jsobj = json.loads(message)
            except json.decoder.JSONDecodeError:
                logger.warning("Invalid JSON message received. Ignoring")                                        
                continue

            if not "event" in jsobj:
                logger.warning("No event in message, ignored") 
                continue

            if jsobj["event"] == "acknowledged":
                if not 'payment_hash' in jsobj:
                    logger.error("Required field: 'payment_hash' not present in message")
                    continue  
                await update_payment_extra(payment_hash=jsobj["payment_hash"], extra = { 'acknowledged':True})
            elif jsobj["event"] == "fulfilled":
                if not 'payment_hash' in jsobj:
                    logger.error("Required field: 'payment_hash' not present in message")
                    continue  
                await update_payment_extra(payment_hash=jsobj["payment_hash"], extra = { 'fulfilled':True})
            elif jsobj["event"] == "createinvoice":
                if not "switch_id" in jsobj:
                    logger.error(f"Required field: 'switch_id' not present in message")
                    continue          
                logger.info(f"Device id: {item_id}")
                await task_create_invoice(item_id,jsobj["switch_id"])
            elif jsobj["event"] == "lnurlw":
                logger.info("Processing LNURLW for payment");
                for field in ["payment_request","lnurlw"]:
                    if not field in jsobj:
                        logger.error(f"Required field: '{field}' not present in message")
                        continue          
                await task_make_lnurlw(jsobj["payment_request"],jsobj["lnurlw"])
            else:                
                logger.warning(f"Unknown event type {jsobj['event']} ignored")

    except WebSocketDisconnect:
        websocketManager.disconnect(websocket)


@bliksembier_ext.get("/api/v1/currencies")
async def api_list_currencies_available():
    return list(currencies.keys())


@bliksembier_ext.post("/api/v1/device", dependencies=[Depends(require_admin_key)])
async def api_lnurldevice_create(data: CreateLnurldevice, req: Request):
    return await create_device(data, req)


@bliksembier_ext.put(
    "/api/v1/device/{device_id}", dependencies=[Depends(require_admin_key)]
)
async def api_device_update(
    data: CreateLnurldevice, device_id: str, req: Request
):
    device = await update_device(device_id, data, req)
    await task_send_switches(device_id)
    return device

@bliksembier_ext.get("/api/v1/device")
async def api_lnurldevices_retrieve(
    req: Request, wallet: WalletTypeInfo = Depends(get_key_type)
):
    user = await get_user(wallet.wallet.user)
    assert user, "Lnurldevice cannot retrieve user"
    devices = await get_devices(user.wallet_ids)
    for device in devices:
        device.websocket = 0
        for connection in websocketManager.active_connections:
            if connection.path_params["item_id"] == device.id:
                device.websocket += 1
    return devices


@bliksembier_ext.get(
    "/api/v1/device/{lnurldevice_id}", dependencies=[Depends(get_key_type)]
)
async def api_lnurldevice_retrieve(req: Request, lnurldevice_id: str):
    device = await get_device(lnurldevice_id)
    if not device:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="device does not exist"
        )

    device.websocket = 0
    for connection in websocketManager.active_connections:
        if connection.path_params["item_id"] == device.id:
            device.websocket += 1

    return device

@bliksembier_ext.get(
    "/api/v1/device/{lnurldevice_id}/switches"
)
async def api_lnurldevice_switches(req: Request, lnurldevice_id: str):
    lnurldevice = await get_device(lnurldevice_id)
    if not lnurldevice:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="lnurldevice does not exist"
        )

    connectdevice = {
        "switches": lnurldevice.switches
    }

    return connectdevice

@bliksembier_ext.get(
    "/api/v1/order/{payment_hash}/received"
)
async def api_payment_received(req: Request, payment_hash: str):
    logger.info("Payment acknowledged by tap");
    await update_payment_extra(payment_hash=payment_hash, extra = { 'acknowledged':True})
    return 1;

@bliksembier_ext.get(
    "/api/v1/order/{payment_hash}/fulfilled"
)
async def api_payment_fulfilled(req: Request, payment_hash: str):
    logger.info("Payment fulfilled by tap");
    await update_payment_extra(payment_hash=payment_hash, extra = { 'fulfilled':True})
    return 1;


@bliksembier_ext.delete(
    "/api/v1/device/{lnurldevice_id}", dependencies=[Depends(require_admin_key)]
)
async def api_lnurldevice_delete(req: Request, lnurldevice_id: str):
    lnurldevice = await get_device(lnurldevice_id)
    if not lnurldevice:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="Lnurldevice does not exist."
        )

    await delete_device(lnurldevice_id)


@bliksembier_ext.delete(
    "/api/v1", status_code=HTTPStatus.OK, dependencies=[Depends(check_admin)]
)
async def api_stop():
    for t in scheduled_tasks:
        try:
            t.cancel()
        except Exception as ex:
            logger.warning(ex)

    return {"success": True}
