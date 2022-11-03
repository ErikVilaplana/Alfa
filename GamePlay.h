#pragma once
#include <SFML/Graphics.hpp>

#include "Enemigo.h"
#include "Jugador.h"
using namespace sf;
class GamePlay
{
private:
    Enemigo enemigo;
    Jugador player;
    
public:

    void setEnemigos();
    void setPlayer();
    
};
