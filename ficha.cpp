#include "ficha.h"

ficha::ficha()
{
    char color = ' ';
}

void ficha::setColor(char newcolor)
{
    color = newcolor;
}

char ficha::getColor()
{
    return color;
}

void ficha::printColor()
{
    std::cout << color << '|';
}
