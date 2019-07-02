#include "Robotutil.hpp"
#include "main.h"

okapi::MotorGroup lift({8, -9});

Motor claw (7, false, AbstractMotor::gearset::green);

Motor left_wheel_front(1, false, AbstractMotor::gearset::green);
Motor left_wheel_back(3, false, AbstractMotor::gearset::green);
Motor right_wheel_front(2, true, AbstractMotor::gearset::green);
Motor right_wheel_back(4, true, AbstractMotor::gearset::green);

 ChassisControllerIntegrated drive = ChassisControllerFactory::create(
   {1,3},
   {-2,-4},
   AbstractMotor::gearset::green,
   {4_in, 12.125_in}
 );

 AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
   2,  // Maximum linear velocity of the Chassis in m/s
   2.0,  // Maximum linear acceleration of the Chassis in m/s/s
   2.5, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
 );
