/*
* Juego de la Serpiente v1
* Pablo_Villa 08/11/2023
*/
  #include <iostream>
  #include "terminal.h"
  #include <cstdlib>


  using namespace std;

  const char TECLA_SIGUIENTE = ' ';
  const char TECLA_FIN = 'F';
  const char SERPIENTE = '@';
  const char ARRIBA = 'W';
  const char ABAJO = 'S';
  const char IZQUIERDA = 'A';
  const char DERECHA = 'D';
  const char SIMBOLO_VERTICAL = '|';
  const char SIMBOLO_INTERMEDIO = ' ';
  const char SIMBOLO_HORIZONTAl = '-';
  const char SIMBOLO_EXTERIOR = '+';
  const int BASE = 80;
  const int ALTURA = 22;
  const int RETARDO = 60;
  const int SERPIENTE_X_INICIAL = 10;
  const int LIMITE_SUPERIOR = 3;
  const int LIMITE_INFERIOR = 19;
  const int LIMITE_IZQUIERDA = 2;
  const int LIMITE_DERECHA = 78;
  const int SERPIENTE_Y_INICIAL = 15;
  const int MOVIMIENTO_X_DERECHA = 1;
  const int MOVIMIENTO_Y_DESCENDENTE = 1;
  const int MOVIMIENTO_X_IZQUIERDA = -1;
  const int MOVIMIENTO_Y_ASCENDENTE = -1;
  const string TITULO = "Juego de la serpiente ";
  const string VERSION = "3.0";
  const string TECLA_CONTINUAR = "ESPACIO";

  void pantalla_incial();
  void inicializar_serpiente(int &serpiente_x, int &serpiente_y, int &movimiento_x, int &movimiento_y);
  void dibujar_linea(const char c_exterior, const char c_interior, const int largo);
  void dibujar_rectangulo(const int base, const int altura);
  void pintar_cabeza_serpiente(const int serpiente_x , const int serpiente_y);
  void borrar_cabeza_serpiente(const int serpiente_x , const int serpiente_y);
  bool juego_terminado(char tecla, int serpiente_x, int serpiente_y);
  void obtener_direccion(const char tecla, int &movimiento_x, int &movimiento_y);
  void mover_cabeza(int &serpiente_x, int &serpiente_y, int movimiento_x , int movimiento_y);

 int main() {
    int serpiente_x = 0;
    int serpiente_y = 0;
    int movimiento_x = 0;
    int movimiento_y  = 0;
    char tecla = '\0';

    inicializar_serpiente( serpiente_x, serpiente_y, movimiento_x,  movimiento_y);
    retardar(RETARDO);
    hacer_cursor_visible(false);
    pantalla_incial();
    while(leer_tecla()!= TECLA_SIGUIENTE){
        retardar(RETARDO);
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    dibujar_rectangulo(BASE, ALTURA);
    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();

    while (! juego_terminado(tecla ,serpiente_x, serpiente_y)) {
            pintar_cabeza_serpiente(serpiente_x, serpiente_y);

            retardar(RETARDO);

            borrar_cabeza_serpiente(serpiente_x, serpiente_y);

            obtener_direccion(tecla,movimiento_x, movimiento_y);
            mover_cabeza(serpiente_x, serpiente_y, movimiento_x, movimiento_y);

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
    movimiento_x = 0;
    movimiento_y = 0;
}
void dibujar_linea(const char c_exterior, const char c_interior, const int largo){
    cout << c_exterior;
    for(int i = 0; i < largo - 2; i++){
        cout << c_interior;
    }
    cout << c_exterior << endl;
}

void dibujar_rectangulo(const int base, const int altura){
    poner_cursor(2,1);
     cout << "+------------------------- " << TITULO
          << VERSION << " --------------------------+ " << endl;
    for (int i = 2; i < altura -2; i++){
        poner_cursor(2,i);
        dibujar_linea(SIMBOLO_VERTICAL,SIMBOLO_INTERMEDIO,base);
    }
    poner_cursor(2,altura - 2);
    dibujar_linea(SIMBOLO_EXTERIOR,SIMBOLO_HORIZONTAl,base);
    poner_cursor(2, altura);
      cout << ARRIBA << "-> Subir " << ABAJO << "-> Bajar " << IZQUIERDA
           << "-> Izda " << DERECHA << "-> Dcha " << TECLA_FIN << "-> Fin" << endl;
}

void pintar_cabeza_serpiente(const int serpiente_x , const int serpiente_y){
     poner_cursor(serpiente_x,serpiente_y);
     cout << SERPIENTE;
}

void borrar_cabeza_serpiente(const int serpiente_x ,const int serpiente_y){
     poner_cursor(serpiente_x,serpiente_y);
     cout << " ";
}

bool juego_terminado(char tecla, int serpiente_x, int serpiente_y){
    return(toupper(tecla) == TECLA_FIN
           ||  serpiente_x == LIMITE_IZQUIERDA || serpiente_x == LIMITE_DERECHA
           || serpiente_y == LIMITE_SUPERIOR || serpiente_y == LIMITE_INFERIOR);
}

void obtener_direccion(const char tecla, int &movimiento_x, int &movimiento_y){
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
}
void mover_cabeza(int &serpiente_x, int &serpiente_y, int movimiento_x , int movimiento_y){
    serpiente_x = serpiente_x + movimiento_x;
    serpiente_y = serpiente_y + movimiento_y;
}
