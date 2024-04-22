/*
 * demo_terminal_1.cpp
 * C.Catalán (9/2023)
 */

#include <iostream>
#include <cctype>
#include "terminal.h"

using namespace std;

const int RETARDO_TECLA = 20;   // milisegundos
const char FIN = ' ';

int main() {
  char tecla = '\0';

  cout << "Demo 1 de terminal.h" << endl;

  // modo "cocinado"
  while (toupper(tecla) != FIN) {
    cout << "Esta es una entrada en modo cocinado, pulsa cualquier "
         << "letra (pulsa "<< FIN << " para finalizar) y ENTER: ";
    cin >> tecla;
  };

  // modo "crudo"
  habilitar_modo_crudo_terminal();

  borrar_terminal();
  hacer_cursor_visible(false);

  cout << "Esta es una entrada en modo crudos, pulsa cualquier "
       << "letra (pulsa "<< FIN << " para finalizar): ";

  tecla = '\0';
  while (toupper(tecla) != FIN) {
    tecla = leer_tecla();

    retardar(RETARDO_TECLA);

    if (tecla != NO_TECLA) {
      poner_cursor(0, 1);
      cout << "Has pulsado la tecla: " << tecla << endl;
    }
  };
  hacer_cursor_visible(true);
  deshabilitar_modo_crudo_terminal();
}
