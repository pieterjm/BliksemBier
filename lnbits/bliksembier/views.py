from http import HTTPStatus

from fastapi import Depends, HTTPException, Query, Request
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse

from lnbits.core.crud import update_payment_status
from lnbits.core.models import User
from lnbits.core.views.api import api_payment
from lnbits.decorators import check_user_exists

from . import bliksembier_ext, bliksembier_renderer
from .crud import get_device, get_payment

templates = Jinja2Templates(directory="templates")


@bliksembier_ext.get("/", response_class=HTMLResponse)
async def index(request: Request, user: User = Depends(check_user_exists)):
    return bliksembier_renderer().TemplateResponse(
        "bliksembier/index.html",
        {"request": request, "user": user.dict()},
    )


