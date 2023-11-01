#include "juego.h"

#include <fstream>
#include <string>


void imprimir_historial(const std::string& path);

int main()
{

    tablero table;
    unsigned int x, y, player2;
    char color;


    while(table.comprobarEstado()) {

        for(int i = 0; i < 2; i++) {
            table.printTablero();
            if(i == 0) {
                color = black;
                player2 = 1;
            }
            else{
                color = white;
                player2 = 0;
            }

            std::cout << color <<" ingrese x: ";
            std::cin >> x;

            std::cout<< color << " ingrese y: ";
            std::cin >> y;
            table.comprobarMov(color, x-1 , y-1, i, player2);
            table.motrarEstadisticas();
        }


    }


/*
    std::string path = "C:/QtProjects/Parcial2_Shared/register/results.txt";


    int opcion = 1;

    while(opcion != 0){

        std::cout<<"--Bienvenido al juego de Othello--"<<std::endl;
        std::cout<<"Ingrese 1 para jugar una nueva partida"<<std::endl;
        std::cout<<"Ingrese 2 para mostrar historial de partidas"<<std::endl;
        std::cout<<"Ingrese 0 para salir del Juego"<<std::endl;
        std::cin >> opcion;

        switch(opcion)
        {
        case 0: std::cout << "Has salido"<<std::endl;
            break;

        case 1: std::cout <<"Nueva Partida"<<std::endl;
            {
                juego* game = new juego;
                game->start_game();
                game->table.printTablero();

                bool game_ended = false;
                while(!game_ended)
                {
                    //Preguntar qué ficha ingresar
                    game->table.comprobarMov(white, 0, 6, 0, 1);
                    game->table.comprobarMov(black, 0, 7, 1, 0);
                    game->table.printTablero();
                    game_ended = true;
                }
                game->juego_finalizado(game,path);

                delete game;
            }
            break;
        case 2: std::cout << "Historico de Partidas"<<std::endl;
            {
                imprimir_historial(path);
            }
            break;
        }
    }


    return 0;
*/
}

/* Función para imprimir el historial de partidas*/

void splitt_line(std::string* data, std::string row)
{
    int pos = 1;
    int index = 0;

    for(unsigned int i=0;i<row.length() && pos>=0;i=pos+1,index++){
        pos = row.find(';',i);
        data[index] = row.substr(i,pos-i);
    }
}

void imprimir_historial(const std::string &path)
{
    std::ifstream archivo(path);
    std::string line;
    int game_num = 1;

    if (!archivo.is_open()) {
        std::cerr << "Error: El archivo no es accesible." << std::endl;
        return;
    }

    else{
        std::string* data = new std::string[5]; //Array temporal para leer cada línea del archivo de texto

        while(!archivo.eof()){
            std::getline(archivo,line);

            if (line == "") break; // Si llega a la última línea

            splitt_line(data, line);
            std::cout << "Juego " << game_num << "\n";
            std::cout << "Fecha: " << data[0] << "\n";
            std::cout << "Jugador 1: " << data[1] << "\n";
            std::cout << "Jugador 2: " << data[2] << "\n";
            std::cout << "Ganador: " << data[3] << "\n";
            std::cout << "Numero de fichas: " << data[4] << "\n";
            std::cout << "------------------------------------\n";
            game_num++;
        }
        delete[] data;
    }
}
