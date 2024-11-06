#include "Jugador.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

Jugador::Jugador() {
    juego = new Juego();
}

Jugador::~Jugador() {
    delete juego;
}

void Jugador::jugar() {
    string aux;
    // Mostrar instrucciones iniciales
    cout << "\n=== BIENVENIDO AL JUEGO DEL ROBOT, ZORRO, CONEJO Y LECHUGA ===\n";
    cout << "Comandos disponibles:\n";
    cout << "B - Mover la barca\n";
    cout << "R - Mover el robot\n";
    cout << "Z - Mover el zorro\n";
    cout << "C - Mover el conejo\n";
    cout << "L - Mover la lechuga\n";
    cout << "S - Salir del juego\n\n";
    cout << "Presione Enter para comenzar...";
    getline(cin,aux);  
    // Iniciar el juego
    juego->iniciar();
    // Bucle principal del juego
    while (!juego->estaTerminado()) {
        mostrarEstado();
        // Verificar si hay problemas después del movimiento
        if (juego->getOrillaIzquierda()->verificarProblemas() || juego->getOrillaDerecha()->verificarProblemas() ||juego->getBarca()->verificarProblemas())
            {
            cout<<"\nEl juego ha terminado, has perdido!\n"<<endl;
            juego->setJuegoTerminado(true);
            return;
            }
            // verifica se ha ganado el juego
        if(juego->haGanado()==true){
            cout<<"\nEl juego ha terminado, has ganado!\n"<<endl;
            juego->setJuegoTerminado(true);
        }
        string comando = leerComando();
        // Verificar si el jugador quiere salir
        if (comando == "S" || comando == "s") {
            cout << "\nJuego terminado por el jugador\n";
            break;
        }
        // Ejecutar el comando
        juego->ejecutarComando(comando);
        //revisa el robot esta ne la barca para saltar mensaje de error
        if (comando == "B" || comando == "b"){
            if (juego->getBarca()->mover()==false){
                if(!juego->getBarca()->tieneRobot()){
                    cout<<"No hay un robot en la barca"<<endl;
                }else if (juego->getBarca()->cantidadIndividuos()>2){
                    cout<<"La barca solo puede transportar 2 individuos (incluyendo al robot)"<<endl;
                }
            }else{
                juego->getBarca()->mover(); // se vuelve a llamar la funcion para validar su movimiento (de lo contrario permaneceria estatico por que se habria llamado 2 veces en una en la funcion y otra en juego.cpp)
            }
        }

        
        // IMPLEMENTAR SALTOS AL AGUA SALIDAS COUT

        
        
    }
    // Mostrar resultado final
    mostrarEstado();
    if (juego->haGanado()) {
        cout << "\n¡GANASTE!\n";
        cout << "Has logrado transportar a todos los individuos de manera segura.\n";
    }
}

string Jugador::leerComando() {
    string comando;
    bool comandoValido = false;
    while (!comandoValido) {
        cout << "\nIngrese su comando (B/R/Z/C/L/S): ";
        getline(cin, comando);

        // Convertir a mayúscula
        transform(comando.begin(), comando.end(), comando.begin(), ::toupper);

        // Validar el comando
        if (comando.length() == 1 && 
            (comando == "B" || comando == "R" || comando == "Z" || 
             comando == "C" || comando == "L" || comando == "S")) {
            comandoValido = true;
        } else {
            cout << "Comando no válido. Por favor, intente de nuevo.\n";
        }
    }
    return comando;
}

void Jugador::mostrarEstado() {
    cout <<"\n\n\n\n\n\n\n\n\n";
    cout << "\n============== ESTADO ACTUAL DEL JUEGO ==============\n\n";
    //salida barca lado izquierdo
    if(juego->getBarca()->estaEnOrillaIzquierda()==true){
        cout << "Orilla Izquierda | Barca |       | Orilla Derecha\n";
        cout << "--------------------------------------------\n";
    }else{
        cout << "Orilla Izquierda |       | Barca | Orilla Derecha\n";
        cout << "--------------------------------------------\n";
    }
    //salida ubicacion robot
    if(juego->getOrillaIzquierda()->getRobot()!=nullptr){
    cout << "Robot            |       |       |               \n";
    }
    else if(juego->getOrillaDerecha()->getRobot()!=nullptr){
    cout << "                 |       |       | Robot         \n";
    }
    else{
            if(juego->getBarca()->estaEnOrillaIzquierda()==true){
        cout << "                 | Robot |       |               \n";
            }else{
        cout << "                 |       | Robot |               \n";
        }
    }
        //salida ubicacion de zorro
    if(juego->getOrillaIzquierda()->getZorro()!=nullptr){
    cout << "Zorro            |       |       |               \n";
    }
    else if(juego->getOrillaDerecha()->getZorro()!=nullptr){
    cout << "                 |       |       | Zorro         \n";
    }
    else{
            if(juego->getBarca()->estaEnOrillaIzquierda()==true){
        cout << "                 | Zorro |       |               \n";
            }else{
        cout << "                 |       | Zorro |               \n";
            }
    }
    //salida ubicacion de conejo
    if(juego->getOrillaIzquierda()->getConejo()!=nullptr){
    cout << "Conejo           |       |       |               \n";
    }
    else if(juego->getOrillaDerecha()->getConejo()!=nullptr){
    cout << "                 |       |       | Conejo        \n";
    }
    else{
            if(juego->getBarca()->estaEnOrillaIzquierda()==true){
    cout << "                 |Conejo |       |               \n";
            }else{
    cout << "                 |       |Conejo |               \n";
            }
    }       
    //salida ubicacion lechuga
    if(juego->getOrillaIzquierda()->getLechuga()!=nullptr){
    cout << "Lechuga          |       |       |               \n";
    }
    else if(juego->getOrillaDerecha()->getLechuga()!=nullptr){
    cout << "                 |       |       | Lechuga       \n";
    }
    else if(juego->getBarca()->getLechuga()!=nullptr){
            if(juego->getBarca()->estaEnOrillaIzquierda()==true){
    cout << "                 |Lechuga|       |               \n";
            }else{
    cout << "                 |       |Lechuga|               \n";
            }
    }
    cout << "--------------------------------------------\n";
}