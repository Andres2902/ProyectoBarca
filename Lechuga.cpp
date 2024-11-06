#include "Conejo.h"
#include "Lechuga.h"

// Constructor: inicializa el conejo llamando al constructor de Individuo con el nombre Lechuga
Lechuga::Lechuga() : Individuo("Lechuga") {}

// La lechuga puede ser comida por el conejo
bool Lechuga::puedeSerComido(Individuo* otro) {
    // Verificamos si el otro individuo es un conejo usando dynamic_cast
    Conejo* conejo = dynamic_cast<Conejo*>(otro);
    return conejo != nullptr;    // devuelve true si es un conejo, false en caso contrario
}

// la lechuga no puede comer a ningún otro individuo
bool Lechuga::puedeComer(Individuo* otro) {
    return false;
}

// devuelve el nombre de la lechuga (Lechuga)
string Lechuga::getNombre() {
    return nombre;
}

// Destructor
Lechuga::~Lechuga() {}