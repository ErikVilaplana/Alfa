﻿#include "Escena.h"
#include <SFML/Graphics.hpp>
void Escena::texto(RenderWindow &w, const char* txt, int tipo, int num, int tam, int pinta, int x, int y)
{
    if(txt=="")
    {
        char chr[sizeof(num)];
        snprintf(chr,sizeof(num),"%d",num);
        txt=chr;//mirar
    }
    if(tipo==1)
    {_font.loadFromFile(_ft);
    }else{_font.loadFromFile(_fd);}
    _text.setFont(_font);
    _text.setString(txt);
    _text.setCharacterSize(tam);
    _text.setFillColor(Color(pinta));
    _text.setStyle(Text::Bold | Text::Italic);
    _text.setPosition(x,y);
    w.draw(_text);
}

void Escena::delay(int time)
{
    float res = time *0.01, tiempo=0;
    while (tiempo<=res)
    {
        float ope = _reloj.getElapsedTime().asSeconds();
        _reloj.restart();
        tiempo+=ope;
    }
}
void Escena::reset(bool a)
{
    _dir=0;
    _x2=1;
    _vel=45;
    _nEnemigo=35;
}
int Escena::getStep()
{
    return _step;
}
int Escena::getVel()
{
    return _vel;
}
int Escena::getDir()
{
    return _dir;
}
int Escena::getNEnemigo()
{
    return _nEnemigo;
}
void Escena::setNEnemigo(int n)
{
    _nEnemigo = n;
}
void Escena::setDir(int d)
{
    _dir = d;
}
void Escena::setVel(int v)
{
    _vel=v;
}
void Escena::setStep(int s)
{
    _step = s;
}
int Escena::getStepCont()
{
    return _step ++;
}
