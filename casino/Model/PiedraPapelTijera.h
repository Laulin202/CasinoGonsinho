//
// Created by Laura Leon on 12/05/2021.
//

#ifndef CASINO_PIEDRAPAPELTIJERA_H
#define CASINO_PIEDRAPAPELTIJERA_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>

class PiedraPapelTijera: public Juego{
private:
    int cantVicJugador;
    int cantVicCasino;
public:
    ~PiedraPapelTijera() override;
    float jugar(float gonzosApostar) override;

protected:
    float calcularResultado(float gonzosApostar) override;

};

#endif //CASINO_PIEDRAPAPELTIJERA_H
