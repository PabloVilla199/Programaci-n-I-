#include <iostream>
 #include <iomanip>


using namespace std;
const int RECTANGULO = 1;
const int CUADRADO = 2;
const int TRIANGULO = 3;
const int FIN = 5;
const char SIMBOLO_ESQUINA = '+';
const char SIMBOLO_INTERMEDIO = ' ';
const char SIMBOLO_HORIZONTAL = '-';
const char SIMBOLO_VERTICAL = '|';

void escribir_linea(const char simbolo_exterior, const char simbolo_interior, const int largo);
void escribir_rectangulo(const int base, const int altura);

int main()
{
  int opcion = 0;
  int altura = 0;
  int base = 0;
  cout << "elige" << endl;
  while(opcion != FIN){
    cin >> opcion;
  switch(opcion) {

    case RECTANGULO:
        cout << "base y altura";
        cin >> base >> altura;
        escribir_rectangulo(base,altura);
       break;

    case CUADRADO:
        cout << "altura";
        cin >> altura;
        //escribir_rectangulo(altura,altura);
         cout << setw(altura) << SIMBOLO_ESQUINA << endl;
        for(int i = 1; i < altura - 1; i++){


           cout <<  setw(altura - i) << SIMBOLO_ESQUINA << setw( 2 * i ) << setfill(SIMBOLO_INTERMEDIO) << SIMBOLO_ESQUINA << endl;
        }
        cout << setw(1) << SIMBOLO_ESQUINA << setfill(SIMBOLO_HORIZONTAL) << setw(altura * 2 -2 ) << SIMBOLO_ESQUINA << endl;

       break;
    case TRIANGULO:
       break;




 }
}
}
void escribir_rectangulo(const int base, const int altura){
  escribir_linea(SIMBOLO_ESQUINA,SIMBOLO_HORIZONTAL,base);

  for(int i = 0; i < altura; i++){
    escribir_linea(SIMBOLO_VERTICAL,SIMBOLO_INTERMEDIO,base);
  }

  escribir_linea(SIMBOLO_ESQUINA,SIMBOLO_HORIZONTAL,base);
}

void escribir_linea(const char simbolo_exterior, const char simbolo_interior, const int largo){

    cout << simbolo_exterior;
    for (int i = 0; i < largo; i++){
            cout << simbolo_interior;
    }
    cout << simbolo_exterior << endl;

}
