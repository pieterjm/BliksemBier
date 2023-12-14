#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenAbout;
lv_obj_t * ui_PanelHeaderAbout;
lv_obj_t * ui_Label17;
lv_obj_t * ui_Image1;
lv_obj_t * ui_LabelAboutStatus;
lv_obj_t * ui_ButtonAboutOne;
lv_obj_t * ui_ButtonAboutTwo;
lv_obj_t * ui_ButtonAboutThree;
lv_obj_t * ui_LabelAboutOne;
lv_obj_t * ui_LabelAboutTwo;
lv_obj_t * ui_LabelAboutThree;
lv_obj_t * ui_PanelAboutMessage;
lv_obj_t * ui_LabelAboutMessage;
void ui_event_ButtonAboutConfig(lv_event_t * e);
void ui_event_ButtonAboutOne(lv_event_t * e);
void ui_event_ButtonAboutTwo(lv_event_t * e);
void ui_event_ButtonAboutThree(lv_event_t * e);
lv_obj_t * ui_ScreenMain;
lv_obj_t * ui_PanelHeaderMain;
lv_obj_t * ui_LabelHeaderMain;
void ui_event_ButtonMainAbout(lv_event_t * e);
lv_obj_t * ui_ButtonMainAbout;
lv_obj_t * ui_Label18;
lv_obj_t * ui_ImageQRCodeBorder;
lv_obj_t * ui_ScreenPin;
lv_obj_t * ui_LabelPINValue;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Label12;
lv_obj_t * ui_PanelMainMessage;
lv_obj_t * ui_LabelMainMessage;
lv_obj_t * ui_QrcodeLnurl;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label15;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label21;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label22;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label25;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Label20;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
lv_obj_t * ui_Label29;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label30;
void ui_event_Button8(lv_event_t * e);
lv_obj_t * ui_Button8;
lv_obj_t * ui_Label31;
void ui_event_Button9(lv_event_t * e);
lv_obj_t * ui_Button9;
lv_obj_t * ui_Label13;
void ui_event_ButtonPINCancel(lv_event_t * e);
lv_obj_t * ui_ButtonPINCancel;
lv_obj_t * ui_Label32;
void ui_event_Button11(lv_event_t * e);
lv_obj_t * ui_Button11;
lv_obj_t * ui_Label33;
void ui_event_ButtonPinOK(lv_event_t * e);
lv_obj_t * ui_ButtonPinOK;
lv_obj_t * ui_Label34;
lv_obj_t * ui_ScreenConfig;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Label23;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label26;
lv_obj_t * ui_Label19;
lv_obj_t * ui_Label36;
lv_obj_t * ui_Label14;
void ui_event_TextAreaConfigSSID(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigSSID;
void ui_event_TextAreaWifiPassword(lv_event_t * e);
lv_obj_t * ui_TextAreaWifiPassword;
void ui_event_TextAreaConfigHost(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigHost;
void ui_event_TextAreaConfigDeviceID(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigDeviceID;
void ui_event_ButtonConfigTuner(lv_event_t * e);
lv_obj_t * ui_ButtonConfigTuner;
lv_obj_t * ui_Label28;
void ui_event_ButtonConfigConnect(lv_event_t * e);
lv_obj_t * ui_ButtonConfigConnect;
lv_obj_t * ui_LabelConfigDeviceID;
void ui_event_ButtonPIN(lv_event_t * e);
lv_obj_t * ui_ButtonPIN;
lv_obj_t * ui_Label37;
lv_obj_t * ui_LabelConfigStatus;
void ui_event_ButtonConfigDone(lv_event_t * e);
lv_obj_t * ui_ButtonConfigDone;
void ui_event_Label24(lv_event_t * e);
lv_obj_t * ui_Label24;
void ui_event_ButtonConfigFree(lv_event_t * e);
lv_obj_t * ui_ButtonConfigFree;
void ui_event_Label27(lv_event_t * e);
lv_obj_t * ui_Label27;
lv_obj_t * ui_PanelConfigPIN;
lv_obj_t * ui_Label38;
lv_obj_t * ui_Label39;
lv_obj_t * ui_Label40;
void ui_event_TextAreaConfigPINCurrent(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigPINCurrent;
void ui_event_TextAreaConfigPINRepeat(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigPINRepeat;
void ui_event_TextAreaConfigPINNew(lv_event_t * e);
lv_obj_t * ui_TextAreaConfigPINNew;
void ui_event_ButtonConfigPINOK(lv_event_t * e);
lv_obj_t * ui_ButtonConfigPINOK;
void ui_event_Label35(lv_event_t * e);
lv_obj_t * ui_Label35;
void ui_event_ButtonConfigPINCancel(lv_event_t * e);
lv_obj_t * ui_ButtonConfigPINCancel;
void ui_event_Label41(lv_event_t * e);
lv_obj_t * ui_Label41;
lv_obj_t * ui_LabelConfigPINMessage;
void ui_event_KeyboardConfigWifi(lv_event_t * e);
lv_obj_t * ui_KeyboardConfigWifi;
lv_obj_t * ui_KeyboardNumeric;
lv_obj_t * ui_ScreenConfigAdvanced;
lv_obj_t * ui_PanelHeaderConfig;
lv_obj_t * ui_Label2;
void ui_event_ButtonConfigBack(lv_event_t * e);
lv_obj_t * ui_ButtonConfigBack;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label3;
lv_obj_t * ui_LabelConfigServoClosed;
void ui_event_SliderConfigServoClosed(lv_event_t * e);
lv_obj_t * ui_SliderConfigServoClosed;
lv_obj_t * ui_Label8;
lv_obj_t * ui_LabelConfigServoOpen;
void ui_event_SliderConfigServoOpen(lv_event_t * e);
lv_obj_t * ui_SliderConfigServoOpen;
void ui_event_ButtonConfigServoBack(lv_event_t * e);
lv_obj_t * ui_ButtonConfigServoBack;
lv_obj_t * ui_Label7;
void ui_event_ButtonConfigServoClose(lv_event_t * e);
lv_obj_t * ui_ButtonConfigServoClose;
lv_obj_t * ui_Label10;
void ui_event_ButtonConfigServoOpen(lv_event_t * e);
lv_obj_t * ui_ButtonConfigServoOpen;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Tap_duration;
lv_obj_t * ui_LabelConfigTapDuration;
void ui_event_SliderConfigTapDuration(lv_event_t * e);
lv_obj_t * ui_SliderConfigTapDuration;
void ui_event_ButtonConfigSave(lv_event_t * e);
lv_obj_t * ui_ButtonConfigSave;
lv_obj_t * ui_Label11;
void ui_event_ScreenBierFlowing(lv_event_t * e);
lv_obj_t * ui_ScreenBierFlowing;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Label42;
lv_obj_t * ui_Image3;
lv_obj_t * ui_BarBierProgress;
lv_obj_t * ui_ButtonBierStart;
lv_obj_t * ui_Label45;
void ui_event_ButtonBierStart(lv_event_t * e);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_ButtonAboutOne(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonAboutOneClicked(e);
    }
}

void ui_event_ButtonAboutTwo(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonAboutTwoClicked(e);
    }
}

void ui_event_ButtonAboutThree(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonAboutThreeClicked(e);
    }
}

void ui_event_ButtonAboutConfig(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonAboutConfigClicked(e);
    }
}

void ui_event_ButtonMainAbout(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_ScreenAbout, LV_SCR_LOAD_ANIM_NONE, 0, 0);
        ButtonMainBackClicked(e);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinOneClicked(e);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinTwoClicked(e);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinThreeClicked(e);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinFourClicked(e);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinFiveClicked(e);
    }
}
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinSixClicked(e);
    }
}
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinSevenClicked(e);
    }
}
void ui_event_Button8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinEightClicked(e);
    }
}
void ui_event_Button9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinNineClicked(e);
    }
}
void ui_event_ButtonPINCancel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinCancelClicked(e);
    }
}
void ui_event_Button11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinZeroClicked(e);
    }
}
void ui_event_ButtonPinOK(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonPinOKClicked(e);
    }
}
void ui_event_TextAreaConfigSSID(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardConfigWifi,  ui_TextAreaConfigSSID);
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TextAreaWifiPassword(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_KeyboardConfigWifi,  ui_TextAreaWifiPassword);
    }
}
void ui_event_TextAreaConfigHost(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardConfigWifi,  ui_TextAreaConfigHost);
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TextAreaConfigDeviceID(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardConfigWifi,  ui_TextAreaConfigDeviceID);
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_ButtonConfigTuner(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonConfigTunerClicked(e);
    }
}
void ui_event_ButtonConfigConnect(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        ButtonConfigConnectClicked(e);
    }
}
void ui_event_ButtonPIN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_PanelConfigPIN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_ButtonConfigDone(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenAbout, LV_SCR_LOAD_ANIM_NONE, 0, 0);
        _ui_flag_modify(ui_PanelConfigPIN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Label24(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenConfigAdvanced, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_ButtonConfigFree(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonFreeClicked(e);
        _ui_flag_modify(ui_PanelConfigPIN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Label27(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenConfigAdvanced, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_TextAreaConfigPINCurrent(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardNumeric,  ui_TextAreaConfigPINCurrent);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TextAreaConfigPINRepeat(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardNumeric,  ui_TextAreaConfigPINRepeat);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TextAreaConfigPINNew(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_KeyboardNumeric,  ui_TextAreaConfigPINNew);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_ButtonConfigPINOK(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonOKPINClicked(e);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Label35(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenConfigAdvanced, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_ButtonConfigPINCancel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtoCancelPINClicked(e);
        _ui_flag_modify(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Label41(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenConfigAdvanced, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_KeyboardConfigWifi(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_ButtonConfigBack(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenConfig, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_SliderConfigServoClosed(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_LabelConfigServoClosed, target, "", "");
    }
}
void ui_event_SliderConfigServoOpen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_LabelConfigServoOpen, target, "", "");
    }
}

void ui_event_ButtonConfigServoClose(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonConfigCloseClicked(e);
    }
}

void ui_event_ButtonConfigServoOpen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonConfigOpenClicked(e);
    }
}
void ui_event_SliderConfigTapDuration(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_LabelConfigTapDuration, target, "", "");
    }
}
void ui_event_ButtonConfigSave(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonConfigSaveClicked(e);
    }
}
void ui_event_ScreenBierFlowing(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonScreenBierFlowingClicked(e);
    }
}

