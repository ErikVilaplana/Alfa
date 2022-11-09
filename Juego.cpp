#include "Juego.h"


    Juego::Juego() {

    }

    Juego::~Juego() {

    }


    void Juego::init() {
        // map.ShowObjects(); // Display all the layer objects.
        //Estudiante * vector = new Estudiante[cantA]{}

        
        
      //  Enemigo * enemigd;
    //    enemigd = new Enemigo[f]{};
    }

    void Juego::update() {

    }

    void Juego::draw() {
        // Clear screen
     //   window.clear();
        // Draw the map
        //window.draw(map);
        // Update the window
       // window.display();
    }

    void Juego::deInit() {
    }

    void Juego::runJuego() {
        RenderWindow window(VideoMode(1000, 700), "TILED");

       
        //init();
        Escena  pantalla;

        Jugador player(0,  0, 500, 520,   70,  70, "img/Nave.png");
        
        
        //arreg
        Jugador *escena = new Jugador(  0, 250, 0, 584, 1024, 120, "img/itens.png");

        // Crea player
        
        
        //Disparo Player and Enemy
        Disparo disparoEnemigo(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoEnemigoDos(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoNave(200, 0, -100, -100, 7,12,"img/itens.png");
        
        int dir=0, outsrc=670;
        
        ///
        Enemigo * enemigo[7][5];

        
        // crea los enemigos
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                enemigo[i][j] = new Enemigo(0, j*50, i*110, j*60-500, 51, 48, "img/itens.png");
            }
            
        }        
        // Main Juego loop
        while (window.isOpen())
        {
            /*// Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            update();
            draw();*/
            int t_sort= rand() %10;
            bool ban=false;

            //disparo del player se panda la posición del los enemigos cargados y el objeto disparo
            player.control(window, enemigo[6][4]->getY() ,  disparoNave);

            // Preparamos los enemigos para su funcion jajaj
            
            for(int i = 0; i < 7; i++)
            {
                /// prparar disparo del enemigo alternando turno de disparo
                if(i==0)
                {
                    if(disparoEnemigo.getY() < outsrc)disparoEnemigo.setYacu(5);
                    disparoEnemigo.show(window);
                    
                }else if(i==1)
                {
                    if(disparoEnemigoDos.getY() < outsrc)disparoEnemigoDos.setYacu(5);
                    disparoEnemigoDos.show(window);
                }

                //disparar los de la primera fila
                for(int j = 4; j > 0; j--)
                {
                    if(!enemigo[i][j]->getHit())
                    {
                        if(enemigo[i][j]->colision(disparoNave))
                        {
                            pantalla.setNEnemigo(pantalla.getNEnemigo()-1);
                            player.setPts(15);
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            disparoNave.setY(-100) ;/// fuera
                        }

                        //movimiento <- ->
                        enemigo[i][j]->movimiento(pantalla.getStep(),pantalla.getVel(), dir, ban);
                        //animacion
                        enemigo[i][j]->animando(pantalla.getStep(),pantalla.getVel());
                        
                        enemigo[i][j]->show(window);
                        
                        /// disparo de loss aliens mirar q solo dispara la primer linea
                        if(t_sort == i && player.getX() && disparoEnemigo.getY()>=outsrc)
                        {
                            disparoEnemigo.setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disparoEnemigo.setY(enemigo[i][j]->getY());
                        }

                        if(enemigo[i][j]->getX()== player.getX() && disparoEnemigoDos.getY()>=outsrc)
                        {
                            disparoEnemigoDos.setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disparoEnemigoDos.setY(enemigo[i][j]->getY());
                        }
                        
                    }
                }   
            }
            //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
            if(pantalla.getNEnemigo()==30)pantalla.setVel(40);
            if(pantalla.getNEnemigo()==20)pantalla.setVel(35);
            if(pantalla.getNEnemigo()==10)pantalla.setVel(20);
            if(pantalla.getNEnemigo()==5)pantalla.setVel(10);
            
            player.show(window);
            
            disparoNave.show(window);
            escena->show(window);

            if ((ban && pantalla.getVel()==pantalla.getVel()/2) || enemigo[6][4]->getY() < 300)
            {
                for(int i=0; i<7; i++)
                {
                    for(int j=0; j<5; j++)
                    {
                        enemigo[i][j]->setYacu(enemigo[6][4]->desplazar());
                    }
                }
            }
            
            //contador pasos
            
            if(pantalla.getStepCont() > pantalla.getVel()) pantalla.setStep(0);

            //estadisticas en pantalla
            pantalla.texto(window,"",1,player.getRecord(),30,0xFFFF0000FF,890,642);
            pantalla.texto(window,"",1,player.getPts(),0,0xFFFF0000FF,670,640);
            pantalla.texto(window,"",1,player.getVidas(),30,0xFFFF0000FF,502,616);
            pantalla.texto(window,"normal",2,0,30,0xFFFF0000FF,250,586);
            pantalla.texto(window,"",1,player.getDisparo(),30,0xFFFF0000FF,824,588);
            pantalla.texto(window,"",1,player.getVelocidad(),30,0xFFFF0000FF,318,644);

            
            window.display();
            
            // con la funcion clock hacemos fluido el juego
            pantalla.delay();
            window.clear(Color::Black);
        }
        deInit();
    }
