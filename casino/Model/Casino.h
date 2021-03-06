//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_CASINO_H
#define CASINO_CASINO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Juego.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::iterator;
using std::ofstream;
using std::ifstream;
using std::ios;

class Casino {
private:
    vector<Juego*> juegosDisponibles;
    map<long, Jugador*> jugadoresMap;

public:
    Casino();
    virtual ~Casino();
    void agregarJuego(Juego *);
    double convertirPesosAGonzos(double dinero);
    double convertirPesosAGonzos(double dinero, int numeroAleatorio);
    double convertirGonzosPesos(float gonzos);
    vector<Juego*> & consultarJuegos();
    bool verExisteJugador(long id);
    Jugador * consultarJugador(long id);
    void agregarJugador(Jugador * pJugador);
    void retirarJugador(long id);
    void guardarMapa();
    void cargarMapa();

};
#endif //CASINO_CASINO_H
