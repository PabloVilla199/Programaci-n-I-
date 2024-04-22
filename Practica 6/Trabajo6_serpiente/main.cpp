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
const int LONGITUD_SERPIENTE = 15;
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
const string VERSION = "4.0";
const string TECLA_CONTINUAR = "ESPACIO";

struct posicion{
    int x = 0;
    int y = 0;
};

struct movimiento{
    int movimiento_x = 0;
    int movimiento_y = 0;

};

struct cabeza_serpiente{
    posicion posicion_serpiente;
    movimiento movimiento_serpiente;
};
struct cuerpo_serpiente{
    posicion posicion_cuerpo[LONGITUD_SERPIENTE];
};

struct serpiente{
    cabeza_serpiente cabeza;
    cuerpo_serpiente cuerpo;
};

void pantalla_incial();
void inicializar_serpiente(serpiente& serpiente);
void dibujar_linea(const char c_exterior, const char c_interior, const int largo);
void dibujar_rectangulo(const int base, const int altura);
void pintar_cabeza_serpiente(serpiente& serpiente);
void borrar_cabeza_serpiente(serpiente& serpiente);
bool juego_terminado(char tecla,serpiente& serpiente);
void obtener_direccion(const char tecla,serpiente& serpiente);
void mover_cabeza(serpiente& serpiente);
void pintar_cuerpo_serpiente(serpiente& serpiente);
void borrar_cuerpo_serpiente(serpiente& serpiente);
void actualizar_posicion_cuerpo(serpiente& serpiente);
bool colision_cuerpo(const serpiente& serpiente);

int main() {
    serpiente serpiente;
    char tecla = '\0';

    inicializar_serpiente(serpiente);
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

   while (!juego_terminado(tecla, serpiente)) {

        pintar_cabeza_serpiente(serpiente);
        pintar_cuerpo_serpiente(serpiente);

        retardar(RETARDO);

        borrar_cabeza_serpiente(serpiente);
        borrar_cuerpo_serpiente(serpiente);

        obtener_direccion(tecla,serpiente);

        actualizar_posicion_cuerpo(serpiente);
        mover_cabeza(serpiente);

    poner_cursor(1, 23);
    cout << "Cabeza: (" << serpiente.cabeza.posicion_serpiente.x << ", " << serpiente.cabeza.posicion_serpiente.y << ")";

    poner_cursor(1, 24);
    cout << "Cuerpo: ";
    for (int i = 0; i < LONGITUD_SERPIENTE; i++) {
        cout << "(" << serpiente.cuerpo.posicion_cuerpo[i].x << ", " << serpiente.cuerpo.posicion_cuerpo[i].y << ") ";
    }

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

void inicializar_serpiente(serpiente& serpiente) {
    serpiente.cabeza.posicion_serpiente.x = SERPIENTE_X_INICIAL - 1;
    serpiente.cabeza.posicion_serpiente.y = SERPIENTE_Y_INICIAL;
    serpiente.cabeza.movimiento_serpiente.movimiento_x = MOVIMIENTO_X_DERECHA;
    serpiente.cabeza.movimiento_serpiente.movimiento_y = MOVIMIENTO_Y_ASCENDENTE;

    for(int i = 0; i < LONGITUD_SERPIENTE; i++){
        serpiente.cuerpo.posicion_cuerpo[i].x = SERPIENTE_X_INICIAL  + i;
        serpiente.cuerpo.posicion_cuerpo[i].y = SERPIENTE_Y_INICIAL;
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

void pintar_cabeza_serpiente(serpiente & serpiente){
    poner_cursor(serpiente.cabeza.posicion_serpiente.x,serpiente.cabeza.posicion_serpiente.y);
    cout << SERPIENTE;
}

void borrar_cabeza_serpiente(serpiente& serpiente){
    poner_cursor(serpiente.cabeza.posicion_serpiente.x,serpiente.cabeza.posicion_serpiente.y);
    cout << " ";
}

bool juego_terminado(char tecla,serpiente& serpiente){
    return(toupper(tecla) == TECLA_FIN ||
           colision_cuerpo(serpiente) ||
           serpiente.cabeza.posicion_serpiente.x == LIMITE_IZQUIERDA ||
           serpiente.cabeza.posicion_serpiente.x == LIMITE_DERECHA ||
           serpiente.cabeza.posicion_serpiente.y == LIMITE_SUPERIOR ||
           serpiente.cabeza.posicion_serpiente.y == LIMITE_INFERIOR);
}

void obtener_direccion(const char tecla, serpiente& serpiente){
    switch (toupper(tecla)) {
        case ARRIBA:
            serpiente.cabeza.movimiento_serpiente.movimiento_x = 0;
            serpiente.cabeza.movimiento_serpiente.movimiento_y = MOVIMIENTO_Y_ASCENDENTE;
            break;

        case ABAJO:
            serpiente.cabeza.movimiento_serpiente.movimiento_x = 0;
            serpiente.cabeza.movimiento_serpiente.movimiento_y = MOVIMIENTO_Y_DESCENDENTE;
            break;

        case IZQUIERDA:
            serpiente.cabeza.movimiento_serpiente.movimiento_x = MOVIMIENTO_X_IZQUIERDA;
            serpiente.cabeza.movimiento_serpiente.movimiento_y = 0;
            break;

        case DERECHA:
            serpiente.cabeza.movimiento_serpiente.movimiento_x = MOVIMIENTO_X_DERECHA;
            serpiente.cabeza.movimiento_serpiente.movimiento_y = 0;
            break;
  }
}

void mover_cabeza(serpiente& serpiente){
    serpiente.cabeza.posicion_serpiente.x =  serpiente.cabeza.posicion_serpiente.x + serpiente.cabeza.movimiento_serpiente.movimiento_x;
    serpiente.cabeza.posicion_serpiente.y =  serpiente.cabeza.posicion_serpiente.y  + serpiente.cabeza.movimiento_serpiente.movimiento_y;
}

void pintar_cuerpo_serpiente(serpiente& serpiente) {
    for (int i = 0; i < LONGITUD_SERPIENTE - 1; i++) {
        poner_cursor(serpiente.cuerpo.posicion_cuerpo[i].x, serpiente.cuerpo.posicion_cuerpo[i].y);
        cout << "o";
    }
}

void borrar_cuerpo_serpiente(serpiente& serpiente) {
    for (int i = 0; i < LONGITUD_SERPIENTE - 1; i++) {
        poner_cursor(serpiente.cuerpo.posicion_cuerpo[i].x, serpiente.cuerpo.posicion_cuerpo[i].y);
        cout << " ";
    }
}

void actualizar_posicion_cuerpo(serpiente& serpiente) {
    posicion cabeza_anterior;
    cabeza_anterior = serpiente.cabeza.posicion_serpiente;

    for (int i = LONGITUD_SERPIENTE - 1; i > 0; --i) {
        serpiente.cuerpo.posicion_cuerpo[i] = serpiente.cuerpo.posicion_cuerpo[i - 1];
    }
    serpiente.cuerpo.posicion_cuerpo[0] = cabeza_anterior;
}

bool colision_cuerpo(const serpiente& serpiente) {
    for (int i = 0; i < LONGITUD_SERPIENTE - 1; ++i) {
        if (serpiente.cabeza.posicion_serpiente.x == serpiente.cuerpo.posicion_cuerpo[i].x &&
            serpiente.cabeza.posicion_serpiente.y == serpiente.cuerpo.posicion_cuerpo[i].y) {
            return true;
        }
    }
    return false;
}
