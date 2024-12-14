/*
Archivo: Juego.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Juego
INTENCIÓN: Controla la lógica del juego y mantiene el estado actual
RELACIONES:
- Contiene Barca
- Contiene Orilla (2 instancias: izquierda y derecha)
*/

#ifndef JUEGO_H
#define JUEGO_H
#include "Barca.h"
#include "Orilla.h"


class Juego{
  private:
    Barca *Barca;
    Orilla *orillaIzquierda;
    Orilla *orillaDerecha;
    bool juegoTerminado;

  public:
    Juego(); //constructor 

    void iniciar(); // inicializa el juego creando los individuos y asignadoselos a la orilla izquierda
    void ejecutarComando(string); //recibe el comando digitado por el usuario y hace la funcion de mover los individuos o la barca
    bool estaTerminado(); // funciona mostrando el estado del juego si esta terminado o no
    bool haGanado(); //evalua las condiciones para que el juego se halla ganado y si las cumple devuelve true

    class Orilla* getOrillaIzquierda(); //permite acceder a la orilla izquierda del juego 
    class Orilla* getOrillaDerecha(); //permite acceder a la orilla derecha del juego
    class Barca* getBarca(); //permite acceder a la barca del juego 

    void setJuegoTerminado(bool); //permite establecer el estado del juego si esta terminado o no

    ~Juego(); //destructor
};


#else
class Juego;
#endif