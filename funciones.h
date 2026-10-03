#pragma once


void pedirNombre(std::string &nombreJugador);
void verMenuPrincipal();
int comenzarJuego(std::string nombreJugador, int ronda, int &puntaje, int dados[], bool esModoSimulado);
void dibujarDados(int dados[]);
void verMensajeRonda(std::string nombre, int ronda, int puntaje);
void verMensajeTurno();
void mostrarPuntosObtenidos(std::string nombre, int ronda, int puntaje, int puntajeCPU);
void notificarGanador(std::string nombreJugador, int puntajeJugador, int puntajeCpu, int huboEscalera);
void verPuntuacionMasAlta(std::string nombreJugador, int puntajeJugador, int puntajeCpu);

