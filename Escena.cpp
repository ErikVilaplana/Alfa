
#include "Escena.h"

#include "ArchivoEstadistica.h"

Escena::Escena()
{
    
   
    
}

void Escena::texto(RenderWindow *w, String txt, int tipo, int num, int tam, int pinta, int x, int y)
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
    w->draw(_text);
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
int Escena::getNivel()
{
    return _nivel;
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
bool  Escena::getInit()
{
    return _init; 
}
void  Escena::setInit(bool ban)
{
    _init=ban; 
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
int Escena::getFila()
{
    return _fila;
}
int Escena::getColumna()
{
    return _columna;
}
void Escena::setColumna()
{
    _columna++;
}
void Escena::setColumnaI(int i)
{
    _columna=i;
}
void Escena::setFila(int f)
{
    _fila= f;
}


void  Escena::reset( Jugador * b)
{
    //s8.stop(); 
    _outsrc=670;	
    _x2      =  1;
    if(_nenemigo==(_fila*_columna))
        _vel  = 45;	
    /*disc->y =  0;
    disc->shot = false;
    disc->x = outscr;
    pup->x  = outscr;
    sh[0]->x= outscr;
    sh[1]->x= outscr;
    sh[2]->x= outscr;
    spUp = 0;*/
    
    if(b->getVidas()==-1){
        b->setPts(0);
        _stage = 1;
        _misil=0;
        b->setVidas(2);
        
        //pw_sh = 1;
        //s11.play(); 
        //Timer(50);
    }
    b->setX(490);
    b->setHit(false);
    //m1.stop();
    //Timer(100);
    //m1.play();
}
void Escena::dibujar(RenderWindow &window){
    window.draw(_spmapa);

}

void Escena::gameOver(RenderWindow * window,Jugador * b){
    bool sair = 0;
    /*m1.stop();
    m2.play();*/
	
    while(!sair){
        Event e;
        while(window->pollEvent(e)) if(e.type==Event::Closed) exit(0);
        if(Keyboard::isKeyPressed(Keyboard::Escape)){_ban=false;}
        if(Keyboard::isKeyPressed(Keyboard::Space)) sair = true;
        this->texto(window, "Presione tecla SPACE para Volver a Jugar ",1, 0, 30,0xffffffFF, 420, 600);	
        if(this->_ban)	this->texto(window, "Game Over",1, 0, 130,0xffffffFF, 250, 212);
        else{
            this->texto(window, "LARAGA",1, 0, 130,0xffffffFF, 80, 70);
            this->texto(window, "UTN",1, 0, 130,0xffffffFF, 290, 232);
            sair=true;
        }
        this->texto(window, "Record",1, 0, 30,0xffffffFF, 460, 442);
        this->texto(window, "",1, 999, 30,0xffffffFF, 490, 510);
        window->display();
        /*Timer();*/
        window->clear(Color::Black);	
    }
				
    /*m2.stop();*/
    this->reset(b);
    
}
void Escena::setNivel(int n)
{
    _nivel=n;
}
void Escena::gameWon(RenderWindow * window,Jugador * b){
    bool salir = false;
    /*m1.stop();
    m2.play();*/
    
    while(!salir){
        Event e;
        while(window->pollEvent(e)) if(e.type==Event::Closed) exit(0);
        if(Keyboard::isKeyPressed(Keyboard::Escape)){exit(0);}
        if(Keyboard::isKeyPressed(Keyboard::G)) {_ban=true; salir = true;}
        if(Keyboard::isKeyPressed(Keyboard::S)) {_ban=false; }
        this->texto(window, "Presione tecla SPACE para Salir ",1, 0, 30,0xffffffFF, 420, 600);
        this->texto(window, "Presione tecla ESC para Salir ",1, 0, 30,0xffffffFF, 420, 600);
        if(this->_ban)	this->texto(window, "Soldado Has Ganado",1, 0, 50,0xffffffFF, 250, 212);
        else{
            
            this->texto(window, "LARAGA",1, 0, 50,0xffffffFF, 80, 70);
            this->texto(window, "UTN",1, 0, 50,0xffffffFF, 290, 102);
           
            /*for(int i = 0;i< arch.cantidadJugador();i++)
            {
                /*Jugador jugador=arch.leerJugador();#1#
                this->texto(window, "",1, 0, 50,0xffffffFF, 80, 150);
                this->texto(window, "UTN",1, 0, 50,0xffffffFF, 80, 180);
            }*/
            
            this->texto(window, "Presione tecla SPACE para Salir ",1, 0, 30,0xffffffFF, 420, 600);
        }
        this->texto(window, "Record",1, 0, 30,0xffffffFF, 460, 442);
        this->texto(window, "",1, 999, 30,0xffffffFF, 490, 510);
        window->display();
        /*Timer();*/
        window->clear(Color::Black);	
    }
				
    /*m2.stop();*/
    this->reset(b);
    
}

void Escena::upNivelWin(RenderWindow * window, Jugador * b)
{
    bool salir = false;
    /*m1.stop();
    m2.play();*/
    
    while (window->isOpen()&& !salir){
        Event e;
        while(window->pollEvent(e))
            if(e.type==Event::Closed) exit(0);
        if(Keyboard::isKeyPressed(Keyboard::Escape)) gameOver(window,b);

        this->texto(window, "Nivel",1, 0, 130,0xffffffFF, 250, 312);
        this->texto(window, "",1, this->_nivel, 130,0xffffffFF, 250, 150);
        this->texto(window, "Presione tecla SPACE para Volver a Jugar ",1, 0, 30,0xffffffFF, 420, 600);	
        if (e.key.code == Keyboard::Enter){
            
            this->_nivel++;
            this->setColumna();
            this->setNEnemigo(this->getColumna()*this->getFila());
            salir=true;
        }
        
        this->texto(window, "Record",1, 0, 30,0xffffffFF, 460, 442);
        this->texto(window, "",1, 999, 30,0xffffffFF, 490, 510);
        window->display();
        
        window->clear(Color::Black);	
    }
				
    
    
}
void Escena::setInicio(RenderWindow* _window)
{
    _texmapa.loadFromFile("img/bg.jpg");
    _spmapa.setTexture(_texmapa);
    _spmapa.setPosition(0,0);
    //crea variable para ingreso nombre del player
    string input_text;
    Font font;
    font.loadFromFile("img/galaga.ttf");
    Text text("", font);
    text.setOutlineThickness(2);
    text.setFillColor(Color::Blue);
    text.setOutlineColor(Color(127,127,127));
    text.setPosition(450,400);

    bool salir = false;
    
    
        while (_window->isOpen()&& !salir)
        {
            Event event;
            while (_window->pollEvent(event) )
            {
                if (event.type == Event::Closed)
                    _window->close();
                else if (event.type == Event::TextEntered) {
                    if (std::isprint(event.text.unicode))
                        input_text += event.text.unicode;
                }
                else if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::BackSpace) {
                        if (!input_text.empty())
                            input_text.pop_back();
                    }
                    if (event.key.code == Keyboard::Return) {
                        input_text += '\n';
                    }
                }
            
            }

            static Time text_effect_time;
            static bool show_cursor;

            text_effect_time += _reloj.restart();

            if (text_effect_time >= seconds(0.5f))
            {
                show_cursor = !show_cursor;
                text_effect_time = Time::Zero;
            }

            text.setString(input_text + (show_cursor ? '_' : ' '));
            if (!input_text.empty())
            {
                if (event.key.code == Keyboard::Escape) {
                    string s = input_text;
 
                    int n = s.length();
 
                    // declaring character array
                    
 
                    // copying the contents of the
                    // string to char array
                    strcpy(_name, s.c_str());
                        
                        salir = true;
                }
            }
            _window->clear();
            _window->draw(_spmapa);
            this->texto(_window,"Ingresa Tu nombre Piloto:",1,0,30,0xFFFF0000FF,100,400);
            this->texto(_window,"Presione Enter para empezar",1,0,30,0xFFFF0000FF,200,650);
            
            _window->draw(text);
            _window->display();
        }
    
}
void  Escena::setName(const char *  name)
{
    strcpy(_name , name);
}
const char * Escena::getName()
{
    return _name;

}