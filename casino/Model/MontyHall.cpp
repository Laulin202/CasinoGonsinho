//
// Created by Laura Leon on 12/05/2021.
//
#include "MontyHall.h"

MontyHall::~MontyHall(){

}

float MontyHall::jugar(float gonzosApostar) {
    float gonzoResultado, n, pos;
    int puertas[3] = {};
    srand(time(NULL));
    cout << "Bienvenido al Monty Hall!" << endl;
    cout << "      [ MODO DE JUEGO ]             " << endl;
    cout << "El casino te mostrara 3 puertas, de las cuales una contiene un carro y las otras dos contienen una cabra cada una. Se te da la opcion de escoger una de las tres, pero antes de saber que contiene esta se te abrira otra de las 2 puertas que contenga un burro, dejandote de esta manera dos opciones, y aqui es cuando decides si cambias de puerta o te quedas con la que habias escogido. Ganas si encuentras el carro, de otra manera perderas." << endl;
    cout << "      [ RESULTADOS ]" << endl;
    cout << "-Si el jugador encuentra el carro ganara el triple de lo apostado\n-Si el jugador no encuentra el carro perdera un 1.5 de lo apostado" << endl;
    cout << "      [ ESCOGE UNA PUERTA ] " << endl;
    for(int j = 0; j < 3; j++){
        cout << "=====" << j + 1 << "=====" << "      ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout << "|         |" << "      ";
        }
        cout << endl;
    }
    n = rand()%2;
    puertaGanadora = n + 1;
    puertas[(int)n] = 1;
    cin >> puertaEscogida;
    for(int i = 0; i < 3; i++){
        if(puertas[i] != 1 && (i + 1) != puertaEscogida){
            cout << "La puerta numero " << (i + 1) << " contiene: " << endl;
            pos = i;
            cabra();
            i = 3;
        }
    }
    cout << "Desea continuar con la puerta escogida o se ira por la puerta restante?" << endl;
    for(int i = 0; i < 3; i++){
        if(i != pos){
            cout << i + 1 << ". Puerta " << i + 1 << endl;
        }
    }
    cin >> puertaEscogida;
    if(puertaEscogida == puertaGanadora){
        carro();
    } else{
        cabra();
    }
    gonzoResultado = calcularResultado(gonzosApostar);
    return gonzoResultado;
}

float MontyHall::calcularResultado(float gonzosApostar) {
    if(puertaEscogida == puertaGanadora){
        return gonzosApostar * 3;
    }
    return gonzosApostar * -1.5;
}

void MontyHall::cabra(){
    cout <<
    "   ," << endl <<
    "  /)\\" << endl <<
    " \'~ \\\'\"\"\"\"\"\')," << endl <<
    "     )/---,( (" << endl <<
    "PjP / |  / |" << endl;
}

void MontyHall::carro(){
    cout <<
    "         __________________________" << endl <<
    "        /   | |______| |___     __/" << endl <<
    "       /  , | |  /\\  | | ^ |   |       ,--." << endl <<
    "     ,' ,'| | |.'  `.| |/ \\|   |      /    \\" << endl <<
    "   ,' ,'__| | |______| |___|   |      \\    /" << endl <<
    "  /         |          |   |   |     _ `--'" << endl <<
    "  [   ,--.  |          |,--|   |]   (_)" << endl <<
    "  |__/    \\_|__________/    \\__|= o" << endl <<
    "     \\    /            \\    /" << endl <<
    "bmw   `--\'              `--'" << endl;
}