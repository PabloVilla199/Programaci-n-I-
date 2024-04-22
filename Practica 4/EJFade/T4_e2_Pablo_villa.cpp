/*
*
*EJ2_p4 Pablo Villa
* 18/10/23
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
const int NUM_DECIMALES = 3;
const int SEPARADOR_MES = 5;
const int SEPARADOR_INICIAL = 10;
const int SEPARADOR_CUOTA = 12;

int main() {
    double capital = 0.0;
    double interes_anual = 0.0;
    double meses = 0.0;
    double interes_mensual = 0.0;
    double cuota = 0.0;
    double saldo_restante = 0.0;
    double interes = 0.0;
    double amortizado = 0.0;

    cout << setprecision(NUM_DECIMALES) << fixed;

    cout << "Introduce capital, interes anual en tanto por ciento y meses: ";
    cin >> capital >> interes_anual >> meses;

    interes_mensual = (interes_anual / 12.0) / 100.0;

    cuota = (capital * interes_mensual) / (1 - pow(1 + interes_mensual, - meses));

    cout << setw(SEPARADOR_MES) << "Mes" << setw(SEPARADOR_INICIAL) << "Inicial" << setw(SEPARADOR_INICIAL)
         << "Cuota" << setw(SEPARADOR_CUOTA) << "Intereses" << setw(SEPARADOR_CUOTA)
         << "Amortizado" << setw(SEPARADOR_INICIAL) << "Restante" << endl;

     saldo_restante = capital;

    for (int i = 1; i <= meses; ++i) {
         interes = saldo_restante * interes_mensual;
         amortizado = cuota - interes;
         saldo_restante =  saldo_restante - amortizado;

        cout << setw(SEPARADOR_MES) << i <<  setw(SEPARADOR_INICIAL) << capital<< setw(SEPARADOR_INICIAL)
             << cuota << setw(SEPARADOR_INICIAL)<< interes << setw(SEPARADOR_INICIAL)
             << amortizado << setw(SEPARADOR_INICIAL) << saldo_restante << endl;

        capital = saldo_restante;
    }

}
