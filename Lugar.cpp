#include "Lugar.h"
#include "Robot.h"
#include "Zorro.h"
#include "Lechuga.h"
#include "Conejo.h"

// Constructor
Lugar::Lugar() {
    Robot = nullptr;
    Zorro = nullptr;
    Conejo = nullptr;
    Lechuga = nullptr;
}


bool Lugar::agregarIndividuo(Individuo* individuo) {
    // Si el puntero es nulo, no se hace nada
    if (individuo == nullptr) return false;

    if (auto robot = dynamic_cast<class Robot*>(individuo)) { 
        if (this->Robot == nullptr) {  // Usa el puntero miembro 'robot'
            this->Robot = robot;       // Apunta al robot proporcionado
            return true;
        }
    } 
    else if (auto zorro = dynamic_cast<class Zorro*>(individuo)) { 
        if (this->Zorro == nullptr) {  // usa el puntero miembro 'zorro'
            this->Zorro = zorro;       // apunta al zorro proporcionado
            return true;
        }
    } 
    else if (auto conejo = dynamic_cast<class Conejo*>(individuo)) {
        if (this->Conejo == nullptr) {    //usa el puntero miembro 'conejo'
            this->Conejo = conejo;       // apunta al conejo proporcionado
            return true;
        }
    } 
    else if (auto lechuga = dynamic_cast<class Lechuga*>(individuo)) {
        if (this->Lechuga == nullptr) {    //usa el puntero miembro 'lechuga'
            this->Lechuga = lechuga;       // apunta al lechuga proporcionado
            return true;
        }
    }

    // Si no se pudo agregar el individuo, retorna false
    return false;
}

bool Lugar::quitarIndividuo(Individuo* individuo) {

    const type_info& tipo = typeid(*individuo); //obtiene el tipo dinamico al que apunta individuo

    if(tipo == typeid(Robot)){ //si el tipo dinamico es Robot
        if(Robot != nullptr){ // verifica que el puntero robot apunte a un robot
            Robot = nullptr; //hace que el puntero robot del lugar apunte a nada
            return true;
        } 
    }

    else if(tipo == typeid(Zorro)){ //si el tipo dinamico es Zorro
        if(Zorro != nullptr){ // verifica que el puntero Zorro apunte a un Zorro
            Zorro = nullptr; //hace que el puntero Zorro del lugar apunte a nada
            return true;
        } 
    }

    else if(tipo == typeid(Conejo)){ //si el tipo dinamico es Conejo
        if(Conejo != nullptr){ // verifica que el puntero Conejo apunte a un Conejo
            Conejo = nullptr; //hace que el puntero Conejo del lugar apunte a nada
            return true;
        } 
    }
    
    else if(tipo == typeid(Lechuga)){ //si el tipo dinamico es Lechuga
        if(Lechuga != nullptr){ // verifica que el puntero Lechuga apunte a un Lechuga
            Lechuga = nullptr; //hace que el puntero Lechuga del lugar apunte a nada
            return true;
        }
    }
    
    return false;
}

bool Lugar::tieneRobot() {
    if(Robot != nullptr){
        return true;
    }
    return false;
    
    //return Robot != nullptr;
}

bool Lugar::verificarProblemas() {
    // Si el robot está presente, no hay problemas
    if (tieneRobot()) {
        return false;
    }
    // Verificar si el zorro se puede comer al conejo
    if (Zorro != nullptr && Conejo != nullptr) {
        return true;
    }

    // Verificar si el conejo se puede comer la lechuga
    if (Conejo != nullptr && Lechuga != nullptr) {
        return true;
    }

    return false;
}

int Lugar::cantidadIndividuos() {
    int cantidad = 0;
    if (Robot != nullptr) 
        cantidad++;
    if (Zorro != nullptr) 
        cantidad++;
    if (Conejo != nullptr) 
        cantidad++;
    if (Lechuga != nullptr) 
        cantidad++;
    return cantidad;
}


// --------------- getters ---------------
Robot* Lugar::getRobot() {
    return Robot;
}

Zorro* Lugar::getZorro(){
    return Zorro;
}

Conejo* Lugar::getConejo(){
    return Conejo;
}

Lechuga* Lugar::getLechuga(){
    return Lechuga;
}

// --------------- setters ---------------

void Lugar::setRobot(class Robot* robot){
    Robot = robot;
}

void Lugar::setZorro(class Zorro* zorro){
    Zorro = zorro;
}

void Lugar::setConejo(class Conejo* conejo){
    Conejo = conejo;
}

void Lugar::setLechuga(class Lechuga* lechuga){
    Lechuga = lechuga;
}


// Destructor
Lugar::~Lugar() {}