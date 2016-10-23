#include <utility/ostream.h>

#include "stepper.cc"

EPOS::OStream cout;

int main(int argc, char** argv) {
    Stepper motor('A', 0,
                  'A', 2,
                  'A', 4,
                  'A', 6);

    // 128 motor revolutions per minute
    motor.set_speed(128);

    cout << "Doing 64 motor steps clock-wise:" << '\n';
    // Sequence should go A, B, C, D.
    // Represents moving 1 coordinate clock-wise
    motor.move(64);

    cout << "Doing 64 motor steps counterclock-wise:" << '\n';
    // Sequence should go D, C, B, A.
    // Represents moving 1 coordinate counterclock-wise
    motor.move(-64);
}
