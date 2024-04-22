/*
* Juego de la Serpiente v4
* Pablo_Villa 08/11/2023
*/
#include <iostream>
#include "terminal.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const char TECLA_SIGUIENTE = ' ';
const char TECLA_FIN = 'F';
const char SERPIENTE = '@';
const char CUERPO_SERPIENTE = 'o';
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';
const char MANZANA = 'M';
const char SIMBOLO_VERTICAL = '|';
const char SIMBOLO_INTERMEDIO = ' ';
const char SIMBOLO_HORIZONTAl = '-';
const char SIMBOLO_EXTERIOR = '+';
const int PREMIO = 100;
const int LONG_SERPIENTE = 15;
const int BASE = 80;
const int ALTURA = 22;
const int RETARDO = 50;
const int SERPIENTE_X_INICIAL = 10;
const int LIMITE_SUPERIOR = 1;
const int LIMITE_INFERIOR = 20 ;
const int LIMITE_IZQUIERDA = 2;
const int LIMITE_DERECHA = 78;
const int SERPIENTE_Y_INICIAL = 15;
const int MOVIMIENTO_X_DERECHA = 1;
const int MOVIMIENTO_Y_DESCENDENTE = 1;
const int MOVIMIENTO_X_IZQUIERDA = -1;
const int MOVIMIENTO_Y_ASCENDENTE = -1;
const int MAX_MANZANAS = 10;
const string TITULO = "Juego de la serpiente ";
const string VERSION = "4.0";
const string TECLA_CONTINUAR = "ESPACIO";

struct posicion {
    int x = 0;
    int y = 0;
};

struct inc_unitario_posicion {
    int x = 0;
    int y = 0;
};

void iniciar_pantalla_inicial();
void inicializar_juego(char tecla,posicion serpiente[],inc_unitario_posicion& inc_unitario_posicion);
void pantalla_incial();
void dibujar_linea(const char c_exterior, const char c_interior, const int largo);
void dibujar_rectangulo(const int base, const int altura);
void inicializar_serpiente(posicion serpiente[], inc_unitario_posicion& inc_unitario_posicion);
bool juego_terminado(char tecla,posicion serpiente[]);
void obtener_direccion(const char tecla,inc_unitario_posicion& inc_unitario_posicion);
void pintar_serpiente(const posicion serpiente[]);
void borrar_serpiente( const posicion serpiente[]);
bool serpiente_tocada(const posicion serpiente[]);
void mover_serpiente(posicion serpiente[], inc_unitario_posicion inc_unitario_posicion);

int main() {
    char tecla = '\0';
    posicion serpiente[LONG_SERPIENTE];
    inc_unitario_posicion inc_unitario_posicion = {0, 0};

    srand(time(0));
    setlocale(LC_ALL, "");

    inicializar_juego(tecla,serpiente, inc_unitario_posicion);
    while ( ! juego_terminado(tecla, serpiente)) {
        pintar_serpiente(serpiente);

        retardar(RETARDO);

        borrar_serpiente(serpiente);

        obtener_direccion(tecla, inc_unitario_posicion);
        mover_serpiente(serpiente, inc_unitario_posicion);

        tecla = leer_tecla();
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();
}

void iniciar_pantalla_inicial(){
    retardar(RETARDO);
    hacer_cursor_visible(false);
    pantalla_incial();
}

void inicializar_juego(char tecla ,posicion serpiente[], inc_unitario_posicion& inc_unitario_posicion){
    iniciar_pantalla_inicial();
    while(leer_tecla()!= TECLA_SIGUIENTE){
            retardar(RETARDO);
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    inicializar_serpiente(serpiente, inc_unitario_posicion);

    dibujar_rectangulo(BASE, ALTURA);
    retardar(RETARDO);

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();
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

void inicializar_serpiente(posicion serpiente[], inc_unitario_posicion& inc_unitario_posicion) {
    serpiente[0].x = SERPIENTE_X_INICIAL;
    serpiente[0].y = SERPIENTE_Y_INICIAL;

    inc_unitario_posicion.x = MOVIMIENTO_X_DERECHA;
    inc_unitario_posicion.y = MOVIMIENTO_Y_ASCENDENTE;

    for (int i = 1; i < LONG_SERPIENTE; i++) {
        serpiente[i].x = serpiente[i - 1].x + 1;
        serpiente[i].y = serpiente[i - 1].y;
    }
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

bool juego_terminado(char tecla, posicion serpiente[]){
    return(toupper(tecla) == TECLA_FIN ||
           serpiente_tocada(serpiente) ||
           serpiente[0].x == LIMITE_IZQUIERDA ||
           serpiente[0].x == LIMITE_DERECHA ||
           serpiente[0].y == LIMITE_SUPERIOR ||
           serpiente[0].y == LIMITE_INFERIOR);
}

void obtener_direccion(const char tecla, inc_unitario_posicion& inc_unitario_posicion) {
    switch (toupper(tecla)) {
        case ARRIBA:
            inc_unitario_posicion.x = 0;
            inc_unitario_posicion.y = MOVIMIENTO_Y_ASCENDENTE;
            break;

        case ABAJO:
            inc_unitario_posicion.x = 0;
            inc_unitario_posicion.y = MOVIMIENTO_Y_DESCENDENTE;
            break;

        case IZQUIERDA:
            inc_unitario_posicion.x = MOVIMIENTO_X_IZQUIERDA;
            inc_unitario_posicion.y = 0;
            break;

        case DERECHA:
            inc_unitario_posicion.x = MOVIMIENTO_X_DERECHA;
            inc_unitario_posicion.y = 0;
            break;
  }
}

void mover_serpiente(posicion serpiente[], inc_unitario_posicion inc_unitario_posicion) {
    posicion cabeza_anterior;
    cabeza_anterior = serpiente[0];

    serpiente[0].x = serpiente[0].x + inc_unitario_posicion.x;
    serpiente[0].y = serpiente[0].y + inc_unitario_posicion.y;

    for (int i = LONG_SERPIENTE - 1; i > 0; --i) {
        serpiente[i] = serpiente[i - 1];
    }
    serpiente[1] = cabeza_anterior;
}


void pintar_serpiente(const posicion serpiente[]) {
    poner_cursor(serpiente[0].x, serpiente[0].y);
    cout << SERPIENTE;

    for (int i = 1; i < LONG_SERPIENTE - 1; i++) {
        poner_cursor(serpiente[i].x, serpiente[i].y);
        cout << CUERPO_SERPIENTE;
    }
}

void borrar_serpiente( const posicion serpiente[]) {
    for (int i = 0; i < LONG_SERPIENTE - 1; i++) {
        poner_cursor(serpiente[i].x, serpiente[i].y);
        cout << " ";
    }
}

bool serpiente_tocada(const posicion serpiente[]) {
    for (int i = 1; i < LONG_SERPIENTE - 1; ++i) {
        if (serpiente[0].x == serpiente[i].x &&
            serpiente[0].y == serpiente[i].y) {
            return true;
        }
    }
    return false;
}
