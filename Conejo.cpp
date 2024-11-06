#include "Zorro.h"
#include "Conejo.h"
#include "Lechuga.h"

// Constructor: inicializa el conejo llamando al constructor de Individuo con el nombre Conejo
Conejo::Conejo() : Individuo("Conejo") {}

// El conejo puede ser comido por el zorro
bool Conejo::puedeSerComido(Individuo* otro) {
    // Verificamos si el otro individuo es un zorro usando dynamic_cast
    Zorro* zorro = dynamic_cast<Zorro*>(otro);
    return zorro != nullptr;    // devuelve true si es un zorro, false en caso contrario
}

// El zorro solo puede comer al conejo
bool Conejo::puedeComer(Individuo* otro) {
    // Verificamos si el otro individuo es un conejo usando dynamic_cast
    Lechuga* lechuga = dynamic_cast<Lechuga*>(otro);
    return lechuga != nullptr;  // devuelve true si es una lechuga, false en caso contrario
}

// devuelve el nombre del conejo (Conejo)
string Conejo::getNombre() {
    return nombre;
}

// Destructor
Conejo::~Conejo() {}