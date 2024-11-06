/*
Archivo: Lugar.h
Autor: 
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Lugar
INTENCIÓN: Clase abstracta que representa un lugar donde pueden estar los individuos (barca u orilla)
RELACIONES:
- Es base abstracta de Barca y Orilla
- Conoce Robot, Zorro, Conejo y Lechuga
*/

#ifndef LUGAR_H
#define LUGAR_H
#include "Robot.h"
#include "Zorro.h"
#include "Lechuga.h"
#include "Conejo.h"

class Lugar{
  protected:

    Robot *Robot;
    Zorro *Zorro;
    Conejo *Conejo;
    Lechuga *Lechuga;

  public:
    Lugar(); //constructor 

    virtual bool agregarIndividuo(Individuo*); //permite agregar un indiviuo al lugar 
    virtual bool quitarIndividuo(Individuo*);  //permite quitar a un individuo del lugar 
    virtual bool tieneRobot();   //verifica si el robot esta en el lugar
    virtual bool verificarProblemas();  //verifica los conflictos (zorro-conejo, conejo-lechuga)
    virtual int cantidadIndividuos();  //devuelve la cantidad de individuos del lugar

    class Robot* getRobot(); //devuelve el robot
    class Zorro* getZorro(); //deuelve el zorro
    class Conejo* getConejo();  //devuelve el conejo
    class Lechuga* getLechuga(); // devuelve la lechuga

    void setRobot(class Robot*); //permite asignarle un robot a un lugar
    void setZorro(class Zorro*); //permite asignarle un zorro a un lugar
    void setConejo(class Conejo*); //permite asignarle un conejo a un lugar
    void setLechuga(class Lechuga*); //permite asignarle una lechuga a un lugar

    virtual ~Lugar(); //destructor
};


#else
class Lugar;
#endif