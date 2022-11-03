﻿#pragma once
#include <SFML/Graphics.hpp>
#include "Escena.h"
using namespace sf;

class Escena 
{
private:
    // Tratar de ordenarlo en Escena
    int _step=0, _vel=45 , _nenemigo=35, _x2=0 , _width=1024, _height=720, _nivel=0, _fila=3;
    String  _name="";
    Clock _reloj;
    Text _text;
    Font _font;
    bool _ban;///no
    VideoMode vid;
    
        
    
    const char * _fu="img/galaga.ttf", *_fd="img/JetBrainsMonoNL-Bold.ttf", * _ft="img/Comication.ttf";
public:
    void texto(RenderWindow &w, const char *txt, int tipo, int num, int tam, int pinta, int x, int y);

    void delay(int time=1);

    void reset(bool);
    //frame 
    int getStep();
    int getVel();
    int getDir();
    int getNEnemigo();
    void setNEnemigo(int n);
    void setDir(int d);
    void setVel(int v);
    void setStep(int s);
    RenderWindow getWindow(int w=1024, int h=720);
    int getStepCont();
    RenderWindow drawt();
    /*void draw(RenderTarget& target, RenderStates state) const
    {
        target.draw();
    }*/
    
    virtual void dibujar(sf::RenderWindow &w) = 0;
    //w.create(sf::VideoMode(1130,600),"Return from hell");
    
};
