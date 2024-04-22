#include <iostream>

using namespace std;
const int TICKET = 1;
const int ANADIR_PRODUCTO = 2;
const int LISTAR_TICKET = 3;
const int FIN = 4;
const int MAX_PRODUCTOS = 100;
const int PRODUCTOS_TIENDA = 4;
struct Producto {
    string nombre = " ";
    double precio = 0.0;

};
struct Ticket {
    Producto productos[MAX_PRODUCTOS];
    int numero_productos = 0;
    double precio_ticket = 0.0;
};

void crear_ticket(Ticket& miticket);
void anadir_producto(Ticket& miticket, Producto productosTienda[]);
void listar_productos(Ticket& miticket);


int main(){
    int opcion = 0;
    Ticket miticket;
    Producto productosTienda[4];
    productosTienda[0].nombre = "mandarina";
    productosTienda[1].nombre = "pera";
    productosTienda[2].nombre = "manzana";
    productosTienda[3].nombre = "sandia";

    for(int i = 0; i < 4; i++){
        if (i % 2 == 0){
            productosTienda[i].precio = 1.3;
        }
        else{
            productosTienda[i].precio = 1.2;
        }
    }


    while (opcion != FIN){
        cout << TICKET << "->Crear ticket" << ANADIR_PRODUCTO << "->Añadir producto a ticket "
             << LISTAR_TICKET <<  "->Listar ticket " << FIN << "->Acabar: ";

        cin >> opcion;

        switch(opcion){

            case TICKET:
                crear_ticket(miticket);
                break;

            case ANADIR_PRODUCTO:
                anadir_producto(miticket,productosTienda);
                break;

            case LISTAR_TICKET:
                listar_productos(miticket);
                break;
            case FIN:
                    cout << "Adiosss" << endl;
                break;

            default :
                cout << "opcion incorrecta " << endl;
                break;
        }
    }

}
void crear_ticket(Ticket& miticket){
    miticket.numero_productos = 0;
    miticket.precio_ticket = 0;
    miticket.productos;
    if(miticket.numero_productos == 0 && miticket.precio_ticket == 0.0){
        cout << "Ticket creado" << endl;
        cout << "Numero Productos: " << miticket.numero_productos << endl;
        cout << "Precio del ticket: " << miticket.precio_ticket << endl;
    }
    else{
        cout << "no se ha podido crear correctamente"<< endl;
        cout << "Numero Productos: " << miticket.numero_productos << endl;
        cout << "Precio del ticket: " << miticket.precio_ticket << endl;
    }
}
void anadir_producto(Ticket& miticket, Producto productosTienda[]) {
    string nombre_producto;
    bool encontrado = false;

    cout << "Nombre producto: ";
    cin >> nombre_producto;

    miticket.precio_ticket = 0.0;  // Reiniciar el precio del ticket

    for (int i = 0; i < PRODUCTOS_TIENDA; i++) {
        if (nombre_producto == productosTienda[i].nombre) {
            cout << "Producto añadido" << endl;
            miticket.numero_productos++;
            miticket.productos[miticket.numero_productos - 1] = productosTienda[i];
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "El producto no se encuentra en el super" << endl;
    }
}

void listar_productos( Ticket& miticket) {
    miticket.precio_ticket = 0.0;

    if (miticket.numero_productos > 0) {
        for (int i = 0; i < miticket.numero_productos; i++) {
            cout << "Producto: " << i << endl;
            cout << "Nombre: " << miticket.productos[i].nombre << endl;
            cout << "Precio: " << miticket.productos[i].precio << " EUR" << endl;
            miticket.precio_ticket += miticket.productos[i].precio;
        }
        cout << "TOTAL " << miticket.precio_ticket << " EUR" << endl;
    } else {
        cout << "No hay productos en el ticket." << endl;
    }
}

