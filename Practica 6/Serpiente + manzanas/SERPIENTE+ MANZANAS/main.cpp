/*
* Juego de la Serpiente v1
*
* Pablo_Villa 08/11/2023
*
* version en la que por cada manzana
* comida se incrementa en 1 el tamaño
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
const int BASE_TIEMPO = 3000;
const int TIEMPO_ACCION = 50000;
const int LONG_SERPIENTE = 100;
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
const int MARGEN_INI_MANZANA = 5;
const int MARGEN_MARCADOR = 5;
const int MAX_MANZANAS = 100;
const string TITULO = "Juego de la serpiente ";
const string VERSION = "5.0";
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
void inicializar_juego(char tecla,posicion serpiente[],
                       inc_unitario_posicion& inc_unitario_posicion, int longitud_serpiente);
void pantalla_incial();
void dibujar_linea(const char c_exterior, const char c_interior, const int largo);
void dibujar_rectangulo(const int base, const int altura);
void inicializar_serpiente(posicion serpiente[], inc_unitario_posicion& inc_unitario_posicion,int longitud_serpiente);
bool juego_terminado(char tecla,posicion serpiente[],int longitud_serpiente);
void obtener_direccion_serpiente(const char tecla,inc_unitario_posicion& inc_unitario_posicion);
void pintar_serpiente(const posicion serpiente[], int longitud_serpiente);
void borrar_serpiente( const posicion serpiente[], int longitud_serpiente);
bool serpiente_tocada(const posicion serpiente[],int longitud_serpiente);
void inicializar_manzana(posicion& manzana);
void pintar_manzana(const posicion& manzana);
void borrar_manzana(const posicion& manzana);
bool manzana_tocada(const posicion manzana[], const posicion serpiente[], int num_manzanas);
void mover_serpiente(posicion serpiente[], inc_unitario_posicion inc_unitario_posicion);
void actualizar_marcador(int& puntos);
void actualizar_longitud(int& longitud_serpiente);

int main() {
    int puntos = 0;
    int tiempo = 0;
    int num_manzanas = 1;
    bool hay_manzana = false;
    char tecla = '\0';
    int longitud_serpiente = 5;
    posicion serpiente[LONG_SERPIENTE];
    posicion manzana[MAX_MANZANAS];
    inc_unitario_posicion inc_unitario_posicion;

    inicializar_juego(tecla, serpiente, inc_unitario_posicion,longitud_serpiente);
    while ( ! juego_terminado(tecla, serpiente,longitud_serpiente)) {
            tiempo = BASE_TIEMPO + tiempo;
            if(num_manzanas < 6){
                if (tiempo % TIEMPO_ACCION == 0) {
                    inicializar_manzana(manzana[num_manzanas]);
                    poner_cursor(1,29);
                    cout << num_manzanas;
                    pintar_manzana(manzana[num_manzanas]);
                    num_manzanas++;
                }
        }
        if( manzana_tocada(manzana, serpiente,num_manzanas)) {
            num_manzanas--;
            actualizar_longitud(longitud_serpiente);
            poner_cursor(1,28);
            cout << longitud_serpiente;
            actualizar_marcador(puntos);
        }

        pintar_serpiente(serpiente,longitud_serpiente);

        retardar(RETARDO);

        borrar_serpiente(serpiente,longitud_serpiente);

        obtener_direccion_serpiente(tecla, inc_unitario_posicion);
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

void inicializar_juego(char tecla, posicion serpiente[],
                       inc_unitario_posicion& inc_unitario_posicion,int longitud_serpiente){
    srand(time(0));
    setlocale(LC_ALL, "");
    iniciar_pantalla_inicial();

    while(leer_tecla()!= TECLA_SIGUIENTE){
            retardar(RETARDO);
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

    inicializar_serpiente(serpiente, inc_unitario_posicion,longitud_serpiente);

    dibujar_rectangulo(BASE, ALTURA);

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

void inicializar_serpiente(posicion serpiente[], inc_unitario_posicion& inc_unitario_posicion,int longitud_serpiente) {
    serpiente[0].x = SERPIENTE_X_INICIAL;
    serpiente[0].y = SERPIENTE_Y_INICIAL;

    inc_unitario_posicion.x = MOVIMIENTO_X_DERECHA;
    inc_unitario_posicion.y = MOVIMIENTO_Y_ASCENDENTE;

    for (int i = 1; i < longitud_serpiente; i++) {
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

bool juego_terminado(char tecla, posicion serpiente[], int longitud_serpiente){
    return(toupper(tecla) == TECLA_FIN ||
           serpiente_tocada(serpiente,longitud_serpiente) ||
           serpiente[0].x == LIMITE_IZQUIERDA ||
           serpiente[0].x == LIMITE_DERECHA ||
           serpiente[0].y == LIMITE_SUPERIOR ||
           serpiente[0].y == LIMITE_INFERIOR);
}

void obtener_direccion_serpiente(const char tecla, inc_unitario_posicion& inc_unitario_posicion) {
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


void pintar_serpiente(const posicion serpiente[],int longitud_serpiente) {
    poner_cursor(serpiente[0].x, serpiente[0].y);
    cout << SERPIENTE;

    for (int i = 1; i < longitud_serpiente - 1; i++) {
        poner_cursor(serpiente[i].x, serpiente[i].y);
        cout << CUERPO_SERPIENTE;
    }
}

void borrar_serpiente( const posicion serpiente[], int longitud_serpiente) {
    for (int i = 0; i < longitud_serpiente - 1; i++) {
        poner_cursor(serpiente[i].x, serpiente[i].y);
        cout << " ";
    }
}

bool serpiente_tocada(const posicion serpiente[],int longitud_serpiente) {
    for (int i = 1; i < longitud_serpiente - 1; ++i) {
        if (serpiente[0].x == serpiente[i].x &&
            serpiente[0].y == serpiente[i].y) {
            return true;
        }
    }
    return false;
}

void inicializar_manzana(posicion& manzana) {
    manzana.x = LIMITE_IZQUIERDA + MARGEN_INI_MANZANA +
                rand() % (LIMITE_DERECHA - LIMITE_IZQUIERDA - MARGEN_INI_MANZANA );

    manzana.y = LIMITE_SUPERIOR + MARGEN_INI_MANZANA +
                rand() % (LIMITE_INFERIOR - LIMITE_SUPERIOR - MARGEN_INI_MANZANA);
}

void pintar_manzana(const posicion& manzana){
    poner_cursor(manzana.x, manzana.y);
    cout << MANZANA;
}

void borrar_manzana(const posicion& manzana){
    poner_cursor(manzana.x, manzana.y);
    cout << " ";
}

bool manzana_tocada(const posicion manzanas[], const posicion serpiente[], int num_manzanas) {
    for (int i = 0; i < num_manzanas; i++) {
        if (manzanas[i].x == serpiente[0].x && manzanas[i].y == serpiente[0].y) {
            return true;
        }
    }
    return false;
}

void actualizar_marcador(int& puntos){
    puntos = puntos + PREMIO;
    poner_cursor(LIMITE_IZQUIERDA,LIMITE_INFERIOR + MARGEN_MARCADOR);
    cout << "PUNTOS: " << puntos;
}
void actualizar_longitud(int& longitud_serpiente){

 longitud_serpiente = longitud_serpiente + 1;

}
