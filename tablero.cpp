#include "tablero.h"

bool tablero::fichaAdversario(unsigned int x, unsigned int y, char color)
{
    bool hayFicha = false;
    char color_adversario = white;
    int nuevaFila;
    int nuevaColumna;

    if(color == white) color_adversario = black;


    if((x == 0) && (y == 0)) // esquina sup izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {1, 0, 1};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((y == 0) && (x == rows - 1)) // esquina sup derecha
    {
        int dy[] = {0, 1, 1};
        int dx[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((y == rows - 1) && (x == 0)) // esquina inf izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((x == rows - 1) && (y == - 1))  //// esquina inf derecha
    {
        int dy[] = {-1, -1, 0};
        int dx[] = {-1, 0, -1};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((y == 0) && ((x > 0) && (x < rows-1))) //lat sup
    {
        int dy[] = {0, 0, 1, 1, 1};
        int dx[] = {-1, 1, -1, 0, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((x == rows-1) && ((y > 0) && (y < rows-1))) //lat der
    {
        int dy[] = {-1, -1, 0, 1, 1};
        int dx[] = {-1, 0, -1, -1, 0};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((y == rows-1) && ((x > 0) && (x < rows-1))) //lat inf
    {
        int dy[] = {-1, -1, -1, 0, 0};
        int dx[] = {-1, 0, 1, -1, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else if((x == 0) && ((y > 0) && (y < rows-1))) //lat izq
    {
        int dy[] = {-1, -1, 0, 1, 1};
        int dx[] = {0, 1, 1, 0, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    else
    {
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            nuevaFila =  y + dy[i];
            nuevaColumna = x + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                coord_ficha[i][0] = nuevaColumna; //x
                coord_ficha[i][1] = nuevaFila;    //y
            }
        }
    }

    return hayFicha;

}

bool tablero::casillaLibre(unsigned int x, unsigned int y)
{
    bool libre;
    if(matriz[y][x].getColor() == ' ') libre = true;

    else libre = false;
    return libre;
}

bool tablero::fichaFinal(unsigned int x_jug, unsigned int y_jug, unsigned int x_enem, unsigned int y_enem, unsigned int player_)
{
    int j = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    bool fichFinal = false;

    if(y_jug == y_enem) {

        if(x_jug < x_enem) {

            y = y_jug;
            j = x_enem;

            while(j < rows) {
                if(matriz[y][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                j++;
            }
        }

        else if(x_jug > x_enem){

            y = y_jug;
            j = x_enem;

            while(j >= 0) {
                if(matriz[y][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                j--;
            }
        }
    }

    else if(x_jug == x_enem) {

        if(y_jug < y_enem) {

            x = x_jug;
            i = y_enem;

            while(i < rows) {
                if(matriz[i][x].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i++;
            }
        }

        else if(y_jug > y_enem) {

            x = x_jug;
            i = y_enem;

            while(i >= 0) {
                if(matriz[i][x].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
            }
        }
    }

    else if ((y_jug != y_enem) && (x_jug != x_enem)) {

        if((y_jug < y_enem) && (x_jug < x_enem)) {

            i = y_enem;          //fil (y)
            j = x_enem;          //col (x)

            while(j < rows && i < rows) {
                if(matriz[i][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i++;
                j++;
            }
        }

        else if((y_jug > y_enem) && (x_jug > x_enem)) {

            i = y_enem;
            j = x_enem;

            while(j >= 0 && i >= 0) {
                if(matriz[i][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
                j--;
            }
        }

        if((y_jug > y_enem) && (x_jug < x_enem)) {

            i = y_enem;
            j = x_enem;

            while(j < rows && i >= 0) {
                if(matriz[i][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
                j++;
            }
        }

        else if((y_jug < y_enem) && (x_jug > x_enem)) {

            i = y_enem;
            j = x_enem;

            while(j >= 0 && i < rows) {
                if(matriz[i][j].getColor() == jugadores[player_].getColor()) {
                    fichFinal = true;
                    break;
                }
                i++;
                j--;
            }
        }
    }

    return fichFinal;
}

void tablero::robarFichas(ficha *ficha_actual, unsigned short player_, unsigned short player2, unsigned int cuadrante)
{
    int j = 0;
    int i = 0;
    int x;
    int y;

    if(ficha_actual->getY() == coord_ficha[cuadrante][1]) {  //robar en x

        if(ficha_actual->getX() < coord_ficha[cuadrante][0]) {

            y = ficha_actual->getY();
            j = coord_ficha[cuadrante][0];

            while(matriz[y][j].getColor() != ficha_actual->getColor()) {

                matriz[y][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                j++;
            }
        }

        else if(ficha_actual->getX() > coord_ficha[cuadrante][0]){

            y = ficha_actual->getY();
            j = coord_ficha[cuadrante][0];

            while(matriz[y][j].getColor() != ficha_actual->getColor()) {

                matriz[y][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                j--;
            }
        }
    }

    else if(ficha_actual->getX() == coord_ficha[cuadrante][0]) { //robar en y

        if(ficha_actual->getY() < coord_ficha[cuadrante][1]) {

            x = ficha_actual->getX();
            i = coord_ficha[cuadrante][1];

            while(matriz[i][x].getColor() != ficha_actual->getColor()) {

                matriz[i][x].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i++;
            }
        }

        else if(ficha_actual->getY() > coord_ficha[cuadrante][1]) {

            x = ficha_actual->getX();
            i = coord_ficha[cuadrante][1];

            while(matriz[i][x].getColor() != ficha_actual->getColor()) {

                matriz[i][x].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i--;
            }
        }
    }

    else if ((ficha_actual->getY() != coord_ficha[cuadrante][1]) && (ficha_actual->getY() != coord_ficha[cuadrante][1])) {
        //robar en diag

        if((ficha_actual->getY() < coord_ficha[cuadrante][1]) && (ficha_actual->getX() < coord_ficha[cuadrante][0])) { //de izq a der y de ar a abj

            i = coord_ficha[cuadrante][1];          //fil (y)
            j = coord_ficha[cuadrante][0];          //col (x)
            while(matriz[i][j].getColor() != ficha_actual->getColor()) {

                matriz[i][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i++;
                j++;
            }
        }

        else if((ficha_actual->getY() > coord_ficha[cuadrante][1]) && (ficha_actual->getX() > coord_ficha[cuadrante][0])) { //de der a izq y de abj a ar

            i = coord_ficha[cuadrante][1];
            j = coord_ficha[cuadrante][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {

                matriz[i][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i--;
                j--;
            }
        }

        if((ficha_actual->getY() > coord_ficha[cuadrante][1]) && (ficha_actual->getX() < coord_ficha[cuadrante][0])) { //de izq a der y de abj a ar

            i = coord_ficha[cuadrante][1];
            j = coord_ficha[cuadrante][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {

                matriz[i][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i--;
                j++;
            }
        }

        else if((ficha_actual->getY() < coord_ficha[cuadrante][1]) && (ficha_actual->getX() > coord_ficha[cuadrante][0])) { //de der a izq y de ar a abj

            i = coord_ficha[cuadrante][1];
            j = coord_ficha[cuadrante][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {

                matriz[i][j].setColor(ficha_actual->getColor());
                jugadores[player_].addFichas(1);
                jugadores[player2].restFichas(1);
                i++;
                j--;
            }
        }
    }
}

void tablero::comprobarMov(char color, unsigned int x, unsigned int y, unsigned short player_, unsigned short player2)
{
    unsigned short lim = 0;
    if(casillaLibre(x, y)) {
        if(fichaAdversario(x, y, color)) {
            for(int i = 0; i < 8; i++) {
                if(coord_ficha[i][0] != -1 && coord_ficha[i][1] != -1) {
                    if(fichaFinal(x, y, coord_ficha[i][0], coord_ficha[i][1], player_)) {
                        colocarFicha(color, x, y);
                        robarFichas(&matriz[y][x], player_, player2, i);
                    }
                }
                lim++;
            }
            lim++;
            if(lim == 8) std::cout << "El movimiento no produce encierro\n";
        }
        else std::cout << "No hay una ficha del contrincante cerca\n";
    }
    else std::cout << "Casilla ocupada\n";
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

    jugadores[0].setColor(black);
    jugadores[1].setColor(white);
    jugadores[0].setFichas(2);
    jugadores[1].setFichas(2);

    coord_ficha = new int*[8]; //par coordenadas enemigas

    for(int i = 0; i < 8; i++) {
        coord_ficha[i] = new int[2];
    }

    for(int j = 0; j < 8; j++) //llenar matriz coordenadas relativas
    {
        coord_ficha[j][0] = -1;
        coord_ficha[j][1] = -1;
    }

    fichas = 4;
}

void tablero::colocarFicha(char color, unsigned int x, unsigned int y)
{
    matriz[y][x].setColor(color);
    matriz[y][x].setX(x);
    matriz[y][x].setY(y);
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

    std::cout << '\t';
    std::cout << ' ';
    nombreCols();
    std::cout << std::endl;

}

bool tablero::comprobarEstado()
{
    if((jugadores[0].getMovimientos() == 0 && jugadores[1].getMovimientos() == 0) || fichas == rows*rows) return false;
    else return true;

}

void tablero::motrarEstadisticas()
{
    std::cout << jugadores[0].getColor() << " " << jugadores[0].getFichas() << std::endl;
    std::cout << jugadores[1].getColor() << " " << jugadores[1].getFichas() << std::endl;
}

tablero::~tablero()
{

    for(unsigned int i = 0; i < rows; i++)
    {
        delete []matriz[i];
    }
    delete []matriz;

    for(unsigned int i = 0; i < 8; i++)
    {
        delete []coord_ficha[i];
    }
    delete []coord_ficha;
}
