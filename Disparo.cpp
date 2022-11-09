


#include "Disparo.h"
Disparo::Disparo()
{
    
}

Disparo::~Disparo()
{
    
}
int Disparo::getWx() 
{
    return _wx;
}

int Disparo::getAwx() 
{
    return _awx;
}
int Disparo::getX() 
{
    return _x;
}
int Disparo::getY() 
{
    return _y;
}
int Disparo::getH() 
{
    return _h;
}
int Disparo::getW() 
{
    return _w;
}
int Disparo::getStep() 
{
    return _step;
}
void Disparo::setX(int x)
{
    _x = x;
}
void Disparo::setY(int y)
{
    _y = y;
}
void Disparo::setAcuX(int x)
{
    _x += x;
}
void Disparo::setYacu(int y)
{
    _y += y;
}
void Disparo::setYacum(int y)
{
    _y -= y;
}

void Disparo::show(RenderWindow &window){
    _spr.setTextureRect(IntRect(_wx,_wy,_w,_h));
    _spr.setPosition(_x,_y);
    if(!_hit) window.draw(_spr);
}

bool Disparo::getShot()
{
    return _shot;
}

void Disparo::setShot(bool shot)
{
    _shot = shot;
}