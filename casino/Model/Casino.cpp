//
// Created by lufe0 on 7/05/2021. :)
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    jugadoresMap.clear(); // Se limpian los jugadores del casino
}


void Casino::agregarJuego(Juego * juego) {
    juegosDisponibles.push_back(juego);
}



void Casino::agregarJugador(Jugador *pJugador) {
    // Se agrega el jugador al mapa de jugadores del casino
   jugadoresMap[pJugador->getId()] = pJugador;
   pJugador->mostrarInfo();
}

bool Casino::verExisteJugador(long id){
   if(jugadoresMap[id] == nullptr){
       return false;
   }
    return true;
}

// Retora el apuntador a jugador.
Jugador *Casino::consultarJugador(long id) {
    return jugadoresMap[id];
}

double Casino::convertirPesosAGonzos(double dinero) {
    // Cada 10 mil pesos equivalen a 100 Gonzos
    // aplicar una potente regla de 3
    return dinero/100;
}

vector<Juego *> &Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    // Investigue como remover el jugador del mapa
    cout << "Fase dos, por hacer \n";
    //TODO
}

double Casino::convertirGonzosPesos(float gonzos) {
    return gonzos * 100;
}

Casino::~Casino() {

}