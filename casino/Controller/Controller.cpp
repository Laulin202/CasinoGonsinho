//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"
#include "../Model/PiedraPapelTijera.h"
#include "../Model/MontyHall.h"

Controller::Controller() {
  this->casino = Casino();
  // Se agregan los juegos disponibles para el casino
  Mayor13 * juego1 = new Mayor13();
  DosColores * juego2 = new DosColores();
  PiedraPapelTijera * juego3 = new PiedraPapelTijera();
  MontyHall * juego4 = new MontyHall();
  casino.agregarJuego(juego1);
  casino.agregarJuego(juego2);
  casino.agregarJuego(juego3);
  casino.agregarJuego(juego4);
}

// Se encarga de crear el objeto Jugador con la info ya validada de view
void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador* pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    float  resultadoFINAL;
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Si no hay errores se inicia el juego

    int posJuego = idJuego -1; // Se corrige la posicion para acceder al juego
    Juego* pJuegoAJugar = casino.consultarJuegos().at(idJuego-1);

    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    Jugador* pJugador = casino.consultarJugador(idJugador);  //Recordar: este metodo retorna el objeto (el jugador)
    cout << "Bienvenid@! " << pJugador->getNombre() << " estos son tus datos: "<< endl;
    pJugador->mostrarInfo();

    resultadoFINAL = pJuegoAJugar->jugar( gonzosApostar );

    // Actualiza el saldo del jugador con el resultado
    pJugador->actualizarGonzos(resultadoFINAL);

    // Actualiza la cantidad de juegos jugados
    pJugador->aumentarJuegos();

    // Retorna verdadero si el jugador ganó y false si el jugador perdio

    if( resultadoFINAL < 0){
        cout << "Lo lamento, perdiste: " << resultadoFINAL * -1 << " Gonzos (" << casino.convertirGonzosPesos(resultadoFINAL * -1) << "$) "<< endl;
        return false;
    }
    cout << "Felicidades, ganaste: " << resultadoFINAL << " Gonzos(" << casino.convertirGonzosPesos(resultadoFINAL) << "$) "<< endl;
    return true;
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    if(casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador* pJugador = casino.consultarJugador(idJugador);
    cout << "El siguiente jugador sera eliminado: " << endl;
    pJugador->mostrarInfo();
    casino.retirarJugador(idJugador);
}

void Controller::recargarGonzos(long idJugador, float dineroRecargar) {
    float gonzosRecargar, numeroAleatorio;
    srand(time(NULL));
    if (!casino.verExisteJugador(idJugador)){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    numeroAleatorio = 1+rand()%10;
    gonzosRecargar = casino.convertirPesosAGonzos(dineroRecargar, numeroAleatorio);
    Jugador* pJugador = casino.consultarJugador(idJugador);
    pJugador->actualizarGonzos(gonzosRecargar);
}

void Controller::guardarDatos(){
    casino.guardarMapa();
}

void Controller::cargarDatos(){
    casino.cargarMapa();
}
