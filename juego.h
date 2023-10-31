#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include <chrono>
#include <fstream>

class juego
{
private:
    std::string** Datosjuego;
public:
    juego();
    tablero table;
    void start_game();
    void set_jugadores(std::string pl1, std::string pl2);
    void set_fichas();
    void append_results(const std::string& path);
    void juego_finalizado(juego* game, const std::string& path);
    ~juego();
};

#endif // JUEGO_H
