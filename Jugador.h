#pragma once
#include<SFML/Graphics.hpp>
#include "Base.h"
#include "Disparo.h"

using namespace sf  ;
class Jugador : public Base
{
    private:
    int  _vidas=2 , _disparo=3, _record=92000, _velocidad=0;
    float _pts=0;
    bool _hit, _shot;
    String   _name;
    public:
    
    Jugador();

    Jugador(int wx, int wy, int x, int y, int w, int h, const String iSrc) : Base(wx,  wy, x,  y,  w,  h, iSrc){
        
        _shot=0;
        _hit=0;
    }
    
    ~Jugador();
    

    void control(RenderWindow *window, int pos, Disparo &disp);

    int getRecord();
    float getPts();
    int getX();
    int getVidas();
    bool getHit();
    int getDisparo();
    int getVelocidad();
    
    void setPts(int pts);
    void setVidas(int v);
    void setVidasDown();
    void setHit(int h);
    void setX(int x);
    bool colision(Disparo disp);
    void setName(String name);
    String getName();
};
