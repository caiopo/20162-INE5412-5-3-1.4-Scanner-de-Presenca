#ifndef __STEPPER_MOTOR_H__
#define __STEPPER_MOTOR_H__

#include "stepper_driver.h"

// These values depend on the driver implementation
const auto STEPS_PER_MOTOR_REVOLUTION = 32;
const auto STEPS_PER_SHAFT_REVOLUTION = 2048;
const auto N_SLICES = 32;
const auto STEPS_PER_SLICE = STEPS_PER_SHAFT_REVOLUTION / STEPS_PER_MOTOR_REVOLUTION;

class StepperMotor {
 private:
    int _current_coord;
    StepperDriver* driver;

 public:
    StepperMotor(char motor_port_1, unsigned int motor_pin_1,
            char motor_port_2, unsigned int motor_pin_2,
            char motor_port_3, unsigned int motor_pin_3,
            char motor_port_4, unsigned int motor_pin_4,
            double motor_steps_per_second):

            _current_coord{0},

            driver{new StepperDriver(motor_port_1, motor_pin_1,
                motor_port_2, motor_pin_2,
                motor_port_3, motor_pin_3,
                motor_port_4, motor_pin_4,
                motor_steps_per_second)}
        {}

    ~StepperMotor() {
        delete driver;
    }

    int current_coord() {
        return _current_coord;
    }

    void turn_to(int target_coord) {
        int offset;
        target_coord = target_coord % N_SLICES;

        offset = -(_current_coord - target_coord);

        driver->move(offset * STEPS_PER_SLICE);
        _current_coord = target_coord;
    }
};

#endif /* __STEPPER_MOTOR_H__ */
