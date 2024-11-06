#include "Individuo.h"

Individuo::Individuo(){  //constructor vacio de individuo
  nombre = " ";
}

Individuo::Individuo(string nombre){ //construcor de individuo con nombre
  this->nombre = nombre;
}

string Individuo::getNombre(){ //devuelve el nombre del individuo
  return nombre;
}

bool Individuo::puedeSerComido(Individuo*){
  return false;
}

bool Individuo::puedeComer(Individuo*){
  return false;
}

Individuo::~Individuo(){} //destructor de individuo