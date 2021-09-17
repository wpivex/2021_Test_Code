#include "robot.h"
#include <math.h>

// Motor ports Left: 12T, 14F,  20T Right: 2F, 6T, 10F
// gear ratio is 60/36

Robot::Robot(motor_group leftdrive, motor_group rightdrive, controller* control){
  leftDrive = leftdrive;
  rightDrive = rightdrive;
  robotController = control;

}

void Robot::teleop() {
  robotController->Screen.clearScreen();

  float leftJoystick = (driveType == ARCADE) ? robotController->Axis3.position()^3 + robotController->Axis1.position()^3: robotController->Axis3.position()^3;
  float rightJoystick = (driveType == ARCADE) ? robotController->Axis3.position()^3 + robotController->Axis1.position()^3: robotController->Axis2.position()^3;

  if (fabs(leftJoystick) > 5) {
    float percent = (driveType == ARCADE) ? (pow((robotController->Axis3.position()/100.00f), 3.00f) + pow((robotController->Axis1.position()/100.00f), 5.00f))*100.00f : leftJoystick;
    leftDrive.spin(forward, percent, percentUnits::pct);
  } else {
    leftDrive.stop();
  }

  if (fabs(rightJoystick) > 5) {
    float percent = (driveType == ARCADE) ? (pow((robotController->Axis3.position()/100.00f), 3.00f) - pow((robotController->Axis1.position()/100.00f), 5.00f))*100.00f : rightJoystick;
    rightDrive.spin(forward, percent, percentUnits::pct);
  } else {
    rightDrive.stop();
  }
}

void Robot::driveStraight(float percent, float dist, float accPercent) {

}

void Robot::driveTimed(float percent, float driveTime) {
  int milliseconds = vex::timer::system();
  while (vex::timer::system() < milliseconds + driveTime) {
    setLeftVelocity(forward, percent);
    setRightVelocity(forward, percent);
  }
  stopLeft();
  stopRight();
}

void Robot::driveStraight(float percent, float dist) {
  driveStraight(percent, dist, 0.1); //acc is from 0 to 1
}

void Robot::turnToAngle(float percent, float turnAngle) {

}

void Robot::setLeftVelocity(directionType d, double percent) {
  leftDrive.spin(d, percent, percentUnits::pct);
}

void Robot::setRightVelocity(directionType d, double percent) {
  rightDrive.spin(d, percent, percentUnits::pct);
}

void Robot::stopLeft() {
  leftDrive.stop();
}

void Robot::stopRight() {
  rightDrive.stop();
}