#include "tablero.h"

bool tablero::fichaAdversario(ficha ficha_actual)
{
    bool hayFicha = false;
    char color_adversario = white;
    int nuevaFila;
    int nuevaColumna;

    if(ficha_actual.getColor() == white) color_adversario = black;


    if((ficha_actual.getX() == 0) && (ficha_actual.getY() == 0)) // esquina sup izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {1, 0, 1};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == 0) && (ficha_actual.getX() == rows - 1)) // esquina sup derecha
    {
        int dy[] = {0, 1, 1};
        int dx[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == rows - 1) && (ficha_actual.getX() == 0)) // esquina inf izquierda
    {
        int dx[] = {0, 1, 1};
        int dy[] = {-1, -1, 0};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == rows - 1) && (ficha_actual.getY() == - 1))  //// esquina inf derecha
    {
        int dy[] = {-1, -1, 0};
        int dx[] = {-1, 0, -1};

        for (int i = 0; i < 3; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == 0) && ((ficha_actual.getX() > 0) && (ficha_actual.getX() < rows-1))) //lat sup
    {
        int dy[] = {0, 0, 1, 1, 1};
        int dx[] = {-1, 1, -1, 0, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == rows-1) && ((ficha_actual.getY() > 0) && (ficha_actual.getY() < rows-1))) //lat der
    {
        int dy[] = {-1, -1, 0, 1, 1};
        int dx[] = {-1, 0, -1, -1, 0};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getY() == rows-1) && ((ficha_actual.getX() > 0) && (ficha_actual.getX() < rows-1))) //lat inf
    {
        int dy[] = {-1, -1, -1, 0, 0};
        int dx[] = {-1, 0, 1, -1, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else if((ficha_actual.getX() == 0) && ((ficha_actual.getY() > 0) && (ficha_actual.getY() < rows-1))) //lat izq
    {
        int dy[] = {-1, -1, 0, 1, 1};
        int dx[] = {0, 1, 1, 0, 1};

        for (int i = 0; i < 5; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }

    else
    {
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            nuevaFila =  ficha_actual.getY() + dy[i];
            nuevaColumna = ficha_actual.getX() + dx[i];
            if (matriz[nuevaFila][nuevaColumna].getColor() == color_adversario) {
                hayFicha = true;
                break;
            }
        }
    }
    if(hayFicha) {
        coord_ficha[0][0] = nuevaColumna; //x
        coord_ficha[0][1] = nuevaFila;    //y
    }

    return hayFicha;
}

bool tablero::casillaLibre(unsigned int x, unsigned int y)
{
    bool libre;
    if(matriz[x][y].getColor() != ' ') libre = false;
    else libre = true;
    return libre;
}

bool tablero::fichaFinal(unsigned int x_jug, unsigned int y_jug, unsigned int x_enem, unsigned int y_enem)
{
    int j = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    bool fichFinal = false;

    if(y_jug == y_enem) {  //robar en x

        if(x_jug < x_enem) {

            y = y_jug;
            j = x_enem;

            while(j < rows) {
                if(matriz[y][j].getColor() == matriz[y_jug][x_jug].getColor()) {
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
                if(matriz[y][j].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                j--;
            }
        }
    }

    else if(x_jug == x_enem) { //robar en y

        if(y_jug < y_enem) {

            x = x_jug;
            i = y_enem;

            while(j < rows) {
                if(matriz[i][x].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                i++;
            }
        }

        else if(y_jug > y_enem) {

            x = x_jug;
            i = y_enem;

            while(j >= 0) {
                if(matriz[i][x].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
            }
        }
    }

    else if ((y_jug != y_enem) && (x_jug != x_enem)) {
        //robar en diag

        if((y_jug < y_enem) && (x_jug < x_enem)) { //de izq a der y de ar a abj

            i = y_enem;          //fil (y)
            j = x_enem;          //col (x)

            while(j < rows && i < rows) {
                if(matriz[i][j].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                i++;
                j++;
            }
        }

        else if((y_jug > y_enem) && (x_jug > x_enem)) { //de der a izq y de abj a ar

            i = y_enem;
            j = x_enem;

            while(j >= 0 && i >= 0) {
                if(matriz[i][j].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
                j--;
            }
        }

        if((y_jug > y_enem) && (x_jug < x_enem)) { //de izq a der y de abj a ar

            i = y_enem;
            j = x_enem;

            while(j < rows && i >= 0) {
                if(matriz[i][j].getColor() == matriz[y_jug][x_jug].getColor()) {
                    fichFinal = true;
                    break;
                }
                i--;
                j++;
            }
        }

        else if((y_jug < y_enem) && (x_jug > x_enem)) { //de der a izq y de ar a abj

            i = y_enem;
            j = x_enem;

            while(j >= 0 && i < rows) {
                if(matriz[i][j].getColor() == matriz[y_jug][x_jug].getColor()) {
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

void tablero::robarFichas(ficha *ficha_actual)
{
    int j = 0;
    int i = 0;
    int x;
    int y;

    if(ficha_actual->getY() == coord_ficha[0][1]) {  //robar en x

        if(ficha_actual->getX() < coord_ficha[0][0]) {

            y = ficha_actual->getY();
            j = coord_ficha[0][0];

            while(matriz[y][j].getColor() != ficha_actual->getColor()) {
                matriz[y][j].setColor(ficha_actual->getColor());
                j++;
            }
        }

        else if(ficha_actual->getX() > coord_ficha[0][0]){

            y = ficha_actual->getY();
            j = coord_ficha[0][0];

            while(matriz[y][j].getColor() != ficha_actual->getColor()) {
                matriz[y][j].setColor(ficha_actual->getColor());
                j--;
            }
        }
    }

    else if(ficha_actual->getX() == coord_ficha[0][0]) { //robar en y

        if(ficha_actual->getY() < coord_ficha[0][1]) {

            x = ficha_actual->getX();
            i = coord_ficha[0][1];

            while(matriz[i][x].getColor() != ficha_actual->getColor()) {
                matriz[i][x].setColor(ficha_actual->getColor());
                i++;
            }
        }

        else if(ficha_actual->getY() > coord_ficha[0][1]) {

            x = ficha_actual->getX();
            i = coord_ficha[0][1];

            while(matriz[i][x].getColor() != ficha_actual->getColor()) {
                matriz[i][x].setColor(ficha_actual->getColor());
                i--;
            }
        }
    }

    else if ((ficha_actual->getY() != coord_ficha[0][1]) && (ficha_actual->getY() != coord_ficha[0][1])) {
        //robar en diag

        if((ficha_actual->getY() < coord_ficha[0][1]) && (ficha_actual->getX() < coord_ficha[0][0])) { //de izq a der y de ar a abj

            i = coord_ficha[0][1];          //fil (y)
            j = coord_ficha[0][0];          //col (x)
            while(matriz[i][j].getColor() != ficha_actual->getColor()) {
                matriz[i][j].setColor(ficha_actual->getColor());
                i++;
                j++;
            }
        }

        else if((ficha_actual->getY() > coord_ficha[0][1]) && (ficha_actual->getX() > coord_ficha[0][0])) { //de der a izq y de abj a ar

            i = coord_ficha[0][1];
            j = coord_ficha[0][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {
                matriz[i][j].setColor(ficha_actual->getColor());
                i--;
                j--;
            }
        }

        if((ficha_actual->getY() > coord_ficha[0][1]) && (ficha_actual->getX() < coord_ficha[0][0])) { //de izq a der y de abj a ar

            i = coord_ficha[0][1];
            j = coord_ficha[0][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {
                matriz[i][j].setColor(ficha_actual->getColor());
                i--;
                j++;
            }
        }

        else if((ficha_actual->getY() < coord_ficha[0][1]) && (ficha_actual->getX() > coord_ficha[0][0])) { //de der a izq y de ar a abj

            i = coord_ficha[0][1];
            j = coord_ficha[0][0];

            while(matriz[i][j].getColor() != ficha_actual->getColor()) {
                matriz[i][j].setColor(ficha_actual->getColor());
                i++;
                j--;
            }
        }
    }
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

    coord_ficha = new int*[1]; //par coordenadas enemigas
    coord_ficha[0] = new int[2];

    for(int j = 0; j < 2; j++) //llenar matriz coordenadas relativas
    {
        coord_ficha[0][j] = -1;
    }

}

void tablero::colocarFicha(char color, unsigned int x, unsigned int y)
{
    matriz[y][x].setColor(color);
    matriz[y][x].setX(x);
    matriz[y][x].setY(y);
    fichaAdversario(matriz[y][x]);
    robarFichas(&matriz[y][x]);
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

    std::cout << std::endl;


    for(unsigned int col = 0;col < 2; col++){
        std::cout << coord_ficha[0][col];
    }
    std::cout << std::endl;
}

tablero::~tablero()
{
    std::cout <<"destructor";
    for(unsigned int i = 0; i < rows; i++)
    {
        delete []matriz[i];
    }
    delete []matriz;

    delete []coord_ficha[0];



}
