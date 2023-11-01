#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:
    ficha **matriz;
    int **coord_ficha;
    unsigned int fichas;
    bool fichaAdversario(unsigned int x, unsigned int y, char color);
    bool casillaLibre(unsigned int x, unsigned int y);
    bool fichaFinal(unsigned int x_jug, unsigned int y_jug, unsigned int x_enem, unsigned int y_enem, unsigned int player_);
    void robarFichas(ficha *ficha_actual, unsigned short player_, unsigned short player2);
    void colocarFicha(char color, unsigned int x, unsigned int y, unsigned short player_);

public:
    tablero();
    player jugadores[2];
    void comprobarMov(char color, unsigned int x, unsigned int y, unsigned short player_, unsigned short player2);
    void printTablero();
    bool comprobarEstado();
    ~tablero();

};

#endif // TABLERO_H
