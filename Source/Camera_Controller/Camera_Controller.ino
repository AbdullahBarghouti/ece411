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
LED led1 = LED(18);
LED led2 = LED(19);

const int button1 = 20;
const int button2 = 21;
const int button3 = 25;
const int button4 = 22;

const int pan_pin = 30;
const int tilt_pin = 29;
//Servo min/max defined here in microseconds
const int tilt_max = 2400;
const int tilt_min = 500;
const int pan_max = 2400;
const int pan_min = 500;

//create 2 servo objects
Servo pan_servo;
Servo tilt_servo;

int tilt_up = 1;
int tilt_down = 1;
int pan_left = 1;
int pan_right = 1;
int pan_value;
int tilt_value;

void setup() {
  //buttons 22, 25, 21, 20
  //needs min/max set for servos 
  pan_servo.attach(pan_pin, pan_min, pan_max);
  pan_servo.attach(tilt_pin, tilt_min, tilt_max);
  //Set button pins as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  led1.blink(2000);
  led2.blink(2000);
}

//TBD might want to write to servos in microseconds
void loop() {
  //poll for button press, one direction at a time
  //TBD if buttons are default high or low
  //Rest of tests to be written
  if(!tilt_up){
    tilt_value = tilt_servo.read();
    //delay(10) should be replaced with something eventually
    if(tilt_value >= 180)
      delay(10);
    else{
      tilt_value = tilt_value + 1;
      tilt_servo.write(tilt_value); 
      led1.off();
      led2.off();  
    }
  }

  tilt_up = digitalRead(button1);
  tilt_down = digitalRead(button2);
  pan_left = digitalRead(button3);
  pan_right = digitalRead(button4);
  delay(50);
}
