#include "tablero.h"

bool tablero::fichaAdversario(ficha ficha_actual)
{
    bool hayFicha = false;
    char color_adversario = white;

    if(ficha_actual.getColor() == white) color_adversario = black;


    if((ficha_actual.getX() == 0) && (ficha_actual.getY() == 0)) // esquina sup izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {1, 0, 1};

        for (int i = 0; i < 3; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == 0) && (ficha_actual.getY() == rows - 1)) // esquina sup derecha
    {
        int dx[] = {0, 1, 1};
        int dy[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == rows - 1) && (ficha_actual.getY() == 0)) // esquina inf izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == rows - 1) && (ficha_actual.getY() == - 1))  //// esquina inf derecha
    {
        int dx[] = {-1, -1, 0};
        int dy[] = {-1, 0, -1};

        for (int i = 0; i < 3; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == 0) && ((ficha_actual.getY() > 0) && (ficha_actual.getY() < rows-1))) //lat sup
    {
        int dx[] = {0, 0, 1, 1, 1};
        int dy[] = {-1, 1, -1, 0, 1};

        for (int i = 0; i < 5; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == rows-1) && ((ficha_actual.getX() > 0) && (ficha_actual.getX() < rows-1))) //lat der
    {
        int dx[] = {-1, -1, 0, 1, 1};
        int dy[] = {-1, 0, -1, -1, 0};

        for (int i = 0; i < 5; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == rows-1) && ((ficha_actual.getY() > 0) && (ficha_actual.getY() < rows-1))) //lat inf
    {
        int dx[] = {-1, -1, -1, 0, 0};
        int dy[] = {-1, 0, 1, -1, 1};

        for (int i = 0; i < 5; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == 0) && ((ficha_actual.getX() > 0) && (ficha_actual.getX() < rows-1))) //lat izq
    {
        int dx[] = {-1, -1, 0, 1, 1};
        int dy[] = {0, 1, 1, 0, 1};

        for (int i = 0; i < 5; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else
    {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int nuevaFila =  ficha_actual.getX() + dx[i];
            int nuevaColumna = ficha_actual.getY() + dy[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }
    return hayFicha;
}

tablero::tablero()
{
    matriz = new ficha *[rows];
    for(unsigned int i = 0; i < rows; i++)
    {
        matriz[i] = new ficha[rows];
    }


    for(unsigned int fil = ((rows/2) - 1); fil < ((rows/2) + 1); fil++)
    {
        for(unsigned int col = ((rows/2) - 1); col < ((rows/2) + 1); col++)
        {
            if(fil == col) matriz[fil][col].setColor(white);
            else matriz[fil][col].setColor(black);

            matriz[fil][col].setX(fil);
            matriz[fil][col].setY(col);

        }
    }
}

void tablero::colocarFicha(char color, unsigned int x, unsigned int y)
{
    matriz[x][y].setColor(color);
    matriz[x][y].setX(x);
    matriz[x][y].setY(y);
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
