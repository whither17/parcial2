#include "juego.h"

juego::juego()
{
    Datosjuego = new std::string *[2];
    for(unsigned int i = 0; i < 2; i++)
    {
        Datosjuego[i] = new std::string[2];
    }
}

void juego::jugar(std::string name1, std::string name2)
{
    unsigned int x, y;

    std::cout << "\nEl juego ha iniciado, ** en Othello siempre inicia las negras! **\n\n";
    table.printTablero();
    table.status_game();
    while (table.comprobarEstado())
    {
        if(table.current_player() == 1) {

            std::cout << "Turno de " << name1 << " (" << black<< ")" << "\n";
        }
        else std::cout << "Turno de " << name2 << " (" << white << ")" << "\n";

        y = entradaNum();    //verificar las filas
        x = entradaString(); //verificar las columnas

        if (table.comprobarMov(x-1, y-1))
        {
            table.hacerMovimiento(x-1, y-1);
        }
        else
        {
            std::cout << "Movimiento incorrecto\n";
        }
        table.printTablero();
        table.status_game();
    }

    std::cout << "Fin de la partida!\n";

    if (table.darGanador() != -1)
    {
        std::cout << " *** Ganador -> ";
        if(table.darGanador() == 0)
            std::cout << name2 << " <- con " << table.jugadores[0].getFichas() << " fichas ***\n";
        else if (table.darGanador() == 1)
            std::cout << name1 << " <- con " << table.jugadores[1].getFichas() << " fichas ***\n";
    }
    else
    {
        std::cout << "--- Empate ---\n";
    }
}

unsigned int juego::entradaNum()
{
    unsigned int y;

    while(true) {
        std::cout << "Ingrese la fila: ";
        if(std::cin >> y) {
            if(y > 0 && y <= rows) return y;

            else {
                std::cout << "Entrada no valida\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        else {
            std::cout << "Entrada no valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

unsigned int juego::entradaString()
{
    std::string *nombres;
    std::string x;
    std::locale loc;
    unsigned int x_, j;

    nombres = table.getNombres_col();

    while(true) {

        std::cout << "Ingrese la columna: ";
        std::cin >> x;

        for (char &c : x) {               //pasamos a mayusculas
            c = std::toupper(c, loc);
        }

        for (int i = 0; i < rows; i++) {  //buscamos los nombres

            if(x == nombres[i]) {          //buscamos si coinciden
                x_ = i + 1;                //retornamos la posicion encontrada
                return x_;
            }
        }
        std::cout << "columna incorrecta\n";
    }
}

void juego::start_game()
{
    std::string name1;
    std::string name2;

    std::cout<<"Ingrese el nombre del jugador 1: ";
    std::cin>>name1;
    std::cout<<"Ingrese el nombre del jugador 2: ";
    std::cin>>name2;
    set_jugadores(name1, name2);
    jugar(name1, name2);
}

void juego::set_jugadores(std::string pl1, std::string pl2)
{
    Datosjuego[0][0] = pl1;
    Datosjuego[1][0] = pl2;
}

void juego::set_fichas()
{
    Datosjuego[0][1] = std::to_string(table.jugadores[0].getFichas());
    Datosjuego[1][1] = std::to_string(table.jugadores[1].getFichas());
}

void juego::append_results(const std::string &path)
{
    std::string* data = new std::string[5];

    // Fecha y hora
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::string horaActual = std::ctime(&time);
    horaActual.pop_back(); //Quitar el caracter de finalización de línea

    data[0] = horaActual;
    data[1] = Datosjuego[0][0];
    data[2] = Datosjuego[1][0];
    //data[3] = Datosjuego[table.darGanador()][0]; //para cuando este definida la función
    data[3] = Datosjuego[1][0]; //Test
    //data[4] = Datosjuego[table.darGanador()][1]; //para cuando este definida la función
    data[4] = std::to_string(2); //Test

    std::ofstream archivo(path, std::ios::app); // Modo Append

    if(!archivo.is_open()) {
        std::cerr << "Error: El archivo no es accesible." << std::endl;
    }

    else {
        for (int i = 0; i < 5; ++i) {
            archivo << data[i];
            if (i < 4) {
                archivo << ';';
            }
        }
        archivo << std::endl;

        archivo.close();
    }

    delete[] data;
}

void juego::juego_finalizado(juego *game, const std::string &path)
{
    std::cout<<"La partida ha finalizado, los resultados seran agregados al historial " <<std::endl;
    game->set_fichas();
    game->append_results(path);

}

juego::~juego()
{
    for(unsigned int i = 0; i < 2; i++)
    {
        delete []Datosjuego[i];
    }
    delete []Datosjuego;
}
