/*
*
* Pablo_Villa 874773
* 01/12/23
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_COCHES = 50;
const int ENTRADA = 1;
const int POSICION_NULA = -1;
const int SALIDA = 2;
const int OCUPACION = 3;
const int RANGO_ALEATORIO = 35;
const double PRECIO_POR_TIEMPO = 0.065;

struct plaza_Parking{
    string matricula;
    string tiempo;
    double ticket = 0;
};

void anadir_coche(plaza_Parking parking[],int &numero_coches);
void leer_coche(plaza_Parking &parking);
void listar_coches(const plaza_Parking parking[], int numero_coches);
void borrar_coche(plaza_Parking parking[], int& numero_coches);
void buscar(plaza_Parking parking[], int& numero_coches);
int busqueda(const plaza_Parking parking [], string matricula, int numero_coches);

int main(){

  plaza_Parking parking [MAX_COCHES];
  int opcion = 0;
  int numero_coches = 0;
  srand(time(0));

  while(opcion != 8){
   cout << ENTRADA << "->entrada " << SALIDA << "-> salida " << OCUPACION << "->ocupacion : ";
   cin >> opcion;

      switch(opcion){
        case ENTRADA:
            anadir_coche(parking,numero_coches);
            break;

        case SALIDA:
            borrar_coche(parking,numero_coches);
            break;

        case OCUPACION:
            listar_coches(parking,numero_coches);
            break;
    }
  }
}

void leer_coche(plaza_Parking &parking){
    cout << "Matricula : ";
    cin >> parking.matricula;
    cout << "Tiempo : ";
    cin.ignore();
    getline(cin,parking.tiempo);
    if(parking.tiempo != "0"){
        cout << "tiempo valido" << endl;
    }
    else{
        parking.tiempo = nullptr;
    }
}

void anadir_coche(plaza_Parking parking[],int &numero_coches){
    string matricula;
    int posicion = 0;

    if (numero_coches > MAX_COCHES){
        cout << "número máximo de coches" << endl;
    }
    else {
        cout << "Introduce la matricula: ";
        cin >> matricula;
        posicion = busqueda(parking,matricula,numero_coches);

        if(posicion == POSICION_NULA){
            cout << "vuelva a introducir los datos " << endl;
            leer_coche(parking[numero_coches]);
            numero_coches++;
        }
        else{
            cout << "matricula repetida" << endl;
        }

    }
}

void borrar_coche(plaza_Parking parking[], int& numero_coches){
    string  matricula;
    int posicion = 0;
    int costo = 0;

    cout << "Introduce un coche que desees eliminar ";
    cin >> matricula;
    posicion = busqueda(parking,matricula,numero_coches);

    if(posicion != POSICION_NULA){
        costo =  1 + rand()% (RANGO_ALEATORIO - 4);
        parking[posicion].ticket = PRECIO_POR_TIEMPO * costo;

        cout << "TICKET: ";
        cout << parking[posicion].ticket << endl;

        parking[posicion] = parking[numero_coches - 1];
        numero_coches--;
    }
    else{
        cout << "matricula no encontrada" << endl;
    }
}
void mostrar_coche(const plaza_Parking& parking){

        cout << "matricula: ";
        cout << parking.matricula << endl;
        cout << "Hora: ";
        cout << parking.tiempo << endl;
}

void listar_coches(const plaza_Parking parking [], int numero_coches){
    for (int i = 0; i < numero_coches; i++){
        mostrar_coche(parking[i]);
        cout << endl;
    }
}

 int busqueda(const plaza_Parking parking [], string matricula , int numero_coches){
    for (int i = 0; i < numero_coches; i++){
        if(matricula == parking[i].matricula){
            return i;
        }
    }
    return POSICION_NULA;
 }
