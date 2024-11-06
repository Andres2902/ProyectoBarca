#include "Barca.h"

// Constructor
Barca::Barca() : Lugar() {
    orillaIzquierda = true; // La barca comienza en la orilla izquierda
    
}

bool Barca::agregarIndividuo(Individuo* individuo) {
    // Verificar que no haya más de 2 individuos en la barca
    if (cantidadIndividuos() >= 2) {
        return false;
    }

    // Si no hay robot en la barca, solo puede subir el robot
    if (!tieneRobot() && typeid(*individuo) != typeid(Robot)) {
        return false;
    }

    // Usar la implementación de la clase base para agregar el individuo
    return Lugar::agregarIndividuo(individuo);
}

bool Barca::quitarIndividuo(Individuo* individuo) {
    // Si es el robot y hay otros individuos, no se puede quitar
    if (typeid(*individuo) == typeid(Robot) && cantidadIndividuos() > 1) {
        return false;
    }

    // Usar la implementación de la clase base para quitar el individuo
    return Lugar::quitarIndividuo(individuo);
}

bool Barca::tieneRobot() {
    return Lugar::tieneRobot();
}

bool Barca::verificarProblemas() {
    return Lugar::verificarProblemas();
}

int Barca::cantidadIndividuos() {
    return Lugar::cantidadIndividuos();
}

bool Barca::mover() {
    // La barca solo se puede mover si hay un robot en ella
    if (!tieneRobot()) {
        return false; 
    }
    
    else if(cantidadIndividuos() > 2){
        return false;
    }
        
    // Cambiar de orilla
    orillaIzquierda = !orillaIzquierda;
    return true;
}

bool Barca::estaEnOrillaIzquierda() {
    return orillaIzquierda; //devuelve verdadero si esta en la Izquierda, falso si esta en la derecha
}

Robot* Barca::getRobot(){
    // Llamamos al método de la clase base
    return Lugar::getRobot();
}

Zorro* Barca::getZorro(){
    // Llamamos al método de la clase base
    return Lugar::getZorro();
}

Conejo* Barca::getConejo(){
    // Llamamos al método de la clase base
    return Lugar::getConejo();
}

Lechuga* Barca::getLechuga(){
    // Llamamos al método de la clase
    return Lugar::getLechuga();
}

void Barca::setRobot(class Robot* robot){
    // Llamamos al método de la clase base
    Lugar::setRobot(robot);
}

void Barca::setZorro(class Zorro* zorro){
    // Llamamos al método de la clase base
    Lugar::setZorro(zorro);
}

void Barca::setConejo(class Conejo* conejo){
    // Llamamos al método de la clase base
    Lugar::setConejo(conejo);
}

void Barca::setLechuga(class Lechuga* lechuga){
    // Llamamos al método de la clase base
    Lugar::setLechuga(lechuga);
}

// Destructor
Barca::~Barca() {}