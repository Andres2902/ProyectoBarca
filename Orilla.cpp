#include "Orilla.h"

// Constructor
Orilla::Orilla() : Lugar() {
    nombre = "";
}

// Constructor con el nombre de parametro
Orilla::Orilla(string nombreOrilla) : Lugar() {
    nombre = nombreOrilla;
}


bool Orilla::agregarIndividuo(Individuo* individuo) {
    // Llamamos al método de la clase base
    return Lugar::agregarIndividuo(individuo);
}

bool Orilla::quitarIndividuo(Individuo* individuo) {
    // Llamamos al método de la clase base
    return Lugar::quitarIndividuo(individuo);
}

bool Orilla::tieneRobot() {
    // Llamamos al método de la clase base
    return Lugar::tieneRobot();
}

bool Orilla::verificarProblemas() {
    // Llamamos al método de la clase base
    return Lugar::verificarProblemas();
}

int Orilla::cantidadIndividuos() {
    // Llamamos al método de la clase base
    return Lugar::cantidadIndividuos();
}

Robot* Orilla::getRobot(){
    // Llamamos al método de la clase base
    return Lugar::getRobot();
}

Zorro* Orilla::getZorro(){
    // Llamamos al método de la clase base
    return Lugar::getZorro();
}

Conejo* Orilla::getConejo(){
    // Llamamos al método de la clase base
    return Lugar::getConejo();
}

Lechuga* Orilla::getLechuga(){
    // Llamamos al método de la clase
    return Lugar::getLechuga();
}

void Orilla::setRobot(class Robot* robot){
    // Llamamos al método de la clase base
    Lugar::setRobot(robot);
}

void Orilla::setZorro(class Zorro* zorro){
    // Llamamos al método de la clase base
    Lugar::setZorro(zorro);
}

void Orilla::setConejo(class Conejo* conejo){
    // Llamamos al método de la clase base
    Lugar::setConejo(conejo);
}

void Orilla::setLechuga(class Lechuga* lechuga){
    // Llamamos al método de la clase base
    Lugar::setLechuga(lechuga);
}


// Destructor
Orilla::~Orilla() {}