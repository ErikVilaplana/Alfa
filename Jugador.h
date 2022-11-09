#pragma once
#include<SFML/Graphics.hpp>
#include "Base.h"
#include "Disparo.h"

using namespace sf;
class Jugador : public Base
{
    private:
    int  _vidas=3 , _disparo=3,_pts=0, _record=92000, _velocidad=0;
    Texture _t;
    Sprite _spr;
    bool _hit, _shot;

    public:
    
    Jugador();

    Jugador(int wx, int wy, int x, int y, int w, int h, const String iSrc) : Base(wx,  wy, x,  y,  w,  h){
        
        
        _shot=0;
        _hit=0;
        
        _t.loadFromFile(iSrc);
        _spr.setTexture(_t);
    }
    
    ~Jugador();
    void show(RenderWindow &window);

    void control(RenderWindow &window, int pos, Disparo &disp);

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
