/*
Archivo: Lechuga.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Lechuga
INTENCIÓN: Representa la lechuga que puede ser comida por el conejo
RELACIONES:
- Es un Individuo
*/

#ifndef LECHUGA_H
#define LECHUGA_H
#include "Individuo.h"

class Lechuga : public Individuo
{
  public:
    Lechuga(); //constructor 

    string getNombre();              //va a devolver el nombre del individuo
    bool puedeSerComido(Individuo*); //va a validar si puede ser comido por algun individuo (devolvera true si y solo si puede ser comido, y el robot no esta presente)
    bool puedeComer(Individuo*);     //va a validar si puede comer algun individuo (devolvera true si y solo si puede comer un individuo, y el robot no esta presente)

    ~Lechuga(); //destructor

};

#else
class Lechuga;
#endif