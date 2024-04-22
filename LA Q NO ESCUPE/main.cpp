/*
* Maquina_Tragaperras
* 03/12/22
* Pablo_Villa
*/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_DECIMALES = 2;
const int MONEDA_10_CENTIMOS= 10;
const int MONEDA_20_CENTIMOS = 20;
const int MONEDA_50_CENTIMOS = 50;
const int MONEDA_1_EURO = 1;
const int NUMERO_FIGURAS = 7;
const int NUMERO_LIMON = 1;
const int NUMERO_NARANJA = 2;
const int NUMERO_MANZANA = 3;
const int NUMERO_PLATANO = 4;
const int NUMERO_SANDIA = 5;
const int NUMERO_MELON = 6;
const int NUMERO_JOKER = 7;
const double PRECIO_JUGADA = 100;
const double PREMIO_1 = 1;
const double PREMIO_2 = 20;
const double PREMIO_3 = 100;

const string TITULO = " ****TRAGAPERRAS**** ";
const string FIGURA_LIMON = "limon";
const string FIGURA_NARANJA = "naranja";
const string FIGURA_MANZANA = "manzana";
const string FIGURA_PLATANO = "platano";
const string FIGURA_SANDIA = "sandia";
const string FIGURA_MELON = "melon";
const string FIGURA_JOKER = "joker";
const string MENU_MONEDAS = "Introduce importe en monedas (10 Cts, 20 Cts, 50 Cts, 1 Eur):";

void introducir_importe_monedas(double &importe_total,int importe);
void escribir_premio();
void devolver_cambio(int centimos);
void devolver_cambio_moneda(const int valor, int &centimos);
void dar_premio(string primera_figura,string segunda_figura,string tercera_figura,
                            int &premio,const int &valor);
void combinacion_ganadora (string primera_figura,string segunda_figura,string tercera_figura);
bool moneda_valida(int moneda);
void devolver_premio( const int valor,int &premio);
void devolver_premios(int premio);
void validar_monedas();
string funcion_jugada();

int main(){
    int importe = 0;
    int monedas = 0;
    int centimos = 0;
    int premio = 0;
    double importe_total = 0;
    int valor = 0;

    string primera_figura ="";
    string segunda_figura ="";
    string tercera_figura ="";

    cout << setprecision(NUM_DECIMALES) << fixed;
    setlocale(LC_ALL,"");
    srand(time(NULL));

    cout << TITULO << endl;
    escribir_premio();
    while(true){
        cout << "Importe jugada: " << PRECIO_JUGADA /100<< "Eur"<< endl;
        introducir_importe_monedas(importe_total,importe);
        if (importe_total > PRECIO_JUGADA){
            cout << "Cambio: " << endl;
            devolver_cambio(importe_total - PRECIO_JUGADA);
        }
        primera_figura = funcion_jugada();
        segunda_figura = funcion_jugada();
        tercera_figura = funcion_jugada();
        cout << "\n";
        cout << "La combinaci�n ganadora es: " << "**** "
             << primera_figura<< " "<< segunda_figura << " " << tercera_figura << " "
             << " ****" << endl;
        dar_premio(primera_figura, segunda_figura,tercera_figura,premio,valor);
        importe_total = 0;
        premio = 0;
  }
}
void validar_monedas(){
    cout << MENU_MONEDAS << endl;
}
void escribir_premio(){
 cout << "Premios: " << endl;
 cout << "1 JOKER = " << PREMIO_1 << "Eur" << endl;
 cout << "2 JOKER = " << PREMIO_2 << "Eur" << endl;
 cout << "3 JOKER = " << PREMIO_3 << "Eur" << endl;
 cout << "\n";
}

bool moneda_valida(int moneda){
 return (moneda == MONEDA_10_CENTIMOS || moneda == MONEDA_20_CENTIMOS ||
         moneda == MONEDA_50_CENTIMOS || moneda == MONEDA_1_EURO);
}

