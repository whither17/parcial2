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
    char getColor() const;
    void setColor(char newColor);
    unsigned int getFichas() const;
    void setFichas(unsigned int newFichas);
    unsigned int getMovimientos() const;
    void setMovimientos(unsigned int newMovimientos);
};

#endif // PLAYER_H
