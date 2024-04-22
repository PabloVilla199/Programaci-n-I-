/*
* Serpiente v_1
* Pablo_Villa 28/09/2023
*/
#include <iostream>
#include "terminal.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
const char TEClA_CONTINUAR = ' ';
const char TECLA_FIN = 'f';
const char CABEZA_SERPIENTE = 'O';
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char DERECHA = 'D';
const char IZQUIERDA = 'A';
const int LIMITE_SUP = 3;
const int LIMITE_INF = 20;
const int LIMITE_DERECHA = 100;
const int LIMITE_IZQUIERDA = 4;
const int RETARDO_TECLA = 800;
const int TAMANIO_SERPIENTE = 5;
const int POS_X_INCIAL_S = 15;
const int POS_Y_INICIAL_S = 15;
const int RETARDO_SERPIENTE = 50;
const int MOVIMIENTO_X_IN = 2;
const int MOVIMIENTO_Y_IN = 1;
const string TITULO = "Juego de la serpiente ";
const string VERSION = "1.0";
const string TECLA = "ESPACIO";
const string FIN = "F";
void pintar_cabeza_serpiente( int serpiente_x, int serpiente_y);
void borrar_cabeza_serpiente(int serpiente_x , int serpiente_y);
void mover_serpiente(int &serpiente_x,  int &serpiente_y,int &movimiento_x, int &movimiento_y,char &tecla);
void inicializar_serpiente(int &serpiente_x, int &serpiente_y);
void movimiento_serpiente_x(int &serpiente_x , int &serpiente_y);
void movimiento_serpiente_y(int &serpiente_y, int movimiento_y,char tecla);
void limites_serpiente(int &serpiente_x, int &serpiente_y);
bool finalizar_juego(char tecla);

int main()
{
    int movimiento_x = 0;
    int movimiento_y = 0;
    int serpiente_x = 0;
    int serpiente_y = 0;
    char tecla = '\0';
    habilitar_modo_crudo_terminal();
    retardo(RETARDO_TECLA);
    cursor_visible(false);

    movimiento_x = MOVIMIENTO_X_IN;
    movimiento_y = MOVIMIENTO_Y_IN;
    serpiente_x = POS_X_INCIAL_S;
    serpiente_y = POS_Y_INICIAL_S;

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
    cout << "Pulsa la tecla de " <<  TECLA << " para continuar" << endl;

    while(leer_tecla()!= TEClA_CONTINUAR){

        leer_tecla();
        retardo(RETARDO_TECLA);

   }
   deshabilitar_modo_crudo_terminal();
   borrar_terminal();

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
    cout << "pulsa " << FIN  << " para acabar  " << endl;

    habilitar_modo_crudo_terminal();
    cursor_visible(false);
    srand(time(NULL));
    tecla = leer_tecla();
    inicializar_serpiente(serpiente_x,serpiente_y);

    while(finalizar_juego(tecla)){
        pintar_cabeza_serpiente(serpiente_x, serpiente_y);
        retardo(RETARDO_SERPIENTE);
        borrar_cabeza_serpiente(serpiente_x, serpiente_y);
        mover_serpiente(serpiente_x,serpiente_y,movimiento_x,movimiento_y,tecla);
        limites_serpiente(serpiente_x,serpiente_y);
        tecla = leer_tecla();
    }
    deshabilitar_modo_crudo_terminal();


}
void pintar_cabeza_serpiente( int serpiente_x, int serpiente_y){

        poner_cursor(serpiente_x,serpiente_y);
        cout << CABEZA_SERPIENTE;

}
void borrar_cabeza_serpiente(int serpiente_x , int serpiente_y){

        poner_cursor(serpiente_x ,serpiente_y);
        cout << ' ';
}
void mover_serpiente(int &serpiente_x, int &serpiente_y, int &movimiento_x, int &movimiento_y, char &tecla) {

    switch (toupper(tecla)) {
        case ARRIBA:
            movimiento_x = 0;
            movimiento_y = -1;
            break;

        case ABAJO:
            movimiento_x = 0;
            movimiento_y = 1;
            break;

        case IZQUIERDA:
            movimiento_x = -1;
            movimiento_y = 0;
            break;

        case DERECHA:
            movimiento_x = 1;
            movimiento_y = 0;
            break;

        case TECLA_FIN:
            return;
    }

    serpiente_x += movimiento_x;
    serpiente_y += movimiento_y;
}

bool finalizar_juego(char tecla) {
    return (tecla != TECLA_FIN);
}

void movimiento_serpiente_x(int &serpiente_x , int movimiento_x){

    serpiente_x = serpiente_x + movimiento_x;

}

void movimiento_serpiente_y(int &serpiente_y, int movimiento_y,char tecla){

    switch(tecla){
        case ARRIBA:
            while(tecla == NO_TECLA){
                serpiente_y = serpiente_y - movimiento_y;

            }
        break;

         case ABAJO:
             while(tecla == NO_TECLA){
                serpiente_y = serpiente_y - movimiento_y;
            }
          break;

    }
}


void limites_serpiente(int &serpiente_x, int &serpiente_y){

    if (serpiente_x == LIMITE_DERECHA){

        inicializar_serpiente(serpiente_x,serpiente_y);

    }
    else if (serpiente_x == LIMITE_IZQUIERDA){

        inicializar_serpiente(serpiente_x,serpiente_y);
    }
    else if (serpiente_y == LIMITE_INF){

        inicializar_serpiente(serpiente_x,serpiente_y);
    }
    else if (serpiente_y == LIMITE_SUP){

        inicializar_serpiente(serpiente_x,serpiente_y);
    }

}

void inicializar_serpiente(int &serpiente_x, int &serpiente_y){

    serpiente_x = POS_X_INCIAL_S;
    serpiente_y = POS_Y_INICIAL_S;

}
