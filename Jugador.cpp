#include "Jugador.h"


Jugador::Jugador()
{
     
}

Jugador::~Jugador()
{
    
}
void  Jugador::setName(String name)
{
    _name = name;
}
String Jugador::getName()
{
    return _name;

}
void Jugador::animando(int step, int velocidad)  
{
    
    //_wx=(step > velocidad/2) ? _awx + _w  : 0; // operador ternario en base a un juego clasico
    //_wx=(step > velocidad/4) ? _awx + (_w * 2)  : _awx; // operador ternario en base a un juego clasico
    if(step<10)
    {
        _wx=_awx;
    }else if(step<20)
    {
        _wx=_awx + _w ;
    }else if(step<30)
    {
        _wx=_awx + (_w * 2);
    }
    
}
void Jugador::control(RenderWindow * window, int pos, Disparo * disp, Sprite _spmapa) 
{
    Event e;
    
    _spmapa.setPosition(_x-1000,-100);
    
    
    while (window->pollEvent(e))   { if(e.type == Event::Closed) {window->close();}}

    if(Keyboard::isKeyPressed(Keyboard::Left) && _x >100)
    {
        _x-=8;
        _spmapa.setPosition(_x-1000,-100);
        
        
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right) &&  _x <840)
    {
        _x+=8;
        _spmapa.setPosition(_x-1000,-100);
        
        
    }
    else if(Keyboard::isKeyPressed(Keyboard::Escape)){exit(0);}//cerrar juego
    // disparos
    else if(Keyboard::isKeyPressed(Keyboard::Space) && (pos >= 300) && disp->getY() <=-20)
    {   disp->setShot(true);
    }else
        { disp->setShot(false); }
    if( disp->getShot() && disp->getY() <= -20)
    {
        disp->setX(_x+30);
        disp->setY(_y-15);
        
    }
    if(disp->getY() > -20) disp->setYacum(5);
    window->draw(_spmapa);
}

int Jugador::getRecord()
{
    return this->_record;
}
float Jugador::getPts()
{
    return _pts;
}
int Jugador::getVidas(){
    return this->_vidas;
}
int Jugador::getDisparo(){
    return this->_disparo;
}
int Jugador::getVelocidad()
{
    return this->_velocidad;
}
bool Jugador::getHit()
{
    return _hit;
}
void  Jugador::setPts(int pts)
{
    _pts+=pts;
}
int Jugador::getX()
{
    return _x;
}
void Jugador::setVidasDown()
{
    _vidas--;
}
void Jugador::setVidas(int v)
{
    _vidas=v;
}
void Jugador::setHit(int h)
{
    _hit=h;
};
void Jugador::setX(int x)
{
    _x=x;
}

bool Jugador::colision(Disparo * b){
    
    return this->_x+this->_w > b->getX() && this->_x < b->getX()+b->getW() && this->_y + this->_h > b->getY() && this->_y < b->getY()+b->getH();
    
}