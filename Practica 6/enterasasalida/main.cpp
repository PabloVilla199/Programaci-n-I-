#include <iostream>
#include <fstream>
using namespace std;

const int MAX_COMPONENTES = 100;
const int ALTA = 1;
const int BAJA = 2;
const int LISTADO = 3;
const int ENTRADA = 4;
const int SALIDA = 5;
const int BUSCAR = 6;
const int FIN = 7;

struct componente {
    int codigo = 0;
    string descripcion = "";
    int existencias = 0;
};

void anadir_componente(componente componentes[], int &numero_componentes);
void leer_componente(componente &comp);
void listar_componentes(componente componentes[], int numero_componentes);
void anadir(componente componentes[], int &numero_componentes);
void eliminar(componente componentes[], int &numero_componentes);
void borrar_componente(componente componentes[], int &numero_componentes);
void buscar(componente componentes[], int &numero_componentes);
int busqueda(componente componentes[], int codigo, int numero_componentes);
void cargar_datos_desde_archivo(componente componentes[], int &numero_componentes);
void guardar_datos_en_archivo(componente componentes[], int numero_componentes);

const string NOMBRE_ARCHIVO = "datos_componentes.txt";

int main(){
    componente componentes[MAX_COMPONENTES];
    int opcion = 0;
    int numero_componentes = 0;

    cargar_datos_desde_archivo(componentes, numero_componentes);

    while(opcion != FIN){
        cout << ALTA << "->Alta " << BAJA << "->Baja " << LISTADO << "->Listado " << ENTRADA
             << "->Entrada " << SALIDA << "->Salida " << BUSCAR << "-> Buscar " << FIN << "->Acabar: ";

        cin >> opcion;

        switch(opcion){
            case ALTA:
                anadir_componente(componentes, numero_componentes);
                break;

            case BAJA:
                borrar_componente(componentes, numero_componentes);
                break;

            case LISTADO:
                listar_componentes(componentes, numero_componentes);
                break;

            case ENTRADA:
                anadir(componentes, numero_componentes);
                break;

            case SALIDA:
                eliminar(componentes, numero_componentes);
                break;

            case BUSCAR:
                buscar(componentes, numero_componentes);
                break;

            case FIN:
                guardar_datos_en_archivo(componentes, numero_componentes);
                cout << "Fin" << endl;
                break;
        }
    }

    return 0;
}

void leer_componente(componente &comp){
    cout << "Código : ";
    cin >> comp.codigo;
    cout << "Descripción : ";
    cin.ignore();
    getline(cin, comp.descripcion);
    cout << "Existencias : ";
    cin >> comp.existencias;
}

void anadir_componente(componente componentes[], int &numero_componentes){
    if (numero_componentes >= MAX_COMPONENTES){
        cout << "Número máximo de componentes alcanzado" << endl;
    } else {
        leer_componente(componentes[numero_componentes]);
        numero_componentes++;
    }
}

void borrar_componente(componente componentes[], int &numero_componentes){
    int codigo = 0;
    bool encontrado = false;

    cout << "Introduce un código de un componente que desees eliminar: ";
    cin >> codigo;

    int posicion = busqueda(componentes, codigo, numero_componentes);

    if (posicion != -1) {
        componentes[posicion] = componentes[numero_componentes - 1];
        numero_componentes--;
        cout << "Componente eliminado" << endl;
    } else {
        cout << "Componente no encontrado" << endl;
    }
}

void mostrar_componente(const componente &comp){
    cout << "Codigo: " << comp.codigo << endl;
    cout << "Descripcion: " << comp.descripcion << endl;
    cout << "Existencias: " << comp.existencias << endl;
}

void listar_componentes(componente componentes[], int numero_componentes){
    for (int i = 0; i < numero_componentes; i++){
        mostrar_componente(componentes[i]);
    }
}

void anadir(componente componentes[], int &numero_componentes){
    int codigo = 0;
    int existencias = 0;
    componente comp_inc_existencias;
    cout << "Codigo: ";
    cin >> codigo;
    cout << "Añadir existencias: ";
    cin >> existencias;

    int posicion = busqueda(componentes, codigo, numero_componentes);

    if (posicion != -1) {
        componentes[posicion].existencias += existencias;
        cout << "Se han almacenado (" << existencias << ") de "
             << componentes[posicion].descripcion << " con código " << componentes[posicion].codigo << endl;
    } else {
        cout << "El código introducido no corresponde con ningún componente." << endl;
    }
}

void eliminar(componente componentes[], int &numero_componentes){
    int codigo = 0;
    int existencias = 0;
    componente comp_eliminar_existencia;
    cout << "Codigo: ";
    cin >> codigo;
    cout << "Eliminar existencias: ";
    cin >> existencias;

    int posicion = busqueda(componentes, codigo, numero_componentes);

    if (posicion != -1) {
        componentes[posicion].existencias -= existencias;
        cout << "Se han retirado (" << existencias << ") de "
             << componentes[posicion].descripcion << " con código " << componentes[posicion].codigo << endl;
    } else {
        cout << "El código introducido no corresponde con ningún componente." << endl;
    }
}

void buscar(componente componentes[], int &numero_componentes){
    int codigo = 0;
    cout << "Introduce un código que desees buscar: ";
    cin >> codigo;

    int posicion = busqueda(componentes, codigo, numero_componentes);

    if(posicion == -1){
        cout << "El código introducido no corresponde a ningún componente" << endl;
    } else {
        mostrar_componente(componentes[posicion]);
    }
}

int busqueda(componente componentes[], int codigo, int numero_componentes){
    for (int i = 0; i < numero_componentes; i++){
        if(codigo == componentes[i].codigo){
            return i;  // Devolver la posición del elemento encontrado
        }
    }
    return -1;  // Devolver -1 si no se encuentra el elemento
}

void cargar_datos_desde_archivo(componente componentes[], int &numero_componentes){
    ifstream archivo(NOMBRE_ARCHIVO);

    if (archivo.is_open()){
        while (!archivo.eof() && numero_componentes < MAX_COMPONENTES){
            archivo >> componentes[numero_componentes].codigo;
            archivo.ignore(); // Ignorar el espacio después del código
            getline(archivo, componentes[numero_componentes].descripcion);
            archivo >> componentes[numero_componentes].existencias;
            numero_componentes++;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar datos." << endl;
    }
}
void guardar_datos_en_archivo(componente componentes[], int numero_componentes){
    ofstream archivo(NOMBRE_ARCHIVO);

    if (archivo.is_open()){
        for (int i = 0; i < numero_componentes; i++){
            archivo << componentes[i].codigo << " " << componentes[i].descripcion << " "
                    << componentes[i].existencias << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar datos." << endl;
    }
}

