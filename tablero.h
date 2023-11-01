#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:
    ficha **matriz;
    int **coord_ficha;
    bool fichaAdversario(ficha ficha_actual);
    bool casillaLibre(unsigned int x, unsigned int y);
    bool fichaFinal(unsigned int x_jug, unsigned int y_jug, unsigned int x_enem, unsigned int y_enem);
    void robarFichas(ficha *ficha_actual);
public:
    tablero();
    player jugadores[2];
    void colocarFicha(char color, unsigned int x, unsigned int y);
    void printTablero();
    ~tablero();
};

#endif // TABLERO_H
