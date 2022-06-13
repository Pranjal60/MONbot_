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
//  70l, 110u
//  $$$$$$$$$$$$$$$$$$

  upperLeg1.write(110);
  upperLeg2.write(110);
  upperLeg3.write(80);
  upperLeg4.write(80);
  
  lowerLeg1.write(150);//130
  lowerLeg2.write(150);
  lowerLeg3.write(30);
  lowerLeg4.write(30);
    delay(2000);

  // #####################################
  if(Serial.available()>0){    
    val = Serial.read(); 
    Serial.println(val);

//val = U
    if(val == 'U'){ 
      while(true){ 
        if(Serial.available()>0){
          char a = Serial.read();
          if(a=='U'){
            break;
            }
          }
        upperLeg1.write(75);
        upperLeg2.write(75);
        upperLeg3.write(110);
        upperLeg4.write(110);

        lowerLeg1.write(87);
        lowerLeg2.write(87);
        lowerLeg3.write(83);
        lowerLeg4.write(83);
        delay(100);
      }
    }

//    val = D
if(val == 'D'){ 
      while(true){ 
        if(Serial.available()>0){
          char a = Serial.read();
          if(a=='D'){
            break;
            }
          }
        upperLeg1.write(130);
        upperLeg2.write(130);
        upperLeg3.write(60);
        upperLeg4.write(60);
        
        lowerLeg1.write(180);
        lowerLeg2.write(180);
        lowerLeg3.write(0);
        lowerLeg4.write(0);
        delay(100);
      }
  }

//    val = F
    if(val == 'F'){ 
      while(true){ 
        if(Serial.available()>0){
          char a = Serial.read();
          if(a=='F'){
            break;
            }
          }
//          Legs 1, 3 Controlled.
        for(int i=60, j=170;i<111 && j>99;i++, j--){
          upperLeg1.write(i);
          lowerLeg3.write(i);
          lowerLeg1.write(j);
          upperLeg3.write(j);
          delay(5);
          }
        delay(500);

//          Legs 2, 4 Controlled.
        for(int i=60, j=170;i<111 && j>99;i++, j--){
          upperLeg2.write(i);
          lowerLeg4.write(i);
          lowerLeg2.write(j);
          upperLeg4.write(j);
          delay(5);
          }
          delay(500);
        }
      }

//      Val = B
    }
}

  
