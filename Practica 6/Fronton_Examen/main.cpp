#include <iostream>
#include "terminal.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const char PELOTA = '*';
const char ARRIBA = 'Q';
const char ABAJO = 'A';
const char FIN = 'F';
const char SIMBOLO_EXTERIOR = '+';
const char SIMBOLO_HORIZONTAL = '-';
const char SIMBOLO_INTERMEDIO = ' ';
const char SIMBOLO_VERTICAL = '|';
const int LIMITE_DERECHA = 75;
const int LIMITE_IZQUIERDA = 3;
const int LIMITE_SUP = 2;
const int LIMITE_INF = 18;
const string TITULO = "Juego del fronton";
const string VERSION = "4.0";
const char RAQUETA = '|';
const int TAMANIO_RAQUETA = 5;
const int RETARDO_PELOTA = 50;
const int MAX_PELOTAS = 8;
const int RANGO_ALEATORIO = 2;

struct posicion {
    int x = 0;
    int y = 0;
};

struct inc_unitario {
    int x = 0;
    int y = 0;
};

void dibujar_linea(const char c_interior, const char c_exterior, const int largo);
void dibujar_pantalla(const int base, const int altura);
bool juego_terminado(char tecla);
void inicializar_pelota(posicion pelota[], inc_unitario inc_pelota[], int &pelotas_pantalla);
bool limites_tocados(posicion pelota);
void movimiento_pelota(posicion pelota[], inc_unitario inc_pelota[], int pelotas_pantalla);
void pintar_pelota(posicion pelota[], int num_pelotas);
void borrar_pelota(posicion pelota[], int num_pelotas);
void pintar_raqueta(posicion raqueta);
void borrar_raqueta(posicion raqueta);
void calcular_posicion_raqueta(posicion &raqueta, char tecla);
bool rebote_raqueta(posicion pelota[], int num_pelotas, posicion raqueta);
void inicializar_raqueta(posicion &raqueta);

int main() {
    posicion pelota[MAX_PELOTAS];
    inc_unitario inc_pelota[MAX_PELOTAS];
    posicion raqueta;
    char tecla = '\0';
    int pelotas_pantalla = 0;
    int tiempo = 0;

    srand(time(0));
    habilitar_modo_crudo_terminal();
    hacer_cursor_visible(false);

    dibujar_pantalla(LIMITE_DERECHA, LIMITE_INF);
    inicializar_raqueta(raqueta);

    while (!juego_terminado(tecla)) {
        tiempo = tiempo + 1;

        if (tiempo % 50 == 0 && pelotas_pantalla < MAX_PELOTAS) {
            pelotas_pantalla++;
            inicializar_pelota(pelota, inc_pelota, pelotas_pantalla);
        }
        pintar_raqueta(raqueta);
        pintar_pelota(pelota, pelotas_pantalla);
        retardar(RETARDO_PELOTA);
        borrar_raqueta(raqueta);
        borrar_pelota(pelota, pelotas_pantalla);
        calcular_posicion_raqueta(raqueta, tecla);
        tecla = leer_tecla();

        for (int i = 0; i < pelotas_pantalla; i++) {
            if (limites_tocados(pelota[i])) {
                inc_pelota[i].y = -inc_pelota[i].y;
            } else if (pelota[i].x == LIMITE_IZQUIERDA) {
                pelotas_pantalla--;
                borrar_pelota(pelota, i);
            } else if (rebote_raqueta(pelota, pelotas_pantalla, raqueta)) {
                inc_pelota[i].x = -inc_pelota[i].x;
            } else if (pelota[i].x == LIMITE_DERECHA) {
                inc_pelota[i].x = -inc_pelota[i].x;
            }
            movimiento_pelota(pelota, inc_pelota, pelotas_pantalla);
        }
    }

    return 0;
}

void dibujar_linea(const char c_interior, const char c_exterior, const int largo) {
    cout << c_exterior;
    for (int i = 2; i < largo; i++) {
        cout << c_interior;
    }
    cout << c_exterior << endl;
}

