#pragma once
#include <SFML/Graphics.hpp>

#include "Enemigo.h"
#include "Jugador.h"

using namespace sf;
using namespace std;

class Escena 
{ 
private:
    //  Tratar de or denarlo en Escena  
    int _x2=0, _dir=0, _outsrc=670, _step=0, _vel=45 , _nenemigo=0 , _width=1024, _height=720,
    _nivel=5, _fila=5, _columna=3, _tsort=0, _texp=0 ,_stage=1,_misil;

    string _input_text;
    char _name[20];
    Clock _reloj;
    Text _text;
    Font _font;
    bool _ban, _hit, _init=false;///no
    Texture _texmapa;
    Sprite _spmapa;
    
    const char * _fu="img/galaga.ttf", *_fd="img/JetBrainsMonoNL-Bold.ttf", * _ft="img/Comication.ttf";
public:
    
    Escena();
    void texto(RenderWindow * w, String txt, int tipo, int num, int tam, int pinta, int x, int y);
    int getNivel();
    int getFila();
    int getColumna();
    void setColumna();

    
    void setFila(int f);
    void delay(int time=1);
    void setColumnaI(int i);
    int getWidth();
    int getHeight();

    void  reset(Jugador *b);
    //frame 
    int getStep();
    int getTexp();
    int getTsort();
    int getVel();
    int & getDir();
    bool & getBan();
    bool getInit();
    void setInit(bool ban);
    int getOutsrc();
    int getNEnemigo();
    void setNEnemigo(int n);
    void setDir(int d);
    void setVel(int v);
    void setStep(int s);
    void setTsort(int t);
    void setTexp(int t);
    void setTexpCont();
    void setOutSrc(int outsrc );
    void setNivel(int n);
    
    void gameOver(RenderWindow * window, Jugador * b);
    void gameWon(RenderWindow * window, Jugador * b);
    void dibujar(RenderWindow &window);
    //RenderWindow getWindow(int w=1024, int h=720);
    int getStepCont();
    void upNivelWin(RenderWindow * window, Jugador * b);
    void setInicio(RenderWindow * window);
    
    void setName(const char * name);
    const char * getName();
    
};
