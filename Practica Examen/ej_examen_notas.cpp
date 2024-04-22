/* Daniel Gomollon
 * Ejercicio 1. Trabajo 7
 * 02/2022
 */

#include <iostream>

using namespace std;

const int MAX_ALUMNOS = 50;
const int NUEVO_ALUMNO = 1;
const int LISTAR = 2;
const int PONER_NOTA = 3;
const int ESTADISTICA = 4;
const int SALIR = 5;

struct alumno {
    string nombre;
    string apellido1;
    string apellido2;
    double nota;
};

void apuntar_alumno(const alumno alumno);
void leer_alumno(alumno &alumno);
void incluir_alumno(alumno alumnos[], int &num_alumnos);
void listar_alumno(const alumno alumnos[], const int alumnos_presentados);
void poner_nota(alumno alumnos[], const int num_alumnos, int &alumnos_presentados);
void calcular_datos(alumno alumnos[], int alumnos_presentados, int &aprobados, 
					int &notables, int &sobresalientes, double &suma);
void mostrar_estadistica(const int num_alumnos, const int alumnos_presentados, const int aprobados, 
						 const int notables, const int sobresalientes, const double suma);

int main() {
    alumno alumnos[MAX_ALUMNOS];
    int num_alumnos = 0;
    int opcion = 0;
    
    int alumnos_presentados = 0;
    int aprobados = 0;
    int notables= 0;
    int sobresalientes = 0;
    double suma = 0;

    setlocale (LC_ALL,"");

    while(true) {
        cout << "*** Notas 1.0 (" << num_alumnos << " estudiante/s) ***" << endl;
        cout << NUEVO_ALUMNO << "->Nuevo estudiante " << LISTAR << "->Listar "
             << PONER_NOTA << "->Poner nota " << ESTADISTICA << "->Estadistica "
			 << SALIR << "->Salir: ";
        cin >> opcion;

        switch(opcion) {
            case NUEVO_ALUMNO:
                incluir_alumno(alumnos, num_alumnos);
                break;
            case LISTAR:
            	listar_alumno(alumnos, alumnos_presentados);
            	break;
            case PONER_NOTA:
                poner_nota(alumnos, num_alumnos, alumnos_presentados);
                break;
            case ESTADISTICA:
            	calcular_datos(alumnos, alumnos_presentados, aprobados, notables, sobresalientes, suma);
				mostrar_estadistica(num_alumnos, alumnos_presentados, aprobados, notables, sobresalientes, suma);
				break;
            case SALIR:
                return 0;
            default:
                cout << "Opcion no encontrada." << endl;
        }
    }
}

void leer_alumno(alumno &alumno) {

    cout << "Nombre: ";
    cin >> ws;
    getline(cin, alumno.nombre);

    cout << "Apellido1: ";
    cin >> ws;
    getline(cin, alumno.apellido1);

    cout << "Apellido2: ";
    cin >> ws;
    getline(cin, alumno.apellido2);
}

void incluir_alumno(alumno alumnos[], int &num_alumnos) {

    if (num_alumnos > MAX_ALUMNOS) {
        cout << "Máximo de estudiantes superado";

        return;
    }
    leer_alumno(alumnos[num_alumnos]);
    num_alumnos++;
}

void listar_alumno(const alumno alumnos[], const int alumnos_presentados){
	for (int i = 0; i < alumnos_presentados; i++){
		if(alumnos[i].nota > 0.1){
			cout << alumnos[i].nombre << " " << alumnos[i].apellido1 << " " 
				 << alumnos[i].apellido2 << " " << alumnos[i].nota << endl;
		}
	}
}

void poner_nota(alumno alumnos[], const int num_alumnos, int &alumnos_presentados) {
    string nombre_ = "";
    string apellido1_ = "";
    string apellido2_ = "";
    bool alumno_encontrado = false;

    cout << "Nombre: ";
    cin >> ws;
    getline(cin, nombre_);
    
	cout << "Apellido1: ";
    cin >> ws;
    getline(cin, apellido1_);
    
    cout << "Apellido2: ";
    cin >> ws;
    getline(cin, apellido2_);

    for(int i = 0; i < num_alumnos; i++) {
		if ((alumnos[i].nombre == nombre_ && alumnos[i].apellido1 == apellido1_ &&
			alumnos[i].apellido2 == apellido2_)){
            
			cout << "Nota: ";
			cin >> alumnos[i].nota;
            
			alumno_encontrado = true;
			alumnos_presentados++;
	    }
    }
    if (! alumno_encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void calcular_datos(alumno alumnos[], int alumnos_presentados, int &aprobados, int &notables, 
					int &sobresalientes, double &suma){
	
	for (int i = 0; i <= alumnos_presentados; i++){
		if(alumnos[i].nota >= 5){
			aprobados++;
		}
		if(alumnos[i].nota >= 7){
			notables++;
		}
		if(alumnos[i].nota >= 9){
			sobresalientes++;
		}
		suma += alumnos[i].nota;
	}
}

void mostrar_estadistica(const int num_alumnos, const int alumnos_presentados, const int aprobados, 
						 const int notables, const int sobresalientes, const double suma){
	
	cout << "Estudiantes: " << num_alumnos << endl
		 << "Presentados: " << alumnos_presentados << endl
		 << "Aprobados: " << aprobados << endl
		 << "Notables: " << notables << endl
		 << "Sobresalientes: " << sobresalientes << endl
		 << "Media: " << suma / alumnos_presentados << endl;
}
