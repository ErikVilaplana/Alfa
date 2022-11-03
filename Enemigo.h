#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
class Enemigo
{
    private:
    int _step=0, _dir=0, _cant=35, _velocidad=45;
    int _wx,_wy,_x,_y,_w,_h,_awx;
    Texture _t;
    Sprite _spr;
    bool _hit, _shot, _ban;
    
    public:
    
    Enemigo(int wx, int wy, int x, int y, int w, int h, const String iSrc){
        _awx=wx;
        _wx=wx;
        _wy=wy;
        _x=x; // posicion en x
        _y=y; // posicion en y
        _w=w; // ancho
        _h=h, // alto
        _shot=0;
        _hit=0;
		
        _t.loadFromFile(iSrc);
        _spr.setTexture(_t);
    }
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
    bool colision(Enemigo disp[]);
    
};
