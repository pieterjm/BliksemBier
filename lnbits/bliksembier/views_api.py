from http import HTTPStatus

from fastapi import Depends, HTTPException, Query, Request
from loguru import logger

from lnbits.utils.exchange_rates import fiat_amount_as_satoshis
from lnbits.core.crud import get_user, update_payment_extra
from lnbits.core.services import create_invoice
from lnbits.decorators import (
    WalletTypeInfo,
    check_admin,
    get_key_type,
    require_admin_key,
)
from lnbits.utils.exchange_rates import currencies

from . import bliksembier_ext, scheduled_tasks
from .crud import (
    create_device,
    delete_device,
    get_device,
    get_devices,
    update_device,
    create_payment,
    update_payment,
    get_payment,
    create_payment_memo,
    create_payment_metadata
)
from .models import CreateLnurldevice



@bliksembier_ext.get("/api/v1/currencies")
async def api_list_currencies_available():
    return list(currencies.keys())


@bliksembier_ext.post("/api/v1/device", dependencies=[Depends(require_admin_key)])
async def api_lnurldevice_create(data: CreateLnurldevice, req: Request):
    return await create_device(data, req)

@bliksembier_ext.post("/api/v1/device/{device_id}/{switch_id}/createInvoice")
async def api_device_create_invoice(req: Request, device_id: str, switch_id: str):
    logger.info(f"Create invoice for device: {device_id} and switch: {switch_id}")
    device = await get_device(device_id, req)
    if not device:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="device does not exist"
        )
    
    switch = None
    if device.switches:
        for _switch in device.switches:
            if ( _switch.id == switch_id ):
                switch = _switch
                break
    if not switch:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="switch does not exist"
        )
    
    # determine price
    price_msat = int((
        await fiat_amount_as_satoshis(float(switch.amount), device.currency)
        if device.currency != "sat"
        else float(switch.amount)
    ) * 1000)

    # create payment
    payment = await create_payment(
        device_id=device.id,
        switch_id=switch.id,
        payload=switch.duration,
        sats=price_msat,
        payhash="created"
    )

    # create invoice
    payment_hash, payment_request = await create_invoice(
        wallet_id=device.wallet,
        amount=int(payment.sats / 1000),
        memo=create_payment_memo(device,switch),
        unhashed_description=create_payment_metadata(device,switch).encode(),
        extra={
            "tag": "BliksemBier",
            "Device": device.id,
            "Switch": switch.id,
            "amount": switch.amount,
            "currency": device.currency,
            "id": payment.id,
            "received": False,
            "acknowledged": False,
            "fulfilled": False
        },
    )

    payment = await update_payment(
        payment_id=payment.id, payhash=payment_hash
    )

    return {
        "pr": payment_request,
        "payment_hash": payment_hash
    }

@bliksembier_ext.put(
    "/api/v1/device/{lnurldevice_id}", dependencies=[Depends(require_admin_key)]
)
async def api_lnurldevice_update(
    data: CreateLnurldevice, lnurldevice_id: str, req: Request
):
    return await update_device(lnurldevice_id, data, req)

@bliksembier_ext.get("/api/v1/device")
async def api_lnurldevices_retrieve(
    req: Request, wallet: WalletTypeInfo = Depends(get_key_type)
):
    user = await get_user(wallet.wallet.user)
    assert user, "Lnurldevice cannot retrieve user"
    return await get_devices(user.wallet_ids, req)


@bliksembier_ext.get(
    "/api/v1/device/{lnurldevice_id}", dependencies=[Depends(get_key_type)]
)
async def api_lnurldevice_retrieve(req: Request, lnurldevice_id: str):
    lnurldevice = await get_device(lnurldevice_id, req)
    if not lnurldevice:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="lnurldevice does not exist"
        )
    return lnurldevice

@bliksembier_ext.get(
    "/api/v1/device/{lnurldevice_id}/switches"
)
async def api_lnurldevice_switches(req: Request, lnurldevice_id: str):
    lnurldevice = await get_device(lnurldevice_id, req)
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
    logger.info("Payment received");
    await update_payment_extra(payment_hash=payment_hash, extra = { 'acknowledged':True})
    return 1;

@bliksembier_ext.get(
    "/api/v1/order/{payment_hash}/fulfilled"
)
async def api_payment_fulfilled(req: Request, payment_hash: str):
    logger.info("Payment fulfilled");
    await update_payment_extra(payment_hash=payment_hash, extra = { 'fulfilled':True})
    return 1;


@bliksembier_ext.delete(
    "/api/v1/device/{lnurldevice_id}", dependencies=[Depends(require_admin_key)]
)
async def api_lnurldevice_delete(req: Request, lnurldevice_id: str):
    lnurldevice = await get_device(lnurldevice_id, req)
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
