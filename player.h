#ifndef PLAYER_H
#define PLAYER_H


class player
{
private:
    char color;
    unsigned int fichas;
    unsigned int movimientos;
public:
    player();
    char getColor();
    void setColor(char newColor);
    unsigned int getFichas();
    void setFichas(unsigned int newFichas);
    unsigned int getMovimientos();
    void setMovimientos(unsigned int newMovimientos);
    void jugar();
};

#endif // PLAYER_H
