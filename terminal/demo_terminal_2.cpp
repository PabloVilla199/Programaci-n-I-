/*
 * demo_terminal_2.cpp
 * CCC (9/2023)
 */

#include <iostream>
#include "terminal.h"

using namespace std;

const int RETARDO_TECLA = 20;

int main() {
  habilitar_modo_crudo_terminal();

  borrar_terminal();
  hacer_cursor_visible(false);
  
  poner_cursor(10, 5);
  cout << "Demo 2 de terminal.h" << endl;

  poner_cursor(5, 15);
  cout << "Pulsa cualquier tecla para continuar" << endl;
  
  while(leer_tecla() == NO_TECLA) {
    retardar(RETARDO_TECLA);
  }
  hacer_cursor_visible(true);
  deshabilitar_modo_crudo_terminal();
}
