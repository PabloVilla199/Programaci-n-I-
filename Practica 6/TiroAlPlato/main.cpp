#include <iostream>
#include "terminal.h"
#include <cstdlib>
#include <ctime>

using namespace std;
const char DERECHA = 'a';
const char IZQUIERDA = 'd';
const char DISPARO = ' ';
const char FIN = 'f';
const char ESCOPETA = '^';
const char ESCOPETA_2 = '*';
const char BALA = '*';
const char PLATO = '@';
const int INC_Y = -1;
const int RETARDO = 50;
const int LIMITE_DCHA = 60;
const int LIMITE_IZQ = 3;

struct posicion {
    int x;
    int y;
};


void inicializar_escopeta(posicion& escopeta);
void inicializar_bala(posicion escopeta, posicion& bala);
void inicializar_plato(posicion& plato);
void pintar_escopeta(posicion escopeta);
void borrar_escopeta(posicion escopeta);
void pintar_bala(posicion bala);
void borrar_bala(posicion bala);
void pintar_plato(posicion plato);
void borrar_plato(posicion plato);
void obtener_direccion_escopeta(char tecla,posicion& escopeta);
void disparar_bala(posicion &bala, int inc_unitario_y);
bool disparo_acertado(posicion bala, posicion plato);
bool juego_finalizado(char tecla);
bool disparo_efectuado(char tecla, bool bala_pantalla);


int main(){
    int tiempo = 0;
    char tecla = '\0';
    posicion plato;
    posicion escopeta;
    posicion bala;
    int inc_unitario_y = INC_Y;
    bool plato_pantalla = false;
    bool bala_pantalla = false;

    srand(time(0));
    setlocale(LC_ALL, "");

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();

    retardar(RETARDO);
    inicializar_escopeta(escopeta);

    while(! juego_finalizado(tecla)){
        tiempo = tiempo + 1;

        if( ! plato_pantalla){
            inicializar_plato(plato);
            plato_pantalla = true;

            pintar_plato(plato);

            if (tiempo == 5){
                borrar_plato(plato);
                plato_pantalla = false;
            }

        }
        if (disparo_efectuado(tecla,bala_pantalla)) {
            bala_pantalla = true;
            inicializar_bala(escopeta, bala);
        }
        pintar_escopeta(escopeta);


        if (bala_pantalla) {
            pintar_bala(bala);

            retardar(RETARDO);

            borrar_bala(bala);
            disparar_bala(bala, inc_unitario_y);

            if (bala.y == 0) {
                borrar_bala(bala);
                bala_pantalla = false;
            }

            if (disparo_acertado(bala, plato)) {
                borrar_bala(bala);
                borrar_plato(plato);
                plato_pantalla = false;
                bala_pantalla = false;
            }
    }
        pintar_escopeta(escopeta);

        retardar(RETARDO);

        borrar_escopeta(escopeta);

        obtener_direccion_escopeta(tecla,escopeta);

        tecla = leer_tecla();



    }
    borrar_terminal();
    deshabilitar_modo_crudo_terminal();
}

void inicializar_escopeta(posicion& escopeta){

    escopeta.x = 30;
    escopeta.y = 19;
}

void inicializar_bala(posicion escopeta, posicion& bala){

    bala.x = escopeta.x;
    bala.y = escopeta.y - 3;
}

void inicializar_plato(posicion& plato){

    plato.x = 20 + rand() % (30 - 5);
    plato.y = 4;
}

void pintar_escopeta(posicion escopeta){

   poner_cursor(escopeta.x, escopeta.y);
   cout << ESCOPETA;

   poner_cursor(escopeta.x, escopeta.y + 1);
   cout << ESCOPETA;

   poner_cursor(escopeta.x, escopeta.y - 1);
   cout << ESCOPETA_2;
}

void borrar_escopeta(posicion escopeta){

  poner_cursor(escopeta.x, escopeta.y);
   cout << " ";

   poner_cursor(escopeta.x, escopeta.y + 1);
   cout << " ";

   poner_cursor(escopeta.x, escopeta.y - 1);
   cout << " ";
}

void pintar_bala(posicion bala){

    poner_cursor(bala.x, bala.y);
    cout << BALA;
}

void borrar_bala(posicion bala){

    poner_cursor(bala.x, bala.y);
    cout << " ";
}

void pintar_plato(posicion plato){

    poner_cursor(plato.x, plato.y);
    cout << PLATO;
}

void borrar_plato(posicion plato){

    poner_cursor(plato.x , plato.y);
    cout << " ";
}

void obtener_direccion_escopeta(char tecla, posicion& escopeta) {
    switch(tecla) {
        case DERECHA:
            escopeta.x--;
            break;
        case IZQUIERDA:
            escopeta.x++;
            break;
    }
}

void disparar_bala(posicion &bala, int inc_unitario_y){

    bala.y = bala.y + inc_unitario_y;
}

bool disparo_acertado(posicion bala, posicion plato){

    return(bala.x == plato.x && bala.y == plato.y);
}

bool juego_finalizado(char tecla){

    return (tecla == FIN);

}
bool disparo_efectuado(char tecla, bool bala_pantalla){
    return((tecla == ' ') && (!bala_pantalla));
}
