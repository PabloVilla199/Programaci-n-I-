/*
* Juego de la Serpiente v3
* Pablo_Villa 08/11/2023
*/
  #include <iostream>
  #include "terminal.h"
  #include <cstdlib>


  using namespace std;

  const char TECLA_SIGUIENTE = ' ';
  const char TECLA_FIN = 'F';
  const char SERPIENTE = '@';
  const char MANZANA = 'O';
  const char MANZANA_RABITO = '//';
  const char ARRIBA = 'W';
  const char ABAJO = 'S';
  const char IZQUIERDA = 'A';
  const char DERECHA = 'D';
  const char MANZANAS = 'M';
  const char BORRAR_SERPIENTE = ' ';
  const int RETARDO = 60;
  const int SERPIENTE_X_INICIAL = 10;
  const int LIMITE_SUPERIOR = 3;
  const int LIMITE_INFERIOR = 19;
  const int LIMITE_IZQUIERDA = 2;
  const int LIMITE_DERECHA = 78;
  const int SERPIENTE_Y_INICIAL = 15;
  const int MOVIMIENTO_X_INICIAL = 0;
  const int MOVIMIENTO_Y_INCIAL = 0;
  const int MOVIMIENTO_X_DERECHA = 1;
  const int MOVIMIENTO_Y_DESCENDENTE = 1;
  const int MOVIMIENTO_X_IZQUIERDA = -1;
  const int MOVIMIENTO_Y_ASCENDENTE = -1;
  const int MAX_MANZANAS = 9;

  const string TITULO = "Juego de la serpiente ";
  const string VERSION = "3.0";
  const string TECLA_CONTINUAR = "ESPACIO";

  void pantalla_incial();
  void inicializar_serpiente(int &serpiente_x, int &serpiente_y, int &movimiento_x, int &movimiento_y);
  void pantalla_juego();
  void pintar_cabeza_serpiente(int serpiente_x , int serpiente_y);
  void borrar_cabeza_serpiente(int serpiente_x , int serpiente_y);
  bool terminar_juego(char tecla, int &serpiente_x, int &serpiente_y);
  void eleccion_movimiento(char tecla, int &movimiento_x, int &movimiento_y);
  void movimiento_serpiente(int &serpiente_x, int &serpiente_y, int movimiento_x , int movimiento_y);
  void inicializar_manzana(int& manzana_x, int& manzana_y);
  void pintar_manzana(int manzana_x, int manzana_y);
  void crear_manzana( char tecla ,int& manzana_x, int& manzana_y);

 int main() {
    int serpiente_x = 0;
    int serpiente_y = 0;
    int movimiento_x = 0;
    int movimiento_y  = 0;
    char tecla = '\0';
    int manzana_x = 0;
    int manzana_y = 0;
    int Tespera = rand()% 30 + 1;
    int numero_manzanas = 0;

    inicializar_serpiente( serpiente_x, serpiente_y, movimiento_x,  movimiento_y);
    retardar(RETARDO);
    hacer_cursor_visible(false);
    pantalla_incial();

    while(leer_tecla()!= TECLA_SIGUIENTE){
        retardar(RETARDO);
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    pantalla_juego();
    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();

    while (terminar_juego(tecla ,serpiente_x,serpiente_y)) {
         pintar_cabeza_serpiente(serpiente_x,serpiente_y);

         retardar(RETARDO);

         borrar_cabeza_serpiente(serpiente_x,serpiente_y);

         eleccion_movimiento(tecla,movimiento_x,movimiento_y);

         movimiento_serpiente(serpiente_x,serpiente_y,movimiento_x,movimiento_y);

         tecla = leer_tecla();
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();
}
void pantalla_incial(){

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
    cout << "Pulsa la tecla de " <<  TECLA_CONTINUAR << " para continuar" << endl;

}

void inicializar_serpiente(int &serpiente_x, int &serpiente_y, int &movimiento_x, int &movimiento_y) {
    serpiente_x = SERPIENTE_X_INICIAL;
    serpiente_y = SERPIENTE_Y_INICIAL;
    movimiento_x = MOVIMIENTO_X_INICIAL;
    movimiento_y = MOVIMIENTO_Y_INCIAL;
}

void pantalla_juego(){

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
}
void pintar_cabeza_serpiente(int serpiente_x , int serpiente_y){
     poner_cursor(serpiente_x,serpiente_y);
     cout << SERPIENTE;
}

void borrar_cabeza_serpiente(int serpiente_x , int serpiente_y){
     poner_cursor(serpiente_x,serpiente_y);
     cout << BORRAR_SERPIENTE;
}

bool terminar_juego(char tecla, int &serpiente_x, int &serpiente_y){
    return(toupper(tecla) != TECLA_FIN && serpiente_x != LIMITE_IZQUIERDA && serpiente_x != LIMITE_DERECHA &&
         serpiente_y != LIMITE_SUPERIOR && serpiente_y != LIMITE_INFERIOR);
}

void eleccion_movimiento(char tecla, int &movimiento_x, int &movimiento_y){

    switch (toupper(tecla)) {
        case ARRIBA:
            movimiento_x = MOVIMIENTO_X_INICIAL;
            movimiento_y = MOVIMIENTO_Y_ASCENDENTE;
            break;

        case ABAJO:
            movimiento_x = MOVIMIENTO_X_INICIAL;
            movimiento_y = MOVIMIENTO_Y_DESCENDENTE;
            break;

        case IZQUIERDA:
            movimiento_x = MOVIMIENTO_X_IZQUIERDA;
            movimiento_y = MOVIMIENTO_Y_INCIAL;
            break;

        case DERECHA:
            movimiento_x = MOVIMIENTO_X_DERECHA;
            movimiento_y = MOVIMIENTO_Y_INCIAL;
            break;

    }
}
void movimiento_serpiente(int &serpiente_x, int &serpiente_y, int movimiento_x , int movimiento_y){

    serpiente_x = serpiente_x + movimiento_x;
    serpiente_y = serpiente_y + movimiento_y;
}
void inicializar_manzana(int& manzana_x, int& manzana_y){

    manzana_x = rand() % LIMITE_DERECHA - 5;
    manzana_y = rand() % LIMITE_INFERIOR -5;

}
void pintar_manzana(int manzana_x, int manzana_y){

  poner_cursor(manzana_x,manzana_y);
  cout << MANZANA_RABITO << endl;
  poner_cursor(manzana_x, manzana_y + 1);
  cout << MANZANA << endl;

}
void crear_manzana( char tecla ,int& manzana_x, int& manzana_y){
    if(toupper(tecla) == MANZANAS){
        inicializar_manzana(manzana_x,manzana_y);
        if(manzana_x < LIMITE_DERECHA || manzana_x > LIMITE_IZQUIERDA ||
           manzana_y < LIMITE_INFERIOR|| manzana_y > LIMITE_SUPERIOR){
                pintar_manzana(manzana_x,manzana_y);
        }
    }
}
