#include "../include/robot.cpp"
#define leftM1 10
#define leftM2 11
#define leftM3 12
#define leftM4 13
#define leftM5 14
#define rightM1 15
#define rightM2 16
#define rightM3 17
#define rightM4 18
#define rightM5 19



competition Competition;
controller Controller1(controllerType::primary);

Robot* mainBotP;

int mainTeleop() {
  while(true) {
    mainBotP->teleop();
  }
  return 0;
}

void userControl(void) {
  task controlLoop1(mainTeleop);
}

void mainAuto(void) {
  mainBotP->driveStraight(0.5, 30, 0);
}

int tetherAuto(void) {
  return 0;
}

void autonomous() {
  thread auto1(mainAuto);
}

int main() {
  motor l1(leftM1);
  motor l2(leftM2);
  motor l3(leftM3);
  motor l4(leftM4);
  motor l5(leftM5);
  motor_group left(l1, l2, l3, l4, l5);
  motor r1(rightM1);
  motor r2(rightM2);
  motor r3(rightM3);
  motor r4(rightM4);
  motor r5(rightM5);
  motor_group right(l1, l2, l3, l4, l5);
  
  Robot mainBot = Robot(left, right, &Controller1);
  mainBotP = &mainBot;
  Competition.autonomous(mainAuto);
  Competition.drivercontrol(userControl);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
