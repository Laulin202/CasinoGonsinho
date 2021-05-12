//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}
void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}

void View::mostrarJugador(){
    long idJug;
    try{
        cout << "Digite la ID del jugador que desea consultar: " << endl;
        cin >> idJug;
        controller.verInfoJugador(idJug);
    } catch(std::domain_error ex){
        cout << ex.what();
    }
}

void View::venderGonzos(){
    long idJug;
    float dineroRecargar;
    try{
        cout << "Digite la ID del jugador: " << endl;
        cin >> idJug;
        do{
            cout << "Digite cuanto dinero desea recargar: " << endl;
            cin >> dineroRecargar;
        } while(dineroRecargar <= 0);
        controller.recargarGonzos(idJug, dineroRecargar);
    } catch(std::domain_error ex){
        cout << ex.what();
    }
}

void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opcion, opJuego;
    float cantGonzos;
    int idJuego;
    do{
        try {
            do {
                cout << "Cuantos gonzos desea apostar \n";
                cin >> cantGonzos;
            } while (cantGonzos <= 0);

            // Agregue el esto de la logica para el juego 1. Juego mayor a 13, 2 juego de dos colores.
            do {
                cout << "1. Juego mayor a 13\n2. Juego de dos colores\n0.Salir\n";
                cin >> opJuego;
            }while( opJuego != 1 && opJuego !=2 );

            //Pasos para empezar a jugar
            if (controller.jugar( opJuego, idJugador, cantGonzos )){
                cout << " Estas ardiendo!"<< endl;
            }
            else{
                cout << "No te rindas!" << endl;
            }

            cout << "Deseas seguir jugando?" << endl;
            cin >> opcion;

        } catch (std::domain_error ex){
            cout << ex.what();
        }
    }while (opcion!=0);
}

void View::retirarJugador(){
    long idJugador;

    try {
        cout << "Digite la id del jugador: " << endl;
        cin >> idJugador;
        controller.retirarJugador(idJugador);
    } catch (std::domain_error ex){
        cout << ex.what();
    }
}

int View::mostrarMenu(){
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Recargar gonzos" << std::endl;
    cout << "5. Retirar jugador" << std::endl;
    cout << "0. Salir\n" << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal(){
    int opcion;
    controller.cargarDatos();
    do{
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 1: 
                agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                venderGonzos();
                break;
            case 5:
                retirarJugador();
                break;
            case 0:
                cout << "Espero la haya pasado bien compadre :D" << endl;
                controller.guardarDatos();
                break;
            default:
                cout << "Seleccione una opcion correcta porfavor :(" << endl;
                break;
        }
    } while(opcion != 0);
}



