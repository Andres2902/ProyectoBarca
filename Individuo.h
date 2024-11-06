/*
Archivo: Individuo.h
Autor: 
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Individuo
INTENCIÓN: Clase abstracta base que representa un individuo del juego (robot, zorro, conejo o lechuga)
RELACIONES: 
- Es base abstracta de Robot, Zorro, Conejo y Lechuga
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

class Individuo{
  protected:
    string nombre;

  public:
    Individuo(); //constructor 
    Individuo(string); //constructor que tendra el nombre del individuo
    virtual string getNombre();              //va a devolver el nombre del individuo
    virtual bool puedeSerComido(Individuo*); //va a validar si puede ser comido por algun individuo (devolvera true si y solo si puede ser comido, y el robot no esta presente)
    virtual bool puedeComer(Individuo*);     //va a validar si puede comer algun individuo (devolvera true si y solo si puede comer un individuo, y el robot no esta presente)

    virtual ~Individuo(); //destructor
};


#else
class Individuo;
#endif