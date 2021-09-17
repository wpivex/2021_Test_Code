#include "../include/robot.cpp"

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
  thread auto1();
}

int main() {
  Robot mainBot = Robot(&Controller1);
  mainBotP = &mainBot;
  Competition.autonomous(mainAuto);
  Competition.drivercontrol(userControl);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
