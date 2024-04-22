/*
 * Pablo_Villa 874773
 * 01/12/23
 */

#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int PRODUCTO_NO_ENCONTRADO = -1;
const int ALTA = 1;
const int BAJA = 2;
const int LISTADO = 3;
const int ENTRADA = 4;
const int SALIDA = 5;
const int BUSCAR = 6;
const int FIN = 7;

struct producto_almacen {
    int codigo = 0;
    string descripcion = "";
    int existencias = 0;
};

void anadir_producto(producto_almacen productos[], int &numero_productos);
void leer_producto(producto_almacen &producto);
void listar_productos(producto_almacen productos[], int numero_productos);
void anadir(producto_almacen productos[], int &numero_productos);
void eliminar(producto_almacen productos[], int &numero_productos);
void borrar_producto(producto_almacen productos[], int &numero_productos);
void buscar(producto_almacen productos[], int &numero_productos);
int busqueda(const producto_almacen productos[], int codigo, int numero_productos);
void cargar_datos_desde_archivo(componente componentes[], int &numero_componentes);
void guardar_datos_en_archivo(componente componentes[], int numero_componentes);

const string NOMBRE_ARCHIVO = "datos_componentes.txt";

int main(){
    producto_almacen productos[MAX_PRODUCTOS];
    int opcion = 0;
    int numero_productos = 0;

    cargar_datos_desde_archivo(componentes, numero_componentes);

    while(opcion != FIN){
        cout << ALTA << "->Alta " << BAJA << "->Baja " << LISTADO << "->Listado " << ENTRADA
             << "->Entrada " << SALIDA << "->Salida " << BUSCAR << "-> Buscar " << FIN << "->Acabar: ";

        cin >> opcion;

        switch(opcion){
            case ALTA:
                anadir_producto(productos, numero_productos);
                break;

            case BAJA:
                borrar_producto(productos, numero_productos);
                break;

            case LISTADO:
                listar_productos(productos, numero_productos);
                break;

            case ENTRADA:
                anadir(productos, numero_productos);
                break;

            case SALIDA:
                eliminar(productos, numero_productos);
                break;

            case BUSCAR:
                buscar(productos, numero_productos);
                break;

            case FIN:
                guardar_datos_en_archivo(componentes, numero_componentes);
                cout << "Fin" << endl;
                break;
        }
    }
}

void leer_producto(producto_almacen &producto){
    cout << "Código : ";
    cin >> producto.codigo;
    cout << "Descripción : ";
    cin.ignore();
    getline(cin, producto.descripcion);
    cout << "Existencias : ";
    cin >> producto.existencias;
}

void anadir_producto(producto_almacen productos[], int &numero_productos){
    if (numero_productos > MAX_PRODUCTOS){
        cout << "Número máximo de productos" << endl;
    } else {
        leer_producto(productos[numero_productos]);
        numero_productos++;
    }
}

void borrar_producto(producto_almacen productos[], int &numero_productos){
    int codigo = 0;
    int posicion = 0;
    cout << "Introduce un código de un producto que desees eliminar ";
    cin >> codigo;


    posicion = busqueda(productos, codigo, numero_productos);
    if (posicion != PRODUCTO_NO_ENCONTRADO) {
        productos[posicion] = productos[numero_productos - 1];
        numero_productos--;
        cout << "Producto eliminado" << endl;
    }
    else {
        cout << "Producto no encontrado" << endl;
    }
}

void mostrar_producto(const producto_almacen &producto){
    cout << "Codigo: ";
    cout << producto.codigo << endl;
    cout << "Descripcion: ";
    cout << producto.descripcion << endl;
    cout << "Existencias: ";
    cout << producto.existencias << endl;
}

void listar_productos(producto_almacen productos[], int numero_productos){
    for (int i = 0; i < numero_productos; i++){
        mostrar_producto(productos[i]);
    }
}

void anadir(producto_almacen productos[], int &numero_productos){
    int codigo = 0;
    int existencias = 0;
    bool encontrado = false;
    int posicion = 0;

    cout << "codigo: ";
    cin >> codigo;
    cout << "Añadir existencias: ";
    cin >> existencias;

    posicion = busqueda(productos, codigo, numero_productos);
    if (posicion == PRODUCTO_NO_ENCONTRADO) {
        cout << "El código introducido no corresponde con ningún producto." << endl;
    } else {
        productos[posicion].existencias =  productos[posicion].existencias + existencias;
        cout << "Se han almacenado (" << existencias << ") de "
             << productos[posicion].descripcion << " con código " << productos[posicion].codigo << endl;
    }
}

void eliminar(producto_almacen productos[], int &numero_productos){
    int codigo = 0;
    int existencias = 0;
    bool encontrado = false;
    int posicion = 0;

    cout << "Codigo: ";
    cin >> codigo;
    cout << "Eliminar existencias: ";
    cin >> existencias;

    posicion = busqueda(productos, codigo, numero_productos);
    if (posicion == PRODUCTO_NO_ENCONTRADO) {
        cout << "El código introducido no corresponde con ningún producto." << endl;
    } else {
        productos[posicion].existencias -= existencias;
        cout << "Se han retirado (" << existencias << ") de "
             << productos[posicion].descripcion << " con código " << productos[posicion].codigo << endl;
    }
}

void buscar(producto_almacen productos[], int &numero_productos){
    int codigo = 0;
    int posicion = 0;
    cout << "Introduce un código que desees buscar ";
    cin >> codigo;

    posicion = busqueda(productos, codigo, numero_productos);
    if(posicion == PRODUCTO_NO_ENCONTRADO){
        cout << "El código introducido no corresponde a ningún producto" << endl;
    } else {
        mostrar_producto(productos[posicion]);
    }
}

int busqueda(const producto_almacen productos[], int codigo, int numero_productos){
    for (int i = 0; i < numero_productos; i++){
        if(codigo == productos[i].codigo){
            return i;
        }
    }
    return PRODUCTO_NO_ENCONTRADO;
}

void cargar_datos_desde_archivo(componente componentes[], int &numero_componentes){
    ifstream archivo(NOMBRE_ARCHIVO);

    if (archivo.is_open()){
        while (!archivo.eof() && numero_componentes < MAX_COMPONENTES){
            archivo >> componentes[numero_componentes].codigo;
            archivo.ignore();
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
