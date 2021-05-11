//
// Created by lufe0 on 8/05/2021.
//

#include "DosColores.h"

float DosColores::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1+rand()%14;// numeros de 1 a 13
    numeroCasino = 1+rand()%14;// numeros de 1 a 13

    colorJugador = rand()%2; // Numero entre 0 y 1
    colorCasino = rand()%2; // Numero entre 0 y 1
    cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n" << "Tu color: " <<colorJugador << "\n";
    cout << "Numero casino: "<< numeroCasino <<"\n" << "Color casino: " <<colorCasino << "\n";
    float gonzosResulado = calcularResultado(gonzosApostar);
    //TODO borrar el cout de prueba
    return gonzosResulado;
}

float DosColores::calcularResultado(float gonzosApostar) {
    cout << "Por implementar \n";
    // Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado
    if(colorCasino == colorJugador && numeroCasino == numeroJugador){
        return gonzosApostar*4;
    }
   // coincide sólo con el valor del dado ganará 0.5 veces lo apostado
    else if(numeroJugador == numeroCasino){
        return gonzosApostar*0.5;
    }
   // no gana ni pierde
    else if(colorCasino == colorJugador){
        return 0;
    }
   // pierde todo lo apostado
   else
       return -1 * gonzosApostar;
}

DosColores::~DosColores() {

}
