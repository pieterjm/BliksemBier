#ifndef _UI_H
#define _UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern lv_obj_t * ui_ScreenAbout;
extern lv_obj_t * ui_PanelHeaderAbout;
extern lv_obj_t * ui_Label17;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_LabelAboutStatus;
extern lv_obj_t * ui_ButtonAboutOne;
extern lv_obj_t * ui_ButtonAboutTwo;
extern lv_obj_t * ui_ButtonAboutThree;
extern lv_obj_t * ui_LabelAboutOne;
extern lv_obj_t * ui_LabelAboutTwo;
extern lv_obj_t * ui_LabelAboutThree;
extern lv_obj_t * ui_PanelAboutMessage;
extern lv_obj_t * ui_LabelAboutMessage;
void ui_event_ButtonAboutConfig(lv_event_t * e);
void ui_event_ButtonAboutOne(lv_event_t * e);
void ui_event_ButtonAboutTwo(lv_event_t * e);
void ui_event_ButtonAboutThree(lv_event_t * e);
extern lv_obj_t * ui_ScreenMain;
extern lv_obj_t * ui_PanelHeaderMain;
extern lv_obj_t * ui_LabelHeaderMain;
void ui_event_ButtonMainAbout(lv_event_t * e);
extern lv_obj_t * ui_ButtonMainAbout;
extern lv_obj_t * ui_QrcodeLnurl;
extern lv_obj_t * ui_Label18;
extern lv_obj_t * ui_ImageQRCodeBorder;
extern lv_obj_t * ui_ScreenPin;
extern lv_obj_t * ui_LabelPINValue;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Label12;

extern lv_obj_t * ui_PanelMainMessage;
extern lv_obj_t * ui_LabelMainMessage;

