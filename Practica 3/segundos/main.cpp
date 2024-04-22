/*
* Ejercicios segundos
* Pablo_Villa 28/09/2023
*/
#include <iostream>
const int SEGUNDOS = 60;
const int MINUTOS = 60;
const int HORAS = 24;

using namespace std;

int main() {
    int dias = 0;
    int horas = 0;
    int minutos = 0;
    int segundos = 0;
    int dias_en_segundos = 0;
    int horas_en_segundos = 0;
    int minutos_en_segundos = 0;

    minutos_en_segundos = SEGUNDOS;
    horas_en_segundos = minutos_en_segundos * MINUTOS;
    dias_en_segundos = horas_en_segundos * HORAS;

    cout << "Introduce segundos: ";
    cin >> segundos;

    dias = segundos / dias_en_segundos;
    segundos -= dias * dias_en_segundos;

    horas = segundos / horas_en_segundos;
    segundos -= horas * horas_en_segundos;

    minutos = segundos / minutos_en_segundos;
    segundos -= minutos * minutos_en_segundos;

    cout << dias << " dias" << endl;
    cout << horas << " horas" << endl;
    cout << minutos << " minutos" << endl;
    cout << segundos << " segundos" << endl;

    return 0;
}
