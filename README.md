## Reading Si7021 temperature and humidity sensor with ESP32

The Si7021 temperature and humidity sensor is a I2C sensor that accurately measures environmental conditions. This application for the [ESP32]() is a test of a component that creates and interface to this device.

### Usage

To use this application, you must have the ESP-IDF environment installed. After cloning, you will need to run `make menuconfig` to set up the proper make files and then `make flash` to flash it onto your device.

### References

- [Si7021 datasheet](http://ojisanseiuchi.com/2018/03/11/Reading-data-from-Si7021-temperature-and-humidity-sensor-using-Raspberry-Pi/Si7021-A20.pdf)
- [Reading Si7021/HTU21D on the Raspberry Pi I2C bus](https://www.iot-programmer.com/index.php/books/22-raspberry-pi-and-the-iot-in-c/chapters-raspberry-pi-and-the-iot-in-c/61-raspberry-pi-and-the-iot-in-c-i2c-bus?showall=&start=3) - an excellent article for understanding how to implement clock-stretching and dealing with specifics of the Si7021 device.