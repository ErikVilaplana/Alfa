
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
    return _outsrc;
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

/*
void Escena::reset(bool mod, Enemigo enemigo[][], Jugador player)
{
    _dir=1;
    _x2=1;
    _nenemigo=35;
    _vel=45;
    for(int i=0; i<7; i++){
        for(int j=0; j<5; j++){
            enemigo[i][j].setX(i*110+120) ;
            enemigo[i][j].setY( j*60-500) ;
            enemigo[i][j].setHit(false) ; 
        }
        
    }
    if(mod)
    {
        player.setPts(0);
        player.setVidas(2);
        
        
    }
}
*/


/*void Escena::reset(Enemigo eny[][],bool mod){
    _s8.stop(); 
    int outscr=-100;	
    _x2      =  1;
    _vel  = 45;
    _disc->y =  0;
    _disc->shot = false;
    _disc->x = outscr;
    _pup->x  = outscr;
    sh[0]->x= outscr;
    sh[1]->x= outscr;
    sh[2]->x= outscr;
    spUp = 0;
	
    if(mod || !_nenemigo){
        _nenemigo = 35;
        dir  =  1;
        for(int i=0; i<7; i++){
            for(int j=0; j<5; j++){
                eny[i][j].setX(i*110+120) ;
                eny[i][j].setY( j*60-500) ;
                eny[i][j]._Shit = false; 
            }
        }
        pw_sh = 1;
        stage++;
    }
    if(mod){
        _pts=0;
        _stage = 1;
        _missile=0;
        _vidas  =2;
        _p1->x = 490;
        _pw_sh = 1;
        s11.play(); 
        _Timer(50);
    }
    _p1->hit= false;	
    _m1.stop();
    _Timer(100);
    _m1.play();
}*/