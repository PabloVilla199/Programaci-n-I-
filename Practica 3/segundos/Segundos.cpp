/*
* Ejercicios segundos
* Pablo_Villa 28/09/2023
*/

#include <iostream>

using namespace std;

const int DIA = 86400;
const int HORA = 3600;
const int MINUTOS = 60;

int main() {
    int dias = 0;
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    cout << "Introduce segundos: ";
    cin >> segundos;

    dias = segundos / DIA;
    segundos %= DIA;

    horas = segundos / HORA;
    segundos %= HORA;

    minutos = segundos / MINUTOS;
    segundos %= MINUTOS;

    cout << dias << " dias" << endl;
    cout << horas << " horas" << endl;
    cout << minutos << " minutos" << endl;
    cout << segundos << " segundos" << endl;

}
