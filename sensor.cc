#include <utility/ostream.h>
#include <gpio.h>
#include <alarm.h>
#include <chronometer.h>

EPOS::OStream cout;

class Sensor {
private:
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

        EPOS::Chronometer chrono;

        while(!echo->get());

        chrono.start();

        while(echo->get());

        chrono.stop();

        return (chrono.read() / 2) / 29.1;
    }

};

int main(int argc, char** argv) {


}
