/*
Archivo: Orilla.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Orilla
INTENCIÓN: Representa una orilla donde pueden estar los individuos
RELACIONES:
- Es un Lugar
*/

#ifndef ORILLA_H
#define ORILLA_H
#include "Lugar.h"

class Orilla : public Lugar
{
  private:
    string nombre; //nombre que tendra la orilla izquierda/derecha


  public:
    Orilla(); //constructor 
    Orilla(string); //constructor que tendra el nombre orilla izquierda/derecha
    
    bool agregarIndividuo(Individuo*); //permite agregar un indiviuo al lugar 
    bool quitarIndividuo(Individuo*);  //permite quitar a un individuo del lugar 
    bool tieneRobot();   //verifica si el robot esta en el lugar
    bool verificarProblemas();  //verifica los conflictos (zorro-conejo, conejo-lechuga)
    int cantidadIndividuos();  //devuelve la cantidad de individuos del lugar


    class Robot* getRobot(); //devuelve el robot
    class Zorro* getZorro(); //deuelve el zorro
    class Conejo* getConejo();  //devuelve el conejo
    class Lechuga* getLechuga(); // devuelve la lechuga

    void setRobot(class Robot*); //permite asignarle un robot a un lugar
    void setZorro(class Zorro*); //permite asignarle un zorro a un lugar
    void setConejo(class Conejo*); //permite asignarle un conejo a un lugar
    void setLechuga(class Lechuga*); //permite asignarle una lechuga a un lugar

    ~Orilla(); //destructor

};

#else
class Orilla;
#endif