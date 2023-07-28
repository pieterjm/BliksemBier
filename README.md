
# BliksemBier, a Bitcoin Lightning enabled beertap

BliksemBier is a beertap that accepts Bitcoin. BliksemBier consists of two components: na LNbits (https://github.com/lnbits/lnbits) extension and firmware for an ESP32-based smart display (made by Sunton). The firmware for the tap is created in such a way that can be used for different beertap types. For 5L draught kegs to professional beertaps. The following pictures illustrate some of the applications of BliksemBier.





## Configuration 

To get the beertap up and running, take the following steps:

1. Open a webbrowser, navigate to: https://lnbits.meulenhoff.org and create a wallet.
2. Add the LNURLdevice extension to the wallet.
3. Create an LNURLDevice by clicking 'NEW LNURLDEVICE INSTANCE'. 
4. Configure the LNURLDevice, make sure that the type is set to 'Switch'.
5. Add one or more (max three) switches by clicking on the '+' button. Configure price, duration and Label for each switch. 
  * The duration is the amount of milliseconds, the tap is switched on.
  * The Label button is displayed on the tap. For instance 'SMALL' or 'LARGE'. Currently, only a limited subset of characters is support (CAPS ONLY).
6. Click 'CREATE LNURLDEVICE' and record the ID of the LNURLdevice (8 charachters).

Now move over to the beertap itself.

7. Power on the beertap and click the 'Config' button.
8. Enter the PIN (the initial PIN is 123456)
9. Configure SSID and Secret to connect the tap to a Wi-Fi network.
10. Make sure that LNbits host is set to: lnbits.meulenhoff.org
11. Set 'Device ID' to the ID of the LNURL device (from step 6). 
12. Click connect. 

If all went as planned, the status says: Wi-Fi connected, Configuration loaded and finally WebSocket connected. 
  
## Compilation

BliksemBier is created with platform.io. 

To compile the project from within Visual Studio Code using platform.io, take the following steps:

  1. Install Visual Studio Code. Download from https://code.visualstudio.com/. If Git is not yet installed on your system, you need to install that as well.
  2. Install the Platform IO extension. Open the Extension Manager (click the wheel icon at the bottom of the bar and the left and select Extensions). Search for PlatformIO, and click 'Install'.
  3. In Visual Studio code, open the command palette (Ctrl-Shift-P) and type 'gitcl'.
  4. When prompted for the repository URL, enter the URL of this repository: `https://github.com/pieterjm/BliksemBier.git`
  5. Select a local directrory where to store the repository and open the repository.
  6. To compile, click the checkmark icon in the blue bar at the bottom to compile the repository. This may take a while as external libraries have to be loaded.
  7. Connect the device to USB port and click the '>' button in the blue bar at the bottom to compile and flash the firmware.
  8. After compilation and firmware flashing is succesful, the device should restart as a fresh Btap.
  
To compile the project using platformio core only, take the following steps

  1. Install platformio core by following the instructions here: https://docs.platformio.org/en/stable/core/installation/methods/installer-script.html
  2. Clone the repository with the following command
     ```
     git clone https://github.com/pieterjm/BliksemBier.git
     ```
  3. Compile and upload
     ```
     cd BliksemBier
     platformio run --target upload
     ```

