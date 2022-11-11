#pragma once
#include <SFML/Graphics.hpp>

#include "Enemigo.h"
#include "Jugador.h"

using namespace sf;

class Escena 
{
private:
    // Tratar de ordenarlo en Escena
    int _vidas,_dir=0, _outsrc=670, _step=0, _vel=45 , _nenemigo=35, _x2=0 , _width=1024, _height=720, _nivel=0, _fila=3, _tsort=0, _texp=0
    ,_stage=1,_misil;
    String  _name="";
    Clock _reloj;
    Text _text;
    Font _font;
    bool _ban, _hit;///no
    Texture texmapa;
    Sprite spmapa;
    const char * _fu="img/galaga.ttf", *_fd="img/JetBrainsMonoNL-Bold.ttf", * _ft="img/Comication.ttf";
public:
    Escena();
    void texto(RenderWindow &w, const char *txt, int tipo, int num, int tam, int pinta, int x, int y);
        
    void delay(int time=1);

    int getWidth();
    int getHeight();

    void  reset(Jugador &b);
    //frame 
    int getStep();
    int getTexp();
    int getTsort();
    int getVel();
    int & getDir();
    bool & getBan();
    int getOutsrc();
    int getNEnemigo();
    void setNEnemigo(int n);
    void setDir(int d);
    void setVel(int v);
    void setStep(int s);
    void setTsort(int t);
    void setTexp(int t);
    void setTexpCont();
    void setOutSrc(int outsrc ){}
    

    //RenderWindow getWindow(int w=1024, int h=720);
    int getStepCont();
    void dibujar(RenderWindow & window);
    
};
