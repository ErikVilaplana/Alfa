﻿#pragma once
#include<SFML/Graphics.hpp>
#include "Base.h"
#include "Disparo.h"


using namespace sf;
class Enemigo : public Base 
{
    private:
    int _step=0, _dir=0, _cant=35, _velocidad=45;
    
    Texture _t;
    Sprite _spr;
    bool _hit, _shot, _ban;
    
    public:
    
    Enemigo(int wx, int wy, int x, int y, int w, int h, const String iSrc): Base(wx,  wy, x,  y,  w,  h){
    
        _shot=0;
        _hit=0;
		
        _t.loadFromFile(iSrc);
        _spr.setTexture(_t);
    }
    Enemigo();
    ~Enemigo();
    void show(RenderWindow &window);

    int getWx();
    int getAwx();
    int getX();
    int getY();
    int getH();
    int getW();
    int getStep();
    
    void setX(int x);
    void setY(int Y);
    
    void setShot(bool shot);
    
    void setHit(bool hit);
    bool getShot();
    void setYacu(int Y);
    void setYacum(int Y);


    bool getHit();
    
    void movimiento(int step, int vel,int &dir, bool &ban);
    int desplazar();
    void animando(int step, int vel );
    bool colision(Disparo disp);
    
};
