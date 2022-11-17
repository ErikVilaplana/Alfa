﻿#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "ArchivoEstadistica.h"
#include "Enemigo.h"

#include "Escena.h"
#include "Jugador.h"
#include "Disparo.h"
#include "MainMenu.h"
using namespace std;
using namespace sf;

class Juego 
{
private:
    sf::RenderWindow* _window;
    MainMenu  * _mainMenu;
    ArchivoEstadistica _arch;
    int  _col=0, _fila=0, _limitY;
    Jugador  _estadistica[10]{},  reg,aux;
    Escena  _pantalla;
    String   _name;
    Jugador * _jugador;
    Event  _aevent;
    Enemigo * _enemigo[8][5],* _boss;
    Base * _escena, * _explosion, *_logo;
    Disparo * _disparoP, * _disparoE1, *_disparoE2,*_bossE1,*_bossE2;
    Font * font;
    Texture  _texmapa;
    Sprite  _spmapa;

    
public:
    Juego();
    ~Juego();
    void crearEnemigo();
    
    void init();// precarga
    void update();// reset o pasa nivel
    void draw();
    void deInit();// precargar
    void runJuego();/////////
    void setPosEnemigo();
    void initMenu();
    void setEnemigos();
    void setBoss();
    void fondo();
    void getEstadistica();
    void getAcercaDe();
    
};


