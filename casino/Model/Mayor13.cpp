//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar){
    int opc;
    float gonzoResultado;
    srand(time(NULL));
    numeroJugador = 1+rand()%13; // Se genera el numero para el usuario
    do{
        cout << "Su numero es: " << numeroJugador << endl << "1. Arriesgar\n2. Rendirse" << endl;
        cin >> opc;
    } while(opc != 1 && opc != 2);
    if(opc == 1){
        numeroCasino = 1+rand()%13; // Se general el numero para el casino
        gonzoResultado = calcularResultado(gonzosApostar);
        return gonzoResultado;
    }
    return (gonzosApostar/2) * -1;
}


float Mayor13::calcularResultado(float gonzosApostar){
    if(numeroJugador <= numeroCasino){
        return gonzosApostar * -1;
    }
    return gonzosApostar * 2;
}

Mayor13::~Mayor13(){ 
}
