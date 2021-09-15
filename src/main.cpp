#include "../include/robot.cpp"

competition Competition;
controller Controller1(controllerType::primary);
controller Controller2(controllerType::partner);

Robot* mainBotP;
Robot* tetherBotP;

int mainTeleop() {
  while(true) {
    mainBotP->teleop();
    tetherBotP->teleop();
  }
  return 0;
}

void userControl(void) {
  task controlLoop1(mainTeleop);
}

int mainAuto(void) {
  // this_thread::sleep_for(10);
  // mainBotP->startYeet();
  // mainBotP->driveStraight(30, 26);
  // mainBotP->turnToAngle(60, -62);
  // mainBotP->endYeet();
  // mainBotP->startIntake();
  // mainBotP->driveTimed(30, 2500);
  // mainBotP->driveStraight(30, -3);
  // mainBotP->driveTimed(30, 500);
  // mainBotP->driveStraight(30, -3);
  // mainBotP->driveTimed(30, 500);
  // mainBotP->stopIntake();
  // mainBotP->shoot(800);
  // mainBotP->resetShoot();
  // mainBotP->startOuttake(25);
  // mainBotP->driveStraight(30, -12);
  // this_thread::sleep_for(2000);
  // mainBotP->stopIntake();
  return 0;
}

int tetherAuto(void) {
  // tetherBotP->startYeet();
  // this_thread::sleep_for(7000);
  // tetherBotP->endYeet();
  // tetherBotP->driveStraight(30, 24);
  // tetherBotP->turnToAngle(60, 59);
  // tetherBotP->startIntake();
  // tetherBotP->driveTimed(30, 3000);
  // tetherBotP->driveStraight(30, -5);
  // tetherBotP->driveTimed(30, 500);
  // tetherBotP->driveStraight(30, -5);
  // tetherBotP->driveTimed(30, 500);
  // this_thread::sleep_for(1000);
  // tetherBotP->stopIntake();
  // tetherBotP->shoot(1500);
  // tetherBotP->startOuttake(20);
  // tetherBotP->driveStraight(30, -20);
  // tetherBotP->turnToAngle(60, -51);
  // tetherBotP->startIntake();
  // tetherBotP->driveTimed(30, 3000);
  // tetherBotP->driveStraight(30, -5);
  // tetherBotP->driveTimed(30, 500);
  // tetherBotP->driveStraight(30, -5);
  // tetherBotP->driveTimed(30, 500);
  // tetherBotP->driveStraight(30, -5);
  // tetherBotP->driveTimed(30, 500);
  // tetherBotP->stopIntake();
  // tetherBotP->driveStraight(30, -6);
  // tetherBotP->startIntake();
  // tetherBotP->driveStraight(30, 6);
  // this_thread::sleep_for(1000);
  // tetherBotP->stopIntake();
  return 0;
}

void autonomous() {
  thread auto2(tetherAuto);
  thread auto1(mainAuto);
}

void pre_auton() {
  mainBotP->yeet.setBrake(brakeType::hold);
  tetherBotP->yeet.setBrake(brakeType::hold);
  mainBotP->yeet.stop();
  tetherBotP->yeet.stop();
}

int main() {
  Robot mainBot = Robot(false, &Controller1);
  Robot tetherBot = Robot(true, &Controller2);
  mainBotP = &mainBot;
  tetherBotP = &tetherBot;
  //All the control code is in robot config, that seems to be the new template
  //Auton and other non-controller stuff can go here
    // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(userControl);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
