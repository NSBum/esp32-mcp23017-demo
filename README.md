## Interfacing an MCP23017 I2C GPIO expander with ESP32

The MCP23017 is an I2C bus GPIO expander. This is an demonstration application for the ESP32 in the ESP-IDF environment.

![](https://github.com/NSBum/esp32-mcp23017-demo/blob/master/i2clogic.png)

### Usage

To use this application, you must have the ESP-IDF environment installed. After cloning, you will need to run `make menuconfig` to set up the proper make files and then `make flash` to flash it onto your device.

**Note**: The MCP23017 component in this demonstration does not yet support interrupt functionality. Also, the intent isn't really to duplicate Arduino `digitalWrite` type functionality. After spending a little time with the datasheet and learning how to set and clear bits, you can easily accomplish what you need without trying to emulate Arduino. 
