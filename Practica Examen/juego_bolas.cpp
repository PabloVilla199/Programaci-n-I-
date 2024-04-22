/* Daniel Gomollon
 * Bola rebotando Versión 5
 * 02/2022
 */

#include "terminal.h"
#include <iostream>
#include <ctime>

using namespace std;

const int RETARDO_TECLA = 50;
const int VERSION_JUEGO = 1;

const char TECLA_FINAL = 'F';

const char BOLA = 'o';
const char PALA = '|';

const char CONTROL_SUBIR = 'W';
const char CONTROL_BAJAR = 'S';

const int LONGITUD_PALA = 4;

const int POS_INICIAL_Y = 10;
const int POS_INICIAL_X = 39;

const int LATERAL_DERECHA = 42;
const int LATERAL_IZQUIERDA = 2;
const int LIMITE_SUPERIOR = 1;
const int LIMITE_INFERIOR = 19;

struct posicion{
	int x;
	int y;
};

struct bola{
    posicion posicion;
    bool movimiento;
};

struct pala{
	posicion posicion;
};

void pintar_escenario(const int vidas);
void mostrar_ronda();
void pintar_game_over();
void pintar_bola(bola &bola);
void borrar_bola(bola &bola);
void mover_bola(bola &bola, pala &pala, int &eje_x, int &eje_y);
void pintar_pala (pala &pala);
void borrar_pala (pala &pala);
void mover_pala (const char tecla_pulsada, pala &pala);
void cambiar_pos_pala(const char tecla_pulsada, pala &pala);
bool juego_finalizado(const char tecla_pulsada);

int main() {
	bola bola = {{POS_INICIAL_X - 1, POS_INICIAL_Y}, true};
	pala pala = {POS_INICIAL_X, POS_INICIAL_Y - 1};

  	char tecla_pulsada = '\0';
  	int vidas = 4;
	int eje_x = -2;
  	int eje_y = -1;

 	habilitar_modo_crudo_terminal();

	srand(time(NULL));
  	cursor_visible(false);

 	pintar_escenario(vidas);

 	while (! juego_finalizado(tecla_pulsada) || vidas >= 0) {
 		retardo(RETARDO_TECLA);

		tecla_pulsada = toupper(leer_tecla());
		
		mover_pala(tecla_pulsada, pala);
  		
  		if(bola.movimiento){
			mover_bola(bola, pala, eje_x, eje_y);
  		}
  		
  		if(bola.posicion.x == LATERAL_DERECHA){
  			vidas--;
			borrar_bola(bola);
  			mostrar_ronda();
  			pintar_escenario(vidas);
		}
		poner_cursor(POS_INICIAL_X + 7, POS_INICIAL_Y);
		cout << "Vidas: " << vidas;
 	}
	deshabilitar_modo_crudo_terminal();
}

void pintar_escenario(const int vidas){
	cout << "+-----------Bola Rebotando  Pared-----------+"				<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 		   	<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 		   	<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |"				<< endl
		 << "|                                           |"				<< endl
		 << "|                                           |"				<< endl
		 << "+-------------------------------------------+"				<< endl
		 << "           Pulsa " << TECLA_FINAL << " para finalizar "   	<< endl;
}

void pintar_game_over(){
	borrar_terminal();
	cout << "+-----------Bola Rebotando  Pared-----------+"				<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 		   	<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 		   	<< endl
		 << "|                " << "GAME" << "           |" 			<< endl
		 << "|                " << "OVER" << "           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |" 			<< endl
		 << "|                                           |"				<< endl
		 << "|                                           |"				<< endl
		 << "|                                           |"				<< endl
		 << "+-------------------------------------------+"				<< endl
		 << "           Pulsa " << TECLA_FINAL << " para finalizar "   	<< endl;
}

void mover_pala (const char tecla_pulsada, pala &pala) {

	poner_cursor(pala.posicion.x, pala.posicion.y);
	borrar_pala (pala);

	cambiar_pos_pala(tecla_pulsada, pala);
	pintar_pala(pala);
}

void borrar_pala (pala &pala) {

	poner_cursor(pala.posicion.x, pala.posicion.y);
	cout << " ";
	poner_cursor(pala.posicion.x, pala.posicion.y + 1);
	cout << " ";
	poner_cursor(pala.posicion.x, pala.posicion.y + 2);
	cout << " ";
	poner_cursor(pala.posicion.x, pala.posicion.y + 3);
	cout << " ";
}

void pintar_pala (pala &pala) {

	poner_cursor(pala.posicion.x, pala.posicion.y);
	cout << PALA;
	poner_cursor(pala.posicion.x, pala.posicion.y + 1);
	cout << PALA;
	poner_cursor(pala.posicion.x, pala.posicion.y + 2);
	cout << PALA;
	poner_cursor(pala.posicion.x, pala.posicion.y + 3);
	cout << PALA;
}

void cambiar_pos_pala(const char tecla_pulsada, pala &pala) {

	if (tecla_pulsada == CONTROL_SUBIR && pala.posicion.y > LIMITE_SUPERIOR){
		pala.posicion.y--;
	}
	if (tecla_pulsada == CONTROL_BAJAR && pala.posicion.y < LIMITE_INFERIOR - 3){
		pala.posicion.y++;
	}
}

