//
// Created by lufe0 on 7/05/2021.
//

#include "Jugador.h"

Jugador::Jugador()
          :cantJuegos(0)
{
}
// Hace llamada delegada al constructor por defecto
Jugador::Jugador(long id, string nombre, float cantGonzos): Jugador() {
    this->id = id;
    this->nombre = nombre;
    this->cantGonzos = cantGonzos;
}


/* Destructor*/
Jugador::~Jugador()
{
}

void Jugador::mostrarInfo() {

    // Muestra el nombre , la cantidad de gonzos y la cantidad de juegos jugados
    cout << "I-------------------------I" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cant Gonzos: " << cantGonzos << endl;
    cout << "Cant juegos: " << cantJuegos << endl;

}

void Jugador::aumentarJuegos() {
    // Incrementa la cantidad de juegos (canJuegos) que ha jugado el jugador
    this->cantJuegos++;
}

void Jugador::actualizarGonzos(float resultadoJuego) {
    cantGonzos+= resultadoJuego;
}

const string &Jugador::getNombre() const {
    return nombre;
}

float Jugador::getCantGonzos() const {
    return cantGonzos;
}

long Jugador::getId() const {
    return id;
}






