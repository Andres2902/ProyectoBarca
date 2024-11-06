#include "Robot.h"

// Constructor inicializa el robot llamando al constructor de Individuo con el nombre Robot
Robot::Robot():Individuo("Robot") {}

// El robot no puede ser comido por ningún otro individuo
bool Robot::puedeSerComido(Individuo* otro) {
    return false;
}

// El robot no puede comer a ningún otro individuo
bool Robot::puedeComer(Individuo* otro) {
    return false;
}


// devuelve el nombre del robot (Robot)
string Robot::getNombre() {
    return nombre;  
}

// Destructor
Robot::~Robot() {}