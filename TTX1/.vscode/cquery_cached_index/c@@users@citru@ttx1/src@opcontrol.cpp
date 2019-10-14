#include "main.h"

#include "RobotUtil/Robotutil.cpp"

void opcontrol() {

    ControllerButton rightButton(ControllerDigital::right);
    ControllerButton leftButton(ControllerDigital::left);

    ControllerButton liftUpButton(ControllerDigital::R1);
    ControllerButton liftDownButton(ControllerDigital::L1);

    ControllerButton clawInButton(ControllerDigital::L2);
    ControllerButton clawOutButton(ControllerDigital::R2);

	  Controller master;


//DRIVE

	  while (true) {
      drive.arcade(master.getAnalog(ControllerAnalog::leftY),
               master.getAnalog(ControllerAnalog::rightX));

			if(rightButton.isPressed()) {

			 left_wheel_front.move_velocity(-100);
			 left_wheel_back.move_velocity(100);
       right_wheel_front.move_velocity(100);
       right_wheel_back.move_velocity(-100);

			}

      if(leftButton.isPressed()) {

			 left_wheel_front.move_velocity(100);
			 left_wheel_back.move_velocity(-100);
       right_wheel_front.move_velocity(-100);
       right_wheel_back.move_velocity(100);

			}

//LIFT

      if(liftUpButton.isPressed()) {

			 lift.moveVelocity(100);

     } else {

       lift.moveVelocity(0);

     }

      if(liftDownButton.isPressed()) {

			 lift.moveVelocity(-100);

			}

//CLAW

      if(clawInButton.isPressed()) {

        clawer.moveVelocity(-100);

      } else {

        clawer.moveVelocity(0);

      }

      if(clawOutButton.isPressed()) {

        clawer.moveVelocity(100);

      }



	    pros::delay(2);
	}
}
