# ESP32 Audio Monitor

This is a port of this [project](https://github.com/atomic14/m5stack-core2-audio-monitor) to work with any ESP32 device with a TFT display.

You can watch a video explainer [here (YouTube)](https://www.youtube.com/watch?v=KaJ4b3HJ3NA) which goes into a bit more detail on the audio capabilities of the device.

[![Demo Video](https://img.youtube.com/vi/KaJ4b3HJ3NA/0.jpg)](https://www.youtube.com/watch?v=KaJ4b3HJ3NA)

You'll need to use PlatformIO to build the project.

To clone the repo use:

```
git clone --recursive git@github.com:atomic14/esp32-tft-audio-monitor.git
```

This will make sure you get the TFT library as well.

Hopefully, the code should be easy to understand.

If you want to add some more visualisations then please open up a pull request and contribute some code.

To modify the code to work with your particular device you will need to change the settings in `platformio.ini` to match your TFT. The easiest way to do this is to look in the `lib/TFT_eSPI/User_Setups` for your device and copy the required pre-processor defines.

If you are feeling lazy then you can just copy the setup for you TFT over the `User_Setup.h` and remove the defines from the build settings.

If you take the lazy option, then remember to remove `-DUSER_SETUP_LOADED=1`.

```
; setup for the TTGO T4
  -DTFT_WIDTH=135
  -DTFT_HEIGHT=240
  -DST7789_DRIVER=1
  -DCGRAM_OFFSET=1
  -DTFT_MISO=-1
  -DTFT_MOSI=19
  -DTFT_SCLK=18
  -DTFT_CS=5
  -DTFT_DC=16
  -DTFT_RST=23
  -DTFT_BL=4
  -DTFT_BACKLIGHT_ON=HIGH
  -DLOAD_GLCD=1
  -DLOAD_FONT2=1
  -DLOAD_FONT4=1
  -DLOAD_FONT6=1
  -DLOAD_FONT7=1
  -DLOAD_FONT8=1
  -DLOAD_GFXFF=1
  -DSMOOTH_FONT=1
  -DSPI_FREQUENCY=40000000
  -DSPI_READ_FREQUENCY=6000000
```

And if you'd like to buy me a coffee...

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Z8Z734F5Y)
