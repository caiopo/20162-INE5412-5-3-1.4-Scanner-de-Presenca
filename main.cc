#include "basics.h"
#include "distance_matrix.h"
#include "alert.h"

const size_t ROWS = 32;
const size_t COLUMNS = 32;
const Distance MAX_ERROR = 5;

DistanceMatrix matrix(ROWS, COLUMNS, MAX_ERROR);

SerialAlert alert;

int main(int argc, char** argv) {
    led.set(false);

    while (true) {

        for (size_t j = 0; j < matrix.height(); ++j) {
            for (size_t i = 0; i < matrix.width(); ++i) {
                Distance distance = sensor.read();

                auto before = matrix.put(i, j, distance);

                if (before) {
                    alert.alert(i, j, *before, distance);
                    led.set(true);
                    EPOS::Delay(5 * 1000 * 1000)
                }

                motorH.turn_to(i);
            }

            motorV.turn_to(j);
        }

        matrix.enable_comparison()
    }
}
