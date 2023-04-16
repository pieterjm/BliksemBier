

## Configuration 

The basic configuration of the beertap is done through the userinterface of the device by clicking on the 'Config' button on the main screen. The default PIN for the config is '123456'.

As connecting to LNbits requires to enter a long identifiers and LNURLs an additional helper file is required. This file cbontains configuration details of the WebSocket URL and the payment LNURL. Use the following steps to create such a file:

1. Create an LNURLDevice in LNbits. Make sure that the type is 'Switch' and set the correct price. 
2. Record the following data of the LNURLdevice
  - id 
  - LNURL
  - hostname (the hostname of the server)
3. Create a JSON file and store the data from the previous step. A sample file is shown below.
```
{
    "host":"lnbits.meulenhoff.org",
    "id":"8NTL78ERDsPkbRgrQsu39w",
    "lnurl":"LNURL1DP68GURN8GHJ7MRWVF5HGUEWD4JH2MR9DE5X7ENX9EHHYEE0D3H82UNVV3JHV6TRV5HKZURF9AMRZTMVDE6HYMP08P89GNPH8PZ4Y3RN2P4KY5N8WFGHXAFN89MN7EMSD9HN6VFXWPEX7ENFWS7NQT33XGNXZMT0W4H8G0F3JTRVVM"
}
```
The following parameters are included in the file:
 - `host` is the hostname of the LNbits server that provides the LNURLdevice. 
 - `id` is the identifier of the LNURLdevice (the value in the id column in LNbits).
 - `lnurl` is the LNURL of the LNURLdevice in LNbits. Click on the 'Eye' icon of the LNURLdevice to copy the LNURL.

4. Store the file on a web location of your choice in the path '/.well-known/bliksembier/{device id}.json'. You are free to choose a 'device id', it is just a mnenomic that is entered on the configuration screen.
5. Navigate to the URL to verify that the file is accessible
```
https://{config host}/.well-known/bliksembier/{device id}.json
```
6. On the tap device, go the config and enter the `config host` and `device id` where the file can be downloaded. The .json extension is not needed. 




## Compilation

BliksemBier is created with platform.io. 

To compile the project from within Visual Studio Code using platform.io, take the following steps:

  1. Install Visual Studio Code. Download from https://code.visualstudio.com/. If Git is not yet installed on your system, you need to install that as well.
  2. Install the Platform IO extension. Open the Extension Manager (click the wheel icon at the bottom of the bar and the left and select Extensions). Search for PlatformIO, and click 'Install'.
  3. In Visual Studio code, open the command palette (Ctrl-Shift-P) and type 'gitcl'.
  4. When prompted for the repository URL, enter the URL of this repository: `https://github.com/pieterjm/Btap.git`
  5. Select a local directrory where to store the repository and open the repository.
  6. To compile, click the checkmark icon in the blue bar at the bottom to compile the repository. This may take a while as external libraries have to be loaded.
  7. Connect the Btap to USB port and click the '>' button in the blue bar at the bottom to compile and flash the firmware.
  8. After compilation and firmware flashing is succesful, the device should restart as a fresh Btap.
  
To compile the project using platformio core only, take the following steps

  1. Install platformio core by following the instructions here: https://docs.platformio.org/en/stable/core/installation/methods/installer-script.html
  2. Clone the repository with the following command
     ```
     git clone https://github.com/pieterjm/Btap.git
     ```
  3. Compile and upload
     ```
     cd Btap
     platformio run --target upload
     ```

