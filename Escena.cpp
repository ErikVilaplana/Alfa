
#include "Escena.h"

void Escena::texto(RenderWindow &w, const char* txt, int tipo, int num, int tam, int pinta, int x, int y)
{
    if(txt=="")
    {
        char chr[sizeof(num)];
        snprintf(chr,sizeof(num),"%d",num);
        txt=chr;//mirar
    }
    if(tipo==1)
    {
        _font.loadFromFile(_ft);
    }
    else{_font.loadFromFile(_fd);}
    
    _text.setFont(_font);
    _text.setString(txt);
    _text.setCharacterSize(tam);///
    _text.setFillColor(Color(pinta));
    _text.setStyle(Text::Bold | Text::Italic);
    _text.setPosition(x,y);
    w.draw(_text);
}

void Escena::delay(int time)
{
    float res = time *0.01, tiempo=0;
    while (tiempo<=res)
    {
        float ope = _reloj.getElapsedTime().asSeconds();
        _reloj.restart();
        tiempo+=ope;
    }
}
void Escena::reset(bool a)
{
    
    _x2=1;
    _vel=45;
    _nenemigo=35;
}
int Escena::getStep()
{
    return _step;
}
int Escena::getVel()
{
    return _vel;
}

int Escena::getNEnemigo()
{
    return _nenemigo;
}
void Escena::setNEnemigo(int n)
{
    _nenemigo = n;
}

void Escena::setVel(int v)
{
    _vel=v;
}
void Escena::setStep(int s)
{
    _step = s;
}
int Escena::getStepCont()
{
    return _step ++;
}
