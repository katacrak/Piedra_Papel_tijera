#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obtenerJugadaComputadora() {
    return rand() % 3;
}

int obtenerJugadaJugador() {
    int jugada;
    printf("Elige una opción:\n");
    printf("0 - Piedra\n");
    printf("1 - Papel\n");
    printf("2 - Tijera\n");
    printf("Opción: ");
    scanf("%d", &jugada);
    return jugada;
}

int determinarGanador(int jugador, int computadora) {
    if (jugador == computadora) return 0;
    if ((jugador == 0 && computadora == 2) || 
        (jugador == 1 && computadora == 0) || 
        (jugador == 2 && computadora == 1)) return 1;
    return -1;
}

void jugar() {
    int victoriasJugador = 0, victoriasComputadora = 0;
    for (int ronda = 0; ronda < 3; ronda++) {
        int jugadaJugador = obtenerJugadaJugador();
        int jugadaComputadora = obtenerJugadaComputadora();
        printf("Computadora eligió: %d\n", jugadaComputadora);
        int resultado = determinarGanador(jugadaJugador, jugadaComputadora);
        if (resultado == 1) {
            printf("Ganaste esta ronda!\n");
            victoriasJugador++;
        } else if (resultado == -1) {
            printf("Perdiste esta ronda.\n");
            victoriasComputadora++;
        } else {
            printf("Empate!\n");
        }
    }
    if (victoriasJugador > victoriasComputadora)
        printf("Ganaste la partida!\n");
    else if (victoriasComputadora > victoriasJugador)
        printf("Perdiste la partida.\n");
    else
        printf("La partida terminó en empate.\n");
}

int main() {
    srand(time(NULL));
    jugar();
    return 0;
}