void introducir_importe_monedas(double &importe_total, int importe){
 while (importe_total < PRECIO_JUGADA){
   validar_monedas();
   cin >> importe;
   if (moneda_valida(importe)){
     if(importe != MONEDA_1_EURO){
        importe_total = importe_total + importe;
     }
     else{
       importe_total = importe_total + (importe * 100);
     }
   }
   cout << "Introducido: " << importe_total / 100 << "Eur" << endl;
 }
  importe_total = 0;
}
 void devolver_cambio(int centimos){
    devolver_cambio_moneda(100,centimos);
    devolver_cambio_moneda(50, centimos);
    devolver_cambio_moneda(20, centimos);
    devolver_cambio_moneda(10, centimos);
}
void devolver_premios(int premio){
    devolver_premio(1,premio);
    devolver_premio(20,premio);
    devolver_premio(100,premio);
}
void devolver_premio( const int valor,int &premio){
    int monedas = premio / valor;
    premio = premio - monedas*valor;
    cout << monedas << " monedas de " << valor << endl;
}
 void devolver_cambio_moneda(const int valor, int &centimos) {
   int monedas = centimos / valor;
   centimos = centimos - monedas*valor;
   cout << monedas << " monedas de "
        << valor << " cts." << endl;
}
string funcion_jugada(){
 switch (rand()% NUMERO_FIGURAS + 1){
  case NUMERO_JOKER:
   return FIGURA_JOKER;

  case NUMERO_LIMON:
   return FIGURA_LIMON;

  case NUMERO_MANZANA:
   return FIGURA_MANZANA;

  case NUMERO_MELON:
   return FIGURA_MELON;

  case NUMERO_NARANJA:
   return FIGURA_NARANJA;

  case NUMERO_PLATANO:
   return FIGURA_PLATANO;

  case NUMERO_SANDIA:
   return FIGURA_SANDIA;
 }
}

void dar_premio(string primera_figura, string segunda_figura, string
                            tercera_figura, int &premio,const int &centimos){

 if (primera_figura == FIGURA_JOKER && segunda_figura != FIGURA_JOKER &&
     tercera_figura != FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_1 << " Eur" << endl;
    devolver_cambio(PREMIO_1);
 }

 else if (primera_figura != FIGURA_JOKER && segunda_figura == FIGURA_JOKER &&
          tercera_figura != FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_1 << " Eur" << endl;
    devolver_cambio(PREMIO_1);
 }

 else if (primera_figura != FIGURA_JOKER && segunda_figura != FIGURA_JOKER &&
          tercera_figura == FIGURA_JOKER){

   cout << "\n";
   cout << "Has ganado " << PREMIO_1 << " Eur" << endl;
   devolver_cambio(PREMIO_1);
 }

 else if (primera_figura == FIGURA_JOKER && segunda_figura == FIGURA_JOKER &&
          tercera_figura != FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_2 << " Eur" << endl;
    cout << "\n";
    devolver_cambio(PREMIO_2);
 }

else if (primera_figura == FIGURA_JOKER && segunda_figura != FIGURA_JOKER &&
     tercera_figura == FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_2 << " Eur" << endl;
    cout << "\n";
    devolver_cambio(PREMIO_2);
 }

else if (primera_figura != FIGURA_JOKER && segunda_figura == FIGURA_JOKER &&
     tercera_figura == FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_2 << " Eur" << endl;
    cout << "\n";
    devolver_cambio(PREMIO_2);
 }

else if (primera_figura == FIGURA_JOKER && segunda_figura == FIGURA_JOKER &&
     tercera_figura == FIGURA_JOKER){

    cout << "\n";
    cout << "Has ganado " << PREMIO_3 << " Eur" << endl;
    cout << "\n";
    devolver_cambio(PREMIO_3);
 }

else if (primera_figura != FIGURA_JOKER && segunda_figura != FIGURA_JOKER &&
     tercera_figura != FIGURA_JOKER){

    cout << "\n";
    cout << "Lo siento, jugada sin premio" << endl;
    cout << "\n";
 }
 premio = 0;
}
