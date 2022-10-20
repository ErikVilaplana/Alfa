#pragma once
#include<SFML/Graphics.hpp>

#include "Enemigo.h"
using namespace sf;
class Jugador
{
    private:
    int  _vidas=3 , _disparo=3,_pts=0, _record=92000, _velocidad=0;
    
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
    void show(RenderWindow &window);

    void control(RenderWindow &window, int pos, Enemigo disp[]);

    int getRecord();
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
