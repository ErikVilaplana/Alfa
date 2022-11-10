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
        RenderWindow window(VideoMode(1000, 700), "LARAGA.EXE");
        Escena  pantalla;
        Jugador * player = new Jugador(50,  0, 500,520,   15,  30,"img/SUPERCARROT.png");
        //init();
        


        //arreg
        Jugador *escena = new Jugador(  0, 250, 0, 584, 1024, 120, "img/itens.png");

        Enemigo * disp[3];

        int dir=0, outsrc=670;
        
        Enemigo * enemigo[7][5];
        
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                enemigo[i][j] = new Enemigo(0, j*50, i*110, j*60-500, 51, 48, "img/itens.png");
            }
            if( i<3)
            {   //creamos el objeto disparo
                disp[i]= new Enemigo(200, 0, -100, -100, 7,12,"img/itens.png");
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
            player->control(window, enemigo[6][4]->getY() ,  disp[2]);

            // Preparamos los enemigos para su funcion jajaj
            for(int i = 0; i < 7; i++)
            {
                /// prparar disparo del enemigo
                if(i<2)
                {
                    if(disp[i]->getY() < outsrc)disp[i]->setYacu(20);

                    disp[i]->show(window);
                }

                //disparar los de la primera fila
                for(int j = 4; j > 0; j--)
                {
                    if(!enemigo[i][j]->getHit())
                    {
                        if(enemigo[i][j]->colision(disp[2]))
                        {
                            pantalla.setNEnemigo(pantalla.getNEnemigo()-1);
<<<<<<< Updated upstream
                            player->setPts(15);
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            disp[2]->setY(-100) ;/// fuera
=======
                            player.setPts(10*player.getMultiplicador());
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            disparoNave.setY(-100) ;/// fuera
                            cout << player.getPts() << endl;  //Prueba, muestra puntaje en CMD
                            if (player.getMultiplicador() < 5)player.setMultiplicador(player.getMultiplicador() + 1); //Suma multiplicador
                            
>>>>>>> Stashed changes
                        }

                        //movimiento <- ->
                        enemigo[i][j]->movimiento(pantalla.getStep(),pantalla.getVel(), dir, ban);
                        //animacion
                        enemigo[i][j]->animando(pantalla.getStep(),pantalla.getVel());
                        
                        enemigo[i][j]->show(window);
                        
                        /// disparo de loss aliens mirar q solo dispara la primer linea
                        if(t_sort == i && player->getX() && disp[1]->getY()>=outsrc)
                        {
                            disp[1]->setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disp[1]->setY(enemigo[i][j]->getY());
                        }

                        if(enemigo[i][j]->getX()== player->getX() && disp[0]->getY()>=outsrc)
                        {
                            disp[0]->setX(enemigo[i][j]->getX() + enemigo[i][j]->getW()/2);
                            disp[0]->setY(enemigo[i][j]->getY());
                        }
                        
                    }
                }   
            }
            //manejamos la cantidad de enemigos  y aumentamos la velocidad Agregar para dificultas
            if(pantalla.getNEnemigo()==30)pantalla.setVel(40);
            if(pantalla.getNEnemigo()==20)pantalla.setVel(35);
            if(pantalla.getNEnemigo()==10)pantalla.setVel(20);
            if(pantalla.getNEnemigo()==5)pantalla.setVel(10);
            
            player->show(window);
            disp[2]->show(window);
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
            pantalla.texto(window,"",1,player->getPuntajeAcumulado(),30,0xFFFF0000FF,890,642);
            pantalla.texto(window,"",1,player->getPts(),0,0xFFFF0000FF,670,640);
            pantalla.texto(window,"",1,player->getVidas(),30,0xFFFF0000FF,502,616);
            pantalla.texto(window,"normal",2,0,30,0xFFFF0000FF,250,586);
            pantalla.texto(window,"",1,player->getDisparo(),30,0xFFFF0000FF,824,588);
            pantalla.texto(window,"",1,player->getVelocidad(),30,0xFFFF0000FF,318,644);
=======
            pantalla.texto(window,"",1,player.getRecord(),30,0xFF85C1E9FF,750,642);
            pantalla.texto(window,"",2,player.getPts(),30,0xFFFFAA00FF,420,642);
            pantalla.texto(window,"",1,player.getVidas(),30,0xFFB2BABBFF,570,592);
            pantalla.texto(window,"",1,player.getMultiplicador(), 30, 0xFFFF0000FF, 250, 642);
            pantalla.texto(window,"",1,player.getDisparo(),30,0xFF8E44ADFF,780,592);
            pantalla.texto(window,"",1,player.getVelocidad(),30,0xFFEDBB99FF,350,592);
>>>>>>> Stashed changes

=======
            pantalla.texto(window,"",1,player->getPuntajeAcumulado(),30,0xFFFFA500FF,630,642);
            pantalla.texto(window,"",1,player->getPts(),0,0xFFFFA500FF,670,640);
            pantalla.texto(window,"",1,player->getVidas(),30,0xFFFFA500FF,600,590);
            pantalla.texto(window,"Normal",2,0,23,0xFFFFA500FF,400,600);
            pantalla.texto(window,"",1,player->getDisparo(),30,0xFFFFA500FF,824,588);
            pantalla.texto(window,"",1,player->getVelocidad(),30,0xFFFFA500FF,318,644);
>>>>>>> Stashed changes
            
            window.display();
            
            // con la funcion clock hacemos fluido el juego
            pantalla.delay();
            window.clear(Color::Black);
        }
        deInit();
    }
