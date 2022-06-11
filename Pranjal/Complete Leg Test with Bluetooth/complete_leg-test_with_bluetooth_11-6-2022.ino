
#include <Servo.h> //Including the servo lib
#include <Wire.h>
#include <SoftwareSerial.h>
Servo upperLeg1, upperLeg2,upperLeg3,upperLeg4,lowerLeg1, lowerLeg2, lowerLeg3, lowerLeg4;
SoftwareSerial Bluetooth(0, 1);
char val;

void sendData(String transmitData){
  Bluetooth.println(transmitData);
}

void setup(){
  Bluetooth.begin(9600);
  upperLeg1.attach(11);
  upperLeg2.attach(10);
  upperLeg3.attach(9);
  upperLeg4.attach(8);
  lowerLeg1.attach(7);
  lowerLeg2.attach(6);
  lowerLeg3.attach(5);
  lowerLeg4.attach(4);
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
  if(Bluetooth.available()){    
    val = Bluetooth.read();
//    Val = F
    if(val == 'F'){ 
      sendData("got command F");
      while(true){ 
        if(Bluetooth.available()){
          char a = Bluetooth.read();
          if(a=='F'){
            break;
            }
          }
//          Legs 1, 3 Controlled.
        upperLeg1.write(50);
        lowerLeg1.write(130);
        upperLeg3.write(130);
        lowerLeg3.write(50);
        delay(100) ;
        upperLeg1.write(80);
        lowerLeg1.write(100);
        upperLeg3.write(100);
        lowerLeg3.write(80);        
        delay(200);

//          Legs 2, 4 Controlled.
        upperLeg2.write(50);
        lowerLeg2.write(130);
        upperLeg4.write(130);
        lowerLeg4.write(50);
        delay(100) ;
        upperLeg2.write(80);
        lowerLeg2.write(100);
        upperLeg4.write(100);
        lowerLeg4.write(80);
       
        }
      }

//      Val = B
    if(val == 'B'){ 
      sendData("got command B");
      while(true){ 
        if(Bluetooth.available()){
          char a = Bluetooth.read();
          if(a=='B'){
            break;
            }
          }
//          Legs 1, 3 Controlled.
        upperLeg1.write(50);
        lowerLeg1.write(130);
        upperLeg3.write(130);
        lowerLeg3.write(50);
        delay(100) ;
        upperLeg1.write(20);
        lowerLeg1.write(160);
        upperLeg3.write(160);
        lowerLeg3.write(20);        
        delay(200);

//          Legs 2, 4 Controlled.
        upperLeg2.write(50);
        lowerLeg2.write(130);
        upperLeg4.write(130);
        lowerLeg4.write(50);
        delay(100) ;
        upperLeg2.write(20);
        lowerLeg2.write(160);
        upperLeg4.write(160);
        lowerLeg4.write(20);
       
            }
          }
    }
 }
  
