#include <utility/ostream.h>

EPOS::OStream cout;

#include "stepper_driver.cc"


int main(int argc, char** argv) {
    StepperMotor motor('A', 0,
                       'A', 2,
                       'A', 5,
                       'A', 7,
                       64.0/60.0);

    while(true) {
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 0 to 0 (just checking)
        // 0 steps
        motor.turn_to(0);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 0 to 8
        // 512 steps
        motor.turn_to(8);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 8 to 16
        // 512 steps
        motor.turn_to(16);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 16 to 24
        // 512 steps
        motor.turn_to(24);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 24 to 31
        // 448 steps
        motor.turn_to(31);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
        // Turns from 31 to 0
        // -1984 steps
        motor.turn_to(0);
        cout << "Current coordinate is: " << motor.current_coord(); << '\n';
    }
}
