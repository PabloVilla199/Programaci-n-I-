 /*
* Fronton_v4
* Pablo_villa
*/
#include <iostream>
#include "terminal.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
const string TITULO = "Fronton";
const string VERSION = "4.0";
 const char PELOTA = '*';
  const char TECLA_CONTINUACION = ' ';
 const char ESPACIO = ' ';
 const char RAQUETA = '|';
 const char FIN = 'f';
 const char SUBIDA = 'Q';
 const char BAJADA = 'A';
 const char NO_MOV = '\0';
 const int POS_X_IN = 4;
 const int POS_y_IN = 7;
 const int RETARDO_PELOTA = 100;
 const int MOVIMIENTO_X = 1;
 const int MOVIMIENTO_Y = 1;
 const int LIMITE_SUP = 3;
 const int LIMITE_INF = 17;
 const int LIMITE_DERECHA = 3;
 const int LIMITE_IZQUIERDA = 55;
 const int VIDAS_INICIALES = 5;
 const int TAMANIO_RAQUETA = 3;
 const int RANGO_ALEATORIO = 2;
 const int SENTIDO_POSITIVO = 0;
 const int POSICION_RAQUETA = 3;
 const int FIN_JUEGO = 0;

 struct desplazamiento{
    int x;
    int y;
 };
 struct posicion {
    int x;
    int y;
 desplazamiento desplazamiento;
 };

 void dibujar_pantalla_inicio();
 void dibujar_pantalla_juego(int vidas_actuales);
 void pintar_pelota(const posicion pelota, char PELOTA);
 void retardo_pelota();
 bool hay_rebote_x( const posicion pelota);
 bool hay_rebote_y(const posicion pelota);
 void rebotar_x( posicion &pelota);
 void rebotar_y(posicion &pelota);
 void rebotar_pelota(posicion &pelota, posicion raqueta);
 void obteber_nueva_posicion(posicion &pelota);
 void movimiento_pelota(posicion &pelota, int &vidas_actuales, posicion &raqueta);
 void contador_actual(int vidas_actuales);
 void pintar_raqueta(posicion &raqueta, char RAQUETA);
 void desplazar_raqueta(posicion &raqueta, char tecla);
 void movimiento_raqueta(posicion& pelota ,char tecla);
 void inicializar_pelota(posicion &pelota);
 void inicializar_raqueta(posicion &raqueta);
 bool rebote_raqueta(const posicion pelota , const posicion raqueta);
 bool finalizar_juego(int vidas_actuales,char tecla);
 int main()
 {
    posicion pelota;
    posicion raqueta;

    char tecla = '\0';
    int vidas_actuales = VIDAS_INICIALES;
    cursor_visible(false);

    setlocale(LC_ALL, "");
    srand(time(NULL));
    habilitar_modo_crudo_terminal();
    cursor_visible(false);
    dibujar_pantalla_inicio();

    while (toupper(tecla) != TECLA_CONTINUACION) {
        tecla = leer_tecla();
    }

    borrar_terminal();
    dibujar_pantalla_juego(vidas_actuales);
    inicializar_pelota(pelota);
    inicializar_raqueta(raqueta);
    pintar_raqueta(raqueta,RAQUETA);
    tecla = '\0';

    while(finalizar_juego(vidas_actuales,tecla)){
      tecla = leer_tecla();
      movimiento_pelota(pelota,vidas_actuales, raqueta);
      movimiento_raqueta(raqueta,tecla);
    }

 }

void pintar_pelota(posicion pelota,char PELOTA){
    poner_cursor(pelota.x , pelota.y);
    cout << PELOTA;
}

bool hay_rebote_x( const posicion pelota){
    return(pelota.x == LIMITE_IZQUIERDA);
}

bool hay_rebote_dcha(const posicion pelota){
    return(pelota.x == LIMITE_DERECHA);
}

bool hay_rebote_y(const posicion pelota){
    return(pelota.y == LIMITE_SUP) || (pelota.y == LIMITE_INF);

}

void obteber_nueva_posicion(posicion &pelota){
    pelota.x = pelota.x + pelota.desplazamiento.x;
    pelota.y = pelota.y + pelota.desplazamiento.y;

}

void inicializar_pelota(posicion &pelota){

    pelota.x = LIMITE_IZQUIERDA - LIMITE_SUP ;
    pelota.y = 1 + rand()% (LIMITE_INF - TAMANIO_RAQUETA);
    pelota.desplazamiento.x = MOVIMIENTO_X;
    if (rand()% (RANGO_ALEATORIO)== SENTIDO_POSITIVO){
       pelota.desplazamiento.y = - MOVIMIENTO_Y;
    }
    else{
        pelota.desplazamiento.y = MOVIMIENTO_Y;
    }

}

void rebotar_pelota(posicion &pelota, posicion raqueta){
    if (hay_rebote_x(pelota)|| rebote_raqueta(pelota,raqueta)){
        pelota.desplazamiento.x = - pelota.desplazamiento.x;
    }
    else if (hay_rebote_y(pelota)){
            pelota.desplazamiento.y = - pelota.desplazamiento.y;
    }
    else if (hay_rebote_dcha(pelota)){
        pintar_pelota(pelota,PELOTA);
    }
}

