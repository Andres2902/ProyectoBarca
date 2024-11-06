#include "Juego.h"
#include "Robot.h"
#include "Zorro.h"
#include "Conejo.h"
#include "Lechuga.h"
#include <stdexcept>

Juego::Juego() {
    // Inicializar punteros
    Barca = new class Barca();
    orillaIzquierda = new Orilla("Orilla Izquierda");
    orillaDerecha = new Orilla("Orilla Derecha");
    juegoTerminado = false;
}

Juego::~Juego() {
    delete Barca;
    delete orillaIzquierda;
    delete orillaDerecha;
}

void Juego::iniciar() {
    // Crear los individuos en la orilla izquierda
    Robot* robot = new Robot();
    Zorro* zorro = new Zorro();
    Conejo* conejo = new Conejo();
    Lechuga* lechuga = new Lechuga();

    // Colocar todos los individuos en la orilla izquierda
    orillaIzquierda->agregarIndividuo(robot);
    orillaIzquierda->agregarIndividuo(zorro);
    orillaIzquierda->agregarIndividuo(conejo);
    orillaIzquierda->agregarIndividuo(lechuga);
}

void Juego::ejecutarComando(string comando) {

    if (juegoTerminado) return;
    if (comando == "B") {  // Mover barca
        if (Barca->mover()) {
            return;
        }
    } else {
        // Determinar el individuo a mover basado en el comando
        Individuo* individuoAMoverBarca = nullptr; // individuo en la barca
        Individuo* individuoAMoverOI = nullptr; // individuo en la orilla izquierda
        Individuo* individuoAMoverOD = nullptr; // individuo en la orilla derecha

// -------------------------------------------------- MOVIMIENTOS -----------------------------------------------------------------------------------------
        
        if (comando == "R") {

            individuoAMoverOI = orillaIzquierda->getRobot();
            individuoAMoverBarca = Barca->getRobot();
            individuoAMoverOD = orillaDerecha->getRobot();
            if(individuoAMoverBarca == nullptr){ // si el robot no esta en la barca
                if(individuoAMoverOI == nullptr){ // si el robot no esta en la orilla izquierda, es decir el robot esta en la orilla derecha
                    if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir el robot va a saltar al agua
                        juegoTerminado = true;
                        return;
                    }
                    else{ // la barca esta en la orilla derecha y el robot esta en la orilla derecha
                        Barca->setRobot(orillaDerecha->getRobot());
                        orillaDerecha->setRobot(nullptr);
                    }                 
                }
                if(individuoAMoverOD == nullptr){ // si el robot no esta en la orilla derecha, es decir el robot esta en la orilla izquierda
                    if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir saltara a la barca
                        Barca->setRobot(orillaIzquierda->getRobot());
                        orillaIzquierda->setRobot(nullptr);
                    } else{ // la barca esta en la orilla derecha y el robot esta en la orilla izquierda
                        juegoTerminado = true;
                        return;
                    }
                }
            } else{ // el robot esta en la barca
                if(Barca->estaEnOrillaIzquierda()== true){ // si esta en la orilla izquierda pasa el robot de la barca a la orilla
                    orillaIzquierda->setRobot(Barca->getRobot());
                    Barca->setRobot(nullptr);
                }else{ // si esta en la orilla derecha pasa el robot de la barca a la orilla
                    orillaDerecha->setRobot(Barca->getRobot());
                    Barca->setRobot(nullptr);
                }
            }
        }
        else if(comando == "Z"){
            individuoAMoverOI = orillaIzquierda->getZorro();
            individuoAMoverBarca = Barca->getZorro();
            individuoAMoverOD = orillaDerecha->getZorro();
            if(individuoAMoverBarca == nullptr){ // si el zorro no esta en la barca
                if(individuoAMoverOI == nullptr){ // si el zorro no esta en la orilla izquierda, es decir el zorro esta en la orilla derecha

                    if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir el zorro va a saltar al agua
                        juegoTerminado = true;
                        return;
                    }
                    else{ // la barca esta en la orilla derecha y el zorro esta en la orilla derecha
                        Barca->setZorro(orillaDerecha->getZorro());
                        orillaDerecha->setZorro(nullptr);
                    }                 
                }

                if(individuoAMoverOD == nullptr){ // si el zorro no esta en la orilla derecha, es decir el zorro esta en la orilla izquierda

                    if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir saltara a la barca
                        Barca->setZorro(orillaIzquierda->getZorro());
                        orillaIzquierda->setZorro(nullptr);
                    } else{ // la barca esta en la orilla derecha y el zorro esta en la orilla izquierda
                        juegoTerminado = true;
                        return;
                    }

                }

            } else{ // el zorro esta en la barca

                if(Barca->estaEnOrillaIzquierda()== true){ // si esta en la orilla izquierda pasa el zorro de la barca a la orilla
                    orillaIzquierda->setZorro(Barca->getZorro());
                    Barca->setZorro(nullptr);
                }else{ // si esta en la orilla derecha pasa el zorro de la barca a la orilla
                    orillaDerecha->setZorro(Barca->getZorro());
                    Barca->setZorro(nullptr);
                }
            }
        }

        else if(comando == "C"){

                individuoAMoverOI = orillaIzquierda->getConejo();
                individuoAMoverBarca = Barca->getConejo();
                individuoAMoverOD = orillaDerecha->getConejo();
                if(individuoAMoverBarca == nullptr){ // si el conejo no esta en la barca
                    if(individuoAMoverOI == nullptr){ // si el conejo no esta en la orilla izquierda, es decir el conejo esta en la orilla derecha
                        if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir el conejo va a saltar al agua
                            juegoTerminado = true;
                            return;
                        }
                        else{ // la barca esta en la orilla derecha y el conejo esta en la orilla derecha
                            Barca->setConejo(orillaDerecha->getConejo());
                            orillaDerecha->setConejo(nullptr);
                        }                 
                    }
                    if(individuoAMoverOD == nullptr){ // si el conejo no esta en la orilla derecha, es decir el conejo esta en la orilla izquierda
                        if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir saltara a la barca
                            Barca->setConejo(orillaIzquierda->getConejo());
                            orillaIzquierda->setConejo(nullptr);
                        } else{ // la barca esta en la orilla derecha y el conejo esta en la orilla izquierda
                            juegoTerminado = true;
                            return;
                        }
                    }
                } else{ // el conejo esta en la barca
                    if(Barca->estaEnOrillaIzquierda()== true){ // si esta en la orilla izquierda pasa el conejo de la barca a la orilla
                        orillaIzquierda->setConejo(Barca->getConejo());
                        Barca->setConejo(nullptr);
                    }else{ // si esta en la orilla derecha pasa el conejo de la barca a la orilla
                        orillaDerecha->setConejo(Barca->getConejo());
                        Barca->setConejo(nullptr);
                    }
                }
        }

        else if(comando == "L"){
            individuoAMoverOI = orillaIzquierda->getLechuga();
            individuoAMoverBarca = Barca->getLechuga();
            individuoAMoverOD = orillaDerecha->getLechuga();
            if(individuoAMoverBarca == nullptr){ // si la lechuga no esta en la barca
                if(individuoAMoverOI == nullptr){ // si la lechuga no esta en la orilla izquierda, es decir la lechuga esta en la orilla derecha
                    if(Barca->estaEnOrillaIzquierda() == true){ //la barca esta en la orilla izquierda, es decir la lechuga va a saltar al agua
                        juegoTerminado = true;
                        return;
                    }
                    else{ // la barca esta en la orilla derecha y la lechuga esta en la orilla derecha
                        Barca->setLechuga(orillaDerecha->getLechuga());
                        orillaDerecha->setLechuga(nullptr);
                        return;
                    }                 
                }
                if(individuoAMoverOD == nullptr){ // si la lechuga no esta en la orilla derecha, es decir la lechuga esta en la orilla izquierda
                    if(Barca->estaEnOrillaIzquierda()){ //la barca esta en la orilla izquierda, es decir saltara a la barca                 
                        Barca->setLechuga(orillaIzquierda->getLechuga());
                        orillaIzquierda->setLechuga(nullptr); 
                        return;              
                    } else{ // la barca esta en la orilla derecha y la lechuga esta en la orilla izquierda
                        juegoTerminado = true;
                        return;
                    }
                }
            } else{ // la lechuga esta en la barca
                if(Barca->estaEnOrillaIzquierda()== true){ // si esta en la orilla izquierda pasa la lechuga de la barca a la orilla
                    orillaIzquierda->setLechuga(Barca->getLechuga());
                    Barca->setLechuga(nullptr);
                }else{ // si esta en la orilla derecha pasa la lechuga de la barca a la orilla
                    orillaDerecha->setLechuga(Barca->getLechuga());
                    Barca->setLechuga(nullptr);
                }
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

bool Juego::estaTerminado(){
    return juegoTerminado;
}

bool Juego::haGanado(){
    // si los 4 individuos se encuentran en la orilla derecha, gana el juego
    if(orillaDerecha->getRobot() !=nullptr && orillaDerecha->getConejo() !=nullptr && orillaDerecha->getZorro() !=nullptr && orillaDerecha->getLechuga() !=nullptr){
        return true;
    }
    return false;
}


Orilla* Juego::getOrillaIzquierda(){
    return orillaIzquierda;
}
Orilla* Juego::getOrillaDerecha(){
    return orillaDerecha;
}
Barca* Juego::getBarca(){
    return Barca;
}

void Juego::setJuegoTerminado(bool estado){
    juegoTerminado = estado;
}
