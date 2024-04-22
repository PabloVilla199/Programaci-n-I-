/*
* Pablo Villa Cama�es
* 12/01/2024
*/
#include <iostream>
#include "terminal.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const string TITULO = "Pelotas";
const string VERSION = "2.0";
const int ALTURA_CUADRADO = 15;
const int RETARDO_PELOTA = 50;
const int INC_UNITARIO_POSITIVO = 1;
const int INC_UNITARIO_NEGATIVO = -1;
const int LIMITE_IZQ_X = 3;
const int LIMITE_DCHA_X = 54;
const int LIMITE_SUPERIOR = 2;
const int LIMITE_INFERIOR = 15;
const int RANGO_ALEATORIO = 2;
const int MAX_PELOTAS = 9;
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
void desplazamiento_pelota(posicion pelota[], inc_unitario inc_unitario[], int pelotas_pantalla);
void borrar_pelota(posicion pelota[], int pelotas_pantalla);
void pintar_pelota(posicion pelota[], int pelotas_pantalla);
void inicializar_pelota(posicion& pelota, inc_unitario& inc_unitario);

int main(){
    char tecla = '\0';
    posicion pelota[MAX_PELOTAS];
    inc_unitario inc_unitario[MAX_PELOTAS];
    int pelotas_pantalla = 0;
    int tiempo = 0;
    srand(time(0));
    setlocale(LC_ALL, "");

    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);
    tecla = leer_tecla();

    pantalla_inicial();

    while(! juego_finalizado(tecla)){
         tiempo = tiempo + 1;
        if(pelotas_pantalla < MAX_PELOTAS && tiempo % 7 == 0){
            inicializar_pelota(pelota[pelotas_pantalla],inc_unitario[pelotas_pantalla]);
            pelotas_pantalla++;

        }
        pintar_pelota(pelota,pelotas_pantalla);

        retardar(RETARDO_PELOTA);

        borrar_pelota(pelota,pelotas_pantalla);

        for(int i = 0; i < pelotas_pantalla; i++){
             if(rebote_eje_x(pelota[i])){
                inc_unitario[i].x = - inc_unitario[i].x;
            }
            else if (rebote_eje_y(pelota[i])){
                inc_unitario[i].y = - inc_unitario[i].y;
            }
        }
        retardar(RETARDO_PELOTA);
        desplazamiento_pelota(pelota,inc_unitario,pelotas_pantalla);
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

    pelota.x = LIMITE_DCHA_X - 10;
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

void pintar_pelota(posicion pelota[],int pelotas_pantalla){
    for(int i = 0; i < pelotas_pantalla; i++){
          poner_cursor(pelota[i].x, pelota[i].y);
         cout << PELOTA;
    }
}

void borrar_pelota(posicion pelota[], int pelotas_pantalla){
        for(int i = 0; i < pelotas_pantalla; i++){
            poner_cursor(pelota[i].x, pelota[i].y);
            cout << " ";
        }
}

void desplazamiento_pelota(posicion pelota[], inc_unitario inc_unitario[],int pelotas_pantalla){
    for (int i = 0; i < pelotas_pantalla; i++){
         pelota[i].x = pelota[i].x + inc_unitario[i].x;
         pelota[i].y = pelota[i].y + inc_unitario[i].y;
    }

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
