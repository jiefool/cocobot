#include <Servo.h>

Servo hip1;
int pushButton = 8;
int buttonState = 0;
int previousButtonState = 0;

void setup(){
  Serial.begin(9600);
  hip1.attach(12);
  pinMode(pushButton, INPUT);
}

void teas(){
  hip1.write(150);
  delay(500);
  hip1.write(100);
  delay(500);
}
void loop(){
    buttonState = digitalRead(pushButton);
    delay(10); 
    
    if (previousButtonState != buttonState){ 
      Serial.println(buttonState);
      if (buttonState==1){
        hip1.write(0);      
        delay(70);
      }else{
        for(int i=0;i<2;i++){
          teas();
        }
        hip1.write(180);
        delay(70);               
      }
      previousButtonState = buttonState;
    }
}
