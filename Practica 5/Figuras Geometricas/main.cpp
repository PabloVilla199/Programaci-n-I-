/*
* Pablo Villa 874773
* 08/11/23
*/
#include <iostream>
 #include <iomanip>

using namespace std;
const int RECTANGULO = 1;
const int CUADRADO = 2;
const int TRIANGULO = 3;
const int FIN = 4;
const char SIMBOLO_EXTERIOR = '+';
const char SIMBOLO_HORIZONTAl = '-';
const char SIMBOLO_INTERMEDIO = ' ';
const char SIMBOLO_VERTICAL = '|';
const char SIMBOLO_PIRAMIDE = '*';

void dibujar_linea(const char c_exterior, const char c_interior, const int largo);
void dibujar_triangulo(const char altura);
void dibujar_rectangulo(const int base, const int altura);
bool medidas_validas(const int base ,const int altura);

int main(){

    int opcion = 0;
    int base = 0;
    int altura = 0;
    cout << "**** Dibujo de figuras geométricas ****" << endl;
    while (opcion != FIN){
        cout << RECTANGULO << "->Rectángulo" << CUADRADO << "->Cuadrado "
             << TRIANGULO << "->Triángulo " << FIN << "->Acabar: "<< endl;
        cin >> opcion;

        switch(opcion){
            case RECTANGULO:
                cout << "Introduce la altura y la base del rectangulo positivas: ";
                cin >> altura >> base;
                if(medidas_validas(altura, base)){
                   dibujar_rectangulo(base, altura);
                }
                else{
                    cout << "base o altura no positivas" << endl;
                }
              break;

            case CUADRADO:
                cout << "Introduce la altura del cuadrado: ";
                cin >> altura;
                if (medidas_validas(altura, altura)){
                    dibujar_rectangulo(altura, altura);
                }
                else{
                    cout << "base o altura no positivas" << endl;
                }
             break;

            case TRIANGULO:
                cout << "Introduce la altura del triángulo: ";
                cin >> altura;
                if (medidas_validas(altura, altura)){
                    dibujar_triangulo(altura);
                }
                else{
                    cout << "base o altura no positivas" << endl;
                }
             break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    }
}
void dibujar_linea(const char c_exterior, const char c_interior, const int largo){
    cout << c_exterior;
    for(int i = 0; i < largo - 2; i++){
        cout << c_interior;
    }
    cout << c_exterior << endl;
}

void dibujar_rectangulo(const int base, const int altura){
    dibujar_linea(SIMBOLO_EXTERIOR,SIMBOLO_HORIZONTAl,base);
    for (int i = 0; i < altura -2; i++){
        dibujar_linea(SIMBOLO_VERTICAL,SIMBOLO_INTERMEDIO,base);
    }
    dibujar_linea(SIMBOLO_EXTERIOR,SIMBOLO_HORIZONTAl,base);
}

void dibujar_triangulo(const char altura){
    cout << setw(altura) << SIMBOLO_EXTERIOR << endl;
    for(int i = 1; i < altura - 1; i++){
        cout << setw(altura - i) << SIMBOLO_EXTERIOR << setw( 2 * i )
             << SIMBOLO_EXTERIOR << endl;
    }
    cout << setw(1) << SIMBOLO_EXTERIOR << setw(altura * 2 -2 )
         << setfill(SIMBOLO_HORIZONTAl) << SIMBOLO_EXTERIOR << endl;
}
bool medidas_validas(const int base, const int altura){
     return( base > 0 && altura > 0);
}

