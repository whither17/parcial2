#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:

    player jugadores[2];
    ficha **matriz;
    unsigned int xFinal(char color);
    unsigned int yFinal(char color);
    bool fichaAdversario(ficha ficha_actual);
public:
    tablero();
    void colocarFicha(char color, unsigned int x, unsigned int y);
    void printTablero();
    ~tablero();
};

#endif // TABLERO_H
