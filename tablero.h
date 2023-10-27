#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:
    ficha **matriz;
    player jugadores[2];
public:
    tablero();
    void colocarFicha(char color, unsigned int x, unsigned int y);
    void printTablero();
    ~tablero();
};

#endif // TABLERO_H
