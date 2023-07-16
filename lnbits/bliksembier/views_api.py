from http import HTTPStatus

from fastapi import Depends, HTTPException, Query, Request
from loguru import logger

from lnbits.core.crud import get_user
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
)
from .models import CreateLnurldevice


@bliksembier_ext.get("/api/v1/currencies")
async def api_list_currencies_available():
    return list(currencies.keys())


@bliksembier_ext.post("/api/v1/device", dependencies=[Depends(require_admin_key)])
async def api_lnurldevice_create(data: CreateLnurldevice, req: Request):
    print("create device")
    return await create_device(data, req)


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
