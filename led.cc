#include <utility/ostream.h>
#include <gpio.h>
#include <alarm.h>
// #include <chronometer.h>

void sleep(unsigned long);

EPOS::OStream cout;
EPOS::GPIO led('C', 3, EPOS::GPIO::OUTPUT);

int main(int argc, char** argv) {

    while(true) {
        led.set(true);

        sleep(500);

        led.set(false);

        sleep(500);
    }
}

void sleep(unsigned long milliseconds) {
    EPOS::Delay(milliseconds * 1000);
}
