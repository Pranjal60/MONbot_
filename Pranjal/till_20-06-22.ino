
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <Servo.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 110
#define SERVOMAX 605
char val;

void setup(){
  Serial.begin(9600);
  Serial.println("16 channe servo test");

  pwm.begin();

  pwm.setPWMFreq(60);
  }

  void loop(){
    int angle = 90;
    int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);

//    INITIAL
//60
//u1 130
//u2 110

      
//        u3 50
//       l7 60
//        u2 50
//       l6 60

//Initial

        pwm.setPWM(0,0, atp(70));//70-->110
        pwm.setPWM(4,0, atp(50));//50-->90

        pwm.setPWM(1,0, atp(100));//100--70
        pwm.setPWM(5,0, atp(130));//130--160--90

        pwm.setPWM(2,0, atp(110));//
        pwm.setPWM(6,0, atp(130));//

        pwm.setPWM(3,0, atp(70));
        pwm.setPWM(7,0, atp(50));
          
        
        delay(2000);


if(Serial.available()>0){
          val = Serial.read();

//          UP
          if(val == 'U'){
          while(true){
            if(Serial.available()>0){
              char a = Serial.read();
              if (a == 'U'){
                break;
                }
              }
            pwm.setPWM(0,0,atp(90));
            pwm.setPWM(4,0,atp(90));

            pwm.setPWM(2,0,atp(90));
            pwm.setPWM(6,0,atp(90));
            
            pwm.setPWM(1,0,atp(90));
            pwm.setPWM(5,0,atp(90));
            
            pwm.setPWM(3,0,atp(90));
            pwm.setPWM(7,0,atp(90));
          }  
         }
         
//          Down
          if(val == 'D'){
          while(true){
            if(Serial.available()>0){
              char a = Serial.read();
              if (a == 'D'){
                break;
                }
              }
            pwm.setPWM(0,0,atp(40));
            pwm.setPWM(4,0,atp(20));

            pwm.setPWM(2,0,atp(130));
            pwm.setPWM(6,0,atp(160));
            
            pwm.setPWM(1,0,atp(140));
            pwm.setPWM(5,0,atp(160));
            
            pwm.setPWM(3,0,atp(40));
            pwm.setPWM(7,0,atp(20));
          }
         }


//        lean Up
             if(val == 'L'){
          while(true){
            if(Serial.available()>0){
              char a = Serial.read();
              if (a == 'L'){
                break;
                }
              }
            pwm.setPWM(0,0,atp(90));
            pwm.setPWM(4,0,atp(90));

            pwm.setPWM(2,0,atp(140));
            pwm.setPWM(6,0,atp(170));
            
            pwm.setPWM(1,0,atp(90));
            pwm.setPWM(5,0,atp(90));
            
            pwm.setPWM(3,0,atp(20));
            pwm.setPWM(7,0,atp(10));
          }
         }
         
          

            }
          }

  

//    Angle to Pulse
    int atp(int ang){
      int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);
      return pulse;
     }

   
