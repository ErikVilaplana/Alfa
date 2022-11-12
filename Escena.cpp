﻿
#include "Escena.h"
Escena::Escena()
{
    texmapa.loadFromFile("img/fondo.jpg");
    spmapa.setTexture(texmapa);
}

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
int & Escena::getDir()
{
   return _dir; 
}
bool & Escena::getBan()
{
    return _ban; 
}
int Escena::getOutsrc()
{
    return _outsrc;
}
int Escena::getTsort()
{
    return _tsort;
}
void Escena::setTsort(int t)
{
    _tsort = t ;
}
int Escena::getTexp()
{
    return _texp;
}
void Escena::setTexp(int t)
{
    _texp = t ;
}
void Escena::setTexpCont()
{
    _texp -- ;
}
int Escena::getWidth()
{
    return _width;
}
int Escena::getHeight()
{
    return _height;
}
void  Escena::reset( Jugador & b)
{
    //s8.stop(); 
    _outsrc=670;	
    _x2      =  1;
    _vel  = 45;	
    /*disc->y =  0;
    disc->shot = false;
    disc->x = outscr;
    pup->x  = outscr;
    sh[0]->x= outscr;
    sh[1]->x= outscr;
    sh[2]->x= outscr;
    spUp = 0;*/
    
    if(b.getVidas()==-1){
        b.setPts(0);
        _stage = 1;
        _misil=0;
        b.setVidas(2);
        b.setX(490);
        //pw_sh = 1;
        //s11.play(); 
        //Timer(50);
    }
    b.setHit(false);
    //m1.stop();
    //Timer(100);
    //m1.play();
}
void Escena::dibujar(RenderWindow &window){
    window.draw(spmapa);

}

void Escena::gameOver(RenderWindow & window,Jugador &b){
    bool sair = 0;
    /*m1.stop();
    m2.play();*/
	
    while(!sair){
        Event e;
        while(window.pollEvent(e)) if(e.type==Event::Closed) exit(0);
        if(Keyboard::isKeyPressed(Keyboard::Escape)){exit(0);}
        if(Keyboard::isKeyPressed(Keyboard::Space)) sair = true;
        this->texto(window, "Presione tecla SPACE para Volver a Jugar ",1, 0, 30,0xffffffFF, 420, 600);	
        if(this->_ban)	this->texto(window, "Game Over",1, 0, 130,0xffffffFF, 250, 212);
        else{
            this->texto(window, "LARAGA",1, 0, 130,0xffffffFF, 80, 70);
            this->texto(window, "UTN",1, 0, 130,0xffffffFF, 290, 232);
        }
        this->texto(window, "Record",1, 0, 30,0xffffffFF, 460, 442);
        this->texto(window, "",1, 999, 30,0xffffffFF, 490, 510);
        window.display();
        /*Timer();*/
        window.clear(Color::Black);	
    }
				
    /*m2.stop();*/
    this->reset(b);
    
}