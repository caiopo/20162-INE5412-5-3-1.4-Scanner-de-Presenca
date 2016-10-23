#include <utility/ostream.h>

#include "stepper_driver.cc"

EPOS::OStream cout;

// These values depend on the driver implementation
const auto STEPS_PER_MOTOR_REVOLUTION = 32;
const auto STEPS_PER_SHAFT_REVOLUTION = 2048;
const auto N_SLICES = 32;
const auto STEPS_PER_SLICE = STEPS_PER_SHAFT_REVOLUTION / STEPS_PER_MOTOR_REVOLUTION;

class StepperMotor {
 private:
    int current_coord;
    StepperDriver driver;


 public:
    StepperMotor(const StepperDriver &driver):
          current_coord{0},
          driver{driver}
    {}

    ~StepperMotor() {}

    int current_coord() {
        return current_coord;
    }

    void turn_to(int target_coord) {
        int offset;
        target_coord = target_coord % NSLICES;

        if(target_coord == 0 && current_coord >= N_SLICES/2) {
            offset = N_SLICES - current_coord;
        } else {
            offset = -(current_coord - target_coord);
        }

        driver.move(offset * STEPS_PER_SLICE);
        current_coord = target_coord;
    }
};
