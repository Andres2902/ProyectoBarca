#include "Zorro.h"
#include "Conejo.h"

// Constructor: inicializa el zorro llamando al constructor de Individuo con el nombre "Zorro"
Zorro::Zorro() : Individuo("Zorro") {}

// El zorro no puede ser comido por ningún otro individuo
bool Zorro::puedeSerComido(Individuo* otro) {
    return false;
}

// El zorro solo puede comer al conejo
bool Zorro::puedeComer(Individuo* otro) {
    // Verificamos si el otro individuo es un conejo usando dynamic_cast
    Conejo* conejo = dynamic_cast<Conejo*>(otro);
    return conejo != nullptr;  // devuelve true si es un conejo, false en caso contrario
}

// devuelve el nombre del conejo (Zorro)
string Zorro::getNombre() {
    return nombre;
}

// Destructor
Zorro::~Zorro() {}