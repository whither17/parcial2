#include "player.h"

char player::getColor() const
{
    return color;
}

void player::setColor(char newColor)
{
    color = newColor;
}

unsigned int player::getFichas() const
{
    return fichas;
}

void player::setFichas(unsigned int newFichas)
{
    fichas = newFichas;
}

unsigned int player::getMovimientos() const
{
    return movimientos;
}

void player::setMovimientos(unsigned int newMovimientos)
{
    movimientos = newMovimientos;
}

player::player()
{

}
