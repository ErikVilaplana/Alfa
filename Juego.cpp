#include "Juego.h"

#include "Menu.h"


    Juego::Juego()
    {
        deInit();
        
    }

    Juego::~Juego() {
    
    }
void  Juego::setName(String name)
    {
        _name = name;
    }
String Juego::getName()
    {
        return _name;

    }

    void Juego::init() {
    
        Escena pantalla;
        
    string input_text;
    Font font;
    font.loadFromFile("img/galaga.ttf");
    Text text("", font);
    text.setOutlineThickness(2);
    text.setFillColor(Color::Blue);
    text.setOutlineColor(Color(127,127,127));
    text.setPosition(60,300);

    Clock clock;

    while (_window->isOpen())
    {
        Event event;
        while (_window->pollEvent(event))
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

        text_effect_time += clock.restart();

        if (text_effect_time >= seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = Time::Zero;
        }

        text.setString(input_text + (show_cursor ? '_' : ' '));
        if (event.key.code == Keyboard::Escape) {
            if (!input_text.empty())
            {
                Escena pantalla;
                _name=input_text;
                runJuego();
            }
        }
        _window->clear();
        _window->draw(text);
        _window->display();
    }
        /*
        Menu menu(pantalla.getWidth(), pantalla.getHeight());
        
        while(w.isOpen()){
            ///Quitar todos los  eventos en cola de la ventana
            Event event;
            while(w.pollEvent(event)){
                switch (event.type){
                case Event::JoystickMoved:
                    if(event.joystickMove.axis == Joystick::Y){
                        if(event.joystickMove.position > 95.f ){
                            menu.moverabajo();
                            
                        }
                        if(event.joystickMove.position < -95.f){
                            menu.moverarriba();
                            
                        }
                    }
                    break;
                case Event::JoystickButtonPressed:
                    switch(menu.presionaritem()){
                case 0:
                    
                    
                    
                        break;
                case 1:
                    
                        break;
                case 2:
                    
                        break;
                case 3:
                    
                        w.close();
                        break;
                    }
                    break;
                    /*
                case Event::KeyReleased:
                switch(event.key.code){
                case Keyboard::Up:
                menu.moverarriba();
                Soundmenu.play();
                break;
                case Keyboard::Down:
                menu.moverabajo();
                Soundmenu.play();
                break;
                case Keyboard::Return:
                switch(menu.presionaritem()){
                case 0:
                Soundmenu.play();
                dosplayer=0;
                MenuInicio();
                break;
                case 1:
                Soundmenu.play();
                dosplayer=1;
                MenuInicio();
                break;
                case 2:
                Soundmenu.play();
                Menudificultad();
                break;
                case 3:
                Soundmenu.play();
                w.close();
                break;
                }
                break;
                }
                break;#1#
                    case Event::Closed:
                    
                    w.close();
                    break;
                }
            }
            menu.dibujar(w);
            */
            
        //}
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

    void Juego::deInit() {
    Escena pantalla;
    _window = new sf::RenderWindow(sf::VideoMode(pantalla.getWidth(), pantalla.getHeight()), "laraga");
    }

    void Juego::runJuego() {
        Escena  pantalla;
              

        //Prepara Tablero Score
        
        
        Base escena(  0, 250, 0, 584, 1024, 120, "img/itens.png");
        Base explosion(  115, 0, 100, 100, 50, 48, "img/itens.png");
        //init();
        
        // Crea player
        Jugador player(0,  0, 500, 520,   70,  70, "img/Nave.png");
        player.setName(_name);
        
        //Disparo Player and Enemy
        Disparo disparoEnemigo(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoEnemigoDos(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoNave(200, 0, -100, -100, 7,12,"img/itens.png");
        
        // crea los enemigos
        Enemigo * enemigo[7][5];
                
        // Main Juego loop
        while (_window->isOpen())
        {
            if(pantalla.getInit()==false)
            {
                pantalla.setNEnemigo((pantalla.getFila ()-2) * pantalla.getColumna());
                for(int i = 0; i < pantalla.getColumna(); i++)
                {
                    for(int j = 0; j < pantalla.getFila(); j++)
                    {
                        enemigo[i][j] = new Enemigo(0, j*50, i*110, j*60-500, 51, 48, "img/itens.png");
                    }
            
                }
                pantalla.setInit(true);
            }
            pantalla.setTsort(rand() %10); 
            pantalla.getBan();
            

            //disparo del player se panda la posición del los enemigos cargados y el objeto disparo
            player.control(_window, enemigo[pantalla.getColumna()-1][pantalla.getFila()-1]->getY() ,  disparoNave);

            // Preparamos los enemigos para su funcion jajaj
            
            for(int i = 0; i < pantalla.getColumna(); i++)
            {
                
                /// prparar disparo del enemigo alternando turno de disparo
                if(i==0){
                    if(player.colision(disparoEnemigo) && !player.getHit())
                    {
                        disparoEnemigo.setY(pantalla.getOutsrc());
                        player.setHit(true);
                        
                        explosion.setX(player.getX());
                        explosion.setY(player.getY());
                        pantalla.setTexp(10);
                        
                    } 
                    if(disparoEnemigo.getY() < pantalla.getOutsrc())disparoEnemigo.setYacu(5);
                    disparoEnemigo.show(_window);
                    
                }else if(i==1)
                {
                    if(player.colision(disparoEnemigoDos) && !player.getHit())
                    {
                        disparoEnemigoDos.setY(pantalla.getOutsrc());
                        player.setHit(true);
                        
                        explosion.setX(player.getX());
                        explosion.setY(player.getY());
                        pantalla.setTexp(10);
                        
                    } 
                    if(disparoEnemigoDos.getY() < pantalla.getOutsrc())disparoEnemigoDos.setYacu(5);
                    disparoEnemigoDos.show(_window);
                }

                //disparar los de la primera filani
                for(int j = 4; j > 0; j--)
                {
                    if(!enemigo[i][j]->getHit())
                    {
                        if(enemigo[i][j]->colision(disparoNave) )
                        {
                            pantalla.setNEnemigo(pantalla.getNEnemigo()-1);
                            player.setPts(15);
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            explosion.setX(enemigo[i][j]->getX());
                            explosion.setY(enemigo[i][j]->getY());
                            pantalla.setTexp(10);
                            disparoNave.setY(-100) ;/// fuera
                        }

                        //movimiento <- ->
                        enemigo[i][j]->movimiento(pantalla.getStep(),pantalla.getVel(), pantalla.getDir(), pantalla.getBan());
                        //animacion
                        enemigo[i][j]->animando(pantalla.getStep(),pantalla.getVel());
                        
                        enemigo[i][j]->show(_window);
                        
                        /// disparo de loss aliens mirar q solo dispara la primer linea
                        if(pantalla.getTsort() == i && player.getX() && disparoEnemigo.getY()>=pantalla.getOutsrc())
                        {
                            disparoEnemigo.setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disparoEnemigo.setY(enemigo[i][j]->getY());
                        }

                        if(enemigo[i][j]->getX()== player.getX() && disparoEnemigoDos.getY()>=pantalla.getOutsrc())
                        {
                            disparoEnemigoDos.setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disparoEnemigoDos.setY(enemigo[i][j]->getY());
                        }
                        
                    }
                }   
            }
            //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
            if(pantalla.getNEnemigo()==(pantalla.getNEnemigo()-3))pantalla.setVel(40);
            if(pantalla.getNEnemigo()==(pantalla.getNEnemigo()-6))pantalla.setVel(35);
            if(pantalla.getNEnemigo()==(pantalla.getNEnemigo()-9))pantalla.setVel(20);
            if(pantalla.getNEnemigo()==(pantalla.getNEnemigo()-10))pantalla.setVel(10);

            if(pantalla.getNEnemigo()==0)
            {
                pantalla.setInit(false);
                pantalla.upNivelWin(_window);
                pantalla.reset(player);
                
                
                
            }

            // manejo de explosion
            if(pantalla.getTexp()){ explosion.show(_window); pantalla.setTexpCont(); }
            
            player.show(_window);
            
            disparoNave.show(_window);
            
            escena.show(_window);

            if ((pantalla.getBan() && pantalla.getVel()==pantalla.getVel()/2) || enemigo[pantalla.getColumna()-1][pantalla.getFila()-1]->getY() < 300)
            {
                for(int i=0; i<pantalla.getColumna(); i++)
                {
                    for(int j=0; j<pantalla.getFila(); j++)
                    {
                        enemigo[i][j]->setYacu(enemigo[pantalla.getColumna()-1][pantalla.getFila()-1]->desplazar());
                    }
                }
            }
            
            //contador pasos
            
            if(pantalla.getStepCont() > pantalla.getVel()) pantalla.setStep(0);

            //estadisticas en pantalla
            pantalla.texto(_window,"",1,player.getRecord(),30,0xFFFF0000FF,890,642);
            pantalla.texto(_window,"",1,player.getPts(),30,0xFFFF0000FF,600,640);
            pantalla.texto(_window,"",1,player.getVidas(),30,0xFFFF0000FF,570,580);
            pantalla.texto(_window,player.getName(),2,0,30,0xFFFF0000FF,180,586);
            pantalla.texto(_window,"",1,pantalla.getNEnemigo(),30,0xFFFF0000FF,824,588);
            pantalla.texto(_window,"",1,player.getVelocidad(),30,0xFFFF0000FF,318,644);

            
            _window->display();
            if(player.getHit()){
                //Timer(190);
                // resta vidas
                player.setVidasDown();
               if (player.getVidas() < 0)
               {
                   pantalla.gameOver(_window, player);
               }else
               {
                   pantalla.reset(player);
                   /*for(int i=0; i<pantalla.getColumna(); i++){
                       for(int j=0; j<pantalla.getFila(); j++){
                           enemigo[i][j]->setX(i*110+120);
                           enemigo[i][j]->setY(j*60-500);
                           enemigo[i][j]->setHit(false); 
                       }
                   }*/
               }
            }
            
            // con la funcion clock hacemos fluido el juego
            pantalla.delay();
            _window->clear(Color::Black);
        }
       
    }

