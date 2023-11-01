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
    void addFichas(unsigned int newFichas);
    void restFichas(unsigned int newFichas);
    void setFichas(unsigned int newFichas);
    unsigned int getMovimientos();
    void setMovimientos(unsigned int newMovimientos);
    void jugar();
};

#endif // PLAYER_H