void pintar_bola(bola &bola){
	
	poner_cursor(bola.posicion.x, bola.posicion.y);
 	cout << BOLA;
}

void borrar_bola(bola &bola){

	poner_cursor(bola.posicion.x, bola.posicion.y);
 	cout << " ";
}

void mover_bola(bola &bola, pala &pala, int &eje_x, int &eje_y){

	borrar_bola(bola);

	bola.posicion.x += eje_x;
 	bola.posicion.y += eje_y;

 	pintar_bola(bola);
	retardo(40);
	
	if(bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 1 || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 2 || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 3 || 
	   bola.posicion.x == LATERAL_IZQUIERDA || bola.posicion.x == LATERAL_DERECHA){
		eje_x = -eje_x;	
	}
	if(bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 1 || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 2 || 
	   bola.posicion.x == POS_INICIAL_X - 1 && bola.posicion.y == pala.posicion.y + 3 || 
	   bola.posicion.y == LIMITE_SUPERIOR || bola.posicion.y == LIMITE_INFERIOR){
		eje_y = -eje_y;	
	}
}

bool juego_finalizado(const char tecla_pulsada) {

	return tecla_pulsada == TECLA_FINAL;
}

void mostrar_ronda(){
	
	borrar_terminal();
	cout << "+-----------------Juego de palas v"<< VERSION_JUEGO <<"------------------+" 	<< endl
		 << "|                        ____                        |"				<< endl
		 << "|       |\\   |  |    |  |     \\      /  /\\           |" 			<< endl
		 << "|       | \\  |  |    |  |____  \\    /  /  \\          |" 			<< endl
		 << "|       |  \\ |  |    |  |       \\  /  /____\\	     |" 			<< endl
		 << "|       |   \\|  |____|  |____    \\/  /      \\	     |" 			<< endl
		 << "|					             |" 									<< endl
		 << "|					             |" 									<< endl
		 << "|        ___   ____	      ____		     |" 						<< endl
		 << "| 	|   | |    |  |\\   | |    \\     /\\	     |" 					<< endl   
		 << "|	|___| |    |  | \\  | |     |   /  \\	     |" 					<< endl
		 << "|	| \\   |    |  |  \\ | |     |  /____\\	     |" 					<< endl
		 << "|	|  \\  |____|  |   \\| |____/  /      \\	     |" 				<< endl
		 << "|                                                    |"				<< endl
		 << "|                       ___                          |"				<< endl
		 << "|                       ___|                         |"				<< endl
		 << "|                       ___|                         |"				<< endl
		 << "+----------------------------------------------------+"				<< endl;
	retardo(1000);
	borrar_terminal();
	cout << "+-----------------Juego de palas v"<< VERSION_JUEGO <<"------------------+" 	<< endl
		 << "|                        ____                        |"				<< endl
		 << "|       |\\   |  |    |  |     \\      /  /\\           |" 			<< endl
		 << "|       | \\  |  |    |  |____  \\    /  /  \\          |" 			<< endl
		 << "|       |  \\ |  |    |  |       \\  /  /____\\	     |" 			<< endl
		 << "|       |   \\|  |____|  |____    \\/  /      \\	     |" 			<< endl
		 << "|					             |" 									<< endl
		 << "|					             |" 									<< endl
		 << "|        ___   ____	      ____		     |" 						<< endl
		 << "| 	|   | |    |  |\\   | |    \\     /\\	     |" 					<< endl   
		 << "|	|___| |    |  | \\  | |     |   /  \\	     |" 					<< endl
		 << "|	| \\   |    |  |  \\ | |     |  /____\\	     |" 					<< endl
		 << "|	|  \\  |____|  |   \\| |____/  /      \\	     |" 				<< endl
		 << "|                                                    |"				<< endl
		 << "|                       ___                          |"				<< endl
		 << "|                       ___|                         |"				<< endl
		 << "|                      |___                          |"				<< endl
		 << "+----------------------------------------------------+"				<< endl;
	retardo(1000);
	borrar_terminal();
	cout << "+-----------------Juego de palas v"<< VERSION_JUEGO <<"------------------+" 	<< endl
		 << "|                        ____                        |"				<< endl
		 << "|       |\\   |  |    |  |     \\      /  /\\           |" 			<< endl
		 << "|       | \\  |  |    |  |____  \\    /  /  \\          |" 			<< endl
		 << "|       |  \\ |  |    |  |       \\  /  /____\\	     |" 			<< endl
		 << "|       |   \\|  |____|  |____    \\/  /      \\	     |" 			<< endl
		 << "|					             |" 									<< endl
		 << "|					             |" 									<< endl
		 << "|        ___   ____	      ____		     |" 						<< endl
		 << "| 	|   | |    |  |\\   | |    \\     /\\	     |" 					<< endl   
		 << "|	|___| |    |  | \\  | |     |   /  \\	     |" 					<< endl
		 << "|	| \\   |    |  |  \\ | |     |  /____\\	     |" 					<< endl
		 << "|	|  \\  |____|  |   \\| |____/  /      \\	     |" 				<< endl
		 << "|                                                    |"				<< endl
		 << "|                                                    |"				<< endl
		 << "|                          |                         |"				<< endl
		 << "|                          |                         |"				<< endl
		 << "+----------------------------------------------------+"				<< endl;
	retardo(1000);
	borrar_terminal();
}
