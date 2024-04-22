/*
* Juego de la Serpiente v1
* Pablo_Villa 28/09/2023
*/
  #include <iostream>
  #include "terminal.h"

  using namespace std;

  const char TECLA_SIGUIENTE = ' ';
  const char TECLA_FIN = 'F';
  const char SERPIENTE = '@';
  const char ARRIBA = 'W';
  const char ABAJO = 'S';
  const char IZQUIERDA = 'A';
  const char DERECHA = 'D';
  const int RETARDO = 60;
  const int SERPIENTE_X_INICIAL = 20;
  const int LIMITE_SUPERIOR = 2;
  const int LIMITE_INFERIOR = 20;
  const int LIMITE_IZQUIERDA = 2;
  const int LIMITE_DERECHA = 78;
  const int SERPIENTE_Y_INICIAL = 10;
  const int MOVIMIENTO_X_DERECHA = 1;
  const int MOVIMIENTO_Y_DESCENDENTE = 1;
  const int MOVIMIENTO_X_IZQUIERDA = -1;
  const int MOVIMIENTO_Y_ASCENDENTE = -1;
  const string TITULO = "Juego de la serpiente ";
  const string VERSION = "2.0";
  const string SIGUIENTE_PANTALLA = "ESPACIO";

 int main() {
    int serpiente_x = SERPIENTE_X_INICIAL;
    int serpiente_y = SERPIENTE_Y_INICIAL;
    int movimiento_x = 0;
    int movimiento_y  = 0;
    char tecla = '\0';

    retardar(RETARDO);
    hacer_cursor_visible(false);
    habilitar_modo_crudo_terminal();

    poner_cursor(1,1);
    cout << " ***************************** " << endl;

    poner_cursor(1,2);
    cout << " * "<< TITULO << VERSION << " * " << endl;

    poner_cursor(1,3);
    cout << " ***************************** " << endl;

    poner_cursor(1,6);
    cout << "   ______" << endl;

    poner_cursor(1,7);
    cout << " _/      \\ " << endl;

    poner_cursor(1,8);
    cout << "  \\___    \\ " << endl;

    poner_cursor(1,9);
    cout << "      \\    \\_____" << endl;

    poner_cursor(1,10);
    cout << "       \\         \\ " << endl;

    poner_cursor(1,11);
    cout << "        \\____     \\______      _|_ " << endl;

    poner_cursor(1,12);
    cout << "             \\         0 \\_/  /   \\ " << endl;

    poner_cursor(1,13);
    cout << "              \\__________/ \\  \\___/" << endl;

    poner_cursor(1,17);
    cout << "Pulsa la tecla de " <<  SIGUIENTE_PANTALLA << " para continuar" << endl;

    while(leer_tecla()!= TECLA_SIGUIENTE){
        retardar(RETARDO);
    }

    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    poner_cursor(2,1);
    cout << " +------------------------ " << TITULO
         << VERSION << " -------------------------+ " << endl;
    poner_cursor(2,2);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,3);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,4);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,5);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,6);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,7);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,8);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,9);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,10);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,11);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,12);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,13);
    cout << "|                                                                             |" << endl;
    poner_cursor (2,14);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,15);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,16);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,17),
    cout << "|                                                                             |" << endl;
    poner_cursor(2,18);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,19);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,20);
    cout << "+-----------------------------------------------------------------------------+ "<< endl;
    poner_cursor(2, 21);
    cout << ARRIBA << "-> Subir " << ABAJO << "-> Bajar " << IZQUIERDA
         << "-> Izda " << DERECHA << "-> Dcha " << TECLA_FIN << "-> Fin" << endl;

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);

    while (toupper(tecla) != TECLA_FIN &&
           serpiente_x != LIMITE_IZQUIERDA && serpiente_x != LIMITE_DERECHA &&
           serpiente_y != LIMITE_SUPERIOR && serpiente_y != LIMITE_INFERIOR) {

        poner_cursor(serpiente_x,serpiente_y);
        cout << SERPIENTE;

        retardar(RETARDO);

        poner_cursor(serpiente_x,serpiente_y);
        cout << " ";

        switch (toupper(tecla)) {
            case ARRIBA:
                movimiento_x = 0;
                movimiento_y = MOVIMIENTO_Y_ASCENDENTE;
                break;

            case ABAJO:
                movimiento_x = 0;
                movimiento_y = MOVIMIENTO_Y_DESCENDENTE;
                break;

            case IZQUIERDA:
                movimiento_x = MOVIMIENTO_X_IZQUIERDA;
                movimiento_y = 0;
                break;

            case DERECHA:
                movimiento_x = MOVIMIENTO_X_DERECHA;
                movimiento_y = 0;
                break;
         }

         serpiente_x = serpiente_x + movimiento_x;
         serpiente_y = serpiente_y + movimiento_y;

         tecla = leer_tecla();
    }

    deshabilitar_modo_crudo_terminal();
    borrar_terminal();
}
