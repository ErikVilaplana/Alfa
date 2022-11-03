#pragma once
#include<SFML/Graphics.hpp>

#include "Enemigo.h"
using namespace sf;
class Jugador
{
    private:
    int  _vidas=4 , _disparo=1, _puntos=0, _puntajeAcumulado=0, _velocidad=0;
    
    int _wx,_wy,_x,_y,_w,_h,_awx;
    Texture _t;
    Sprite _spr;
    bool _hit, _shot;

    public:
    
    Jugador(int wx, int wy, int x, int y, int w, int h, const String iSrc){
        _awx=wx;
        _wx=wx;
        _wy=wy;
        _x=x;
        _y=y;
        _w=w;
        _h=h,
        _shot=0;
        _hit=0;
		
        _t.loadFromFile(iSrc);
        _spr.setTexture(_t);
    }
    Jugador();
    ~Jugador();
    void show(RenderWindow &window);

    void control(RenderWindow &window, int pos, Enemigo disp[]);

    int getPuntajeAcumulado();
    int getPts();
    int getX();
    int getVidas();
    int getDisparo();
    int getVelocidad();
    
    void setPts(int pts);
    void setVidas(int v);
    void setHit(int h);
    void setX(int x);
};
