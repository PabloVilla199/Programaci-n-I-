#include <iostream>
#include "terminal.h"

using namespace std;
const char SIMBOLO_ESQUINA = '+';
const char SIMBOLO_HORIZONTAL = '-';
const char SIMBOLO_VERTICAL = '|';
const char SIMBOLO_VACIO = ' ';
const int ALTURA_MAQUINA = 20;
const int ANCHO_MAQUINA = 15;
const int ALTURA_PATATAS = 6;
void escribir_linea(const char c_exterior, const char c_interior,const int altura);
void pantalla_maquina();
void escribir_productos(const int altura);



int main()
{

   pantalla_maquina();
   escribir_productos(ALTURA_PATATAS);

}
void pantalla_maquina(){

poner_cursor(2,1);
    cout << " +------------------------ "
            " -------------------------+ " << endl;
    poner_cursor(2,2);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,3);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,4);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,5);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,6);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,7);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,8);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,9);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,10);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,11);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,12);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,13);
    cout << "|                                                                             |" << endl;
    poner_cursor (2,14);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,15);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,16);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,17),
    cout << "|                                                                             |" << endl;
    poner_cursor(2,18);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,19);
    cout << "|                                                                             |" << endl;
    poner_cursor(2,20);
    cout << "+-----------------------------------------------------------------------------+ "<< endl;




}
void escribir_productos(const int altura){


    poner_cursor(5,10);
    escribir_linea(SIMBOLO_ESQUINA,SIMBOLO_HORIZONTAL,ALTURA_PATATAS);
    for(int i = 1; i < ALTURA_PATATAS -1 ; i++){
            poner_cursor(5, 10 +i);
        escribir_linea(SIMBOLO_VERTICAL,SIMBOLO_VACIO,altura);
    }
    poner_cursor(5,altura +1);
    escribir_linea(SIMBOLO_ESQUINA,SIMBOLO_HORIZONTAL,ALTURA_PATATAS);




}
void escribir_linea(const char c_exterior, const char c_interior,const int altura){
    cout << c_exterior;
    for  (int i = 1; i < altura; i++){
        cout << c_interior;
    }
    cout << c_exterior << endl;


}
