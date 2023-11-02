#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:

    ficha **matriz;
    unsigned int fichas;
    std::string *nombres_col;
    short jug_actual, enemy, winner;

    bool checkFlip(char color, int y, int x, int dy, int dx);
    void robarFichas(char color, int y, int x, int dy, int dx);
    void nombreCols();
    void printNombresCol();

public:

    tablero();
    player jugadores[2];
    std::string *getNombres_col() const;
    unsigned int current_player();
    unsigned int enemy_player();
    bool comprobarMov(int x, int y);
    void hacerMovimiento(int x, int y);
    void printTablero();
    bool comprobarEstado();
    short darGanador();
    void status_game();
    ~tablero();

};

#endif // TABLERO_H
