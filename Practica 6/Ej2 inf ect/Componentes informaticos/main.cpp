/*
*
* Pablo_Villa 874773
* 01/12/23
*
*/

#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int ALTA = 1;
const int BAJA = 2;
const int LISTADO = 3;
const int ENTRADA = 4;
const int SALIDA = 5;
const int BUSCAR = 6;
const int FIN = 7;

struct ProductoAlmacen{
    int codigo = 0;
    string descripcion = "";
    int reserva = 0;
};

void anadir_producto(ProductoAlmacen productos[],int &numero_productos);
void leer_producto(ProductoAlmacen &producto);
void listar_productos(const ProductoAlmacen productos[], int numero_productos);
void anadir(ProductoAlmacen productos[],int &numero_productos);
void eliminar(ProductoAlmacen productos[],int& numero_productos);
void borrar_producto(ProductoAlmacen productos[], int& numero_productos);
void buscar(ProductoAlmacen productos[], int& numero_productos);

int main()
{
  ProductoAlmacen productos[MAX_PRODUCTOS];
  int opcion = 0;
  int numero_productos = 0;

  while(opcion != FIN){
   cout << ALTA << "->Alta " << BAJA << "->Baja " << LISTADO << "->Listado " << ENTRADA
        << "->Entrada " << SALIDA << "->Salida "  << BUSCAR  << "-> Buscar " << FIN <<  "->Acabar: ";

   cin >> opcion;

   switch(opcion){
        case ALTA:
            anadir_producto(productos,numero_productos);
            break;

        case BAJA:
            borrar_producto(productos,numero_productos);
            break;

        case LISTADO:
            listar_productos(productos,numero_productos);
            break;

        case ENTRADA:
            anadir(productos,numero_productos);
            break;

        case SALIDA:
            eliminar(productos,numero_productos);
            break;

        case BUSCAR:
            buscar(productos,numero_productos);
            break;

        case FIN:
            cout << "Fin" << endl;
            break;
   }
 }
}

void leer_producto(ProductoAlmacen &producto){
    cout << "Código : ";
    cin >> producto.codigo;
    cout << "descripción : ";
    cin.ignore();
    getline(cin, producto.descripcion);
    cout << "reserva : ";
    cin >> producto.reserva;
}

void anadir_producto(ProductoAlmacen producto[],int &numero_productos){

    if (numero_productos > MAX_PRODUCTOS){
        cout << "número máximo de productos" << endl;
    }
    else {
        leer_producto(producto[numero_productos]);
        numero_productos++;
    }
}

void borrar_producto(ProductoAlmacen producto[], int& numero_productos){
    int codigo = 0;
    bool encontrado = false;

    cout << "Introduce un código de un producto que desees eliminar ";
    cin >> codigo;

    for (int i = 0; i < numero_productos; i++){
        if(codigo == producto[i].codigo){
            encontrado = true;
            producto[i] = producto[numero_productos - 1];
            numero_productos--;
            cout << "Producto eliminado" << endl;
        }
    }
    if(! encontrado){
        cout << "Producto no encontrado" << endl;
    }
}
void mostrar_producto(const ProductoAlmacen& producto){

        cout << "Codigo: ";
        cout << producto.codigo << endl;
        cout << "Descripcion: ";
        cout << producto.descripcion << endl;
        cout << "Reservas: ";
        cout << producto.reserva << endl;
}

void listar_productos(const ProductoAlmacen producto[], int numero_productos){
    for (int i = 0; i < numero_productos; i++){
        mostrar_producto(producto[i]);
    }
}

void anadir(ProductoAlmacen Producto[],int &numero_productos){
    int codigo = 0;
    int reserva = 0;
    bool encontrado = false;

    cout << "codigo: ";
    cin >> codigo;
    cout << "Añadir existencias: ";
    cin >> reserva;

    for (int i = 0; i < numero_productos; i++){

      if(codigo == Producto[i].codigo){
        Producto[i].reserva += reserva;
        encontrado = true;

        cout << "Se han almacenado ("<< Producto[i].reserva << ") de "
             << Producto[i].descripcion << " con código " << Producto[i].codigo << endl;
      }
    }
    if( ! encontrado){
        cout << " No se ha encontrado ningun código en el almacén" << endl;
    }
}

void eliminar(ProductoAlmacen Producto[],int &numero_productos){
    int codigo = 0;
    int reserva = 0;
    bool encontrado = false;

    cout << "Codigo: ";
    cin >> codigo;
    cout << "Eliminar reserva: ";
    cin >> reserva;

    for (int i = 0; i < numero_productos; i++){
      if(codigo == Producto[i].codigo){
        Producto[i].reserva -= reserva;
        encontrado = true;

        cout << "Se han retirado ("<< Producto[i].reserva << ") de "
             << Producto[i].descripcion << " con codigo " << Producto[i].codigo << endl;
      }
    }
    if( ! encontrado){
        cout << " No se ha encontrado ningun codigo en el almacen" << endl;
    }
}

void buscar(ProductoAlmacen producto[], int& numero_productos){
    int codigo = 0;
    bool encontrado = false;

    cout << "Introduce un codigo que desees buscar ";
    cin >> codigo;
    for (int i = 0; i < numero_productos; i++){
        if(codigo == producto[i].codigo){
            encontrado = true;
            mostrar_producto(producto[i]);
    }
 }
 if(! encontrado){
    cout << "Producto no encontrado" << endl;
 }
}