void movimiento_pelota(posicion &pelota,int &vidas_actuales, posicion &raqueta){
    pintar_pelota(pelota,PELOTA);
    retardo(RETARDO_PELOTA);
    pintar_pelota(pelota,ESPACIO);
    rebotar_pelota(pelota,raqueta);
    obteber_nueva_posicion(pelota);
    if (pelota.x == LIMITE_DERECHA){
      vidas_actuales--;
      contador_actual(vidas_actuales);
      inicializar_pelota(pelota);
    }
}
void contador_actual(int vidas_actuales){
    poner_cursor (2,20);
    cout << "Pelotas restantes:" << vidas_actuales << endl;
}

void inicializar_raqueta(posicion &raqueta){
    raqueta.x = POSICION_RAQUETA;
    raqueta.y = LIMITE_INF / 2;
}

void pintar_raqueta(posicion &raqueta, char RAQUETA){

    for(int i = 0; i < TAMANIO_RAQUETA; i++){
        poner_cursor(raqueta.x, raqueta.y + i);
        cout << RAQUETA << endl;
    }
}

void movimiento_raqueta(posicion &raqueta, char tecla){
    if (toupper(tecla) != NO_MOV){
        desplazar_raqueta(raqueta,tecla);
    }
}
void calcular_posicion_raqueta(posicion &raqueta, char tecla){
    switch(toupper(tecla)){
        case SUBIDA:
            if (raqueta.y != LIMITE_SUP){
                raqueta.y--;
            }
          break;
        case BAJADA:
            if (raqueta.y != LIMITE_INF){
                raqueta.y++;
            }
          break;
    }
}
bool rebote_raqueta(const posicion pelota , const posicion raqueta){
    return (pelota.x == raqueta.x +1 && (pelota.y == raqueta.y ||
            pelota.y == raqueta.y + 1 || pelota.y == raqueta.y + (TAMANIO_RAQUETA / 2)||
            pelota.y == raqueta.y + (TAMANIO_RAQUETA-1)));

}

void desplazar_raqueta(posicion &raqueta,char tecla){
    pintar_raqueta(raqueta,ESPACIO);
    calcular_posicion_raqueta(raqueta,tecla);
    pintar_raqueta(raqueta,RAQUETA);
}
bool finalizar_juego(int vidas_actuales,char tecla){
    return(vidas_actuales != FIN_JUEGO && toupper(tecla) != FIN);
}
void dibujar_pantalla_inicio(){
    poner_cursor(0, 0);
    cout <<  "****************************" << endl;

    poner_cursor(0, 1);
    cout << "* " << TITULO << " " << VERSION << " *" << endl;

    poner_cursor(0, 2);
    cout <<  "****************************" << endl;

    poner_cursor(11, 4);
    cout << "____" << endl;

    poner_cursor(10, 5);
    cout << "/....\\" << endl;

    poner_cursor(9, 6);
    cout << "|......|  __" << endl;

    poner_cursor(9, 7);
    cout << "|......| (__)" << endl;

    poner_cursor(9, 8);
    cout << "\\....../" << endl;

    poner_cursor(10, 9);
    cout << "\\..../" << endl;

    poner_cursor(11, 10);
    cout << "\\--/" << endl;

    poner_cursor(12, 11);
    cout << "||" << endl;

    poner_cursor(12, 12);
    cout << "||" << endl;

    poner_cursor(12, 13);
    cout << "[]" << endl;

    poner_cursor(12, 14);
    cout << "[]" << endl;

    poner_cursor(12, 15);
    cout << "[]" << endl;

    poner_cursor(1, 17);
    cout << "Pulsa " << TECLA_CONTINUACION
    << " para continuar" << endl;
}

void dibujar_pantalla_juego(int vidas_actuales){
    poner_cursor(2,1);
    cout << "+---------------------" <<TITULO << VERSION<<"---------------------+" << endl;
    poner_cursor(2,2);
    cout << "|                                                     |" << endl;
    poner_cursor(2,3);
    cout << "|                                                     |" << endl;
    poner_cursor(2,4);
    cout << "|                                                     |" << endl;
    poner_cursor(2,5);
    cout << "|                                                     |" << endl;
    poner_cursor(2,6);
    cout << "|                                                     |" << endl;
    poner_cursor(2,7);
    cout << "|                                                     |" << endl;
    poner_cursor(2,8);
    cout << "|                                                     |" << endl;
    poner_cursor(2,9);
    cout << "|                                                     |" << endl;
    poner_cursor(2,10);
    cout << "|                                                     |" << endl;
    poner_cursor(2,11);
    cout << "|                                                     |" << endl;
    poner_cursor(2,12);
    cout << "|                                                     |" << endl;
    poner_cursor(2,13);
    cout << "|                                                     |" << endl;
    poner_cursor(2,14);
    cout << "|                                                     |" << endl;
    poner_cursor(2,15);
    cout << "|                                                     |" << endl;
    poner_cursor(2,16);
    cout << "|                                                     |" << endl;
    poner_cursor(2,17);
    cout << "|                                                     |" << endl;
    poner_cursor(2,18);
    cout << " +----------------------------------------------------+" << endl;
    poner_cursor (2,19);
    cout << "pulsa tecla " << FIN << " para finalizar" << endl;
}
