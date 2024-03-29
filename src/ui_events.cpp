#include "ui.h"
#include "bliksembier.h"
#include <WString.h>

String entered_pin = "";

void addToPIN(int digit) {
  if (  entered_pin.length() < 6 ) {
    entered_pin += digit;

    String hidePIN = "";
    for(int i=0;(i<entered_pin.length());i++) {
      hidePIN += "*";
    }
    lv_label_set_text(ui_LabelPINValue,hidePIN.c_str());
  }
}

void ButtonPinOneClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(1);
}

void ButtonPinTwoClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(2);
}

void ButtonPinThreeClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(3);
}

void ButtonPinFourClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(4);
}

void ButtonPinFiveClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(5);
}

void ButtonPinSixClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(6);
}

void ButtonPinSevenClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(7);
}

void ButtonPinEightClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(8);
}

void ButtonPinNineClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(9);
}

void ButtonPinCancelClicked(lv_event_t * e)
{
	// Your code here
	if ( entered_pin.length() == 0 ) {
		lv_disp_load_scr(ui_ScreenAbout);		
	}
	entered_pin = "";
	lv_label_set_text(ui_LabelPINValue,"ENTER PIN");
}

void ButtonPinZeroClicked(lv_event_t * e)
{
	// Your code here
	addToPIN(0);
}

void ButtonPinOKClicked(lv_event_t * e)
{
	// Your code here
	if ( checkPIN(entered_pin.c_str()) == true ) {
		lv_disp_load_scr(ui_ScreenConfig);	
		lv_label_set_text(ui_LabelPINValue,"ENTER PIN");
		entered_pin = "";
	} else {
		lv_label_set_text(ui_LabelPINValue,"PIN INCORRECT");
		entered_pin = "";
	}
}

void ButtonConfigTunerClicked(lv_event_t * e)
{
	lv_disp_load_scr(ui_ScreenConfigAdvanced);
	if ( false ) {
		beginOTA();
		/// UNREACHABLE CODE
	}
}

void ButtonConfigConnectClicked(lv_event_t * e)
{
	// Your code here
	const char *ssid = lv_textarea_get_text(ui_TextAreaConfigSSID);
	const char *pwd = lv_textarea_get_text(ui_TextAreaWifiPassword);
	const char *deviceid = lv_textarea_get_text(ui_TextAreaConfigDeviceID);
	const char *cfgserver = lv_textarea_get_text(ui_TextAreaConfigHost);
	connectBliksemBier(ssid,pwd,deviceid,cfgserver);
}

void ButtonOKPINClicked(lv_event_t * e)
{
	// Your code here
	const char *currentPIN = lv_textarea_get_text(ui_TextAreaConfigPINCurrent);
	const char *newPIN = lv_textarea_get_text(ui_TextAreaConfigPINNew);
	const char *repeatPIN = lv_textarea_get_text(ui_TextAreaConfigPINRepeat);

	if ( checkPIN(currentPIN) == false ) {	
		lv_label_set_text(ui_LabelConfigPINMessage,"Current PIN incorrect");
		return;
	}

	if ( strlen(newPIN) != 6 ) {
		lv_label_set_text(ui_LabelConfigPINMessage,"PIN must be 6 characters");
		return;	
	}

	if ( strncmp(newPIN,repeatPIN,6) != 0 ) {
		lv_label_set_text(ui_LabelConfigPINMessage,"New PIN not equal");
		return;	
	}

	
	updatePIN(newPIN);

	// Your code here
	lv_textarea_set_text(ui_TextAreaConfigPINCurrent,"");
	lv_textarea_set_text(ui_TextAreaConfigPINNew,"");
	lv_textarea_set_text(ui_TextAreaConfigPINRepeat,"");
	lv_label_set_text(ui_LabelConfigPINMessage,"");
	lv_obj_add_flag(ui_PanelConfigPIN,LV_OBJ_FLAG_HIDDEN);
}

void ButtoCancelPINClicked(lv_event_t * e)
{
	// Your code here
	lv_textarea_set_text(ui_TextAreaConfigPINCurrent,"");
	lv_textarea_set_text(ui_TextAreaConfigPINNew,"");
	lv_textarea_set_text(ui_TextAreaConfigPINRepeat,"");
	lv_label_set_text(ui_LabelConfigPINMessage,"");
	lv_obj_add_flag(ui_PanelConfigPIN,LV_OBJ_FLAG_HIDDEN);
}

void ButtonConfigCleanClicked(lv_event_t * e)
{
	// Your code here
	beerClean();
}

void ButtonConfigCloseClicked(lv_event_t * e)
{
	// Your code here
	beerClose();
}

void ButtonConfigOpenClicked(lv_event_t * e)
{
	// Your code here
	beerOpen();
}

void ButtonConfigSaveClicked(lv_event_t * e)
{
	// Your code here
	int32_t servoBack = lv_slider_get_value(ui_SliderConfigServoBack);
	int32_t servoClosed = lv_slider_get_value(ui_SliderConfigServoClosed);
	int32_t servoOpen = lv_slider_get_value(ui_SliderConfigServoOpen);
	int32_t tapDuration = lv_slider_get_value(ui_SliderConfigTapDuration);
	saveTuning(servoBack,servoClosed,servoOpen,tapDuration);	
}

void ButtonScreenBierFlowingClicked(lv_event_t * e)
{
	// Your code here
	beerClose();
}


void ButtonBierStartClicked(lv_event_t *e ) 
{
	beerStart();
}

void ButtonAboutOneClicked(lv_event_t *e) 
{
	wantBierClicked(0);
}

void ButtonAboutTwoClicked(lv_event_t *e) 
{
	wantBierClicked(1);
}

void ButtonAboutThreeClicked(lv_event_t *e) 
{
	wantBierClicked(2);
}

void ButtonFreeClicked(lv_event_t *e)
{
	freeBeerClicked();
}

void ButtonMainBackClicked(lv_event_t *e) {
	backToAboutPage();
}

void ButtonAboutConfigClicked(lv_event_t *e) {
	entered_pin = "";
	toConfigPage();
}