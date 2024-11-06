/*
Archivo: Barca.h
Autor:
Fecha creación: 24/10/2024
Fecha última modificación: 24/10/2024
Versión: 1.0
Licencia: GNU-GPL
*/

/*
CLASE: Barca
INTENCIÓN: Representa la barra donde pueden estar los individuos
RELACIONES:
- Es un Lugar
*/

#ifndef BARCA_H
#define BARCA_H
#include "Lugar.h"

class Barca : public Lugar
{
  private:
    bool orillaIzquierda;


  public:
    Barca(); //constructor 

    bool agregarIndividuo(Individuo*); //permite agregar un indiviuo al lugar 
    bool quitarIndividuo(Individuo*);  //permite quitar a un individuo del lugar 
    bool tieneRobot();   //verifica si el robot esta en el lugar
    bool verificarProblemas();  //verifica los conflictos (zorro-conejo, conejo-lechuga)
    int cantidadIndividuos();  //devuelve la cantidad de individuos del lugar

    bool mover(); //permite mover la barca
    bool estaEnOrillaIzquierda(); //verifica si se encuentra en la orilla izquierda


    class Robot* getRobot(); //devuelve el robot
    class Zorro* getZorro(); //deuelve el zorro
    class Conejo* getConejo();  //devuelve el conejo
    class Lechuga* getLechuga(); // devuelve la lechuga
  
    void setRobot(class Robot*); //permite asignarle un robot a un lugar
    void setZorro(class Zorro*); //permite asignarle un zorro a un lugar
    void setConejo(class Conejo*); //permite asignarle un conejo a un lugar
    void setLechuga(class Lechuga*); //permite asignarle una lechuga a un lugar


    ~Barca(); //destructor

};

#else
class Barca;
#endif