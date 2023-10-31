#include "juego.h"

juego::juego()
{
    Datosjuego = new std::string *[2];
    for(unsigned int i = 0; i < 2; i++)
    {
        Datosjuego[i] = new std::string[2];
    }

    table.jugadores[0].setColor(' ');
    table.jugadores[1].setColor(' ');

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
    //data[3] = Datosjuego[table.darGanador()-1][0]; para cuando este definida la función
    data[3] = Datosjuego[1][0]; //Test
    //data[4] = Datosjuego[table.darGanador()-1][1]; para cuando este definida la función
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
