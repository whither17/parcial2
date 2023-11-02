#include "tablero.h"

void tablero::robarFichas(char color, int y, int x, int dy, int dx)
{
    char enemyColour = white;
    if (color == white)
    {
        enemyColour = black;
    }

    while(matriz[y][x].getColor() == enemyColour)
    {
        matriz[y][x].setColor(color);
        jugadores[current_player()].addFichas(1);
        jugadores[enemy_player()].restFichas(1);
        y += dy;
        x += dx;
    }
    return;
}

std::string *tablero::getNombres_col() const
{
    return nombres_col;
}

bool tablero::checkFlip(char color, int y, int x, int dy, int dx)
{
    char color_enemigo = white;
    bool check = false;

    if (color == white)
    {
        color_enemigo = black;     //seleccion de color
    }

    if ((y < 0) || (y >= rows) || (x < 0) || (x >= rows))     //si la posicion esta fuera del tablero
    {
        check = false;
    }

    else if (matriz[y][x].getColor() == color_enemigo)
    {
        while ((y >= 0) && (y < rows) && (x >= 0) && (x < rows))   //mientras se este dentro del tablero
        {
            y += dy;
            x += dx;
            if (matriz[y][x].getColor() == ' ')
            {
                check = false;
                break;
            }
            if (matriz[y][x].getColor() == color)
            {
                check = true;
                break;
            }
        }
    }
    return check;
}

bool tablero::comprobarMov(int x, int y)
{
    //Algoritmo basado en el trabajo de G V Ganesh Maurya
    //https://coderspacket.com/othello-game-in-c

    if ((y < 0) || (y >= rows) || (x < 0) || (x >= rows))
    {
        return false;
    }

    if (matriz[y][x].getColor() != ' ')    //verifica casilla vacia
    {
        return false;
    }

    char color = white;
    if (current_player() == 1)      //seleccion de color
    {
        color = black;
    }

    if (checkFlip(color, y - 1, x, -1, 0))   //arriba de la ficha
    {
        return true;
    }

    if (checkFlip(color, y + 1, x, 1, 0))    //abajo de la ficha
    {
        return true;
    }

    if (checkFlip(color, y, x - 1, 0, -1))   //izq de la ficha
    {
        return true;
    }

    if (checkFlip(color, y, x + 1, 0, 1))    //der de la ficha
    {
        return true;
    }

    if (checkFlip(color, y + 1, x + 1, 1, 1))   //inf der
    {
        return true;
    }

    if (checkFlip(color, y + 1, x - 1, 1, -1))  //inf izq
    {
        return true;
    }

    if (checkFlip(color, y - 1, x + 1, -1, 1))  //sup der
    {
        return true;
    }

    if (checkFlip(color, y - 1, x - 1, -1, -1))  //sup izq
    {
        return true;
    }

    return false;
}

void tablero::hacerMovimiento(int x, int y)
{
    char colour = white;
    if (current_player() == 1)      //seleccion de color
    {
        colour = black;
    }

    matriz[y][x].setColor(colour);
    jugadores[current_player()].addFichas(1);
    fichas++;

    if (checkFlip(colour, y - 1, x, -1, 0))         //arriba de la ficha
    {
        robarFichas(colour, y - 1, x, -1, 0);
    }

    if (checkFlip(colour, y + 1, x, 1, 0))          //abajo de la ficha
    {
        robarFichas(colour, y + 1, x, 1, 0);
    }

    if (checkFlip(colour, y, x - 1, 0, -1))         //izquierda de la ficha
    {
        robarFichas(colour, y, x - 1, 0, -1);
    }

    if (checkFlip(colour, y, x + 1, 0, 1))          //derecha de la ficha
    {
        robarFichas(colour, y, x + 1, 0, 1);
    }

    if (checkFlip(colour, y + 1, x + 1, 1, 1))      //inf derecha
    {
        robarFichas(colour, y + 1, x + 1, 1, 1);
    }

    if (checkFlip(colour, y + 1, x - 1, 1, -1))     //inf izquierda
    {
        robarFichas(colour, y + 1, x - 1, 1, -1);
    }

    if (checkFlip(colour, y - 1, x + 1, -1, 1))     //sup derecha
    {
        robarFichas(colour, y - 1, x + 1, -1, 1);
    }

    if (checkFlip(colour, y - 1, x - 1, -1, -1))   //sup izquierda
    {
        robarFichas(colour, y - 1, x - 1, -1, -1);
    }

    jug_actual = -1 * jug_actual; //invertir jugadores para cambio de turno;
    enemy = -1 * enemy;
    return;
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

    nombres_col = new std::string[rows];

    nombreCols();

    jugadores[0].setColor(white);
    jugadores[1].setColor(black);
    jugadores[0].setFichas(2);
    jugadores[1].setFichas(2);

    winner = -1;
    jug_actual = 1;
    enemy = -1;
    fichas = 63;
}

unsigned int tablero::current_player()
{
    if (jug_actual == -1)
    {
        return 0;
    }
    return jug_actual;
}

unsigned int tablero::enemy_player()
{
    if (enemy == -1)
    {
        return 0;
    }
    return enemy;
}

void tablero::nombreCols()
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
        nombres_col[i-1] = nombre;
        nombre = "";
    }
}

void tablero::printNombresCol()
{
    for(int i = 0; i < rows; i++)
    {
        std::cout << nombres_col[i] << ' ';
    }
}

void tablero::printTablero()
{
    unsigned int fila = 1;

    std::cout << '\t';
    std::cout << ' ';
    printNombresCol();
    std::cout << std::endl;

    for(unsigned int fil = 0;fil < rows; fil++){
        std::cout << fila << '\t' << '|';
        for(unsigned int col = 1;col <= rows; col++){
            matriz[fil][col-1].printColor();
        }
        std::cout << std::endl;
        fila++;
    }
    std::cout << '\t';
    std::cout << ' ';
    printNombresCol();
    std::cout << std::endl;

}

bool tablero::comprobarEstado()
{
    if (jugadores[0].getFichas() == 0)
    {
        winner = 1;
        return false;
    }
    else if (jugadores[1].getFichas() == 0)
    {
        winner = 0;
        return false;
    }
    else if(fichas == rows*rows)
    {
        if (jugadores[0].getFichas() > jugadores[1].getFichas())
        {
            winner = 0;
        }
        else if (jugadores[0].getFichas() < jugadores[1].getFichas())
        {
            winner = 1;
        }
        else
        {
            winner = -1;
        }
        return false;
    }
    return true;
}

short tablero::darGanador()
{
    return winner;
}

void tablero::status_game()
{
    std::cout << "fichas " << jugadores[0].getColor() << " : " << jugadores[0].getFichas() << std::endl;
    std::cout << "fichas " << jugadores[1].getColor() << " : " << jugadores[1].getFichas() << std::endl;
    std::cout << fichas << " <- en el tablero\n";
}

tablero::~tablero()
{
    for(unsigned int i = 0; i < rows; i++)
    {
        delete []matriz[i];
    }
    delete []matriz;

    delete []nombres_col;

}
