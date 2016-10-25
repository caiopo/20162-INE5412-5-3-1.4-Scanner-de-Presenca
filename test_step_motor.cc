#include <alarm.h>
#include "basics.h"

void test_countdown() {
  for (int i = 5; i > 0; --i) {
    cout << i << "...\n";
    EPOS::Delay(1000000);
  }
}

int main(int argc, char const *argv[]) {
  cout << "Esse teste irá, através da plataforma EPOSMote III, comandar o \n
           motor para que ele vá da coordenada 0 (inicial) até 8 (90 graus \n
           sentido horário), esperar 5 segundos, mover para a coordenada 24 \n
           (270 graus, sentido horário),esperar 5 segundos, mover para a \n
           coordenada 31 (348,75 graus sentido horário), esperar 5 segundos \n
           e voltar até a coordenada 0 (348,75 graus sentido anti-horário).\n";

  test_countdown();

  while(true) {
    cout << "// ----- // Iniciando Teste  // ----- //\n";

    cout << "Coordenada atual: " << motorH.current_coord() << '\n';
    cout << "Movendo para coordenada 8...\n";
    motorH.turn_to(8);
    cout << "Pronto!\n";



    cout << "Coordenada atual: " << motorH.current_coord() << '\n';
    cout << "Movendo para coordenada 24...\n";
    motorH.turn_to(24);
    cout << "Pronto!\n";

    EPOS::Delay(5000000);

    cout << "Coordenada atual: " << motorH.current_coord() << '\n';
    cout << "Movendo para coordenada 31...\n";
    motorH.turn_to(31);
    cout << "Pronto!\n";

    EPOS::Delay(5000000);

    cout << "Coordenada atual: " << motorH.current_coord() << '\n';
    cout << "Movendo para coordenada 0...\n";
    motorH.turn_to(0);
    cout << "Pronto!\n";

    cout << "// ----- // Teste Finalizado // ----- //\n";

    EPOS::Delay(5000000);
  }

  return 0;
}
