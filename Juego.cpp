#include "Juego.h"

#include "Menu.h"


    Juego::Juego()
    {
        
        deInit();
        init();
        
    }

    Juego::~Juego() {
    
    }
   
    void Juego::deInit() {
        _texmapa.loadFromFile("img/fondoDos.jpg");
        _spmapa.setTexture(_texmapa);
        _spmapa.setPosition(0,0);
        _window = new sf::RenderWindow(sf::VideoMode(_pantalla.getWidth(), _pantalla.getHeight()), "laraga");
        _window->setPosition(Vector2i(0,0));
        _jugador = new Jugador(0,  0, 500, 520,   70,  70, "img/Nave.png");
         _escena = new Base(  0, 250, 0, 584, 1024, 120, "img/itens.png");
         _logo = new Base(  0, 0, 300, 600, 346, 123, "img/LaraGa.png");
        _explosion = new Base(  115, 0, 100, 100, 50, 48, "img/itens.png");
        _disparoE1= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        _disparoE2= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        _disparoP= new Disparo(200, 0, -100, -100, 7,12,"img/itens.png");
        
        
        _window->draw(_spmapa);
    }


    void Juego::init() {
        _window->draw(_spmapa);
    _pantalla.setInicio(_window);
    runJuego();
        
    }
    

    void Juego::update() {
        

    }

    void Juego::draw() {
        // Clear screen
     //   _window->clear();
        // Draw the map
        //_window->draw(map);
        // Update the window
       // _window->display();
    }

    

    void Juego::runJuego() {

        
        _jugador->setName(_pantalla.getName());      
        
        Enemigo * enemigo[7][5];
                
        
        while (_window->isOpen())
        {_window->draw(_spmapa);
            if(_pantalla.getInit()==false)
            {
                
                _pantalla.setNEnemigo((_pantalla.getFila()-2) * _pantalla.getColumna());
                for(int i = 0; i < _pantalla.getColumna(); i++)
                {
                    for(int j = 0; j < _pantalla.getFila(); j++)
                    {
                        enemigo[i][j] = new Enemigo(0, j*50, i*110, j*60-500, 51, 48, "img/itens.png");
                    }
            
                }
                _pantalla.setInit(true);
            }
            _pantalla.setTsort(rand() %10); 
            _pantalla.getBan();
            

            //disparo del player se panda la posición del los enemigos cargados y el objeto disparo
            _jugador->control(_window, enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->getY() ,  _disparoP);

            // Preparamos los enemigos para su funcion jajaj
            
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
                for(int j = 4; j > 0; j--)
                {
                    if(!enemigo[i][j]->getHit())
                    {
                        
                        if(enemigo[i][j]->colision(_disparoP) )
                        {
                            _pantalla.setNEnemigo(_pantalla.getNEnemigo()-1);
                            _jugador->setPts(15);
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            _explosion->setX(enemigo[i][j]->getX());
                            _explosion->setY(enemigo[i][j]->getY());
                            _pantalla.setTexp(10);
                            _disparoP->setY(-100) ;/// fuera
                        }

                        //movimiento <- ->
                        enemigo[i][j]->movimiento(_pantalla.getStep(),_pantalla.getVel(), _pantalla.getDir(), _pantalla.getBan());
                        //animacion
                        enemigo[i][j]->animando(_pantalla.getStep(),_pantalla.getVel());
                        
                        enemigo[i][j]->show(_window);
                        
                        /// disparo de loss aliens mirar q solo dispara la primer linea
                        if(_pantalla.getTsort() == i && _jugador->getX() && _disparoE1->getY()>=_pantalla.getOutsrc())
                        {
                            _disparoE1->setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            _disparoE1->setY(enemigo[i][j]->getY());
                        }

                        if(enemigo[i][j]->getX()== _jugador->getX() && _disparoE2->getY()>=_pantalla.getOutsrc())
                        {
                            _disparoE2->setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            _disparoE2->setY(enemigo[i][j]->getY());
                        }
                        
                    }
                }   
            }
            //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-3))_pantalla.setVel(40);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-6))_pantalla.setVel(35);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-9))_pantalla.setVel(20);
            if(_pantalla.getNEnemigo()==(_pantalla.getNEnemigo()-10))_pantalla.setVel(10);

            if(_pantalla.getNEnemigo()==0)
            {
                _pantalla.setInit(false);
                _pantalla.upNivelWin(_window);
                _pantalla.reset(_jugador);
                
                
                
            }

            
            if(_pantalla.getTexp()){ _explosion->show(_window); _pantalla.setTexpCont(); }
            
            _jugador->show(_window);
            
            _disparoP->show(_window);
            
            _escena->show(_window);

            if ((_pantalla.getBan() && _pantalla.getVel()==_pantalla.getVel()/2) || enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->getY() < 300)
            {
                for(int i=0; i<_pantalla.getColumna(); i++)
                {
                    for(int j=0; j<_pantalla.getFila(); j++)
                    {
                        enemigo[i][j]->setYacu(enemigo[_pantalla.getColumna()-1][_pantalla.getFila()-1]->desplazar());
                    }
                }
            }
            
            //contador pasos
            
            if(_pantalla.getStepCont() > _pantalla.getVel()) _pantalla.setStep(0);

            //estadisticas en pantalla
            _pantalla.texto(_window,"",1,_jugador->getRecord(),30,0xFFFF0000FF,890,642);
            _pantalla.texto(_window,"",1,_jugador->getPts(),30,0xFFFF0000FF,600,640);
            _pantalla.texto(_window,"",1,_jugador->getVidas(),30,0xFFFF0000FF,570,580);
            _pantalla.texto(_window,_jugador->getName(),2,0,30,0xFFFF0000FF,180,586);
            _pantalla.texto(_window,"",1,_pantalla.getNEnemigo(),30,0xFFFF0000FF,824,588);
            _pantalla.texto(_window,"",1,_jugador->getVelocidad(),30,0xFFFF0000FF,318,644);

            
            _window->display();
            if(_jugador->getHit()){
                //Timer(190);
                // resta vidas
                _jugador->setVidasDown();
               if (_jugador->getVidas() < 0)
               {
                   _pantalla.gameOver(_window, _jugador);
               }else
               {
                   _pantalla.reset(_jugador);
                   /*for(int i=0; i<_pantalla.getColumna(); i++){
                       for(int j=0; j<_pantalla.getFila(); j++){
                           enemigo[i][j]->setX(i*110+120);
                           enemigo[i][j]->setY(j*60-500);
                           enemigo[i][j]->setHit(false); 
                       }
                   }*/
                   
               }
            }
            
            // con la funcion clock hacemos fluido el juego
            _pantalla.delay();
            _window->clear(Color::Black);
        }
       
    }

