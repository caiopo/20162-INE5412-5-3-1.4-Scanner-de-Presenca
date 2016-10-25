#include "basics.h"
#include "distance_matrix.h"
#include "alert.h"

int main(int argc, char** argv) {

    DistanceMatrix matrix(32, 32, 5);

    SerialAlert alert;

    while (true) {

        for (size_t j = 0; j < matrix.height(); ++j) {
            for (size_t i = 0; i < matrix.width(); ++i) {
                Distance distance = sensor.read();

                auto before = matrix.put(i, j, distance);

                if (before) {
                    alert.alert(i, j, *before, distance);
                }

                motorH.turn_to(j);
                motorV.turn_to(i);

            }
        }
    }
}

