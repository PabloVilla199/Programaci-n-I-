/*
* Juego de la Serpiente v1
* Pablo_Villa 28/09/2023
*/
  #include <iostream>
  #include "terminal.h"

  using namespace std;

  const char TECLA_SIGUIENTE = ' ';
  const char TECLA_FIN = 'F';
  const char PELOTA = '0';
  const char BORRAR_PELOTA = ' ';
  const int RETARDO = 60;
  const int PELOTA_X_INICIAL = 20;
  const int PELOTA_Y_INICIAL = 10;
  const int LIMITE_SUPERIOR = 2;
  const int LIMITE_INFERIOR = 19;
  const int LIMITE_IZQUIERDA = 3;
  const int LIMITE_DERECHA = 78;
  const int MOVIMIENTO_X = 1;
  const int MOVIMIENTO_Y = 1;

  const string TITULO = "Juego de la PELOTA ";
  const string VERSION = "2.0";
  const string TECIA_SIGUIENTE = "ESPACIO";

 int main() {
     int pelota_x = PELOTA_X_INICIAL;
     int pelota_y = PELOTA_Y_INICIAL;
     int movimiento_x = MOVIMIENTO_X;
     int movimiento_y  = MOVIMIENTO_Y;
     char tecla = '\0';

    retardar(RETARDO);
    hacer_cursor_visible(false);
    poner_cursor(1,1);
    cout << " ***************************** " << endl;

    poner_cursor(1,2);
    cout << " * "<< TITULO << VERSION << " * " << endl;

    poner_cursor(1,3);
    cout << " ***************************** " << endl;

    for(int i = 4; i < 16; i++){
        poner_cursor(1,i);
        cout << "Comeme el rabo Comeme el rabo Comeme el rabo" << endl;
    }

    poner_cursor(1,17);
    cout << "Pulsa la tecla de " <<  TECIA_SIGUIENTE << " para continuar" << endl;

    while(leer_tecla()!= TECLA_SIGUIENTE){

        retardar(RETARDO);
    }

    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    poner_cursor(2,1);
    cout << " +------------------------ " << TITULO
         << VERSION << " ----------------------------+ " << endl;
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

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);

  while (tecla != TECLA_FIN) {

        poner_cursor (pelota_x,pelota_y);
        cout << PELOTA;

        retardar(RETARDO);
        poner_cursor (pelota_x,pelota_y);
        cout << BORRAR_PELOTA;

        if(pelota_x == LIMITE_DERECHA|| pelota_x == LIMITE_IZQUIERDA){
            movimiento_x = - movimiento_x;
        }
        else if(pelota_y == LIMITE_INFERIOR || pelota_y == LIMITE_SUPERIOR){
            movimiento_y = - movimiento_y;
        }

        pelota_x = pelota_x + movimiento_x;
        pelota_y = pelota_y + movimiento_y;
        tecla = leer_tecla();

    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();
}
