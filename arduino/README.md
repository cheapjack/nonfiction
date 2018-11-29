## Arduino Setup

Though not ideal we used an arduino UNO to listen to the arcade buttons and send keypresses via `Keyboard.write("KEYCODE");` which went over usb to the Pi 

Sketch is here but remember to build with the `#include <Keyboard.h>` in the right place for your arduino setup
