#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigo.h"
#include "Escena.h"
#include "Jugador.h"
#include "Disparo.h"
using namespace std;
using namespace sf;

class Juego 
{
private:
    sf::RenderWindow* _window;
    String   _name;
public:
    Juego();
    ~Juego();
    void init();// precarga
    void update();// reset o pasa nivel
    void draw();
    void deInit();// precargar
    void runJuego();/////////
    void setName(String name);
    String getName();
     
};


