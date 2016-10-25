#include <alarm.h>
#include "basics.h"

void test_countdown() {
  for (int i = 5; i > 0; --i) {
    cout << i << "...\n";
    EPOS::Delay(1000000);
  }
}

int main(int argc, char const *argv[]) {
  cout << "Esse teste irá, através da plataforma EPOSMote III, comandar o \n"
          "sensor ultrasônico para medir a distância atual em intervalos \n"
          "regulares de 5 segundos, durante 30 segundos.\n";

  test_countdown();

  while(true) {
    cout << "// ----- // Iniciando Teste  // ----- //\n";

    for (int i = 0; i < 6; ++i) {
      cout << "Distância medida: " << sensor.read() << '\n';
      EPOS::Delay(5000000);
    }

    cout << "// ----- // Teste Finalizado // ----- //\n";

    EPOS::Delay(5000000);
  }

  return 0;
}
