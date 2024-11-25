#include "Jugador.h"
#include <iostream>
#include <string>
#include <algorithm>

// Función auxiliar que maneja la verificación de problemas en una ubicación (orilla o barca)
auto verificarProblemasEnUbicacion = [](auto* ubicacion, const string& nombreUbicacion) { //recibe una ubicacion y su nombre 
    if (ubicacion->verificarProblemas() == true) { // si la ubicacion posee algun problema rectifica que problema tiene e imprime el mensaje
        if (ubicacion->getZorro() != nullptr && ubicacion->getConejo() != nullptr && ubicacion->getLechuga() == nullptr) {
            cout << "\nEl zorro se comió al conejo en la " << nombreUbicacion << endl;
        } else if (ubicacion->getConejo() != nullptr && ubicacion->getLechuga() != nullptr && ubicacion->getZorro() == nullptr) {
            cout << "\nEl conejo se comió la lechuga en la " << nombreUbicacion << endl;
        } else {
            cout << "\nEl zorro se comió al conejo y el conejo se comió a la lechuga en la " << nombreUbicacion << endl;
        }
    }
};


Jugador::Jugador() {
    juego = new Juego();
}

Jugador::~Jugador() {
    delete juego;
}

void Jugador::jugar() {
    string tipoObjeto,aux;
    bool enBarca = false,enIzquierda = false,enDerecha = false,huboProblema = false;
    getline(cin,aux);  
    // Iniciar el juego
    juego->iniciar();
    // Bucle principal del juego
    while (!juego->estaTerminado()) {
        mostrarEstado();
        // Verificar si hay problemas después del movimiento
        if (juego->getOrillaIzquierda()->verificarProblemas() || juego->getOrillaDerecha()->verificarProblemas() || juego->getBarca()->verificarProblemas()) {
            // Verificar problemas en la orilla izquierda
            verificarProblemasEnUbicacion(juego->getOrillaIzquierda(), "orilla izquierda");
            // Verificar problemas en la barca
            verificarProblemasEnUbicacion(juego->getBarca(), "barca");
            // Verificar problemas en la orilla derecha
            verificarProblemasEnUbicacion(juego->getOrillaDerecha(), "orilla derecha");
            cout << "\nEl juego ha terminado!\n" <<"PERDISTE"<<endl;
            juego->setJuegoTerminado(true);
            return;
        }
        string comando = leerComando();
        // Verificar si el jugador quiere salir
        if (comando == "S" || comando == "s") {
            cout << "\nJuego terminado por el jugador\n";
            break;
        }
    // Ejecutar el comando
    juego->ejecutarComando(comando);
    // Verificar caídas al agua
    if (comando == "B" || comando == "b") {
        if (juego->getBarca()->mover() == false) {
            if (!juego->getBarca()->tieneRobot()) {
                cout << "No hay un robot en la barca" << endl;
            } else if (juego->getBarca()->cantidadIndividuos() > 2) {
                cout << "La barca solo puede transportar 2 individuos (incluyendo al robot)" << endl;
            }
        } else {
            juego->getBarca()->mover(); // Validar el movimiento de la barca
        }
    }   
    if (comando == "Z" || comando == "z" || comando == "C" || comando == "c" || comando == "L" || comando == "l") { //implementacion cout de caidas al agua
        // Determinar qué objeto se está verificando
        if (comando == "Z" || comando == "z") {
            enBarca = (juego->getBarca()->getZorro() != nullptr);
            tipoObjeto = "zorro";
        } else if (comando == "C" || comando == "c") {
            enBarca = (juego->getBarca()->getConejo() != nullptr);
            tipoObjeto = "conejo";
        } else if (comando == "L" || comando == "l") {
            enBarca = (juego->getBarca()->getLechuga() != nullptr);
            tipoObjeto = "lechuga";
        }
        if (!enBarca) { // Si el objeto no está en la barca, verifica las orillas
            if (comando == "Z" || comando == "z") {
                enIzquierda = (juego->getOrillaIzquierda()->getZorro() != nullptr);
                enDerecha = (juego->getOrillaDerecha()->getZorro() != nullptr);
            } else if (comando == "C" || comando == "c") {
                enIzquierda = (juego->getOrillaIzquierda()->getConejo() != nullptr);
                enDerecha = (juego->getOrillaDerecha()->getConejo() != nullptr);
            } else if (comando == "L" || comando == "l") {
                enIzquierda = (juego->getOrillaIzquierda()->getLechuga() != nullptr);
                enDerecha = (juego->getOrillaDerecha()->getLechuga() != nullptr);
            }
            // Verificación de caídas al agua
            if (enIzquierda && !juego->getBarca()->estaEnOrillaIzquierda()) {
                cout << "\nEl " << tipoObjeto << " ha caído al agua!"<<"\nPERDISTE" << endl;
                huboProblema = true;
            } else if (enDerecha && juego->getBarca()->estaEnOrillaIzquierda()) {
                cout << "\nEl " << tipoObjeto << " ha caído al agua!"<<"\nPERDISTE" << endl;
                huboProblema = true;
            }
        }
    }
    // FINAL IMPLEMENTACION CAIDAS AL AGUA
    // Mostrar resultado final
    if (!huboProblema) { // Evitar impresión extra al terminar el juego
        mostrarEstado();
    }
    // verifica se ha ganado el juego
    if (juego->haGanado()) {
        cout << "\nGANASTE\n";
        cout << "Has logrado transportar a todos los individuos de manera segura.\n";
        juego->setJuegoTerminado(true);
        return;
    }}
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