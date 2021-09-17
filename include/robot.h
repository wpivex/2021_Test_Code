#pragma once
#include "vex.h"

using namespace vex;

class Robot {
  public:
    Robot(controller* c);
    motor_group leftDrive;
    motor_group rightDrive;

    controller* robotController;

    Robot(motor_group, motor_group, controller*);

    void driveStraight(float percent, float dist);
    void driveStraight(float percent, float dist, float accPercent);
    void driveTimed(float percent, float driveTime);
    void turnToAngle(float percent, float turnAngle);
    void userControl( void );
    void teleop( void );
    void init();
    void setLeftVelocity(directionType d, double percent);
    void setRightVelocity(directionType d, double percent);
    void stopLeft();
    void stopRight();

    enum DriveType { ARCADE, TANK };
    DriveType driveType;
};