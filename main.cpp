#include <iostream>
#include "Jugador.h"

void mostrarIntroduccion() {
    string aux;
    cout << "============================================\n";
    cout << "   JUEGO DEL ROBOT, ZORRO, CONEJO Y LECHUGA\n";
    cout << "============================================\n\n";
    cout << "Objetivo del juego:\n";
    cout << "Ayudar al robot a transportar al zorro, conejo y lechuga\n";
    cout << "desde la orilla izquierda hasta la orilla derecha.\n\n";
    cout << "Reglas:\n";
    cout << "1. La barca solo puede llevar al robot y un pasajero\n";
    cout << "2. El zorro se comerá al conejo si el robot no está presente\n";
    cout << "3. El conejo se comerá la lechuga si el robot no está presente\n";
    cout << "4. El robot debe estar en la barca para poder moverla\n\n";
    cout << "Presione Enter para continuar...";
    getline(cin,aux);
}

int main() {

        // Mostrar introducción
        mostrarIntroduccion();

        // Crear instancia del jugador y comenzar el juego
        Jugador* jugador = new Jugador();

        // Iniciar el juego
        jugador->jugar();

        // Liberar memoria
        delete jugador;

        // Mensaje de despedida
        cout << "\nGracias por jugar!\n";

        return 0;

}