void ui_event_ButtonBierStart(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ButtonBierStartClicked(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_ScreenAbout_screen_init(void)
{
    ui_ScreenAbout = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAbout, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAbout, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAbout, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHeaderAbout = lv_obj_create(ui_ScreenAbout);
    lv_obj_set_width(ui_PanelHeaderAbout, 320);
    lv_obj_set_height(ui_PanelHeaderAbout, 50);
    lv_obj_clear_flag(ui_PanelHeaderAbout, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHeaderAbout, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHeaderAbout, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHeaderAbout, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHeaderAbout, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label17 = lv_label_create(ui_PanelHeaderAbout);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, BB_NAME);
    lv_obj_set_style_text_color(ui_Label17, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label17, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label17, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Image1 = lv_img_create(ui_ScreenAbout);

    lv_img_set_src(ui_Image1, &ui_img_kanhetal256_png);  // kan het al logp

    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 256
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 256
    lv_obj_set_y(ui_Image1, -50);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelAboutStatus = lv_label_create(ui_ScreenAbout);
    lv_obj_set_width(ui_LabelAboutStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAboutStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelAboutStatus, 0);
    lv_obj_set_y(ui_LabelAboutStatus, -20);
    lv_obj_set_align(ui_LabelAboutStatus, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_LabelAboutStatus, "--");
    lv_obj_set_style_text_color(ui_LabelAboutStatus, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAboutStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAboutStatus, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonAboutOne = lv_btn_create(ui_ScreenAbout);
    lv_obj_set_width(ui_ButtonAboutOne, 100);
    lv_obj_set_height(ui_ButtonAboutOne, 100);
    lv_obj_set_align(ui_ButtonAboutOne, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_x(ui_ButtonAboutOne, 0);
    lv_obj_set_y(ui_ButtonAboutOne, -60);
    lv_obj_add_flag(ui_ButtonAboutOne, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAboutOne, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonAboutOne, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonAboutOne, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
    
    ui_LabelAboutOne = lv_label_create(ui_ButtonAboutOne);
    lv_obj_set_width(ui_LabelAboutOne, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAboutOne, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAboutOne, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAboutOne, "");
    lv_obj_set_style_text_color(ui_LabelAboutOne, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAboutOne, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAboutOne, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonAboutTwo = lv_btn_create(ui_ScreenAbout);
    lv_obj_set_width(ui_ButtonAboutTwo, 100);
    lv_obj_set_height(ui_ButtonAboutTwo, 100);
    lv_obj_set_align(ui_ButtonAboutTwo, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_x(ui_ButtonAboutTwo, 0);
    lv_obj_set_y(ui_ButtonAboutTwo, -60);
    lv_obj_add_flag(ui_ButtonAboutTwo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAboutTwo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonAboutTwo, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonAboutTwo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);

    ui_LabelAboutTwo = lv_label_create(ui_ButtonAboutTwo);
    lv_obj_set_width(ui_LabelAboutTwo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAboutTwo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAboutTwo, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAboutTwo, "");
    lv_obj_set_style_text_color(ui_LabelAboutTwo, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAboutTwo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAboutTwo, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonAboutThree = lv_btn_create(ui_ScreenAbout);
    lv_obj_set_width(ui_ButtonAboutThree, 100);
    lv_obj_set_height(ui_ButtonAboutThree, 100);
    lv_obj_set_align(ui_ButtonAboutThree, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_x(ui_ButtonAboutThree, 0);
    lv_obj_set_y(ui_ButtonAboutThree, -60);
    lv_obj_add_flag(ui_ButtonAboutThree, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAboutThree, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonAboutThree, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonAboutThree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);

    ui_LabelAboutThree = lv_label_create(ui_ButtonAboutThree);
    lv_obj_set_width(ui_LabelAboutThree, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAboutThree, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAboutThree, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAboutThree, "");
    lv_obj_set_style_text_color(ui_LabelAboutThree, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAboutThree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAboutThree, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_PanelAboutMessage = lv_obj_create(ui_ScreenAbout);
    lv_obj_set_width(ui_PanelAboutMessage, 240);
    lv_obj_set_height(ui_PanelAboutMessage, 240);
    lv_obj_clear_flag(ui_PanelAboutMessage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_align(ui_PanelAboutMessage, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_PanelAboutMessage, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelAboutMessage, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelAboutMessage, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAboutMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);

    ui_LabelAboutMessage = lv_label_create(ui_PanelAboutMessage);
    lv_obj_set_width(ui_LabelAboutMessage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAboutMessage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAboutMessage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAboutMessage, "FETCHING INVOICE");
    lv_obj_set_style_text_color(ui_LabelAboutMessage, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAboutMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAboutMessage, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_event_cb(ui_ButtonAboutOne, ui_event_ButtonAboutOne, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAboutTwo, ui_event_ButtonAboutTwo, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAboutThree, ui_event_ButtonAboutThree, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHeaderAbout, ui_event_ButtonAboutConfig, LV_EVENT_ALL, NULL);

}
void ui_ScreenMain_screen_init(void)
{
    ui_ScreenMain = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenMain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenMain, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHeaderMain = lv_obj_create(ui_ScreenMain);
    lv_obj_set_width(ui_PanelHeaderMain, 320);
    lv_obj_set_height(ui_PanelHeaderMain, 50);
    lv_obj_clear_flag(ui_PanelHeaderMain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHeaderMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHeaderMain, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHeaderMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHeaderMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHeaderMain = lv_label_create(ui_PanelHeaderMain);
    lv_obj_set_width(ui_LabelHeaderMain, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelHeaderMain, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelHeaderMain, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelHeaderMain, "PAY FOR YOUR DRINK");
    lv_obj_set_style_text_color(ui_LabelHeaderMain, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHeaderMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHeaderMain, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonMainAbout = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_ButtonMainAbout, 100);
    lv_obj_set_height(ui_ButtonMainAbout, 50);
    lv_obj_set_x(ui_ButtonMainAbout, 0);
    lv_obj_set_y(ui_ButtonMainAbout, -10);
    lv_obj_set_align(ui_ButtonMainAbout, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_ButtonMainAbout, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonMainAbout, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonMainAbout, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMainAbout, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label18 = lv_label_create(ui_ButtonMainAbout);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "BACK");
    lv_obj_set_style_text_color(ui_Label18, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label18, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label18, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageQRCodeBorder = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_ImageQRCodeBorder, &ui_img_329557545);
    lv_obj_set_width(ui_ImageQRCodeBorder, LV_SIZE_CONTENT);   /// 274
    lv_obj_set_height(ui_ImageQRCodeBorder, LV_SIZE_CONTENT);    /// 274
    lv_obj_set_x(ui_ImageQRCodeBorder, 5);
    lv_obj_set_y(ui_ImageQRCodeBorder, -25);
    lv_obj_set_align(ui_ImageQRCodeBorder, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageQRCodeBorder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageQRCodeBorder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // initialize the QR code
    lv_color_t bg_color = lv_color_hex(0xFFFFFF);
    lv_color_t fg_color = lv_color_hex(0x000000);
    ui_QrcodeLnurl = lv_qrcode_create(ui_ScreenMain,240,fg_color,bg_color);
    lv_obj_center(ui_QrcodeLnurl);
    lv_obj_set_pos(ui_QrcodeLnurl,-3, -33);
    lv_obj_set_style_border_width(ui_QrcodeLnurl, 0, 0);
    lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);

    ui_PanelMainMessage = lv_obj_create(ui_ScreenMain);
    lv_obj_set_y(ui_PanelMainMessage,140);
    lv_obj_set_width(ui_PanelMainMessage, 256);
    lv_obj_set_height(ui_PanelMainMessage, 50);
    lv_obj_clear_flag(ui_PanelMainMessage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_align(ui_PanelMainMessage, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_PanelMainMessage, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelMainMessage, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMainMessage, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMainMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_add_flag(ui_PanelMainMessage,LV_OBJ_FLAG_HIDDEN);

    ui_LabelMainMessage = lv_label_create(ui_PanelMainMessage);
    lv_obj_set_width(ui_LabelMainMessage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelMainMessage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelMainMessage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMainMessage, "THIS IS A TEST");
    lv_obj_set_style_text_color(ui_LabelMainMessage, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMainMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMainMessage, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);





    lv_obj_add_event_cb(ui_ButtonMainAbout, ui_event_ButtonMainAbout, LV_EVENT_ALL, NULL);

}

void ui_ScreenPin_screen_init(void)
{
    ui_ScreenPin = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenPin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenPin, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenPin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPINValue = lv_label_create(ui_ScreenPin);
    lv_obj_set_width(ui_LabelPINValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPINValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPINValue, 0);
    lv_obj_set_y(ui_LabelPINValue, 80);
    lv_obj_set_align(ui_LabelPINValue, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelPINValue, "ENTER PIN");
    lv_obj_set_style_text_color(ui_LabelPINValue, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPINValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_LabelPINValue, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LabelPINValue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPINValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPINValue, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_ScreenPin);
    lv_obj_set_width(ui_Panel3, 320);
    lv_obj_set_height(ui_Panel3, 50);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Panel3);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "ENTER PIN");
    lv_obj_set_style_text_color(ui_Label12, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label12, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button1, 80);
    lv_obj_set_height(ui_Button1, 80);
    lv_obj_set_x(ui_Button1, -90);
    lv_obj_set_y(ui_Button1, -80);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "1");
    lv_obj_set_style_text_color(ui_Label15, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label15, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button2, 80);
    lv_obj_set_height(ui_Button2, 80);
    lv_obj_set_x(ui_Button2, 0);
    lv_obj_set_y(ui_Button2, -80);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label21 = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "2");
    lv_obj_set_style_text_color(ui_Label21, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label21, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button3, 80);
    lv_obj_set_height(ui_Button3, 80);
    lv_obj_set_x(ui_Button3, 90);
    lv_obj_set_y(ui_Button3, -80);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label22 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "3");
    lv_obj_set_style_text_color(ui_Label22, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label22, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button4, 80);
    lv_obj_set_height(ui_Button4, 80);
    lv_obj_set_x(ui_Button4, -90);
    lv_obj_set_y(ui_Button4, 10);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label25 = lv_label_create(ui_Button4);
    lv_obj_set_width(ui_Label25, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label25, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label25, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label25, "4");
    lv_obj_set_style_text_color(ui_Label25, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label25, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label25, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button5, 80);
    lv_obj_set_height(ui_Button5, 80);
    lv_obj_set_x(ui_Button5, 0);
    lv_obj_set_y(ui_Button5, 10);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label20 = lv_label_create(ui_Button5);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "5");
    lv_obj_set_style_text_color(ui_Label20, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label20, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label20, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button6, 80);
    lv_obj_set_height(ui_Button6, 80);
    lv_obj_set_x(ui_Button6, 90);
    lv_obj_set_y(ui_Button6, 10);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label29 = lv_label_create(ui_Button6);
    lv_obj_set_width(ui_Label29, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label29, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label29, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label29, "6");
    lv_obj_set_style_text_color(ui_Label29, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button7 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button7, 80);
    lv_obj_set_height(ui_Button7, 80);
    lv_obj_set_x(ui_Button7, -90);
    lv_obj_set_y(ui_Button7, 100);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button7, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label30 = lv_label_create(ui_Button7);
    lv_obj_set_width(ui_Label30, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label30, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label30, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label30, "7");
    lv_obj_set_style_text_color(ui_Label30, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label30, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label30, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button8 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button8, 80);
    lv_obj_set_height(ui_Button8, 80);
    lv_obj_set_x(ui_Button8, 0);
    lv_obj_set_y(ui_Button8, 100);
    lv_obj_set_align(ui_Button8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button8, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label31 = lv_label_create(ui_Button8);
    lv_obj_set_width(ui_Label31, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label31, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label31, 0);
    lv_obj_set_y(ui_Label31, -1);
    lv_obj_set_align(ui_Label31, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label31, "8");
    lv_obj_set_style_text_color(ui_Label31, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label31, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label31, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button9 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button9, 80);
    lv_obj_set_height(ui_Button9, 80);
    lv_obj_set_x(ui_Button9, 90);
    lv_obj_set_y(ui_Button9, 100);
    lv_obj_set_align(ui_Button9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button9, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Button9);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "9");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPINCancel = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_ButtonPINCancel, 80);
    lv_obj_set_height(ui_ButtonPINCancel, 80);
    lv_obj_set_x(ui_ButtonPINCancel, -90);
    lv_obj_set_y(ui_ButtonPINCancel, 190);
    lv_obj_set_align(ui_ButtonPINCancel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonPINCancel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPINCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonPINCancel, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPINCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label32 = lv_label_create(ui_ButtonPINCancel);
    lv_obj_set_width(ui_Label32, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label32, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label32, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label32, "C");
    lv_obj_set_style_text_color(ui_Label32, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label32, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label32, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button11 = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_Button11, 80);
    lv_obj_set_height(ui_Button11, 80);
    lv_obj_set_x(ui_Button11, 0);
    lv_obj_set_y(ui_Button11, 190);
    lv_obj_set_align(ui_Button11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button11, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label33 = lv_label_create(ui_Button11);
    lv_obj_set_width(ui_Label33, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label33, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label33, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label33, "0");
    lv_obj_set_style_text_color(ui_Label33, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label33, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label33, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPinOK = lv_btn_create(ui_ScreenPin);
    lv_obj_set_width(ui_ButtonPinOK, 80);
    lv_obj_set_height(ui_ButtonPinOK, 80);
    lv_obj_set_x(ui_ButtonPinOK, 90);
    lv_obj_set_y(ui_ButtonPinOK, 190);
    lv_obj_set_align(ui_ButtonPinOK, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonPinOK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPinOK, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonPinOK, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPinOK, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label34 = lv_label_create(ui_ButtonPinOK);
    lv_obj_set_width(ui_Label34, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label34, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label34, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label34, "OK");
    lv_obj_set_style_text_color(ui_Label34, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label34, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label34, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button8, ui_event_Button8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button9, ui_event_Button9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPINCancel, ui_event_ButtonPINCancel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button11, ui_event_Button11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPinOK, ui_event_ButtonPinOK, LV_EVENT_ALL, NULL);

}
void ui_ScreenConfig_screen_init(void)
{
    ui_ScreenConfig = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenConfig, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenConfig, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenConfig, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Panel1, 320);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label23 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label23, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label23, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label23, LV_ALIGN_CENTER);
#define STR1(x)  #x
#define STR(x)  STR1(x)    
#define VERSION_LABEL "VERSION " STR(FIRMWARE_VERSION)
    lv_label_set_text(ui_Label23, VERSION_LABEL);
    lv_obj_set_style_text_color(ui_Label23, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label23, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label23, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 10);
    lv_obj_set_y(ui_Label6, 70);
    lv_label_set_text(ui_Label6, "SSID");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Label26 = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Label26, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label26, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label26, 10);
    lv_obj_set_y(ui_Label26, 120);
    lv_label_set_text(ui_Label26, "Secret");
    lv_obj_set_style_text_color(ui_Label26, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label26, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label26, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label19 = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label19, 10);
    lv_obj_set_y(ui_Label19, 170);
    lv_label_set_text(ui_Label19, "LNbits host");
    lv_obj_set_style_text_color(ui_Label19, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label19, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label36 = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Label36, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label36, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label36, 10);
    lv_obj_set_y(ui_Label36, 220);
    lv_label_set_text(ui_Label36, "Device ID");
    lv_obj_set_style_text_color(ui_Label36, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label36, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label36, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, 10);
    lv_obj_set_y(ui_Label14, 320);
    lv_label_set_text(ui_Label14, "Status");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*
    // Drop Down for Wi=Fi network selection
    ui_DropdownConfigSSID = lv_dropdown_create(ui_ScreenConfig);
    lv_dropdown_set_options(ui_DropdownConfigSSID, "");
    lv_dropdown_set_text(ui_DropdownConfigSSID, "Select Wi-Fi network");
    lv_obj_set_width(ui_DropdownConfigSSID, 240);
    lv_obj_set_height(ui_DropdownConfigSSID, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DropdownConfigSSID, -10);
    lv_obj_set_y(ui_DropdownConfigSSID, 60);
    lv_obj_set_align(ui_DropdownConfigSSID, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_DropdownConfigSSID, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    */

    ui_TextAreaConfigSSID = lv_textarea_create(ui_ScreenConfig);
    lv_obj_set_width(ui_TextAreaConfigSSID, 240);
    lv_obj_set_height(ui_TextAreaConfigSSID, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_TextAreaConfigSSID, 70);
    lv_obj_set_y(ui_TextAreaConfigSSID, 60);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigSSID, "Wi-Fi SSID");
    lv_textarea_set_one_line(ui_TextAreaConfigSSID, true);

    ui_TextAreaWifiPassword = lv_textarea_create(ui_ScreenConfig);
    lv_obj_set_width(ui_TextAreaWifiPassword, 240);
    lv_obj_set_height(ui_TextAreaWifiPassword, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextAreaWifiPassword, 70);
    lv_obj_set_y(ui_TextAreaWifiPassword, 110);
    lv_textarea_set_placeholder_text(ui_TextAreaWifiPassword, "Wi-Fi password");
    lv_textarea_set_one_line(ui_TextAreaWifiPassword, true);
    lv_textarea_set_password_mode(ui_TextAreaWifiPassword, true);

    ui_TextAreaConfigHost = lv_textarea_create(ui_ScreenConfig);
    lv_obj_set_width(ui_TextAreaConfigHost, 200);
    lv_obj_set_height(ui_TextAreaConfigHost, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextAreaConfigHost, -10);
    lv_obj_set_y(ui_TextAreaConfigHost, 160);
    lv_obj_set_align(ui_TextAreaConfigHost, LV_ALIGN_TOP_RIGHT);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigHost, "LNbits host");
    lv_textarea_set_one_line(ui_TextAreaConfigHost, true);

    ui_TextAreaConfigDeviceID = lv_textarea_create(ui_ScreenConfig);
    lv_obj_set_width(ui_TextAreaConfigDeviceID, 200);
    lv_obj_set_height(ui_TextAreaConfigDeviceID, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextAreaConfigDeviceID, -10);
    lv_obj_set_y(ui_TextAreaConfigDeviceID, 210);
    lv_obj_set_align(ui_TextAreaConfigDeviceID, LV_ALIGN_TOP_RIGHT);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigDeviceID, "Device ID");
    lv_textarea_set_one_line(ui_TextAreaConfigDeviceID, true);

    ui_ButtonConfigTuner = lv_btn_create(ui_ScreenConfig);
    lv_obj_set_width(ui_ButtonConfigTuner, 95);
    lv_obj_set_height(ui_ButtonConfigTuner, 50);
    lv_obj_set_x(ui_ButtonConfigTuner, 10);
    lv_obj_set_y(ui_ButtonConfigTuner, 260);
    lv_obj_add_flag(ui_ButtonConfigTuner, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigTuner, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigTuner, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigTuner, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label28 = lv_label_create(ui_ButtonConfigTuner);
    lv_obj_set_width(ui_Label28, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label28, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label28, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label28, "TUNER");
    lv_obj_set_style_text_color(ui_Label28, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label28, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label28, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigConnect = lv_btn_create(ui_ScreenConfig);
    lv_obj_set_width(ui_ButtonConfigConnect, 95);
    lv_obj_set_height(ui_ButtonConfigConnect, 50);
    lv_obj_set_x(ui_ButtonConfigConnect, -10);
    lv_obj_set_y(ui_ButtonConfigConnect, 260);
    lv_obj_set_align(ui_ButtonConfigConnect, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_ButtonConfigConnect, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigConnect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigConnect, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigConnect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelConfigDeviceID = lv_label_create(ui_ButtonConfigConnect);
    lv_obj_set_width(ui_LabelConfigDeviceID, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfigDeviceID, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelConfigDeviceID, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelConfigDeviceID, "CONNECT");
    lv_obj_set_style_text_color(ui_LabelConfigDeviceID, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelConfigDeviceID, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelConfigDeviceID, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPIN = lv_btn_create(ui_ScreenConfig);
    lv_obj_set_width(ui_ButtonPIN, 95);
    lv_obj_set_height(ui_ButtonPIN, 50);
    lv_obj_set_x(ui_ButtonPIN, 0);
    lv_obj_set_y(ui_ButtonPIN, 260);
    lv_obj_set_align(ui_ButtonPIN, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ButtonPIN, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPIN, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonPIN, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPIN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label37 = lv_label_create(ui_ButtonPIN);
    lv_obj_set_width(ui_Label37, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label37, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label37, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label37, "PIN");
    lv_obj_set_style_text_color(ui_Label37, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label37, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label37, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelConfigStatus = lv_label_create(ui_ScreenConfig);
    lv_obj_set_width(ui_LabelConfigStatus, 210);
    lv_obj_set_height(ui_LabelConfigStatus, 90);
    lv_obj_set_x(ui_LabelConfigStatus, 100);
    lv_obj_set_y(ui_LabelConfigStatus, 320);
    lv_label_set_text(ui_LabelConfigStatus, "--");

    ui_ButtonConfigDone = lv_btn_create(ui_ScreenConfig);
    lv_obj_set_width(ui_ButtonConfigDone, 100);
    lv_obj_set_height(ui_ButtonConfigDone, 50);
    lv_obj_set_x(ui_ButtonConfigDone, -10);
    lv_obj_set_y(ui_ButtonConfigDone, -10);
    lv_obj_set_align(ui_ButtonConfigDone, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ButtonConfigDone, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigDone, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigDone, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigDone, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label24 = lv_label_create(ui_ButtonConfigDone);
    lv_obj_set_width(ui_Label24, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label24, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label24, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label24, "DONE");
    lv_obj_set_style_text_color(ui_Label24, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label24, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label24, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigFree = lv_btn_create(ui_ScreenConfig);
    lv_obj_set_width(ui_ButtonConfigFree, 100);
    lv_obj_set_height(ui_ButtonConfigFree, 50);
    lv_obj_set_x(ui_ButtonConfigFree, 10);
    lv_obj_set_y(ui_ButtonConfigFree, -10);
    lv_obj_set_align(ui_ButtonConfigFree, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_ButtonConfigFree, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigFree, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigFree, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigFree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label27 = lv_label_create(ui_ButtonConfigFree);
    lv_obj_set_width(ui_Label27, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label27, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label27, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label27, "FREE");
    lv_obj_set_style_text_color(ui_Label27, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label27, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label27, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_PanelConfigPIN = lv_obj_create(ui_ScreenConfig);
    lv_obj_set_width(ui_PanelConfigPIN, 256);
    lv_obj_set_height(ui_PanelConfigPIN, 256);
    lv_obj_set_x(ui_PanelConfigPIN, 0);
    lv_obj_set_y(ui_PanelConfigPIN, 70);
    lv_obj_set_align(ui_PanelConfigPIN, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_PanelConfigPIN, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelConfigPIN, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelConfigPIN, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelConfigPIN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelConfigPIN, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelConfigPIN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelConfigPIN, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label38 = lv_label_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_Label38, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label38, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label38, 0);
    lv_obj_set_y(ui_Label38, 10);
    lv_label_set_text(ui_Label38, "Current");

    ui_Label39 = lv_label_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_Label39, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label39, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label39, 0);
    lv_obj_set_y(ui_Label39, 60);
    lv_label_set_text(ui_Label39, "New");

    ui_Label40 = lv_label_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_Label40, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label40, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label40, 0);
    lv_obj_set_y(ui_Label40, 110);
    lv_label_set_text(ui_Label40, "Repeat");

    ui_TextAreaConfigPINCurrent = lv_textarea_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_TextAreaConfigPINCurrent, 150);
    lv_obj_set_height(ui_TextAreaConfigPINCurrent, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_align(ui_TextAreaConfigPINCurrent, LV_ALIGN_TOP_RIGHT);
    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_TextAreaConfigPINCurrent, NULL);
    else lv_textarea_set_accepted_chars(ui_TextAreaConfigPINCurrent, "0123456789");
    lv_textarea_set_max_length(ui_TextAreaConfigPINCurrent, 6);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigPINCurrent, "Current PIN");
    lv_textarea_set_one_line(ui_TextAreaConfigPINCurrent, true);
    lv_textarea_set_password_mode(ui_TextAreaConfigPINCurrent, true);
    lv_obj_set_style_text_font(ui_TextAreaConfigPINCurrent, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaConfigPINRepeat = lv_textarea_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_TextAreaConfigPINRepeat, 150);
    lv_obj_set_height(ui_TextAreaConfigPINRepeat, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextAreaConfigPINRepeat, 0);
    lv_obj_set_y(ui_TextAreaConfigPINRepeat, 100);
    lv_obj_set_align(ui_TextAreaConfigPINRepeat, LV_ALIGN_TOP_RIGHT);
    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_TextAreaConfigPINRepeat, NULL);
    else lv_textarea_set_accepted_chars(ui_TextAreaConfigPINRepeat, "0123456789");
    lv_textarea_set_max_length(ui_TextAreaConfigPINRepeat, 6);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigPINRepeat, "Confirm PIN");
    lv_textarea_set_one_line(ui_TextAreaConfigPINRepeat, true);
    lv_textarea_set_password_mode(ui_TextAreaConfigPINRepeat, true);
    lv_obj_set_style_text_font(ui_TextAreaConfigPINRepeat, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaConfigPINNew = lv_textarea_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_TextAreaConfigPINNew, 150);
    lv_obj_set_height(ui_TextAreaConfigPINNew, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextAreaConfigPINNew, 0);
    lv_obj_set_y(ui_TextAreaConfigPINNew, 50);
    lv_obj_set_align(ui_TextAreaConfigPINNew, LV_ALIGN_TOP_RIGHT);
    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_TextAreaConfigPINNew, NULL);
    else lv_textarea_set_accepted_chars(ui_TextAreaConfigPINNew, "0123456789");
    lv_textarea_set_max_length(ui_TextAreaConfigPINNew, 6);
    lv_textarea_set_placeholder_text(ui_TextAreaConfigPINNew, "New PIN");
    lv_textarea_set_one_line(ui_TextAreaConfigPINNew, true);
    lv_textarea_set_password_mode(ui_TextAreaConfigPINNew, true);
    lv_obj_set_style_text_font(ui_TextAreaConfigPINNew, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigPINOK = lv_btn_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_ButtonConfigPINOK, 100);
    lv_obj_set_height(ui_ButtonConfigPINOK, 50);
    lv_obj_set_align(ui_ButtonConfigPINOK, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ButtonConfigPINOK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigPINOK, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigPINOK, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigPINOK, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label35 = lv_label_create(ui_ButtonConfigPINOK);
    lv_obj_set_width(ui_Label35, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label35, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label35, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label35, "OK");
    lv_obj_set_style_text_color(ui_Label35, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label35, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label35, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigPINCancel = lv_btn_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_ButtonConfigPINCancel, 100);
    lv_obj_set_height(ui_ButtonConfigPINCancel, 50);
    lv_obj_set_align(ui_ButtonConfigPINCancel, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_ButtonConfigPINCancel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigPINCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigPINCancel, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigPINCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label41 = lv_label_create(ui_ButtonConfigPINCancel);
    lv_obj_set_width(ui_Label41, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label41, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label41, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label41, "CANCEL");
    lv_obj_set_style_text_color(ui_Label41, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label41, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label41, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelConfigPINMessage = lv_label_create(ui_PanelConfigPIN);
    lv_obj_set_width(ui_LabelConfigPINMessage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfigPINMessage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelConfigPINMessage, 0);
    lv_obj_set_y(ui_LabelConfigPINMessage, -60);
    lv_obj_set_align(ui_LabelConfigPINMessage, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_LabelConfigPINMessage, "");

    ui_KeyboardConfigWifi = lv_keyboard_create(ui_ScreenConfig);
    lv_obj_set_width(ui_KeyboardConfigWifi, 320);
    lv_obj_set_height(ui_KeyboardConfigWifi, 150);
    lv_obj_add_flag(ui_KeyboardConfigWifi, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_KeyboardNumeric = lv_keyboard_create(ui_ScreenConfig);
    lv_keyboard_set_mode(ui_KeyboardNumeric, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardNumeric, 320);
    lv_obj_set_height(ui_KeyboardNumeric, 143);
    lv_obj_set_x(ui_KeyboardNumeric, 0);
    lv_obj_set_y(ui_KeyboardNumeric, 149);
    lv_obj_set_align(ui_KeyboardNumeric, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_KeyboardNumeric, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_add_event_cb(ui_TextAreaConfigSSID, ui_event_TextAreaConfigSSID, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaWifiPassword, ui_event_TextAreaWifiPassword, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaConfigHost, ui_event_TextAreaConfigHost, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaConfigDeviceID, ui_event_TextAreaConfigDeviceID, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigTuner, ui_event_ButtonConfigTuner, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigConnect, ui_event_ButtonConfigConnect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPIN, ui_event_ButtonPIN, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Label24, ui_event_Label24, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigDone, ui_event_ButtonConfigDone, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigFree, ui_event_ButtonConfigFree, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaConfigPINCurrent, ui_event_TextAreaConfigPINCurrent, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaConfigPINRepeat, ui_event_TextAreaConfigPINRepeat, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaConfigPINNew, ui_event_TextAreaConfigPINNew, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Label35, ui_event_Label35, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigPINOK, ui_event_ButtonConfigPINOK, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Label41, ui_event_Label41, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigPINCancel, ui_event_ButtonConfigPINCancel, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardConfigWifi, ui_TextAreaConfigSSID);
    lv_obj_add_event_cb(ui_KeyboardConfigWifi, ui_event_KeyboardConfigWifi, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardNumeric, ui_TextAreaConfigPINCurrent);

}
void ui_ScreenConfigAdvanced_screen_init(void)
{
    ui_ScreenConfigAdvanced = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenConfigAdvanced, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenConfigAdvanced, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenConfigAdvanced, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScreenConfigAdvanced, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScreenConfigAdvanced, lv_color_hex(BB_FGCOLOR), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenConfigAdvanced, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ScreenConfigAdvanced, lv_color_hex(BB_BGCOLOR), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ScreenConfigAdvanced, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_PanelHeaderConfig = lv_obj_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_PanelHeaderConfig, 320);
    lv_obj_set_height(ui_PanelHeaderConfig, 50);
    lv_obj_clear_flag(ui_PanelHeaderConfig, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_PanelHeaderConfig, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(ui_PanelHeaderConfig, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHeaderConfig, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHeaderConfig, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHeaderConfig, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_PanelHeaderConfig);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Label2, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_Label2, "SETTINGS TUNER");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigBack = lv_btn_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_ButtonConfigBack, 100);
    lv_obj_set_height(ui_ButtonConfigBack, 50);
    lv_obj_set_x(ui_ButtonConfigBack, -10);
    lv_obj_set_y(ui_ButtonConfigBack, -10);
    lv_obj_set_align(ui_ButtonConfigBack, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ButtonConfigBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigBack, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label16 = lv_label_create(ui_ButtonConfigBack);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "DONE");
    lv_obj_set_style_text_color(ui_Label16, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label16, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 10);
    lv_obj_set_y(ui_Label3, 60);
    lv_label_set_text(ui_Label3, "Servo closed position");

    ui_LabelConfigServoClosed = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_LabelConfigServoClosed, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfigServoClosed, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelConfigServoClosed, -15);
    lv_obj_set_y(ui_LabelConfigServoClosed, 60);
    lv_obj_set_align(ui_LabelConfigServoClosed, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_LabelConfigServoClosed, "--");

    ui_SliderConfigServoClosed = lv_slider_create(ui_ScreenConfigAdvanced);
    lv_slider_set_range(ui_SliderConfigServoClosed, 0, 180);
    lv_obj_set_width(ui_SliderConfigServoClosed, 290);
    lv_obj_set_height(ui_SliderConfigServoClosed, 10);
    lv_obj_set_x(ui_SliderConfigServoClosed, 15);
    lv_obj_set_y(ui_SliderConfigServoClosed, 85);
    lv_obj_set_style_bg_color(ui_SliderConfigServoClosed, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoClosed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SliderConfigServoClosed, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SliderConfigServoClosed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SliderConfigServoClosed, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigServoClosed, lv_color_hex(BB_BGCOLOR), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoClosed, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigServoClosed, lv_color_hex(BB_BGCOLOR), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoClosed, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 10);
    lv_obj_set_y(ui_Label8, 120);
    lv_label_set_text(ui_Label8, "Servo open position");

    ui_LabelConfigServoOpen = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_LabelConfigServoOpen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfigServoOpen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelConfigServoOpen, -15);
    lv_obj_set_y(ui_LabelConfigServoOpen, 120);
    lv_obj_set_align(ui_LabelConfigServoOpen, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_LabelConfigServoOpen, "--");

    ui_SliderConfigServoOpen = lv_slider_create(ui_ScreenConfigAdvanced);
    lv_slider_set_range(ui_SliderConfigServoOpen, 0, 180);
    lv_obj_set_width(ui_SliderConfigServoOpen, 290);
    lv_obj_set_height(ui_SliderConfigServoOpen, 10);
    lv_obj_set_x(ui_SliderConfigServoOpen, 15);
    lv_obj_set_y(ui_SliderConfigServoOpen, 145);
    lv_obj_set_style_bg_color(ui_SliderConfigServoOpen, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoOpen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SliderConfigServoOpen, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SliderConfigServoOpen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SliderConfigServoOpen, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigServoOpen, lv_color_hex(BB_BGCOLOR), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoOpen, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigServoOpen, lv_color_hex(BB_BGCOLOR), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigServoOpen, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ButtonConfigServoClose = lv_btn_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_ButtonConfigServoClose, 145);
    lv_obj_set_height(ui_ButtonConfigServoClose, 50);
    lv_obj_set_x(ui_ButtonConfigServoClose, 10);
    lv_obj_set_y(ui_ButtonConfigServoClose, 170);
    lv_obj_set_align(ui_ButtonConfigServoClose, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_ButtonConfigServoClose, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigServoClose, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigServoClose, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigServoClose, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_ButtonConfigServoClose);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "CLOSE");
    lv_obj_set_style_text_color(ui_Label10, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label10, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonConfigServoOpen = lv_btn_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_ButtonConfigServoOpen, 145);
    lv_obj_set_height(ui_ButtonConfigServoOpen, 50);
    lv_obj_set_x(ui_ButtonConfigServoOpen, -10);
    lv_obj_set_y(ui_ButtonConfigServoOpen, 170);
    lv_obj_set_align(ui_ButtonConfigServoOpen, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_ButtonConfigServoOpen, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigServoOpen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigServoOpen, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigServoOpen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_ButtonConfigServoOpen);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "OPEN");
    lv_obj_set_style_text_color(ui_Label9, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label9, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Tap_duration = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_Tap_duration, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Tap_duration, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Tap_duration, 15);
    lv_obj_set_y(ui_Tap_duration, 235);
    lv_label_set_text(ui_Tap_duration, "Fallback tap duration (ms)");

    ui_LabelConfigTapDuration = lv_label_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_LabelConfigTapDuration, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfigTapDuration, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelConfigTapDuration, -15);
    lv_obj_set_y(ui_LabelConfigTapDuration, 235);
    lv_obj_set_align(ui_LabelConfigTapDuration, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_LabelConfigTapDuration, "--");

    ui_SliderConfigTapDuration = lv_slider_create(ui_ScreenConfigAdvanced);
    lv_slider_set_range(ui_SliderConfigTapDuration, 0, 15000);
    lv_obj_set_width(ui_SliderConfigTapDuration, 290);
    lv_obj_set_height(ui_SliderConfigTapDuration, 10);
    lv_obj_set_x(ui_SliderConfigTapDuration, 15);
    lv_obj_set_y(ui_SliderConfigTapDuration, 260);
    lv_obj_set_style_bg_color(ui_SliderConfigTapDuration, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigTapDuration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SliderConfigTapDuration, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SliderConfigTapDuration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SliderConfigTapDuration, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigTapDuration, lv_color_hex(BB_BGCOLOR), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigTapDuration, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderConfigTapDuration, lv_color_hex(BB_BGCOLOR), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderConfigTapDuration, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ButtonConfigSave = lv_btn_create(ui_ScreenConfigAdvanced);
    lv_obj_set_width(ui_ButtonConfigSave, 160);
    lv_obj_set_height(ui_ButtonConfigSave, 50);
    lv_obj_set_x(ui_ButtonConfigSave, 0);
    lv_obj_set_y(ui_ButtonConfigSave, 280);
    lv_obj_set_align(ui_ButtonConfigSave, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ButtonConfigSave, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfigSave, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonConfigSave, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfigSave, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_ButtonConfigSave);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "SAVE SETTINGS");
    lv_obj_set_style_text_color(ui_Label11, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label11, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonConfigBack, ui_event_ButtonConfigBack, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SliderConfigServoClosed, ui_event_SliderConfigServoClosed, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SliderConfigServoOpen, ui_event_SliderConfigServoOpen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigServoClose, ui_event_ButtonConfigServoClose, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigServoOpen, ui_event_ButtonConfigServoOpen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SliderConfigTapDuration, ui_event_SliderConfigTapDuration, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonConfigSave, ui_event_ButtonConfigSave, LV_EVENT_ALL, NULL);

}
void ui_ScreenBierFlowing_screen_init(void)
{
    ui_ScreenBierFlowing = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenBierFlowing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenBierFlowing, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenBierFlowing, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_ScreenBierFlowing);
    lv_obj_set_width(ui_Panel4, 320);
    lv_obj_set_height(ui_Panel4, 50);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label42 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_Label42, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label42, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label42, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label42, "ENJOY YOUR DRINK!");
    lv_obj_set_style_text_color(ui_Label42, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label42, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label42, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image3 = lv_img_create(ui_ScreenBierFlowing);
    lv_img_set_src(ui_Image3, &ui_img_biertap256_png);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 256
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 256
    lv_obj_set_y(ui_Image3, -10);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonBierStart = lv_btn_create(ui_ScreenBierFlowing);
    lv_obj_set_width(ui_ButtonBierStart, 160);
    lv_obj_set_height(ui_ButtonBierStart, 50);
    lv_obj_set_x(ui_ButtonBierStart, 0);
    lv_obj_set_y(ui_ButtonBierStart, -50);
    lv_obj_set_align(ui_ButtonBierStart, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_ButtonBierStart, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBierStart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonBierStart, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBierStart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label45 = lv_label_create(ui_ButtonBierStart);
    lv_obj_set_width(ui_Label45, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label45, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label45, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label45, "START");
    lv_obj_set_style_text_color(ui_Label45, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label45, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label45, &ui_font_FontBoucherieBlock24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BarBierProgress = lv_bar_create(ui_ScreenBierFlowing);
    lv_bar_set_range(ui_BarBierProgress,0,TAPPROGRESS_STEPS);
    lv_bar_set_value(ui_BarBierProgress, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_BarBierProgress, 260);
    lv_obj_set_height(ui_BarBierProgress, 20);
    lv_obj_set_x(ui_BarBierProgress, 0);
    lv_obj_set_y(ui_BarBierProgress, -70);
    lv_obj_set_align(ui_BarBierProgress, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_bg_color(ui_BarBierProgress, lv_color_hex(BB_FGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarBierProgress, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BarBierProgress, lv_color_hex(BB_BGCOLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BarBierProgress, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BarBierProgress, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_bg_color(ui_BarBierProgress, lv_color_hex(BB_BGCOLOR), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarBierProgress, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonBierStart, ui_event_ButtonBierStart, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenBierFlowing, ui_event_ScreenBierFlowing, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenAbout_screen_init();
    ui_ScreenMain_screen_init();
    ui_ScreenPin_screen_init();
    ui_ScreenConfig_screen_init();
    ui_ScreenConfigAdvanced_screen_init();
    ui_ScreenBierFlowing_screen_init();
    lv_disp_load_scr(ui_ScreenAbout);
}
