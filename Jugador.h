/*
Archivo: Jugador.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Jugador
INTENCIÓN: Maneja la interacción con el usuario y controla el flujo del juego
RELACIONES:
- Conoce Juego
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include "Juego.h"



class Jugador{
  private:
    Juego *juego;

  public:
    Jugador(); //constructor 

    void jugar(); //es la base estructural del juego siendo un bucle, mostrando el estado (la parte grafica para el usuario), y permitiendo la interaccion del usuario con el juego mediante los comandos
    string leerComando(); // es la entrada de texto que verifica tanto su validez (que sea uno de los comandos establecidos) y en caso que no le avisa al usuario para que vuelva a ingresarlo
    void mostrarEstado(); // hace la impresion del estado del juego mostrando en que posicion se encuentran los individuos para que el usuario lo vea

    ~Jugador(); //destructor
};


#else
class Jugador;
#endif