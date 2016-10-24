#include <utility/ostream.h>

EPOS::OStream cout;

#include "stepper_driver.cc"

EPOS::GPIO led('C', 3, EPOS::GPIO::OUTPUT);

int main(int argc, char** argv) {

    // Sets the speed in motor steps per second
    // 32 motor steps = 1 motor revolution
    // 2048 motor steps = 1 shaft revolution
    // Should go 1 step each 1.875s
    StepperDriver driver('A', 0,
                  'A', 2,
                  'A', 5,
                  'A', 7,
                  32.0/60.0);

    StepperDriver driver2('C', 4,
                  'C', 7,
                  'B', 2,
                  'B', 5,
                  32.0/60.0);


    while(true) {
        led.set(true);
        cout << "Doing 64 motor steps clock-wise:\n";
        // Sequence should go A, B, C, D.
        // Represents moving 1 coordinate clock-wise
        driver.move(10);
        driver2.move(10);

        led.set(false);

        cout << "Doing 64 motor steps counterclock-wise:\n";
        // Sequence should go D, C, B, A.
        // Represents moving 1 coordinate counterclock-wise
        driver.move(-10);
        driver2.move(-10);

    }
}
