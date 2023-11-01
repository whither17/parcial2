#include "player.h"

char player::getColor()
{
    return color;
}

void player::setColor(char newColor)
{
    color = newColor;
}

unsigned int player::getFichas()
{
    return fichas;
}

void player::addFichas(unsigned int newFichas)
{
    fichas += newFichas;
}

void player::restFichas(unsigned int newFichas)
{
    fichas -= newFichas;
    if(fichas < 0) fichas = 0;
}

void player::setFichas(unsigned int newFichas)
{
    fichas = newFichas;
}

unsigned int player::getMovimientos()
{
    return movimientos;
}

void player::setMovimientos(unsigned int newMovimientos)
{
    movimientos = newMovimientos;
}

void player::jugar()
{

}

player::player()
{

}
