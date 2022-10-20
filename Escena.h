#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Escena
{
private:
    // Tratar de ordenarlo en Escena
    int _step=0, _vel=45, _dir=0 , _nEnemigo=35, _x2=0;
    Clock _reloj;
    Text _text;
    Font _font;
    bool _ban;
    const char * _fu="img/Comication.ttf", *_fd="img/JetBrainsMonoNL-Bold.ttf", * _ft="img/Comication.ttf";
public:
    void texto(RenderWindow &w, const char *txt, int tipo, int num, int tam, int pinta, int x, int y);
    void delay(int time=1);
    void reset(bool);

    int getStep();
    int getVel();
    int getDir();
    int getNEnemigo();
    void setNEnemigo(int n);
    void setDir(int d);
    void setVel(int v);
    void setStep(int s);
    int getStepCont();
    
};
