#include "tablero.h"
int main()
{
    tablero table1;
    table1.printTablero();

    table1.colocarFicha(white, 0, 6);
    table1.colocarFicha(black, 0, 7);
    table1.printTablero();
    return 0;
}
