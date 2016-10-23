#include <utility/ostream.h>

EPOS::OStream cout;

#include "stepper.cc"

EPOS::GPIO led('C', 3, EPOS::GPIO::OUTPUT);

int main(int argc, char** argv) {
    Stepper motor('A', 0,
                  'A', 2,
                  'A', 5,
                  'A', 7);

    // 128 motor revolutions per minute
    motor.set_speed(1);

    while(true) {
        led.set(true);
        cout << "Doing 64 motor steps clock-wise:\n";
        // Sequence should go A, B, C, D.
        // Represents moving 1 coordinate clock-wise
        motor.move(64);

        cout << "Doing 64 motor steps counterclock-wise:\n";
        // Sequence should go D, C, B, A.
        // Represents moving 1 coordinate counterclock-wise
        motor.move(-64);

        led.set(false);
    }
}
