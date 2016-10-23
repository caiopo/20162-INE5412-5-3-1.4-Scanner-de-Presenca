// This class is meant to be used with the 28BYJ-48 Stepper Motor

#include <utility/ostream.h>
#include <alarm.h>
#include <gpio.h>

class StepperDriver {
 private:
    // These correspond to the ULN2003 Driver pins for the stepper motor
    EPOS::GPIO *IN1, *IN2, *IN3, *IN4; // Blue, pink, yellow, orange, repectivelly

    int direction;                  // Direction of rotation (1 is CW, 0 is CCW)
    unsigned int step_delay;       // Delay between steps, in microseconds, based on speed
    int steps_per_motor_revolution;
    int current_step;

    void step(int this_step) {
        // Using Wave Drive (11.25 degree motor step angle | ~0.17578 degree output shaft angle)
        switch (this_step) {
            case 0:  // 1000
                IN1->set(true);
                IN2->set(false);
                IN3->set(false);
                IN4->set(false);
                cout << "A should light up";
            break;
            case 1:  // 0100
                IN1->set(false);
                IN2->set(true);
                IN3->set(false);
                IN4->set(false);
                cout << "B should light up";
            break;
            case 2:  // 0010
                IN1->set(false);
                IN2->set(false);
                IN3->set(true);
                IN4->set(false);
                cout << "C should light up";
            break;
            case 3:  // 0001
                IN1->set(false);
                IN2->set(false);
                IN3->set(false);
                IN4->set(true);
                cout << "D should light up";
            break;
        }
    }


 public:
    StepperDriver(char motor_port_1, unsigned int motor_pin_1,
            char motor_port_2, unsigned int motor_pin_2,
            char motor_port_3, unsigned int motor_pin_3,
            char motor_port_4, unsigned int motor_pin_4):

        // Setup the pins on EPOSMote III:
        IN1{new EPOS::GPIO(motor_port_1, motor_pin_1, EPOS::GPIO::OUTPUT)},
        IN2{new EPOS::GPIO(motor_port_2, motor_pin_2, EPOS::GPIO::OUTPUT)},
        IN3{new EPOS::GPIO(motor_port_3, motor_pin_3, EPOS::GPIO::OUTPUT)},
        IN4{new EPOS::GPIO(motor_port_4, motor_pin_4, EPOS::GPIO::OUTPUT)},
        direction{0},
        current_step{0},
        steps_per_motor_revolution{32}
    {}

    ~StepperDriver() {
        delete IN1;
        delete IN2;
        delete IN3;
        delete IN4;
    }

    // Sets the speed in motor steps per second
    // 32 motor steps = 1 motor revolution
    // 2048 motor steps = 1 shaft revolution
    void set_speed(double motor_steps_per_second) {
        step_delay = (unsigned int)((1 / motor_steps_per_second) * 1000 * 1000);
    }

    void move(int steps_to_move) {
        int steps_left;

        if (steps_to_move < 0) {
            steps_left = - steps_to_move;
        } else {
            steps_left = steps_to_move;
        }

        // Determine direction based on whether steps_to_move is + or -:
        if (steps_to_move > 0) {
            direction = 1;
        } else {
            direction = 0;
        }

        // Decrement the number of steps, moving one step each time:
        while (steps_left > 0) {
            // Move after the appropriate delay has passed:
            EPOS::Delay(step_delay);
            // Increment or decrement the step number, depending on direction:
            if (direction == 1) {
                current_step++;
                if (current_step == steps_per_motor_revolution) {
                    current_step = 0;
                }
            } else {
                if (current_step == 0) {
                    current_step = steps_per_motor_revolution;
                }
                current_step--;
            }
            // Decrement the steps left:
            steps_left--;
            cout << "Steps left: " << steps_left << '\n';
            // Step the motor to step number 0, 1, ..., 3
            step(current_step % 4);
        }
    }
};