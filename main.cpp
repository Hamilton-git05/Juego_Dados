#include <iostream>
#include <ctime>
#include "funciones.h"
#include "logicaDados.h"
#include "rlutil.h"

using namespace std;

int main(){

    srand(time(NULL));
    rlutil::setColor(rlutil::WHITE);
    int ronda = 1, opcion, puntajeJugador, dadosJugador[6] = {}, puntajeCpu, dadosCpu[6] = {};
    string nombreJugador, nombreCpu = "CPU";

    do{
        verMenuPrincipal();
        cin >> opcion;
        int huboEscalera = 0; // SI ES 1 GANO EL JUGADOR, SI ES 2 GANO EL CPU.

        switch(opcion){
        case 1:
            system("cls");
            pedirNombre(nombreJugador);
            //RESETEO LOS PUNTAJES DE LOS JUGADORES PARA VOLVER A COMENZAR UNA RONDA DE 0
            puntajeJugador = 0;
            puntajeCpu = 0;
            do{

                huboEscalera = comenzarJuego(nombreJugador, ronda, puntajeJugador, dadosJugador, 0);
                if(huboEscalera == 0){
                    if(puntajeJugador >= 100){
                        cout << "GANO: " << nombreJugador << " CON: " << puntajeJugador << " PUNTOS!" << endl;
                        break;
                    }
                    verMensajeTurno();
                    huboEscalera = comenzarJuego(nombreCpu, ronda, puntajeCpu, dadosCpu, 0);
                    if(puntajeCpu >= 100){
                        cout << "GANO: " << nombreCpu << " CON: " << puntajeCpu << " PUNTOS!" << endl;
                        break;
                    }
                }

                if(huboEscalera == 0){
                    mostrarPuntosObtenidos(nombreJugador, ronda, puntajeJugador, puntajeCpu);
                    ronda++;
                    verMensajeRonda(nombreJugador, ronda, puntajeJugador);
                }

            }while(huboEscalera == 0);

            notificarGanador(nombreJugador, puntajeJugador, puntajeCpu, huboEscalera);

            break;
        case 2:
            verPuntuacionMasAlta(nombreJugador, puntajeJugador, puntajeCpu);
            break;

        case 3:
            system("cls");
            pedirNombre(nombreJugador);
            //RESETEO LOS PUNTAJES DE LOS JUGADORES PARA VOLVER A COMENZAR UNA RONDA DE 0
            puntajeJugador = 0;
            puntajeCpu = 0;
            do{

                huboEscalera = comenzarJuego(nombreJugador, ronda, puntajeJugador, dadosJugador, 1);
                if(huboEscalera == 0){
                    if(puntajeJugador >= 100){
                        cout << "GANO: " << nombreJugador << " CON: " << puntajeJugador << " PUNTOS!" << endl;
                        break;
                    }
                    verMensajeTurno();
                    huboEscalera = comenzarJuego(nombreCpu, ronda, puntajeCpu, dadosCpu, 0);
                    if(puntajeCpu >= 100){
                        cout << "GANO: " << nombreCpu << " CON: " << puntajeCpu << " PUNTOS!" << endl;
                        break;
                    }
                }

                if(huboEscalera == 0){
                    mostrarPuntosObtenidos(nombreJugador, ronda, puntajeJugador, puntajeCpu);
                    ronda++;
                    verMensajeRonda(nombreJugador, ronda, puntajeJugador);
                }

            }while(huboEscalera == 0);

            notificarGanador(nombreJugador, puntajeJugador, puntajeCpu, huboEscalera);
            break;

        case 0:
                return 0;
            break;

        default:
            system("cls");
            cout << "Opcion incorrecta, vuelva a ingresar una opción disponible nuevamente.";
            rlutil::anykey();
            break;
        }

    }while(opcion != 0);

    return 0;
}


