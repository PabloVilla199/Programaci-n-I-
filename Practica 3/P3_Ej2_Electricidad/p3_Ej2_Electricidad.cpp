/*
* EJercicio Electricidad
* Pablo_Villa 28/09/2023
*/

#include <iostream>
#include <iomanip>

using namespace std;

const double POTENCIA = 3.5;
const double COSTO_CONSUMO_KWH = 0.12;
const double IVA = 0.05;
const int NUM_DECIMALES = 2;

int main() {
    double potencia_contratada = 0;
    double consumo_anterior = 0;
    double consumo_actual = 0;
    double coste_potencia = 0;
    double consumo = 0;
    double coste_consumo = 0;
    double total_sin_iva = 0;
    double iva = 0;
    double total = 0;

    cout << setprecision(NUM_DECIMALES) << fixed;

    cout << "Potencia contratada (kW), contador mes anterior y mes actual:";
    cin >> potencia_contratada >> consumo_anterior >> consumo_actual;

    coste_potencia = potencia_contratada * POTENCIA;
    consumo = consumo_actual - consumo_anterior;
    coste_consumo = consumo * COSTO_CONSUMO_KWH ;
    total_sin_iva= coste_consumo + coste_potencia;
    iva = IVA * total_sin_iva;
    total = iva + total_sin_iva;

    cout << "Coste potencia contratada: " << potencia_contratada << " kW x " << POTENCIA
         << " Eur/kW = " << coste_potencia << " Eur" << endl;

    cout << "Consumo: " << consumo_actual << " kWh  - " << consumo_anterior << " kWh = "
         << consumo << " kWh" << endl;
    cout << "Coste consumo: " << consumo << " * " << COSTO_CONSUMO_KWH  << " Eur/kWh = " << coste_consumo << " Eur" << endl;

    cout << "Total sin IVA: " << total_sin_iva << " Eur" << endl;

    cout << IVA * 100 << "% IVA = " << iva << " Eur " << endl;

    cout << "Total: " << total << " Eur" << endl;

}
