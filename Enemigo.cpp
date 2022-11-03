﻿#include "Enemigo.h"
int Enemigo::getWx() 
{
    return _wx;
}

int Enemigo::getAwx() 
{
    return _awx;
}
int Enemigo::getX() 
{
    return _x;
}
int Enemigo::getY() 
{
    return _y;
}
int Enemigo::getH() 
{
    return _h;
}
int Enemigo::getW() 
{
    return _w;
}
int Enemigo::getStep() 
{
    return _step;
}
void Enemigo::setX(int x)
{
   _x = x;
}
void Enemigo::setY(int y)
{
    _y = y;
}
void Enemigo::setYacu(int y)
{
    _y += y;
}
void Enemigo::setYacum(int y)
{
    _y -= y;
}

bool Enemigo::getShot()
{
    return _shot;
}

void Enemigo::setShot(bool shot)
{
    _shot = shot;
}
void Enemigo::setHit(bool hit)
{
    _hit = hit;
}
bool Enemigo::getHit()
{
    return _hit;
}


void Enemigo::show(RenderWindow &window){
    _spr.setTextureRect(IntRect(_wx,_wy,_w,_h));
    _spr.setPosition(_x,_y);
    if(!_hit) window.draw(_spr);
}
void Enemigo::movimiento(int step, int velocidad, int &dir,bool &ban)
{
    
    if(this->_x <10){ban=true; dir=1;}
    if(this->_x >950){ban=true; dir=-1;}
    
    this->_x+=(step==(velocidad/2) || !step)*dir*(50 - velocidad);
    
}
int Enemigo::desplazar()
{
    return (30 -(this->_y < 300)*25);/// desplaza hacia abajo
}
void Enemigo::animando(int step, int velocidad)  
{
    
    _wx=(step > velocidad/2) ? _awx + _w : _awx; // operador ternario en base a un juego clasico
    
}

bool Enemigo::colision(Enemigo b[]){
    
    return this->_x+this->_w > b->getX() && this->_x < b->getX()+b->getW() && this->_y + this->_h > b->getY() && this->_y < b->getY()+b->getH();
    
}


