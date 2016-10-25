#include <alarm.h>

#include "basics.h"
#include "distance_matrix.h"
#include "alert.h"

void test_countdown() {
  for (int i = 5; i > 0; --i) {
    cout << i << "...\n";
    EPOS::Delay(1000000);
  }
}

int main(int argc, char const *argv[]) {
  DistanceMatrix matrix(32, 32, 5);

  SerialAlert alert;

  cout << "Esse teste irá, através da plataforma EPOSMote III, \n";

  test_countdown();

  while(true) {
    cout << "// ----- // Iniciando Teste  // ----- //\n";
    for (size_t j = 0; j < matrix.height(); ++j) {
        for (size_t i = 0; i < matrix.width(); ++i) {
            Distance distance = sensor.read();
            cout << "Distância lida: " << distance << '\n';

            auto before = matrix.put(i, j, distance);

            if (before) {
                alert.alert(i, j, *before, distance);
            }

            cout << "Coordenada atual (H): " << motorH.current_coord() << '\n';
            cout << "Movendo motorH para coordenada " << j << "...\n";
            motorH.turn_to(j);

            cout << "Coordenada atual (V): " << motorV.current_coord() << '\n';
            cout << "Movendo motorV para coordenada " << i << "...\n";
            motorV.turn_to(i);

            matrix.print();
        }
    }

    cout << "// ----- // Teste Finalizado // ----- //\n";

    EPOS::Delay(5000000);
  }

  return 0;
}
