/*
* Pablo Villa 874773
* 09/11/23
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const string GANA_ORDENADOR = "Ordenador";
const string EMPATE = "Empate";
const string GANA_USUARIO = "Usuario";
const string OPCION_PIEDRA = "piedra";
const string OPCION_PAPEL = "papel";
const string OPCION_TIJERA = "tijera";
const int OPCIONES = 3;

string eleccion_usuario();
string eleccion_ordenador();
void mostrar_eleccion(string jugador);
string obtener_ganador_ronda(string jugador, string ordenador, int& aciertos);
void mostrar_ganador_ronda(string jugador, string ordenador , int aciertos);
void declarar_ganador(int aciertos, int rondas);

int main() {
    string nombre = "";
    int rondas = 0;
    int aciertos = 0;
    string jugada_usuario = "";
    string jugada_ordenador = "";

    srand(time(0));
    setlocale(LC_ALL, "");

    cout << "**** Juego de Piedra, papel o tijeras ****" << endl;
    cout << "PIEDRA => " << OPCION_PIEDRA << " PAPEL => "
         << OPCION_PAPEL << " TIJERAS => " << OPCION_TIJERA << endl;
    cout << "Nombre jugador: ";
    cin >> nombre;
    cout << "Número de jugadas a realizar: ";
    cin >> rondas;

    for (int ronda = 1; ronda <= rondas; ronda++) {
        cout << endl;
        cout << "Introduce tu Jugada " << ronda << ": ";
        jugada_usuario = eleccion_usuario();
        mostrar_eleccion(jugada_usuario);
        jugada_ordenador = eleccion_ordenador();
        obtener_ganador_ronda(jugada_usuario,jugada_ordenador,aciertos);
        mostrar_ganador_ronda(jugada_usuario, jugada_ordenador,aciertos);
    }
    cout << endl;
    cout << nombre;
    declarar_ganador(aciertos, rondas);

}

string eleccion_usuario() {
    string jugada_usuario = "";
    bool jugada_valida = false;

    while ( ! jugada_valida) {
        cin >> jugada_usuario;

        if (jugada_usuario == OPCION_PIEDRA || jugada_usuario == OPCION_PAPEL ||
            jugada_usuario == OPCION_TIJERA) {

            cout << "Tu jugada es : " << jugada_usuario << " es válida" << endl;
            jugada_valida = true;
        } else {
            cout << "Jugada no válida. Repítela." << endl;
        }
    }

    return jugada_usuario;
}

string eleccion_ordenador() {
    int num_aleatorio = 0;
    num_aleatorio = rand() % OPCIONES;
    cout << "El ordenador juega";

    switch (num_aleatorio) {
        case 0:
            cout << " piedra"<< endl;
            return OPCION_PIEDRA;

        case 1:
            cout << " papel"<< endl;
            return OPCION_PAPEL;

        case 2:
            cout << " tijera" << endl;
            return OPCION_TIJERA;
    }
}

void mostrar_eleccion(string jugador) {
    cout << "El usario juega " << jugador  <<endl;
}

string obtener_ganador_ronda(string jugador, string ordenador, int &aciertos) {
    if (jugador == ordenador) {
        return EMPATE;
    } else if ((jugador == OPCION_PIEDRA && ordenador == OPCION_TIJERA) ||
               (jugador == OPCION_PAPEL && ordenador == OPCION_PIEDRA) ||
               (jugador == OPCION_TIJERA && ordenador == OPCION_PAPEL)) {

        aciertos++;
        return GANA_USUARIO;
    } else {
        return GANA_ORDENADOR;
    }
}

void mostrar_ganador_ronda(string jugador, string ordenador,int aciertos) {

    string resultado = obtener_ganador_ronda(jugador, ordenador,aciertos);
    cout << "Resultado: ";

    if (resultado == EMPATE) {
        cout << "Es un empate" << endl;
    } else if (resultado == GANA_USUARIO) {
        cout << "¡Ganaste esta ronda!" << endl;
    } else {
        cout << "El ordenador gana esta ronda." << endl;
    }
}

void declarar_ganador(int aciertos, int rondas) {
    if (aciertos > rondas / 2) {
        cout << " Después de " << rondas << " jugadas, ganas tú" << endl;
    } else {
        cout << " Después de " << rondas << " jugadas, gana el ordenador" << endl;
    }
}
