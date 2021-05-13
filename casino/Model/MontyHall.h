//
// Created by Laura Leon on 12/05/2021.
//

#ifndef CASINO_MONTYHALL_H
#define CASINO_MONTYHALL_H

#include "Juego.h"
#include <cstdlib>
#include <ctime>

class MontyHall: public Juego{
private:
    int puertaGanadora;
    int puertaEscogida;
public:
    ~MontyHall() override;
    float jugar(float gonzosApostar) override;

protected:
    float calcularResultado(float gonzosApostar) override;
    void cabra();
    void carro();

};

#endif //CASINO_MONTYHALL_H