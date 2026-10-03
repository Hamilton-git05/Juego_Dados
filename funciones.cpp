#include <iostream>
#include "funciones.h"
#include "logicaDados.h"
#include <clocale>
#include "rlutil.h"

using namespace std;

void verMenuPrincipal(){
    cout << "                  Bienvenido al juego de dados ESCALERA                 " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Opcion 1 - Iniciar juego para un jugador                                " << endl;
    cout << "Opcion 2 - Ver puntuacion mas alta                                      " << endl;
    cout << "Opcion 3 - Modo simulado                                                " << endl;
    cout << "Opcion 0 - Salir                                                        " << endl;
}


void pedirNombre(string &nombreJugador){
    char opcion = 'n';
    // LIMPIA EL BUFFER DE ENTRADA, SI NO SE LLAMA A LA FUNCION CIN.IGNORE(), NO SE GUARDA EL NOMBRE.
    cin.ignore();
    do{
    system("cls");
    cout << "ESCALERA                                                                " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Antes de comenzar tenes que registrar tu nombre                         " << endl;
    cout << "                                                                        " << endl;
    cout << "Nombre del jugador: ";
    // ES PARA TRABAJAR CON STRINGS
    getline(cin, nombreJugador);
    cout << "Confirmar nombre? (S/N) : ";
    cin >> opcion;
    cin.ignore();
    }while(opcion == 'N' || opcion == 'n');
    system("cls");
}

int comenzarJuego(string nombreJugador, int ronda, int &puntaje, int dados[], bool esModoSimulado){

    int maxPuntajeRonda = 0, lanzamiento = 1;
    int puntajeLanzamiento, combinacion = 0;

    for(int j=0; j<3; j++){

        if(esModoSimulado == false){
            lanzarDados(dados);
            puntajeLanzamiento = determinarPuntajeRonda(dados, combinacion);
        }
        else if(nombreJugador != "CPU" && esModoSimulado == true){
            ingresarDados(dados);
            puntajeLanzamiento = determinarPuntajeRonda(dados, combinacion);
        }

        if(puntajeLanzamiento > maxPuntajeRonda){
            maxPuntajeRonda = puntajeLanzamiento;
        }
        cout << "TURNO DE: " << nombreJugador << "       |      RONDA #" << ronda << "       |        PUNTAJE TOTAL: " << puntaje << endl;
        cout << "---------------------------------------------------------------------------"             << endl;
        cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << "                                  " << endl;
        cout << "LANZAMIENTO #" << lanzamiento << "                                                     " << endl;
        cout << "DADOS OBTENIDOS                                                                        " << endl;
        dibujarDados(dados);
        cout << endl << endl;
        if(combinacion == 1){
            cout << "SUMA DE DADOS! PUNTAJE OBTENIDO DE LA TIRADA: " << puntajeLanzamiento << endl;
        }
        if(combinacion == 2){
            //La posicion es 3 por que es indiferente, ya que son todos iguales.
            cout << "SEXTETO " << dados[3] << ", EL PUNTAJE DE LA TIRADA FUE DE : " << puntajeLanzamiento << endl;
        }
        if(combinacion == 3){
            cout << "ESCALERA! GANASTE LA PARTIDA!" << endl;
            if(nombreJugador != "CPU"){
                return 1;
            }
            else{
                return 2;
            }
        }
        if(combinacion == 4){
            puntaje = 0;
            cout << "ES SEXTETO DE 6!, EL PUNTAJE TOTAL PASO A SER : " << puntajeLanzamiento << endl;
        }
        cout << endl;

        if(nombreJugador != "CPU"){
            //system("pause");
            cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
            rlutil::anykey();
            system("cls");
        }
        else{
            //cout << endl << "EL CPU TIRA LOS DADOS SOLO, ESPERE POR FAVOR..." << endl;
            //rlutil::hidecursor();
            //rlutil::msleep(3000);
            cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
            rlutil::anykey();
            system("cls");
            //rlutil::showcursor();
        }
        lanzamiento++;
    }
    //while(puntaje < 100 && combinacion != 2);
    puntaje += maxPuntajeRonda;
    return 0;

}

