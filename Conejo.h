/*
Archivo: Conejo.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Conejo
INTENCIÓN: Representa al conejo que puede ser comido por el zorro y que puede comerse la lechuga
RELACIONES:
- Es un Individuo
*/

#ifndef CONEJO_H
#define CONEJO_H
#include "Individuo.h"

class Conejo : public Individuo
{
  public:
    Conejo(); //constructor 

    string getNombre();              //va a devolver el nombre del individuo
    bool puedeSerComido(Individuo*); //va a validar si puede ser comido por algun individuo (devolvera true si y solo si puede ser comido, y el robot no esta presente)
    bool puedeComer(Individuo*);     //va a validar si puede comer algun individuo (devolvera true si y solo si puede comer un individuo, y el robot no esta presente)

    ~Conejo(); //destructor

};

#else
class Conejo;
#endif