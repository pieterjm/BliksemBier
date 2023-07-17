import base64
import hmac
from http import HTTPStatus
from io import BytesIO
import json

from embit import compact
from fastapi import HTTPException, Query, Request

from lnbits import bolt11
from lnbits.core.services import create_invoice
from lnbits.core.views.api import pay_invoice
from lnbits.utils.exchange_rates import fiat_amount_as_satoshis

from . import bliksembier_ext
from .crud import (
    create_payment,
    get_device,
    get_payment,
    get_payment_by_p,
    update_payment,
)

@bliksembier_ext.get(
    "/api/v1/lnurl/{device_id}",
    status_code=HTTPStatus.OK,
    name="bliksembier.lnurl_v1_params",
)
async def lnurl_v1_params(
    request: Request,
    device_id: str,
    switch_id: str
):
    return await lnurl_params(request, device_id, switch_id)


def create_payment_metadata(device, switch):
    return json.dumps([["text/plain", device.title + " " + switch.label]])

@bliksembier_ext.get(
    "/api/v2/lnurl/{device_id}",
    status_code=HTTPStatus.OK,
    name="bliksembier.lnurl_v2_params",
)
async def lnurl_v2_params(
    request: Request,
    device_id: str,
    switch_id: str
):
    return await lnurl_params(request, device_id, switch_id)


async def lnurl_params(
    request: Request,
    device_id: str,
    switch_id: str
):
    # find the device
    device = await get_device(device_id, request)
    if not device:
        return {
            "status": "ERROR",
            "reason": f"lnurldevice {device_id} not found on this server",
        }
    
    # find the switch
    switch = None
    if device.switches:
        for _switch in device.switches:
            if ( _switch.id == switch_id ):
                switch = _switch
                break
    if not switch:
        return {"status": "ERROR", "reason": "Switch params wrong"}

    price_msat = int((
        await fiat_amount_as_satoshis(float(switch.amount), device.currency)
        if device.currency != "sat"
        else float(switch.amount)
    ) * 1000)

    lnurldevicepayment = await create_payment(
        device_id=device.id,
        switch_id=switch.id,
        payload=switch.duration,
        sats=price_msat,
        payhash="bla"
    )
    if not lnurldevicepayment:
        return {"status": "ERROR", "reason": "Could not create payment."}

    return {
        "tag": "payRequest",
        "callback": request.url_for(
            "bliksembier.lnurl_callback", paymentid=lnurldevicepayment.id
        ),
        "minSendable": price_msat,
        "maxSendable": price_msat,
        "metadata": create_payment_metadata(device,switch)
    }

@bliksembier_ext.get(
    "/api/v1/lnurl/cb/{paymentid}",
    status_code=HTTPStatus.OK,
    name="bliksembier.lnurl_callback",
)
async def lnurl_callback(
    request: Request,
    paymentid: str,
    pr: str = Query(None),
    k1: str = Query(None),
):
    payment = await get_payment(paymentid)
    if not payment:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="payment not found."
        )
    device = await get_device(payment.deviceid, request)
    if not device:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="device not found."
        )
    
    switch = None
    for _switch in device.switches:
        if _switch.id == payment.switchid:
            switch = _switch
            break
    
    if not switch:
        raise HTTPException(
            status_code=HTTPStatus.NOT_FOUND, detail="device switch not found."
        )

    payment_hash, payment_request = await create_invoice(
        wallet_id=device.wallet,
        amount=int(payment.sats / 1000),
        memo=device.title + " " + switch.label,
        unhashed_description=create_payment_metadata(device,switch).encode(),
        extra={
            "tag": "Switch",
            "Device": device.id,
            "Switch": switch.id,
            "amount": switch.amount,
            "currency": device.currency,
            "id": paymentid,
            "received": False,
            "fulfilled": False
        },
    )

    payment = await update_payment(
        payment_id=paymentid, payhash=payment_hash
    )

    return {
        "pr": payment_request,
        "routes": [],
    }

   
