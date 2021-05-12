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
    jugadoresMap.erase(id);
}

double Casino::convertirGonzosPesos(float gonzos) {
    return gonzos * 100;
}

void Casino::guardarMapa(){
    int n, cantJuegos;
    float cantGonzos;
    ofstream wf;
    wf.open("jugadores.dat", ios::out | ios::binary);
    n = jugadoresMap.size();
    wf.write((char *) &n, sizeof(int));
    map<long, Jugador*>::iterator itr;
    for (itr = jugadoresMap.begin(); itr != jugadoresMap.end(); ++itr) {
        size_t size = itr->second->getNombre().size();
        wf.write((char *) &itr->first, sizeof(long));
        wf.write((char *) &size, sizeof(size));
        wf.write((char *) &itr->second->getNombre()[0], size);
        cantGonzos = itr->second->getCantGonzos();
        wf.write((char *) &cantGonzos, sizeof(float));
        cantJuegos = itr->second->getCantJuegos();
        wf.write((char *) &cantJuegos, sizeof(int));
    }
    wf.close();
}

void Casino::cargarMapa(){
    int n, cantJuegos;
    float cantGonzos;
    long id;
    string nombre;
    ifstream rf;
    rf.open("jugadores.dat", ios::out | ios::binary);
    if(!rf) {
      cout << "No se encontro archivo para cargar!" << endl;
      return;
    }
    rf.read((char *) &n, sizeof(int));
    for(int i = 0; i < n; i++){
        size_t size;
        rf.read((char *) &id, sizeof(long));
        rf.read((char *) &size, sizeof(size));
        nombre.resize(size);
        rf.read((char *) &nombre[0], size);
        rf.read((char *) &cantGonzos, sizeof(float));
        rf.read((char *) &cantJuegos, sizeof(int));
        Jugador* pJugador = new Jugador (id, nombre, cantGonzos);
        for(int j = 0; j < cantJuegos; j++){
            pJugador->aumentarJuegos();
        }
        jugadoresMap[id] = pJugador;
    }
    rf.close();
}

Casino::~Casino() {

}