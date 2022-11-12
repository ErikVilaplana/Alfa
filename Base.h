#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Base{
    
protected:
 
    
    int _wx,_wy,_x,_y,_w,_h,_awx;
    Texture _t;
    Sprite _spr;
    bool _hit;

public:
    
    Base(int wx, int wy, int x, int y, int w, int h,const String iSrc){
        
        _wx=wx;
        _wy=wy;
        _x=x; // posicion en x
        _y=y; // posicion en y
        _w=w; // ancho
        _h=h; // alto
        
        _t.loadFromFile(iSrc);
        _spr.setTexture(_t);
        ///////////////
        
        _hit=false;
        _awx=wx;
        
    }

    Base();
    ~Base();

    void show(RenderWindow &window);

    int getAwx();
    int getWx();
    int getWy();
    
    int getX();
    int getY();
    int getH();
    int getW();
    
    int getStep();
    
    void SetAwx(int awx);
    void SetWx(int wx);
    void SetWy(int wy);
    void setX(int x);
    void setY(int Y);
    
    void setShot(bool shot);
    void setHit(bool hit);
    bool getShot();
    void setYacu(int Y);
    void setYacum(int Y);

    void setAcuX(int x);
    
    
};
