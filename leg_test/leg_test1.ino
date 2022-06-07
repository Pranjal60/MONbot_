#include <Servo.h>
Servo upperLeg;
Servo lowerLeg;
Servo lowerLeg1;
Servo upperLeg1;
int initialPos[] = {85, 50};

void setup() {
  upperLeg.attach(9);
  lowerLeg.attach(8);

}

void loop() {
  //             Initial position of everymotor
  //  delay(5000);
  upperLeg.write(initialPos[0]);
    delay(1000);
  lowerLeg.write(initialPos[1]);
//  delay(5000);
//    lowerLeg.write(0);
//    delay(100);
//    upperLeg.write(150);
//    delay(100);
//    lowerLeg.write(50);
//    delay(100);
//   upperLeg.write(85);
}
