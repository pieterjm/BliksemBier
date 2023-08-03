import asyncio

from lnbits.core.models import Payment
from lnbits.core.services import websocketUpdater
from lnbits.helpers import get_current_extension_name
from lnbits.tasks import register_invoice_listener
from lnbits.core.crud import get_user, update_payment_extra

from .crud import get_payment, update_payment

from loguru import logger
import json

async def wait_for_paid_invoices():
    invoice_queue = asyncio.Queue()
    register_invoice_listener(invoice_queue, get_current_extension_name())

    while True:
        payment = await invoice_queue.get()
        await on_invoice_paid(payment)


async def on_invoice_paid(payment: Payment) -> None:
    # Check that the payment is intended for this extension
    if payment.extra.get("tag") != "BliksemBier":
        return

    device_payment = await get_payment(payment.extra["id"])

    if not device_payment:
        return
    if device_payment.payhash == "used":
        return

    device_payment = await update_payment(
        payment_id=payment.extra["id"], payhash="used"
    )

    await update_payment_extra(payment_hash=payment.payment_hash, extra = { 'received':True})        

    message = json.dumps({
        'event': "paid",
        'payment_hash': payment.payment_hash,
        'payload': device_payment.payload
    })
    logger.info(message)
    return await websocketUpdater(
        device_payment.deviceid,
        message    
    )
