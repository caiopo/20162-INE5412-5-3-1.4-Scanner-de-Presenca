#include <alarm.h>

#include "basics.h"

void test_countdown() {
  for (int i = 5; i > 0; --i) {
    cout << i << "...\n";
    EPOS::Delay(1000000);
  }
}

int main(int argc, char const *argv[]) {
  cout << "Esse teste irá, através da plataforma EPOSMote III, \n";

  test_countdown();

  while(true) {
    cout << "// ----- // Iniciando Teste  // ----- //\n";



    cout << "// ----- // Teste Finalizado // ----- //\n";

    EPOS::Delay(5000000);
  }

  return 0;
}