void verMensajeRonda(string nombre, int ronda, int puntaje){
    cout << endl << endl;
    cout << " -----------------------------------------------------" << endl;
    cout << "                                                      " << endl;
    cout << "               COMIENZA LA RONDA # " << ronda           << endl;
    cout << "                                                      " << endl;
    cout << "               PUNTAJE " << nombre << " : " << puntaje << " PUNTOS  " << endl;
    cout << "                                                      " << endl;
    cout << " -----------------------------------------------------" << endl << endl;
    cout << " ";
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
    system("cls");
}

void mostrarPuntosObtenidos(string nombre, int ronda, int puntaje, int puntajeCPU){
    cout << endl << endl;
    cout << " -----------------------------------------------------     " << endl;
    cout << "                                                           " << endl;
    cout << "        PUNTOS OBTENIDOS PARA ESTA RONDA  # " << ronda       << endl;
    cout << "                                                           " << endl;
    cout << "                                                           " << endl;
    cout << "              " << nombre << " : " << puntaje << " PUNTOS  " << endl;
    cout << "                                                           " << endl;
    cout << "                                                           " << endl;
    cout << "                CPU : " << puntajeCPU << " PUNTOS  " << endl;
    cout << "                                                           " << endl;
    cout << "                                                           " << endl;
    cout << " -----------------------------------------------------     " << endl << endl;
    cout << "                                                           " << endl;
    cout << " ";
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
    system("cls");
}

void verMensajeTurno(){
    cout << endl << endl;
    cout << " -----------------------------------------------------" << endl;
    cout << "                                                      " << endl;
    cout << "                                                      " << endl;
    cout << "                    TURNO DE CPU                      " << endl;
    cout << "                                                      " << endl;
    cout << "                                                      " << endl;
    cout << " -----------------------------------------------------" << endl;
    cout << "                                                      " << endl;
    cout << " ";
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
    system("cls");
}

void notificarGanador(string nombreJugador, int puntajeJugador, int puntajeCpu, int huboEscalera){

    system("cls");
    if(huboEscalera == 1){
        cout << "FELICIDADES " << nombreJugador << " ! GANASTE EL JUEGO CON ESCALERA!" << endl;
    }
    if(huboEscalera == 2){
        cout << "MALA SUERTE :( GANO EL CPU CON ESCALERA" << endl;
    }
    if(puntajeJugador >= 100){
        cout << "FELICIDADES " << nombreJugador << " ! GANASTE EL JUEGO CON: " << puntajeJugador << " PUNTOS!" << endl;
    }
    if(puntajeCpu >= 100){
        cout << "MALA SUERTE :( GANO EL CPU CON: " << puntajeCpu << " PUNTOS!" << endl;
    }
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
    system("cls");

}

void verPuntuacionMasAlta(std::string nombreJugador, int puntajeJugador, int puntajeCpu){

    system("cls");
    if(puntajeJugador > puntajeCpu){
        cout << "JUGADOR QUE OBTUVO EL MAYOR PUNTAJE: " << nombreJugador << endl;
        cout << "CON: " << puntajeJugador << " PUNTOS." << endl;
    }
    if(puntajeCpu > puntajeJugador){
        cout << "JUGADOR QUE OBTUVO EL MAYOR PUNTAJE: CPU"  << endl;
        cout << "CON: " << puntajeCpu << " PUNTOS." << endl;
    }
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
    system("cls");
}


void dibujarDados(int dados[]){

    int posiciones[] = {5, 16, 27, 38, 49, 60};
    for (int i = 0; i < 6; i++) {
        // Obtener la posición actual basada en el índice
        int posX = posiciones[i];
        int posY = 8; // Altura fija para todos los dados

        switch (dados[i]) {
            case 1:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "|       |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "|   *   |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "|       |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
            case 2:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "| *     |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "|       |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "|     * |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
            case 3:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "| *     |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "|   *   |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "|     * |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
            case 4:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "|       |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
            case 5:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "|   *   |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
            case 6:
                rlutil::locate(posX, posY);
                cout << " ------- " << endl;
                rlutil::locate(posX, posY + 1);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 2);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 3);
                cout << "| *   * |" << endl;
                rlutil::locate(posX, posY + 4);
                cout << " ------- " << endl;
                break;
        }
    }
}
