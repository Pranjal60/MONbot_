//        write F in the serial monitor to start ... and F to stop
//        for connections.... connect the black wire of adaptor to GND of arduino and the GND of servos.. so... the GND of arduino,adaptor, and all the servos are common... middle wire of servos to the red wire of adaptor ... and signal wire of servos to pin 9,8,7,and6 of aurdino.
//        MONbot leg_test program: 09/06/2022
#include <Servo.h> //Including the servo lib
Servo upperLeg1, upperLeg2,upperLeg3,upperLeg4,lowerLeg1, lowerLeg2, lowerLeg3, lowerLeg4; // Giving names to servo
char val;
void setup(){
  upperLeg1.attach(11);
  upperLeg2.attach(10);
  upperLeg3.attach(9);
  upperLeg4.attach(8);
  lowerLeg1.attach(7);
  lowerLeg2.attach(6);
  lowerLeg3.attach(5);
  lowerLeg4.attach(4);
  Serial.begin(9600);// TO start Serial communication
  }
  

void loop(){
  upperLeg1.write(50);
  upperLeg2.write(50);
  upperLeg3.write(130);
  upperLeg4.write(130);
  
  lowerLeg1.write(130);
  lowerLeg2.write(130);
  lowerLeg3.write(50);
  lowerLeg4.write(50);
  delay(2000);
  if(Serial.available()>0){    
    val = Serial.read(); 
    Serial.println(val);
    if(val == 'F'){ 
      while(true){ 
        if(Serial.available()>0){
          char a = Serial.read();
          if(a=='F'){
            break;
            }
          }
//          $$$
        lowerLeg1.write(130);
        lowerLeg3.write(50);
        lowerLeg1.write(130);
        lowerLeg3.write(50);
        delay(200);
        upperLeg1.write(80);
        upperLeg3.write(100);
        lowerLeg1.write(100);
        lowerLeg3.write(80);
        delay(200);
        lowerLeg2.write(130);
//        $$$
        lowerLeg4.write(50);
        delay(100);
        upperLeg1.write(80);
        upperLeg3.write(100);
        delay(100);
        lowerLeg1.write(100);
        lowerLeg2.write(100);
        lowerLeg3.write(80);
        lowerLeg4.write(80);
        delay(100);
        }
      }
    }
 }
  
