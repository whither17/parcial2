#include "tablero.h"
int main()
{
    tablero table1;
    table1.printTablero();
    table1.colocarFicha(white, 2, 2);
    table1.printTablero();
    return 0;
}
