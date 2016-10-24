#include <utility/ostream.h>
#include <alarm.h>
EPOS::OStream cout;
#include "sensor.cc"


int main(int argc, char** argv) {
    Sensor sensor('A', 2, 'A', 5);
    unsigned int dist;

    while(true) {
        cout << "\n";

        dist = sensor.read();
        cout << "distance: " << dist << " cm\n";

        EPOS::Delay(500000);
    }
}
