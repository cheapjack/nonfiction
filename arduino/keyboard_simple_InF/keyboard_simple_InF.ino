#include <Keyboard.h>

char shiftKey = KEY_LEFT_SHIFT;
char tabKey = KEY_TAB;
char ctrlKey = KEY_LEFT_CTRL

void setup() {
  // make pins 2-5 inputs and turn on the 
  // pullup resistor so it stays high unless
  // pulled to ground:
  // 2 is Blue (UP, '218')
  pinMode(2, INPUT_PULLUP);
  
  // 3 is Black for menu, keycombo ( shift+Key m, 'KEY_LEFT_SHIFT' 'M' )
  // For bitsy 3/Black can become close window ( ctrlKey & Key W)
  pinMode(3, INPUT_PULLUP);
  
  // 4 is Yellow ('Down', '217')
  pinMode(4, INPUT_PULLUP);
  
  // 5 is White ('Select', 'Emter', '176')
  pinMode(5, INPUT_PULLUP);
  
  // 6 is Red for shift+Tab, keycombo ('Tab', '179' + 'KEY_LEFT_SHIFT') )
  pinMode(6, INPUT_PULLUP);
  
    // 8 is Green for Tab ('Tab', '179')
  pinMode(8, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  //if the button is pressed
  if(digitalRead(2)==LOW){
    //Send the message UP
    Keyboard.write(218);
    delay(250);
  }
  else if (digitalRead(4)==LOW){
    //Send the message DOWN
    Keyboard.write(217);
    delay(250);
  }
  else if(digitalRead(5)==LOW){
    //Send the message
    Keyboard.write(176);
    delay(250);
    }
// use Keyboard.press to do a key combo
  else if (digitalRead(3)==LOW){
    Keyboard.press(shiftKey);
    Keyboard.press('m');
    delay(250);
    Keyboard.releaseAll();
    delay(1000);    
  }
  else if (digitalRead(6)==LOW){
    // Send the message 'shift+KEY_TAB'
    Keyboard.press(shiftKey);
    Keyboard.press(tabKey);
    delay(250);
    Keyboard.releaseAll();
    delay(250);
  }
  else if (digitalRead(8)==LOW){
    // Send KEY_TAB
    Keyboard.write(tabKey);
    delay(250);
  }
    else
    {
      delay(250);
    }

  }
