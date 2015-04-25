# audiocore
A wifi-enabled dac/amp project featuring a sparkcore and es9018k2m dac

## Change Log
4-25-15 Initial commit for project: 
* adding device drivers for the dac
* adding wi-fi functionalities volume_control,mute, and reset



##Description
This project connects an es9018k2m DAC to a [Spark Core](https://www.spark.io) controller through an I2C bus.

Connecting the es9018k2m DAC to the sparkcore enables dac control over wi-fi. For instance, the user will be able to control volume, mute/unmute, and reset the dac with their phone.

##Installation
This firmware is built from gcc-arm, and flashed with the spark cli interface. Please see [spark core git](https://github.com/spark/firmware) for information to get the environment setup

NOTE: before building the audiocore firmware, make sure to compile the sparkcore firmware. 

1. clone this repository in [sparkcore directory]/firmware/applications/audiocore
2. cd [sparkcore directory]/firmware/build
3. make APP=audiocore
4. spark flash [sparkcore id] applications/audiocore/audiocore.bin


##Hardware used for this project
* [Spark Core Core](https://store.spark.io/?product=spark-core)
* [DIYINHK ES9018K2M](http://www.diyinhk.com/shop/audio-kits/60-usb-dsd-dxd-384khz-dac-with-bit-perfect-volume-control-and-spdif-inputxmoses9018k2m.html)
* [DIYINHK Isolated XMOS](http://www.diyinhk.com/shop/audio-kits/69-isolated-xmos-dsd-dxd-384khz-high-quality-usb-to-i2sdsd-pcb-with-ultralow-noise-regulator.html)
* [DIYINHK D1 High Fideility Headphone Amplifier](http://www.diyinhk.com/shop/audio-kits/61-d1-high-fideility-headphone-amplifier.html)
