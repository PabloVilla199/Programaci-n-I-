/* Daniel Gomollon
 * Ejercicio 1. Trabajo independiente
 * 02/2022
 */

#include <iostream>

using namespace std;

const int MAX_CANCIONES = 200;
const int ANADIR = 1;
const int ELIMINAR = 2;
const int CANCIONES = 3;
const int BUSCAR = 4;
const int FAVORITAS = 5;
const int SALIR = 6;

struct cancion {
	string titulo;
    string artista;
    string genero;
    bool favorita = false;
};

void apuntar_cancion(const cancion cancion);
void leer_alumno(cancion &cancion);
void anadir_cancion(cancion[], int &num_canciones);
void eliminar_cancion(cancion canciones[], int &num_canciones);
void mostrar_canciones(const cancion canciones[], const int num_canciones, const int favoritas);
void mostrar_todas(const cancion canciones[], const int num_canciones);
void mostrar_por_genero(const cancion canciones[], const int num_canciones);
void mostrar_por_artista(const cancion canciones[], const int num_canciones);
void mostrar_favoritas(const cancion canciones[], const int num_canciones, const int favoritas);
void buscar_cancion(const cancion canciones[], const int num_canciones);
void anadir_favorita(cancion canciones[], const int num_canciones, int &favoritas);

int main() {
    cancion canciones[MAX_CANCIONES];
    int num_canciones = 0;
    int opcion = 0;
    
    int favoritas = 0;

    setlocale (LC_ALL,"");

    while(true) {
        cout << "*** Reproductor mp3 1.0 (" << num_canciones << " canciones/s) ***" << endl;
        cout << ANADIR << "->Añadir " << ELIMINAR << "->Eliminar " << CANCIONES 
			 << "->Canciones " << BUSCAR << "->Buscar " << FAVORITAS << "->Favoritas "
			 << SALIR << "->Salir: ";
        cin >> opcion;

        switch(opcion) {
            case ANADIR:
                anadir_cancion(canciones, num_canciones);
                break;
            case ELIMINAR:
            	eliminar_cancion(canciones, num_canciones);
            	break;
            case CANCIONES:	
            	mostrar_canciones(canciones, num_canciones, favoritas);
            	break;
            case BUSCAR:
                buscar_cancion(canciones, num_canciones);
                break;
            case FAVORITAS:
            	anadir_favorita(canciones, num_canciones, favoritas);
				break;
            case SALIR:
                return 0;
            default:
                cout << "Opcion no encontrada." << endl;
        }
    }
}

void apuntar_cancion(const cancion cancion) {

    cout << "Titulo: " << cancion.titulo << endl
         << "Artista: " << cancion.artista << endl
         << "Genero: " << cancion.genero << endl;
}

void leer_datos(cancion &cancion) {

    cout << "Titulo: ";
    cin >> ws;
    getline(cin, cancion.titulo);

    cout << "Artista: ";
    cin >> ws;
    getline(cin, cancion.artista);

    cout << "Genero: ";
    cin >> ws;
    getline(cin, cancion.genero);
}

void anadir_cancion(cancion canciones[], int &num_canciones) {

    if (num_canciones > MAX_CANCIONES) {
        cout << "Máximo de estudiantes superado";

        return;
    }
	leer_datos(canciones[num_canciones]);
    num_canciones++;
}

void mostrar_canciones(const cancion canciones[], const int num_canciones, const int favoritas){
	int opcion = 0;
	
	cout << "\n1-> Mostrar todas las canciones 2-> Mostrar por genero 3-> Mostrar por artista 4-> Mostrar favoritas: ";
	cin >> opcion;
	
	switch(opcion){
		case 1:
			mostrar_todas(canciones, num_canciones);
			break;
		case 2:
			mostrar_por_genero(canciones, num_canciones);
			break;
		case 3:
			mostrar_por_artista(canciones, num_canciones);
			break;
		case 4:
			mostrar_favoritas(canciones, num_canciones, favoritas);
			break;
		default:
			cout << "Opcion no valida.\n";
			break;	
	}
}

