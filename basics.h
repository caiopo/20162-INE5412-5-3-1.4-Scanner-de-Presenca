#ifndef __BASICS_H__
#define __BASICS_H__

#include <utility/ostream.h>
#include <gpio.h>

#include "stepper_motor.h"
#include "sensor.h"

typedef unsigned short Distance;

EPOS::OStream cout;

EPOS::GPIO led('C', 3, EPOS::GPIO::OUTPUT);

StepperMotor motorH('A', 0,
              'A', 2,
              'A', 5,
              'A', 7,
              1);

StepperMotor motorV('B', 1,
              'B', 2,
              'B', 3,
              'B', 4,
              1);

Sensor sensor('C', 4, 'A', 5);

#endif /* __BASICS_H__ */
