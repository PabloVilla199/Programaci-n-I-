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
const int TABULADOR_MES = 5;
const int TABULADOR_INICIAL = 10;
const int TABULADOR_CUOTA = 12;

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

    cout << setw(TABULADOR_MES) << "Mes" << setw(TABULADOR_INICIAL) << "Inicial" << setw(TABULADOR_INICIAL)
         << "Cuota" << setw(TABULADOR_CUOTA) << "Intereses" << setw(TABULADOR_CUOTA)
         << "Amortizado" << setw(TABULADOR_INICIAL) << "Restante" << endl;

    saldo_restante = capital;

    for (int i = 1; i <= meses; ++i) {
         interes = saldo_restante * interes_mensual;
         amortizado = cuota - interes;
         saldo_restante =  saldo_restante - amortizado;

         cout << setw(TABULADOR_MES) << i <<  setw(TABULADOR_INICIAL) << capital<< setw(TABULADOR_INICIAL)
              << cuota << setw(TABULADOR_INICIAL)<< interes << setw(TABULADOR_INICIAL)
              << amortizado << setw(TABULADOR_INICIAL) << saldo_restante << endl;

        capital = saldo_restante;
    }

}
