/*
Archivo: Robot.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Robot
INTENCIÓN: Representa al robot que puede mover a los demás individuos
RELACIONES:
- Es un Individuo
*/

#ifndef ROBOT_H
#define ROBOT_H
#include "Individuo.h"

class Robot : public Individuo
{
  public:
    Robot(); //constructor 
    
    string getNombre();              //va a devolver el nombre del individuo
    bool puedeSerComido(Individuo*); //va a validar si puede ser comido por algun individuo (devolvera true si y solo si puede ser comido, y el robot no esta presente)
    bool puedeComer(Individuo*);     //va a validar si puede comer algun individuo (devolvera true si y solo si puede comer un individuo, y el robot no esta presente)
    
    ~Robot(); //destructor

};

#else
class Robot;
#endif