void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label15;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Label21;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_Label22;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Label25;
void ui_event_Button5(lv_event_t * e);
extern lv_obj_t * ui_Button5;
extern lv_obj_t * ui_Label20;
void ui_event_Button6(lv_event_t * e);
extern lv_obj_t * ui_Button6;
extern lv_obj_t * ui_Label29;
void ui_event_Button7(lv_event_t * e);
extern lv_obj_t * ui_Button7;
extern lv_obj_t * ui_Label30;
void ui_event_Button8(lv_event_t * e);
extern lv_obj_t * ui_Button8;
extern lv_obj_t * ui_Label31;
void ui_event_Button9(lv_event_t * e);
extern lv_obj_t * ui_Button9;
extern lv_obj_t * ui_Label13;
void ui_event_ButtonPINCancel(lv_event_t * e);
extern lv_obj_t * ui_ButtonPINCancel;
extern lv_obj_t * ui_Label32;
void ui_event_Button11(lv_event_t * e);
extern lv_obj_t * ui_Button11;
extern lv_obj_t * ui_Label33;
void ui_event_ButtonPinOK(lv_event_t * e);
extern lv_obj_t * ui_ButtonPinOK;
extern lv_obj_t * ui_Label34;
extern lv_obj_t * ui_ScreenConfig;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Label23;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Label26;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Label36;
extern lv_obj_t * ui_Label14;
void ui_event_TextAreaConfigSSID(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigSSID;
void ui_event_TextAreaWifiPassword(lv_event_t * e);
extern lv_obj_t * ui_TextAreaWifiPassword;
void ui_event_TextAreaConfigHost(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigHost;
void ui_event_TextAreaConfigDeviceID(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigDeviceID;
void ui_event_ButtonConfigTuner(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigTuner;
extern lv_obj_t * ui_Label28;
void ui_event_ButtonConfigConnect(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigConnect;
extern lv_obj_t * ui_LabelConfigDeviceID;
void ui_event_ButtonPIN(lv_event_t * e);
extern lv_obj_t * ui_ButtonPIN;
extern lv_obj_t * ui_Label37;
extern lv_obj_t * ui_LabelConfigStatus;
void ui_event_ButtonConfigDone(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigDone;
void ui_event_Label24(lv_event_t * e);
extern lv_obj_t * ui_Label24;
void ui_event_ButtonConfigFree(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigFree;
void ui_event_Label27(lv_event_t * e);
extern lv_obj_t * ui_Label27;



extern lv_obj_t * ui_PanelConfigPIN;
extern lv_obj_t * ui_Label38;
extern lv_obj_t * ui_Label39;
extern lv_obj_t * ui_Label40;
void ui_event_TextAreaConfigPINCurrent(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigPINCurrent;
void ui_event_TextAreaConfigPINRepeat(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigPINRepeat;
void ui_event_TextAreaConfigPINNew(lv_event_t * e);
extern lv_obj_t * ui_TextAreaConfigPINNew;
void ui_event_ButtonConfigPINOK(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigPINOK;
void ui_event_Label35(lv_event_t * e);
extern lv_obj_t * ui_Label35;
void ui_event_ButtonConfigPINCancel(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigPINCancel;
void ui_event_Label41(lv_event_t * e);
extern lv_obj_t * ui_Label41;
extern lv_obj_t * ui_LabelConfigPINMessage;
void ui_event_KeyboardConfigWifi(lv_event_t * e);
extern lv_obj_t * ui_KeyboardConfigWifi;
extern lv_obj_t * ui_KeyboardNumeric;
extern lv_obj_t * ui_ScreenConfigAdvanced;
extern lv_obj_t * ui_PanelHeaderConfig;
extern lv_obj_t * ui_Label2;
void ui_event_ButtonConfigBack(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigBack;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_LabelConfigServoClosed;
void ui_event_SliderConfigServoClosed(lv_event_t * e);
extern lv_obj_t * ui_SliderConfigServoClosed;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_LabelConfigServoOpen;
void ui_event_SliderConfigServoOpen(lv_event_t * e);
extern lv_obj_t * ui_SliderConfigServoOpen;
void ui_event_ButtonConfigServoClose(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigServoClose;
extern lv_obj_t * ui_Label10;
void ui_event_ButtonConfigServoOpen(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigServoOpen;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_Tap_duration;
extern lv_obj_t * ui_LabelConfigTapDuration;
void ui_event_SliderConfigTapDuration(lv_event_t * e);
extern lv_obj_t * ui_SliderConfigTapDuration;
void ui_event_ButtonConfigSave(lv_event_t * e);
extern lv_obj_t * ui_ButtonConfigSave;
extern lv_obj_t * ui_Label11;
void ui_event_ScreenBierFlowing(lv_event_t * e);
extern lv_obj_t * ui_ScreenBierFlowing;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Label42;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_BarBierProgress;
extern lv_obj_t * ui_ButtonBierStart;
extern lv_obj_t * ui_Label45;
void ui_event_ButtonBierStart(lv_event_t * e);


void ButtonPinOneClicked(lv_event_t * e);
void ButtonPinTwoClicked(lv_event_t * e);
void ButtonPinThreeClicked(lv_event_t * e);
void ButtonPinFourClicked(lv_event_t * e);
void ButtonPinFiveClicked(lv_event_t * e);
void ButtonPinSixClicked(lv_event_t * e);
void ButtonPinSevenClicked(lv_event_t * e);
void ButtonPinEightClicked(lv_event_t * e);
void ButtonPinNineClicked(lv_event_t * e);
void ButtonPinCancelClicked(lv_event_t * e);
void ButtonPinZeroClicked(lv_event_t * e);
void ButtonPinOKClicked(lv_event_t * e);
void ButtonConfigConnectClicked(lv_event_t * e);
void ButtonOKPINClicked(lv_event_t * e);
void ButtoCancelPINClicked(lv_event_t * e);
void ButtonConfigTunerClicked(lv_event_t * e);
void ButtonConfigCloseClicked(lv_event_t * e);
void ButtonConfigOpenClicked(lv_event_t * e);
void ButtonConfigSaveClicked(lv_event_t * e);
void ButtonScreenBierFlowingClicked(lv_event_t * e);
void ButtonBierStartClicked(lv_event_t * e);
void ButtonAboutOneClicked(lv_event_t * e);
void ButtonAboutTwoClicked(lv_event_t * e);
void ButtonAboutThreeClicked(lv_event_t * e);
void ButtonAboutConfigClicked(lv_event_t * e);
void ButtonFreeClicked(lv_event_t * e );
void ButtonMainBackClicked(lv_event_t * e);

LV_IMG_DECLARE(ui_img_kanhetal256_png);    // kan het al
LV_IMG_DECLARE(ui_img_329557545);    // assets/qr-code-slagschaduw-274x274-v2.png
LV_IMG_DECLARE(ui_img_biertap256_png);    // assets/biertap256.png


LV_FONT_DECLARE(ui_font_FontBoucherieBlock24);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
