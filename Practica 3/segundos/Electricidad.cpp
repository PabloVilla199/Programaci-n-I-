#include <iostream>
#include <iomanip>

using namespace std;
const double POTENCIA = 3,5;
const double CONSUMO_MES = 0,12;
const double IVA = 0,05;
const int NUM_DECIMALES = 2;
int main() {
    double potencia_contratada = 0;
    double consumo_anterior = 0;
    double consumo_actual = 0;
    double coste_potencia = 0;
    double consumo = 0;
    double coste_consumo = 0;
    double tot_sin_iva = 0;
    double iva = 0;
    double total = 0;

    coste_potencia = potencia_contratada * POTENCIA;
    consumo = consumo_actual - consumo_anterior;
    coste_consumo = consumo * CONSUMO_MES;
    tot_sin_iva = coste_consumo + consumo;
    iva = IVA * tot_sin_iva;
    total = iva + tot_sin_iva;


    cout << setprecision(NUM_DECIMALES) << fixed;

    cout << "Potencia contratada (kW), contador mes anterior y mes actual:";
    cin >> potencia_contratada >> consumo_anterior >> consumo_actual;

    cout << "Coste potencia contratada: " << potencia_contratada << " kW x " << POTENCIA
         << " Eur/kW = " << coste_potencia<< "Eur" << endl;

    cout << " Consumo: "consumo_actual << "kWh – " << consumo_anterior "kWh = "
         << consumo << "kWh" << endl;

    cout << "Coste consumo: "<< consumo << " * " << CONSUMO_MES << " Eur/kWh = " << coste_consumo << endl;

    cout << "Total sin IVA: " << tot_sin_iva << "Eur" endl;

    cout << IVA << "% IVA = " << iva << "Eur " << endl;

    cout << "Total: " << total << endl;







}
