#ifndef __BASICS_H__
#define __BASICS_H__

#include <utility/ostream.h>
#include <gpio.h>

typedef unsigned short Distance;

EPOS::OStream cout;

#include "stepper_motor.h"
#include "sensor.h"

EPOS::GPIO led('C', 3, EPOS::GPIO::OUTPUT);

StepperMotor motorH('C', 4,
              'C', 7,
              'B', 2,
              'B', 5,
              60);

StepperMotor motorV('B', 1,
              'B', 2,
              'B', 3,
              'B', 4,
              1);

Sensor sensor('C', 4, 'C', 7);

#endif /* __BASICS_H__ */
