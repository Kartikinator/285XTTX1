#include "Robotutil.hpp"
#include "main.h"

MotorGroup lift({11, -18});

MotorGroup clawer({1, -10});

Motor left_wheel_front(19, false, AbstractMotor::gearset::green);
Motor left_wheel_back(20, false, AbstractMotor::gearset::green);
Motor right_wheel_front(12, true, AbstractMotor::gearset::green);
Motor right_wheel_back(13, true, AbstractMotor::gearset::green);

 ChassisControllerIntegrated drive = ChassisControllerFactory::create(
   {19,20},
   {-12,-13},
   AbstractMotor::gearset::green,
   {4_in, 12.125_in}
 );
