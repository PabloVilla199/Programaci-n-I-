/*
* Pablo Villa Camañes
* 12/01/2024
*/
#include <iostream>
#include "terminal.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const string TITULO = "Pelotas";
const string VERSION = "1.0";
const int ALTURA_CUADRADO = 15;
const int RETARDO_PELOTA = 50;
const int INC_UNITARIO_POSITIVO = 1;
const int INC_UNITARIO_NEGATIVO = -1;
const int LIMITE_IZQ_X = 3;
const int LIMITE_DCHA_X = 54;
const int LIMITE_SUPERIOR = 2;
const int LIMITE_INFERIOR = 15;
 const int RANGO_ALEATORIO = 2;
const char PELOTA = '0';
const char TECLA_FIN = 'f';

struct posicion {
    int x = 0;
    int y = 0;
};
struct inc_unitario{
    int x = 0;
    int y = 0;
};

void pantalla_inicial();
bool juego_finalizado(char tecla);
bool rebote_eje_y(posicion pelota);
bool rebote_eje_x(posicion pelota);
void desplazamiento_pelota(posicion& pelota, inc_unitario inc_unitario);
void borrar_pelota(posicion pelota);
void pintar_pelota(posicion pelota);
void inicializar_pelota(posicion& pelota,inc_unitario& inc_unitario);

int main(){
    char tecla = '\0';
    posicion pelota;
    inc_unitario inc_unitario;
    srand(time(0));
    setlocale(LC_ALL, "");

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();

    pantalla_inicial();
    inicializar_pelota(pelota,inc_unitario);

    while(! juego_finalizado(tecla)){
        pintar_pelota(pelota);

        retardar(RETARDO_PELOTA);

        borrar_pelota(pelota);

        if(rebote_eje_x(pelota)){
            inc_unitario.x = - inc_unitario.x;
        }
        else if (rebote_eje_y(pelota)){
            inc_unitario.y = - inc_unitario.y;
        }
        desplazamiento_pelota(pelota,inc_unitario);
        tecla = leer_tecla();
    }
    deshabilitar_modo_crudo_terminal();
    borrar_terminal();

}

void pantalla_inicial(){
    poner_cursor(2,1);
    cout << "+--------------------" << TITULO << VERSION << "----------------------+ " << endl;
    for(int i = 1; i < ALTURA_CUADRADO; i++){

        poner_cursor(2,1 + i);
        cout << "|                                                    |" << endl;
    }
    poner_cursor(2,ALTURA_CUADRADO + 1);
    cout << "+----------------------------------------------------+ " << endl;

    poner_cursor(2,ALTURA_CUADRADO + 2);
    cout << "F => FIN" << endl;
}
void inicializar_pelota(posicion& pelota,inc_unitario& inc_unitario){

    pelota.x = LIMITE_DCHA_X - 3;
    pelota.y = 1 + rand()%(LIMITE_INFERIOR - LIMITE_SUPERIOR);


    if (rand()% (RANGO_ALEATORIO)== INC_UNITARIO_POSITIVO){
        inc_unitario.x = INC_UNITARIO_POSITIVO;
        inc_unitario.y = INC_UNITARIO_NEGATIVO;
    }
    else{
        inc_unitario.x = INC_UNITARIO_NEGATIVO;
        inc_unitario.y = INC_UNITARIO_POSITIVO;
    }
}

void pintar_pelota(posicion pelota){

   poner_cursor(pelota.x, pelota.y);
   cout << PELOTA;
}

void borrar_pelota(posicion pelota){

    poner_cursor(pelota.x, pelota.y);
    cout << " ";
}

void desplazamiento_pelota(posicion& pelota, inc_unitario inc_unitario){

    pelota.x = pelota.x + inc_unitario.x;
    pelota.y = pelota.y + inc_unitario.y;
}

bool rebote_eje_x(posicion pelota){
    return(pelota.x == LIMITE_DCHA_X || pelota.x == LIMITE_IZQ_X);
}

bool rebote_eje_y(posicion pelota){
    return(pelota.y == LIMITE_SUPERIOR || pelota.y == LIMITE_INFERIOR);
}

bool juego_finalizado(char tecla){
    return(tecla == TECLA_FIN);
}


