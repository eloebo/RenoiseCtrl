#include <Keyboard.h>

int pwmPin1 = 5;
int pwmPin2 = 6;
int patDownBtn = 7;
int patUpBtn = 8;
int pwmPin3 = 9;
int editBtnPin = 18;   
int startBtnPin = 19;
int delBtnPin = 20; 

void setup()
{
  pinMode(pwmPin1, OUTPUT);
  pinMode(pwmPin2, OUTPUT);
  pinMode(pwmPin3, OUTPUT);
  pinMode(patDownBtn, INPUT);  // Set the button as an input
  pinMode(patUpBtn, INPUT);
  pinMode(delBtnPin, INPUT);
  pinMode(editBtnPin, INPUT);
  pinMode(startBtnPin, INPUT);
  digitalWrite(patDownBtn, HIGH); // Pull the button high
  digitalWrite(patUpBtn, HIGH);
  digitalWrite(delBtnPin, HIGH); 
  digitalWrite(editBtnPin, HIGH);
  digitalWrite(startBtnPin, HIGH);
}

void loop()
{
  analogWrite(pwmPin1, 127); //PWM for leds. Adjust to your liking different colours have different intensity
  analogWrite(pwmPin2, 32);
  analogWrite(pwmPin3, 96);
  
  if (digitalRead(delBtnPin) == 0)  // if the button goes low
  {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F3); // 
  }
  else if (digitalRead(editBtnPin) == 0)
  {
    Keyboard.press(KEY_ESC);                    
  }
  else if (digitalRead(startBtnPin) == 0)
  {
     Keyboard.write(' ');
    //Keyboard.press(KEY_RIGHT_ALT);
    //Keyboard.press(KEY_RIGHT_CTRL);
    delay(50);
  }
  else if (digitalRead(patDownBtn) == 0) //Left Ctrl + Up/Down Arrow Keys: Move to prev/next pattern in sequence.
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW);
  }
    else if (digitalRead(patUpBtn) == 0) //Left Ctrl + Up/Down Arrow Keys: Move to prev/next pattern in sequence.
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
  }
  Keyboard.releaseAll();
  delay(200);  // delay
}