void mostrar_todas(const cancion canciones[], const int num_canciones){
	for (int i = 0; i < num_canciones; i++){
		cout << i + 1 << ". " << canciones[i].titulo << " - " << canciones[i].artista << " / " 
			 << canciones[i].genero << "\n\n";
	}
}

void mostrar_por_genero(const cancion canciones[], const int num_canciones){
	string genero_ = "";
	bool cancion_encontrada = false;

    cout << "Genero: ";
    cin >> ws;
    getline(cin, genero_);

    for(int i = 0; i < num_canciones; i++) {
        if ((canciones[i].genero == genero_)){
            cout << i + 1 << ". " << canciones[i].titulo << " - " << canciones[i].artista << "\n\n";
            cancion_encontrada = true;
        }
    }
    if (! cancion_encontrada) {
        cout << "Cancion no encontrada.\n" << endl;
    }
}

void mostrar_por_artista(const cancion canciones[], const int num_canciones){
	string artista_ = "";
	bool cancion_encontrada = false;

    cout << "Artista: ";
    cin >> ws;
    getline(cin, artista_);

    for(int i = 0; i < num_canciones; i++) {
        if ((canciones[i].artista == artista_)){
            cout << i + 1 << ". " << canciones[i].titulo << " / " << canciones[i].genero << "\n\n";
            cancion_encontrada = true;
        }
    }
    if (! cancion_encontrada) {
        cout << "Cancion no encontrada.\n" << endl;
    }
}

void mostrar_favoritas(const cancion canciones[], const int num_canciones, const int favoritas){
	
	for (int i = 0; i < num_canciones; i++){
		if(canciones[i].favorita){
			cout << canciones[i].titulo << " - " << canciones[i].artista << " / " 
				 << canciones[i].genero << " (+)" << endl;
		}
		else if(favoritas == 0){
        	cout << "No hay favoritos todavia.\n" << endl;
		}
	}
}

void anadir_favorita(cancion canciones[], const int num_canciones, int &favoritas) {
    string titulo_ = "";
    bool cancion_encontrada = false;

    cout << "Escribe la cancion para anadirla a favoritos: ";
    cin >> ws;
    getline(cin, titulo_);

    for(int i = 0; i < num_canciones; i++) {
        if (canciones[i].titulo == titulo_){
            
			canciones[i].favorita = true;
            cancion_encontrada = true;
			favoritas++;
            
			cout << "\nLa cancion ha sido añadida a favoritos (" << favoritas << " favoritas)\nNOTA: Aparecera un simbolo que la diferenciara de las demas.\n\n";
        }
    }
    if (! cancion_encontrada) {
        cout << "Cancion no encontrada.\n" << endl;
    }
}

void eliminar_cancion(cancion canciones[], int &num_canciones) {
    string titulo_ = "";

    cout << "Titulo de la cancion: ";
    cin >> ws;
    getline(cin, titulo_);

    for(int i = 0; i < num_canciones; i++) {
        if (canciones[i].titulo == titulo_) {
            canciones[i] = canciones[num_canciones - 1];
            num_canciones--;

            return;
        }
    }
    cout << "Cancion no encontrada.\n" << endl;
}

void buscar_cancion(const cancion canciones[], const int num_canciones) {
    string artista_ = "";
    bool cancion_encontrada = false;

    cout << "Artista: ";
    cin >> ws;
    getline(cin, artista_);

    for(int i = 0; i < num_canciones; i++) {
        if ((canciones[i].artista == artista_)){
            apuntar_cancion(canciones[i]);
            cancion_encontrada = true;
            cout << endl;
        }
    }
    if (! cancion_encontrada) {
        cout << "Cancion no encontrada.\n" << endl;
    }
}
