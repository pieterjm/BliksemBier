#ifndef _BLIKSEMBIER_H_
#define _BLIKSEMBIER_H_

#ifdef __cplusplus
extern "C" {
#endif

bool checkPIN(const char *pin);

void updatePIN(const char *pin);

void beerOpen();

void beerClose();

void beerScreen();

void beerStart();

void wantBierClicked(int item);

void connectBliksemBier(const char *ssid,const char *pwd, const char *deviceid,const char *lnbitshost);

void saveTuning(int32_t servoClosed, int32_t servoOpen, int32_t tapDuration);

bool getWifiStatus();

void backToAboutPage();

void toConfigPage();

bool getWebSocketStatus();

void myDelay(uint32_t ms);

void saveConfig();

void beginOTA();

void freeBeerClicked();

#ifdef __cplusplus
}
#endif


#endif