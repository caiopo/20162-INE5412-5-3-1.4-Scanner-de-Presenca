#include <utility/ostream.h>

EPOS::OStream cout;

#include "stepper_driver.cc"


int main(int argc, char** argv) {
    StepperDriver motor('A', 0,
                  'A', 2,
                  'A', 5,
                  'A', 7);

    // Sets the speed in motor steps per second
    // 32 motor steps = 1 motor revolution
    // 2048 motor steps = 1 shaft revolution
    // Should go 1 step each 1.875s
    motor.set_speed(32.0/60.0);

    while(true) {
        cout << "Doing 64 motor steps clock-wise:" << '\n';
        // Sequence should go A, B, C, D.
        // Represents moving 1 coordinate clock-wise
        motor.move(64);

        cout << "Doing 64 motor steps counterclock-wise:" << '\n';
        // Sequence should go D, C, B, A.
        // Represents moving 1 coordinate counterclock-wise
        motor.move(-64);
    }
}
