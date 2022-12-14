#include "Juego.h"

    Juego::Juego()
    {
        ordenaEstadistica();       
        deInit();
    }

    Juego::~Juego() {
    
    }
    void Juego::ordenaEstadistica()
    {
        int pos=0;
            
        while(_arch.leerDeDisco(  reg,pos)){
                
            _estadistica[pos]=reg;
            cout << _estadistica[pos].getName() << endl;
            pos++;
        }
            
        for(int i=0 ; i<10 ;i++){
            for(int j=0;j<10-1;j++){
                if(_estadistica[i].getPts()>_estadistica[j].getPts()){
                    aux=_estadistica[i];
                    _estadistica[i]=_estadistica[j];
                    _estadistica[j]=aux;
                }
            }
        }
    }
   
    void Juego::deInit() {
        
        _texmapa.loadFromFile("img/fondoDos.jpg");
        _spmapa.setTexture(_texmapa);
        _spmapa.setPosition(500,200);
        _mainMenu = new MainMenu(_pantalla.getWidth(), _pantalla.getHeight());
        _window = new sf::RenderWindow(sf::VideoMode(_pantalla.getWidth(), _pantalla.getHeight()), "laraga");
        _window->setPosition(Vector2i(200,0));
        _jugador = new Jugador(0,  0, 500, 520,   70,  70, "img/Nave.png");
        _boss = new Enemigo(0,  0, 0, 0,   184,  164, "img/boss.png");
         _escena = new Base(  0, 250, 0, 584, 1024, 120, "img/HUD2.png");
         /*_logo = new Base(  0, 0, 300, 600, 346, 123, "img/LaraGa.png");*/
        _explosion = new Base(  115, 0, 100, 100, 50, 48, "img/itens.png");
        /*_explosionBoss = new Base(  115, 0, 100, 100, 50, 48, "img/itens.png");*/
        _disparoE1= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        _disparoE2= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        _bossE1= new Disparo(0, 0, -100, -100, 11,19,"img/fire.png");
        _bossE2= new Disparo(0, 0, -100, -100, 11,19,"img/fire.png");
        _disparoP= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        //seteo de enemigos
        _pantalla.setNEnemigo(_pantalla.getFila() * _pantalla.getColumna());
        crearEnemigo();
        _window->draw(_spmapa);
    }
    void Juego::crearEnemigo()
    {
        setPosEnemigo();
        for(int i = 0; i < _pantalla.getColumna(); i++)
        {
            for(int j = 0; j < _pantalla.getFila(); j++)
            {
                _enemigo[i][j] = new Enemigo(0, j*50, i*110, j*60-500, 52, 48, "img/enemigos.png");
            }
            
        }
    }

    void Juego::init() {
        
    while (_window->isOpen())
    {

        while (_window->pollEvent(_aevent))
        {
            if (_aevent.type == Event::Closed)
            {
                _window->close();
            }
            if (_aevent.type == Event::KeyReleased)
            {
                if (_aevent.key.code == Keyboard::Down)
                {
                    _mainMenu->MoveDown();
                    break;
                }
                if (_aevent.key.code == Keyboard::Up)
                {
                    _mainMenu->Moveup();
                    break;
                }
                if (_aevent.key.code == Keyboard::Return) {
                    

                    int x = _mainMenu->MainMenuPressed();
                    if (x == 0)
                    {
                        while (_window->isOpen())
                        {
                                
                            while (_window->pollEvent(_aevent)) {
                                if (_aevent.type == Event::Closed)
                                {
                                    _window->close();
                                }
                         
                                        _jugador->setName(_pantalla.getName());
                                        _pantalla.setInicio(_window);
                                        
                                        runJuego();
                                               
                            }
                            
                        }
                    }
                    if (x == 1) {
                        
                        while (_window->isOpen() )
                        {
                            
                            while (_window->pollEvent(_aevent)) {
                                if (_aevent.type == Event::Closed)
                                {
                                    _window->close();
                                }
                                if (_aevent.key.code == Keyboard::Escape)
                                {   
                                    init();
                                }
                                
                                    getEstadistica();
                                
                            }
                            
        
                        }
                    }
                    if (x == 2)
                    {
                        while (_window->isOpen())
                        {
                            
                            while (_window->pollEvent(_aevent)) {
                                if (_aevent.type == Event::Closed)
                                {
                                    _window->close();
                                }
                                if (_aevent.key.code == Keyboard::Escape)
                                {
                                    
                                    init();
                                }
                                
                                getAcercaDe();
                                
                                
                            }
                        }
                    }
                    if (x == 3)
                        _window->close();
                    break;
                }
            }
        }
        _window->clear();
        _mainMenu->draw(_window);
        _window->display();
        _window->clear(Color::Black);
    }


        
    }


    

    void Juego::runJuego() {
        
        _texmapa.loadFromFile("img/fondoDos.jpg");
        _spmapa.setTexture(_texmapa);
        _jugador->setName(_pantalla.getName());
        
        while (_window->isOpen())
        {   
            
            _pantalla.setTsort(rand() %10); 

            //evalua el nivel
            (_pantalla.getNivel()< 6)? setEnemigos() : setBoss();
            
            //contador pasos
            if(_pantalla.getStepCont() > _pantalla.getVel()) _pantalla.setStep(0);

            //estadisticas en pantalla
            _pantalla.texto(_window,"",1, _pantalla.getNivel(),45,0xFFFFBB00FF,170,630);
            _pantalla.texto(_window,"",1,_jugador->getPts(),50,0xFFFFFFFFFF,500,630);
            _pantalla.texto(_window,"",1,_jugador->getVidas(),35,0xFFFFCCCCFF,850,660);
            _pantalla.texto(_window,_jugador->getName(),2,0,30,0xFFFF0000FF,70,610);
            _pantalla.texto(_window,"",1,_pantalla.getNEnemigo(),35,0xFFFF0000FF,810,635);
            //_pantalla.texto(_window,"",1,_jugador->getVelocidad(),30,0xFFFF0000FF,318,644);
            
            _window->display();
            if(_jugador->getHit()){
                
                // resta vidas
                _jugador->setVidasDown();
               if (_jugador->getVidas() < 1)
               {
                   _pantalla.gameOver(_window, _jugador);
                   if(!_pantalla.getBan())
                   {
                       _jugador->setPts(0);
                       crearEnemigo();
                       init();
                   }
               }else
               {
                   _pantalla.reset(_jugador);
               }
            }
            
            // con la funcion clock hacemos fluido el juego
            _pantalla.delay();
            _window->clear(Color::Black);
        }
       
    }
    void Juego::setPosEnemigo()
    {
        for(int i=0; i<_pantalla.getColumna(); i++){
            for(int j=0; j<_pantalla.getFila(); j++){
                _enemigo[i][j]={} ;
                
            }
        }
    }

    void Juego::setEnemigos()
    {
        _jugador->control(_window, _enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->getY() ,  _disparoP,_spmapa);
        for(int i = 0; i < _pantalla.getColumna(); i++)
                {
                    
                    /// prparar disparo del enemigo alternando turno de disparo
                    if(i==0){
                        if(_jugador->colision(_disparoE1) && !_jugador->getHit())
                        {
                            _disparoE1->setY(_pantalla.getOutsrc());
                            _jugador->setHit(true);
                            
                            _explosion->setX(_jugador->getX());
                            _explosion->setY(_jugador->getY());
                            _pantalla.setTexp(10);
                            
                        } 
                        if(_disparoE1->getY() < _pantalla.getOutsrc())_disparoE1->setYacu(5);
                        _disparoE1->show(_window);
                        
                        
                    }else if(i==1)
                    {
                        if(_jugador->colision(_disparoE2) && !_jugador->getHit())
                        {
                            _disparoE2->setY(_pantalla.getOutsrc());
                            _jugador->setHit(true);
                            
                            _explosion->setX(_jugador->getX());
                            _explosion->setY(_jugador->getY());
                            _pantalla.setTexp(10);
                            
                        } 
                        if(_disparoE2->getY() < _pantalla.getOutsrc())_disparoE2->setYacu(5);
                        _disparoE2->show(_window);
                    }
                    

                    //disparar los de la primera filani
                    for(int j = 4; j > -1; j--)
                    {
                        if(!_enemigo[i][j]->getHit())
                        {
                            
                            if(_enemigo[i][j]->colision(_disparoP) )
                            {
                                _pantalla.setNEnemigo(_pantalla.getNEnemigo()-1);
                                _jugador->setPts(_jugador->getVidas()*(j+15));
                                _enemigo[i][j]->setHit(true); ///fuera eliminado
                                _explosion->setX(_enemigo[i][j]->getX());
                                _explosion->setY(_enemigo[i][j]->getY());
                                _pantalla.setTexp(10);
                                _disparoP->setY(-100) ;/// fuera
                            }

                            //movimiento <- ->
                            
                            _enemigo[i][j]->movimiento(_pantalla.getStep(),_pantalla.getVel(), _pantalla.getDir(), _pantalla.getBan());
                            //animacion

                            
                            _enemigo[i][j]->animando(_pantalla.getStep(),_pantalla.getVel());
                            _jugador->animando(_pantalla.getStep(),_pantalla.getVel());

                            //enemigos niveles comunes
                            
                            _enemigo[i][j]->show(_window);
                            
                            if(_pantalla.getTsort() == i && _jugador->getX() && _disparoE1->getY()>=_pantalla.getOutsrc())
                            {
                                _disparoE1->setX(_enemigo[i][j]->getX() + _enemigo[i][j]->getW()/2);
                                _disparoE1->setY(_enemigo[i][j]->getY());
                            }

                            if(_enemigo[i][j]->getX()== _jugador->getX() && _disparoE2->getY()>=_pantalla.getOutsrc())
                            {
                                _disparoE2->setX(_enemigo[i][j]->getX() + _enemigo[i][j]->getW()/2);
                                _disparoE2->setY(_enemigo[i][j]->getY());
                            }
                            
                        }
                    }   
                }
                //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
                if(_pantalla.getNEnemigo()==((_pantalla.getColumna()*_pantalla.getFila())/_pantalla.getNivel()))_pantalla.setVel(45);
                if(_pantalla.getNEnemigo()==((_pantalla.getColumna()*_pantalla.getFila())/_pantalla.getNivel())-2)_pantalla.setVel(35);
                if(_pantalla.getNEnemigo()==((_pantalla.getColumna()*_pantalla.getFila())/_pantalla.getNivel())-3)_pantalla.setVel(20);
                if(_pantalla.getNEnemigo()==((_pantalla.getColumna()*_pantalla.getFila())/_pantalla.getNivel())-4)_pantalla.setVel(10);

                if(_pantalla.getNEnemigo()==0)
                {
                    if(_pantalla.getNivel()<6){
                                           
                    _pantalla.upNivelWin(_window, _jugador);
                    _pantalla.reset(_jugador);
                    
                    crearEnemigo();
                    }
                    _disparoP->setX(_pantalla.getOutsrc());
                    runJuego();
                }

                
                if(_pantalla.getTexp()){ _explosion->show(_window); _pantalla.setTexpCont(); }
                
                _jugador->show(_window);
                _disparoP->show(_window);
                _escena->show(_window);
                
                if ((_pantalla.getBan() && _pantalla.getVel()==_pantalla.getVel()/2) || _enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->getY() < 300)
                {
                    for(int i=0; i<_pantalla.getColumna(); i++)
                    {
                        for(int j=0; j<_pantalla.getFila(); j++)
                        {
                            _enemigo[i][j]->setYacu(_enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->desplazar());
                        }
                    }
                }
                
    }
    void Juego::setBoss()
    {
        _jugador->control(_window, _boss->getY() ,  _disparoP,_spmapa);
     for(int i = 0; i < _pantalla.getColumna(); i++)
            {
                
                /// prparar disparo del enemigo alternando turno de disparo
                if(i==0){

                    if(_jugador->colision(_bossE1) && !_jugador->getHit())
                    {
                        _bossE1->setY(_pantalla.getOutsrc());
                        _jugador->setHit(true);
                        
                        _explosion->setX(_jugador->getX());
                        _explosion->setY(_jugador->getY());
                        _pantalla.setTexp(10);
                        
                    } 
                    if(_bossE1->getY() < _pantalla.getOutsrc())_bossE1->setYacu(5);
                    _bossE1->show(_window);
                    
                }else if(i==1)
                {
                    
                    if(_jugador->colision(_bossE2) && !_jugador->getHit())
                    {
                        _bossE2->setY(_pantalla.getOutsrc());
                        _jugador->setHit(true);
                        
                        _explosion->setX(_jugador->getX());
                        _explosion->setY(_jugador->getY());
                        _pantalla.setTexp(10);
                        
                    } 
                    if(_bossE2->getY() < _pantalla.getOutsrc())_bossE2->setYacu(5);
                    _bossE2->show(_window);
                }
                

                //disparar los de la primera filani
                for(int j = 4; j > -1; j--)
                {
                    if(!_enemigo[i][j]->getHit())
                    {
                        //mirar    
                        if(_boss->colision(_disparoP) )
                        {
                            _pantalla.setNEnemigo(_pantalla.getNEnemigo()-1);
                            _jugador->setPts(15);
                            _enemigo[i][j]->setHit(true); ///fuera eliminado
                            _explosion->setX(_boss->getX());
                            _explosion->setY(_boss->getY());
                            _pantalla.setTexp(10);
                            _disparoP->setY(-100) ;/// fuera
                        }

                        //movimiento <- ->
                        _boss->movimiento(_pantalla.getStep(),_pantalla.getVel(), _pantalla.getDir(), _pantalla.getBan());
                        
                        //animacion

                        _boss->animando(_pantalla.getStep(),_pantalla.getVel());
                        
                        _jugador->animando(_pantalla.getStep(),_pantalla.getVel());

                        //enemigos niveles comunes
                        
                        ///disparo Bosss
                        if(_pantalla.getTsort() == i && _jugador->getX() && _bossE1->getY()>=_pantalla.getOutsrc())
                        {
                            _bossE1->setX(_boss->getX() + _boss->getW()/2);
                            _bossE1->setY(_boss->getY());
                        }

                        if(_boss->getX()== _jugador->getX() && _bossE2->getY()>=_pantalla.getOutsrc())
                        {
                            _bossE2->setX(_boss->getX() + _boss->getW()/2);
                            _bossE2->setY(_boss->getY());
                        }
                        
                    }
                }   
            }
            //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-3))_pantalla.setVel(40);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-6))_pantalla.setVel(35);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-9))_pantalla.setVel(20);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-10))_pantalla.setVel(10);


        //final BOSS
            if(_pantalla.getNEnemigo()==0)
            {
                _pantalla.gameWon(_window, _jugador);
                if(_pantalla.getBan())
                {
                    _jugo.setName(_jugador->getName());
                    _jugo.setPts(_jugador->getPts());
                    _arch.guardar(_jugo);
                    _pantalla.setColumnaI(3);
                    _pantalla.setNivel(1);
                    _pantalla.setNEnemigo(_pantalla.getColumna()*_pantalla.getFila());
                    crearEnemigo();
                    ordenaEstadistica();
                    init();
                }
            }

            
            if(_pantalla.getTexp()){ _explosion->show(_window); _pantalla.setTexpCont(); }
            
            _jugador->show(_window);
            _disparoP->show(_window);
            _escena->show(_window);
            _boss->show(_window);
            
            if ((_pantalla.getBan() && _pantalla.getVel()==_pantalla.getVel()/2) || _boss->getY() < 200)
            {
                _boss->setYacu(_boss->desplazar());
            }
               
    }
    void Juego::getEstadistica()
    {
        _texmapa.loadFromFile("img/acercade.jpeg");
        _spmapa.setTexture(_texmapa);
        _spmapa.setPosition(0,0);
        
        _window->draw(_spmapa);
        _pantalla.texto(_window,"Nombre",0,0,30,0xFFFF0000FF,300,150);
        _pantalla.texto(_window,"Puntos",0,0,30,0xFFFF0000FF,600,150);
        for(int i=0;i<10;i++){
        _pantalla.texto(_window,_estadistica[i].getName(),0,0,30,0xFFFF0000FF,300,200+(i*30));
        _pantalla.texto(_window,"",0,_estadistica[i].getPts(),30,0xFFFF0000FF,600,200+(i*30));
        }
        _window->display();
    }
    void Juego::getAcercaDe()
    {
        
                
        _texmapa.loadFromFile("img/acercade.jpeg");
        _spmapa.setTexture(_texmapa);
        _spmapa.setPosition(0,0);
        _window->draw(_spmapa);
        _pantalla.texto(_window,"Presione Esc para salir",1,0,30,0xFFFF0000FF,600,640);

        
        _window->display();
        

    }


