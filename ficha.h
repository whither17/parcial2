#ifndef FICHA_H
#define FICHA_H
#include <iostream>
#include "macros.h"

class ficha
{

private:
    char color = ' ';

public:
    ficha(); //constructor.

    void setColor(char newcolor);
/*Funcion que recibe un caracter
*y cambia el caracter de color por el de newcolor
*
*@parametros: char newcolor.
*@return: void.
*/

    char getColor();
/*Funcion que retorna el valor del
*atributo color.
*
*@parametros: void.
*@return: char.
*/

    void printColor();
/*Funcion que muestra por consola
*el valor de color.
*
*@parametros: void.
*@return: void.
*/

};

#endif // FICHA_H
