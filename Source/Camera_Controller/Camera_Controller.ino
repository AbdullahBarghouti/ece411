/*
 * Group 14
 * 
 * 
 */
#include <Servo.h>
#include <LED.h>

/*      B1  B2  B3  B4
 * LED1 0   0   1   1
 * LED2 0   1   0   1
 */
LED led1 = LED(5);
LED led2 = LED(13);

const int button1 = 2;
const int button2 = 3;
const int button3 = 1;
const int button4 = 0;

const int pan_pin = 9;
const int tilt_pin = 10;
//Servo min/max defined here in microseconds
const int tilt_max = 2000;
const int tilt_min = 1000;
const int pan_max = 2000;
const int pan_min = 1000;

//create 2 servo objects
Servo pan_servo;
Servo tilt_servo;

int tilt_up = 1;
int tilt_down = 1;
int pan_left = 1;
int pan_right = 1;
int pan_value = 90;
int tilt_value = 90;

void setup() {
  //buttons 22, 25, 21, 20
  //needs min/max set for servos 
  Serial.begin(9600);
  pan_servo.attach(pan_pin);
  tilt_servo.attach(tilt_pin);
  //Set button pins as inputs
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  led1.blink(2000);
  led2.blink(2000);
}

//TBD might want to write to servos in microseconds
void loop() {
  //poll for button press, one direction at a time
  //Rest of tests to be written
  if(!tilt_up){
    Serial.print("button 1");
    if(tilt_value >= 180)
      delay(10);
    else{
      tilt_value = tilt_value + 1;
      tilt_servo.write(tilt_value); 
      led1.off();
      led2.off();  
    }
  } 
   if(!tilt_down){
    Serial.print("button 2");
    if(tilt_value <= 0)
      delay(10);
    else{
      tilt_value = tilt_value - 1;
      tilt_servo.write(tilt_value); 
      led1.off();
      led2.on();  
    }
  }
   if(!pan_left){
    Serial.print("button 3");
    if(pan_value <= 0)
      delay(10);
    else{
      pan_value = pan_value + 1;
      pan_servo.write(pan_value); 
      led1.on();
      led2.off();  
    }
  }
   if(!pan_right){
    Serial.print("button 4");
    if(pan_value >= 180)
      delay(10);
    else{
      pan_value = pan_value - 1;
      pan_servo.write(pan_value); 
      led1.on();
      led2.on();  
    }
  }

  tilt_up = digitalRead(button1);
  tilt_down = digitalRead(button2);
  pan_left = digitalRead(button3);
  pan_right = digitalRead(button4);
  delay(50);
}
