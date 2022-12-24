# Pocketgame
An open source, cheap, easy to thinker and use esp8266-based console
# Supported hardware 
This project is easy to modify to make it run on various kinds of hardware, the configuration supported out of the box is the following:
- **nodeMCU Esp8266**
- **ST7735 128*160 TFT screen** (using the [Adafruit_ST7735](https://github.com/adafruit/Adafruit-ST7735-Library) library) 
- **6 buttons**

# Using unsupported hardware
## Screen
1. Head to the screen.h file
2. Edit the `width` and `height` variables according to the pixels on the desired screen
3. Head to the screen.cpp file
4. Import your preferred library to work with that screen
5. change the content of each function to the homologous function in the library you chose. [^1]

[^1]: be aware that the send function may or may not be needed by your screen 

