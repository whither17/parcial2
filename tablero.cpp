#include "tablero.h"

tablero::tablero()
{
    matriz = new ficha *[rows];
    for(unsigned int i = 0; i < rows; i++)
    {
        matriz[i] = new ficha[rows];
    }
    matriz[(rows/2)-1][(rows/2)-1].setColor(white);
    matriz[(rows/2)][(rows/2)-1].setColor(black);
    matriz[(rows/2)-1][(rows/2)].setColor(black);
    matriz[(rows/2)][(rows/2)].setColor(white);

}

void tablero::colocarFicha(char color, unsigned int x, unsigned int y)
{
    matriz[x][y].setColor(color);
}

void nombreCols()
{
    int j;
    std::string nombre = "";

    for (int i = 1; i <= rows; i++) {
        j = i;
        while (j > 0) {
            char letra = 'A' + (j - 1) % 26;
            nombre = letra + nombre;
            j = (j - 1) / 26;
        }
        std::cout << nombre << ' ';
        nombre = "";
    }

}

void tablero::printTablero()
{
    unsigned int fila = 1;

    std::cout << '\t';
    std::cout << ' ';
    nombreCols();
    std::cout << std::endl;

    for(unsigned int fil = 0;fil < rows; fil++){
        std::cout << fila << '\t' << '|';
        for(unsigned int col = 1;col <= rows; col++){
            matriz[fil][col-1].printColor();
        }
        std::cout << std::endl;
        fila++;
    }
}

tablero::~tablero()
{
    for(unsigned int i = 0; i < rows; i++)
    {
        delete []matriz[i];
    }
    delete []matriz;
}
