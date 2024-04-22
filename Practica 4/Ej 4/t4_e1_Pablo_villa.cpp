/*
* Secuencia inicial y final
* Pablo Villa 18/10/23
*
*/
#include <iostream>

using namespace std;
const int FIN_SECUENCIA = 0;

int main()
{

    int buscado = 0;
    int numero_actual = 0;
    int posicion_inicial = 0;
    int posicion_final = 0;
    int posicion = 0;
    bool encontrado = false;

    cout << "Introduce el buscado: ";
    cin >> buscado;

    cout << "Introduce secuencia: ";
    cin >> numero_actual;

    while(numero_actual!= FIN_SECUENCIA){
        posicion++;
        if(numero_actual == buscado){
            if(posicion_inicial == 0){
                posicion_inicial = posicion;
                encontrado = true;
            }
            posicion_final = posicion;
        }
        cin >> numero_actual;
    }
    if (encontrado){
        cout << "Posición inicial: " <<  posicion_inicial
             <<  " Posición final " << posicion_final;

    }
    else {
       cout << "Número no encontrado" << endl;

    }
}
