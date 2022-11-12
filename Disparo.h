#pragma once

#include<SFML/Graphics.hpp>

#include "Base.h"
using namespace sf;
class Disparo : public Base{
    
private:
bool _shot;
public:
    
    Disparo(int wx, int wy, int x, int y, int w, int h, const String iSrc): Base(wx,  wy, x,  y,  w,  h, iSrc){
        
        ///////////////
        _shot=false;
        
        
        
    }
    Disparo();
    ~Disparo();

    
    

    int getAwx();
    int getWx();
    int getWy();
    
    int getX();
    int getY();
    int getH();
    int getW();
    
    
    
    void setShot(bool shot);
    bool getShot();
    
    void SetAwx(int awx);
    void SetWx(int wx);
    void SetWy(int wy);
    void setX(int x);
    void setY(int Y);
    
    
    void setHit(bool hit);
    
    void setYacu(int Y);
    
    void setYacum(int Y);

    void setAcuX(int x);
    
    
};

