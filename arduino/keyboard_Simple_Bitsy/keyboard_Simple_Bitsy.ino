#include <Keyboard.h>

// from https://github.com/arduino-libraries/Keyboard
// for the Arcade De Bruno

char shiftKey = KEY_LEFT_SHIFT;
char tabKey = KEY_TAB;
char ctrlKey = KEY_LEFT_CTRL;
char right = KEY_RIGHT_ARROW;
char left = KEY_LEFT_ARROW;
char up = KEY_UP_ARROW;
char down = KEY_DOWN_ARROW;
char enter = KEY_RETURN;

const int keyboardDelay = 15;

void setup() {
  // make pins 2-5 inputs and turn on the 
  // pullup resistor so it stays high unless
  // pulled to ground:
  // 2 is Blue (UP, '218')
  pinMode(2, INPUT_PULLUP);
  
  // 3 is Black for menu, keycombo ( shift+Key m, 'KEY_LEFT_SHIFT' 'M' )
  // In the Arcade de Bruno we use ctrlkey to trigger return to menu with BitsyNav3.js
  // 3 is Black for menu ie open  
  pinMode(3, INPUT_PULLUP);
  
  // 4 is Yellow ('Down', '217')
  pinMode(4, INPUT_PULLUP);
  
  // 5 is White ('Select', 'Enter', '176')
  pinMode(5, INPUT_PULLUP);
  
  // 6 is Red for shift+Tab, keycombo, Left ('left' 'Tab', '179' + 'KEY_LEFT_SHIFT') )
  pinMode(6, INPUT_PULLUP);
  
    // 8 is Green for Tab ('Tab', '179')
  pinMode(8, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  //if the button is pressed
  // 2 is Blue (UP, '218')
  if(digitalRead(2)==LOW){
    //Send the message UP
    Keyboard.write(up);
    delay(keyboardDelay);
  }
  else if (digitalRead(4)==LOW){
    //Send the message DOWN
    Keyboard.write(down);
    delay(keyboardDelay);
  }
  else if(digitalRead(5)==LOW){
    // 5 is White ('Select', 'Enter', '176')
    //Send the message enter/return
    Keyboard.write(enter);
    delay(keyboardDelay);
    }
    // use Keyboard.press to do a key combo
    // 3 is Black for menu, keycombo ( shift+Key w, 'KEY_LEFT_SHIFT' 'W' ) to close a window
  else if (digitalRead(3)==LOW){
    //Keyboard.press(shiftKey);
    //Keyboard.press('W');
    //Keyboard.releaseAll();
    delay(keyboardDelay);
    //ctrl to exit
    Keyboard.write(ctrlKey);
    delay(keyboardDelay);   
    //delay(50);    
  }
  else if (digitalRead(6)==LOW){
    // 6 is Red for shift+Tab, keycombo, Left ('left' 'Tab', '179' + 'KEY_LEFT_SHIFT')
    // Send the message 'shift+KEY_TAB'
    Keyboard.press(shiftKey);
    Keyboard.press(tabKey);
    delay(keyboardDelay);
    Keyboard.releaseAll();
    Keyboard.write(left);
    delay(keyboardDelay); 
  }
  else if (digitalRead(8)==LOW){
    // 8 is Green for Tab/Right ('Tab', '179')
    // Send KEY_TAB
    Keyboard.write(tabKey);
    delay(keyboardDelay);
    Keyboard.write(right);
    delay(keyboardDelay); 
  }
    else
    {
      delay(keyboardDelay);
    }

  }