void dibujar_pantalla(const int base, const int altura) {
    poner_cursor(2, 1);
    cout << "+------------------------- " << TITULO << VERSION << " --------------------------+ " << endl;

    for (int i = 2; i < altura; i++) {
        poner_cursor(2, i);
        dibujar_linea(SIMBOLO_INTERMEDIO, SIMBOLO_VERTICAL, base);
    }

    poner_cursor(2, altura + 1);
    dibujar_linea(SIMBOLO_HORIZONTAL, SIMBOLO_EXTERIOR, base);

    poner_cursor(2, altura + 2);
    cout << ARRIBA << "-> Subir " << ABAJO << "-> Bajar " << FIN << "-> Fin" << endl;
}

bool juego_terminado(char tecla) {
    return (toupper(tecla) == FIN);
}

void inicializar_pelota(posicion pelota[], inc_unitario inc_pelota[], int &pelotas_pantalla) {
    pelota[pelotas_pantalla - 1].x = LIMITE_DERECHA - 5;
    pelota[pelotas_pantalla - 1].y = 1 + rand() % (LIMITE_INF - TAMANIO_RAQUETA);

    if ((rand() % (RANGO_ALEATORIO) == 1)) {
        inc_pelota[pelotas_pantalla - 1].x = -1;
        inc_pelota[pelotas_pantalla - 1].y = 1;
    } else {
        inc_pelota[pelotas_pantalla - 1].x = 1;
        inc_pelota[pelotas_pantalla - 1].y = -1;
    }
}

bool limites_tocados(posicion pelota) {
    return (pelota.y == LIMITE_INF) || (pelota.y == LIMITE_SUP);
}

void movimiento_pelota(posicion pelota[], inc_unitario inc_pelota[], int pelotas_pantalla) {
    for (int i = 0; i < pelotas_pantalla; i++) {
        pelota[i].x = pelota[i].x + inc_pelota[i].x;
        pelota[i].y = pelota[i].y + inc_pelota[i].y;
    }
}

void inicializar_raqueta(posicion &raqueta) {
    raqueta.x = LIMITE_IZQUIERDA + 1;
    raqueta.y = LIMITE_INF / 2;
}

void pintar_pelota(posicion pelota[], int num_pelotas) {
    for (int i = 0; i < num_pelotas; i++) {
        poner_cursor(pelota[i].x, pelota[i].y);
        cout << PELOTA;
    }
}

void borrar_pelota(posicion pelota[], int num_pelotas) {
    for (int i = 0; i < num_pelotas; i++) {
        poner_cursor(pelota[i].x, pelota[i].y);
        cout << ' ';
    }
}

void pintar_raqueta(posicion raqueta) {
    for (int i = 0; i < TAMANIO_RAQUETA; i++) {
        poner_cursor(raqueta.x, raqueta.y + i);
        cout << RAQUETA;
    }
}

void borrar_raqueta(posicion raqueta) {
    for (int i = 0; i < TAMANIO_RAQUETA; i++) {
        poner_cursor(raqueta.x, raqueta.y + i);
        cout << ' ';
    }
}

void calcular_posicion_raqueta(posicion &raqueta, char tecla) {
    switch (toupper(tecla)) {
        case ARRIBA:
            if (raqueta.y > LIMITE_SUP) {
                raqueta.y--;
            }
            break;
        case ABAJO:
            if (raqueta.y < LIMITE_INF - TAMANIO_RAQUETA) {
                raqueta.y++;
            }
            break;
    }
}

bool rebote_raqueta(posicion pelota[], int num_pelotas, posicion raqueta) {
    for (int i = 0; i < num_pelotas; i++) {
        for (int j = 0; j < TAMANIO_RAQUETA; j++) {
            if (pelota[i].x == raqueta.x && pelota[i].y == raqueta.y + j) {
                return true;
            }
        }
    }
    return false;
}
