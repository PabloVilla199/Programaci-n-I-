#include <iostream>

using namespace std;
const double Cocacola = 1.20;
const double FANTA = 1.30;
const double NESTEA = 1.70;

void devolver_cambios_moneda(const int valor, int& centimos);
void devolver_cambios(int centimos);

int main()
{
  int importe = 0;
  int opcion = 0;
  int cambios = 0;
  cout << "opcion";
  cin >> opcion;
  switch(opcion){
   case 1:
       cout << "Importe";
       cin >> importe;
       cout << "devolver cambios" << endl;
       cambios = importe - Cocacola;
       devolver_cambios(cambios);
       break;
   case 2:
     break;
   case 3:
    break;



  }
}
void devolver_cambios_moneda(const int valor, int& centimos){


 int moneda = centimos / valor;
 centimos = centimos - moneda * valor;
 cout << moneda << " monedas de " << valor << " cts." << endl;


}
void devolver_cambios(int centimos){

 devolver_cambios_moneda(50,centimos);
 devolver_cambios_moneda(20,centimos);
 devolver_cambios_moneda(10,centimos);
 devolver_cambios_moneda(5,centimos);


}
