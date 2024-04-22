/*
* Serpiente v_1
 * Pablo_Villa 28/09/2023
 */
  #include <iostream>
  #include "terminal.h"

  using namespace std;
  const char TECLA_CONTINUAR = ' ';
  const int RETARDO = 20;
  const string TITULO = "Juego de la serpiente ";
  const string VERSION = "1.0";
  const string TECLA = "ESPACIO";

 int main(){
    char tecla = '\0';
    habilitar_modo_crudo_terminal();
    retardo(RETARDO);
    cursor_visible(false);

    poner_cursor(1,1);
    cout << " ***************************** " << endl;

    poner_cursor(1,2);
    cout << " * "<< TITULO << VERSION << " * " << endl;

    poner_cursor(1,3);
    cout << " ***************************** " << endl;

    poner_cursor(1,6);
    cout << " ______" << endl;

    poner_cursor(1,7);
    cout << " _/ \\ " << endl;

    poner_cursor(1,8);
    cout << " \\___ \\ " << endl;

    poner_cursor(1,9);
    cout << " \\ \\_____" << endl;

    poner_cursor(1,10);
    cout << " \\ \\ " << endl;

    poner_cursor(1,11);
    cout << " \\____ \\______ _|_ " << endl;

    poner_cursor(1,12);
    cout << " \\ 0 \\_/ / \\ " << endl;

    poner_cursor(1,13);
    cout << " \\__________/ \\ \\___/" << endl;

    poner_cursor(1,17);
    cout << "Pulsa la tecla de " << TECLA << " para continuar" << endl;


    while(leer_tecla()!= TEClA_CONTINUAR){

        leer_tecla();
        retardo(RETARDO);
    }

 deshabilitar_modo_crudo_terminal();
 borrar_terminal();
 }
