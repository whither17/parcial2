#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include <chrono>
#include <fstream>
#include <string>
#include <locale>

class juego
{
private:
    std::string** Datosjuego;
    void jugar(std::string name1, std::string name2);
    unsigned int entradaNum();
    unsigned int entradaString();
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
