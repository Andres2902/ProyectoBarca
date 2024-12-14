/*
Archivo: Zorro.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Zorro
INTENCIÓN: Representa al zorro que puede comerse al conejo si se queda solo con él
RELACIONES:
- Es un Individuo
*/

#ifndef ZORRO_H
#define ZORRO_H
#include "Individuo.h"

class Zorro : public Individuo
{
  public:
    Zorro(); //constructor 

    string getNombre();              //va a devolver el nombre del individuo
    bool puedeSerComido(Individuo*); //va a validar si puede ser comido por algun individuo (devolvera true si y solo si puede ser comido, y el robot no esta presente)
    bool puedeComer(Individuo*);     //va a validar si puede comer algun individuo (devolvera true si y solo si puede comer un individuo, y el robot no esta presente)

    ~Zorro(); //destructor

};

#else
class Zorro;
#endif