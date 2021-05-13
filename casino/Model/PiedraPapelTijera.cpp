//
// Created by Laura Leon on 12/05/2021.
//
#include "PiedraPapelTijera.h"

PiedraPapelTijera::~PiedraPapelTijera(){

}

float PiedraPapelTijera::jugar(float gonzosApostar) {
    int op;
    float gonzoResultado;
    cantVicCasino = 0;
    cantVicJugador = 0;
    srand(time(NULL));
    cout << "Bienvenido a piedra papel o tijeras!" << endl;
    cout << "      [ MODO DE JUEGO ]             " << endl;
    cout << "Jugaras con el casino al piedra papel o tijeras!\nLas reglas son:\n1. Ganara el que tenga mayor cantidad de puntos de victoria\n2. Son 3 turnos por partida" << endl;
    cout << "      [ RESULTADOS ]" << endl;
    cout << "- Si el jugador gana con 3 rondas (3 puntos de victoria) se llevara el doble de lo apostado.\n- Si gana con 2 rondas, ganara lo apostado\n- Si gana con 1 ronda, gana la mitad de lo apostado\n- si no gana, pierde lo apostado.\n- Empate absoluto: no gana ni ´pierde nada" << endl;
    cout << "      [ INFORMACION ADICIONAL ] " << endl;
    cout << " 1 = Piedra\n 2 = Tijera\n 3 = Papel " << endl;


    for(int i = 0; i < 3; i++){
        do {
            cout << "Digite opcion!" << endl;
            cin >> op;
        } while( op != 1 && op != 2 && op != 3);
        numeroCasino = 1+rand()%3;
        cout << "Resultado: " << endl;
        cout << "Numero del casino:" << numeroCasino << endl;
        if((op == 1 && numeroCasino == 2) || (op == 2 && numeroCasino == 3) || (op == 3 && numeroCasino == 1)){
            cantVicJugador++;
            cout << " Gana jugador! :)" << endl;
        }
        else if( ( numeroCasino == 1 && op == 2) || ( numeroCasino == 2 && op == 3) || (numeroCasino == 3 && op == 1)){
            cantVicCasino++;
            cout << "Gana la casa! :(" << endl;
        }
        else{
            cout << "Empate!" << endl;
        }
        gonzoResultado = calcularResultado(gonzosApostar);
    }

    return gonzoResultado;
}


float PiedraPapelTijera::calcularResultado(float gonzosApostar) {
    if (cantVicCasino > cantVicJugador){
        return gonzosApostar * -1;
    }
    else if( cantVicJugador > cantVicCasino){
        switch (cantVicJugador){
            case 1:
                return gonzosApostar * 0.5;
            case 2:
                return gonzosApostar;
            case 3:
                return gonzosApostar * 2;
        }
    }
    return 0;
}