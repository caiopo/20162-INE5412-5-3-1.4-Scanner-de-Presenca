#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <gpio.h>

class Sensor {
public:
    EPOS::GPIO *trigger, *echo;

public:
    Sensor(char triggerPort, unsigned int triggerPin,
           char echoPort, unsigned int echoPin):
        trigger{new EPOS::GPIO(triggerPort, triggerPin, EPOS::GPIO::OUTPUT)},
        echo{new EPOS::GPIO(echoPort, echoPin, EPOS::GPIO::INPUT)} {}

    ~Sensor() {
        delete trigger;
        delete echo;
    }

    unsigned int read() {
        trigger->set(false);
        EPOS::Delay(2);
        trigger->set(true);
        EPOS::Delay(10);
        trigger->set(false);

        int i = 0;

        while(echo->get());

        while(!echo->get());

        while(echo->get()) ++i;

        return i / 150;
    }
};

#endif /* __SENSOR_H__ */
