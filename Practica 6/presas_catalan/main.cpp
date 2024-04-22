    #include <iostream>
    #include "terminal.h"
    #include <cstdlib>
    #include <ctime>
    using namespace std;
    const int LONGITUD_PANTALLA = 20;
    const int MAX_PELOTAS_PANTALLA = 4;
    const int RETARDO_TIEMPO = 300;
    const int TIEMPO_CREACION_PRESA = 3000;
    const int LIMITE_IZQ = 2;
    const int LIMITE_SUP = 2;
    const int LIMITE_DCHA = 70;
    const int LIMITE_INF = 19;
    const int RETARDO = 80;
    const string TITULO = "Juego del p�jaro";
    const char PELOTA = '0';
    const char FIN = 'f';
    const char PAJARO = '@';
    const char ARRIBA = 'q';
    const char ABAJO = 'a';

    struct posicion{
        int x = 0;
        int y = 0;
    };
    struct inc_unitario{
        int x = 0;
    };

    bool juego_finalizado(char tecla);
    void inicializar_pajaro(posicion& pajaro);
    void pintar_pajaro(posicion pajaro);
    void borrar_pajaro(posicion pajaro);
    void obtener_direccion(char tecla,posicion& pajaro);
    void inicializar_pelota(posicion& pelota , inc_unitario& inc_unitario);
    void pintar_pelota(posicion pelota);
    void borrar_pelota(posicion pelota);
    void actualizar_posicion(posicion& pelota, inc_unitario inc_unitario);
    bool limite_tocado(posicion pelota);
    bool pelota_capturada(posicion pelota , posicion pajaro);
    void pantalla_inicial();

    int main(){
        char tecla = '\0';
        posicion pajaro;
        posicion pelota[100];
        inc_unitario inc_unitario;
        int pelotas_pantalla = 1;
        int tiempo = 0;

        srand(time(0));
        setlocale(LC_ALL, "");

        habilitar_modo_crudo_terminal();
        hacer_cursor_visible(false);
        tecla = leer_tecla();


        pantalla_inicial();
        inicializar_pajaro(pajaro);
        retardar(RETARDO);

        while (!juego_finalizado(tecla)){
               // retardar(RETARDO_TIEMPO);

                tiempo = tiempo + RETARDO_TIEMPO;

                if(tiempo % (TIEMPO_CREACION_PRESA)== 0){
                    inicializar_pelota(pelota[pelotas_pantalla],inc_unitario);
                    pelotas_pantalla++;
                }

                for(int i = 0; i < pelotas_pantalla; i++){

                    pintar_pajaro(pajaro);
                    pintar_pelota(pelota[i]);

                    retardar(RETARDO);

                    borrar_pajaro(pajaro);
                    borrar_pelota(pelota[i]);

                    obtener_direccion(tecla,pajaro);
                    actualizar_posicion(pelota[i],inc_unitario);

                    if(pelota_capturada(pelota[i],pajaro)){
                        borrar_pelota(pelota[i]);

                        poner_cursor(1,25);
                        cout << "lo hiciste me vine rico" << endl;
                        pelotas_pantalla--;
                    }

                    if(limite_tocado(pelota[i])){
                        borrar_pelota(pelota[i]);

                        poner_cursor(1,25);
                        cout << "no lo hiciste  no me vine rico" << endl;
                        pelotas_pantalla--;
                    }
                    tecla = leer_tecla();

            }
        }
        deshabilitar_modo_crudo_terminal();
        borrar_terminal();


    }

    bool juego_finalizado(char tecla){
        return (tecla == FIN);

    }
    void pantalla_inicial(){
        poner_cursor(1,1);
        cout << "+-----------------" << TITULO << "---------------------+" << endl;
        for (int i = 1; i < LONGITUD_PANTALLA - 1; i++){
            poner_cursor(1, i + 1);
            cout << "|                                                      |" << endl;
        }
        poner_cursor(1,LONGITUD_PANTALLA);
        cout << "+------------------------------------------------------+" << endl;
    }
    void inicializar_pajaro(posicion& pajaro){
        pajaro.x = 3;
        pajaro.y =  3 + rand()% (LIMITE_INF);
    }

    void pintar_pajaro(posicion pajaro){

        poner_cursor(pajaro.x , pajaro.y);
        cout << PAJARO << endl;
    }

    void borrar_pajaro(posicion pajaro){

        poner_cursor(pajaro.x, pajaro.y);
        cout << " " << endl;
    }

    void obtener_direccion(char tecla,posicion& pajaro){

        switch(tecla){
            case ARRIBA:
                if(pajaro.y > LIMITE_SUP){
                    pajaro.y--;
                }
                break;
            case ABAJO:
                if(pajaro.y < LIMITE_INF){
                    pajaro.y++;
                }
                break;
        }
    }
    void inicializar_pelota(posicion& pelota , inc_unitario& inc_unitario){
        pelota.x = LONGITUD_PANTALLA + rand() % (LIMITE_DCHA - LIMITE_INF);
        pelota.y = 3 + rand() % (LIMITE_INF - 4);
        inc_unitario.x = 1;
    }

    void pintar_pelota(posicion pelota){

        poner_cursor(pelota.x, pelota.y);
        cout << PELOTA;
    }

    void borrar_pelota(posicion pelota){
          poner_cursor(pelota.x, pelota.y);
        cout << " ";
    }

    void actualizar_posicion(posicion& pelota, inc_unitario inc_unitario){

        pelota.x = pelota.x  - inc_unitario.x;
        pelota.y = pelota.y;
    }

    bool limite_tocado(posicion pelota){

        return(pelota.x == LIMITE_IZQ);
    }

    bool pelota_capturada(posicion pelota , posicion pajaro){

        return(pajaro.x == pelota.x && pajaro.y == pelota.y);
    }

