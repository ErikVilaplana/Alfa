#include<SFML/Graphics.hpp>
using namespace sf;
#include "Base.h"
Base::Base(){}
Base::~Base(){}


int Base::getWx() 
{
    return _wx;
}

int Base::getAwx() 
{
    return _awx;
}
int Base::getX() 
{
    return _x;
}
int Base::getY() 
{
    return _y;
}
int Base::getH() 
{
    return _h;
}
int Base::getW() 
{
    return _w;
}
int Base::getStep() 
{
    return _step;
}
void Base::setX(int x)
{
    _x = x;
}
void Base::setY(int y)
{
    _y = y;
}
void Base::setAcuX(int x)
{
    _x += x;
}
