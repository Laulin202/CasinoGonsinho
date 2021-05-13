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

double Casino::convertirPesosAGonzos(double dinero, int numeroAleatorio) {
    // Cada 10 mil pesos equivalen a 100 Gonzos
    // aplicar una potente regla de 3
    cout << "El numero aleatorio es: " << numeroAleatorio << endl;
    if(numeroAleatorio > 5){
        cout << "FELICIDADES!" << endl;
        dinero = dinero * 2;
    } else{
        cout << "NO GANASTE >:)" << endl;
    }
    return convertirPesosAGonzos(dinero);
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
    ofstream wf; //Se crea la variable con la cual voy a cargar el archivo .dat
    wf.open("jugadores.dat", ios::out | ios::binary); //Se abre el archivo .dat en la variable wf
    n = jugadoresMap.size(); //Se guarda el tamanio del mapa en una variable n
    wf.write((char *) &n, sizeof(int)); //Se escribe el tamanio del mapa en el archivo
    map<long, Jugador*>::iterator itr; //Se crea el iterador para recorrer el mapa
    for (itr = jugadoresMap.begin(); itr != jugadoresMap.end(); ++itr) {
        size_t size = itr->second->getNombre().size(); //Se guarda en una variable de tipo size_t el size del string nombre de cada jugador
        wf.write((char *) &itr->first, sizeof(long)); //Se escribe en el archivo el id
        wf.write((char *) &size, sizeof(size)); //Se escribe en el archivo el size del string nombre
        wf.write((char *) &itr->second->getNombre()[0], size); //Se escribe en el archivo el nombre del jugador usando el size anteriormente guardado
        cantGonzos = itr->second->getCantGonzos();
        wf.write((char *) &cantGonzos, sizeof(float)); //Se escribe la cantidad de gonzos en el archivo
        cantJuegos = itr->second->getCantJuegos();
        wf.write((char *) &cantJuegos, sizeof(int)); //Se escribe la cantidad de juegos en el archivo
    }
    wf.close(); //Se cierra el archivo
}

void Casino::cargarMapa(){     
    int n, cantJuegos;        
    float cantGonzos;
    long id;
    string nombre;
    ifstream rf;
    rf.open("jugadores.dat", ios::out | ios::binary); //Se abre el archivo .dat para comenzar a leer
    if(!rf) { //Se evalua si existe un archivo con ese nombre para abrir
      cout << "No se encontro archivo para cargar!" << endl;
      return;
    }
    rf.read((char *) &n, sizeof(int)); //Se lee el tamanio del mapa para saber hasta donde se completa
    for(int i = 0; i < n; i++){
        size_t size; //Se crea la variable size de tipo size_t
        rf.read((char *) &id, sizeof(long)); //Se lee el id de cada jugador
        rf.read((char *) &size, sizeof(size)); //Se lee el tamanio de los strings nombres de cada jugador
        nombre.resize(size); //Se ajusta el tamanio del string nombre segun el tamanio del nombre guardado
        rf.read((char *) &nombre[0], size); //Se lee el string nombre
        rf.read((char *) &cantGonzos, sizeof(float)); //Se lee la cantidad de gonzos
        rf.read((char *) &cantJuegos, sizeof(int)); //Se lee la cantidad de juegos
        Jugador* pJugador = new Jugador (id, nombre, cantGonzos); //Se crea el pJugador con los datos leidos
        for(int j = 0; j < cantJuegos; j++){
            pJugador->aumentarJuegos(); //Se recorre la cantidad de juegos para determinar cuantos juegos ha jugado el jugador
        }
        jugadoresMap[id] = pJugador; //Se agrega el jugador al mapa
    }
    rf.close(); //Se cierra el archivo
}

Casino::~Casino() {

}