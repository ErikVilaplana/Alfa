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

        Jugador * player = new Jugador(0,  0, 500, 520,   70,  70,"img/Nave.png");
        //init();
        Escena  pantalla;


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
                    if(disp[i]->getY() < outsrc)disp[i]->setYacu(5);

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
                            player->setPts(15);
                            enemigo[i][j]->setHit(true); ///fuera eliminado
                            disp[2]->setY(-100) ;/// fuera
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
            pantalla.texto(window,"",1,player->getRecord(),30,0xFFFF0000FF,890,642);
            pantalla.texto(window,"",1,player->getPts(),0,0xFFFF0000FF,670,640);
            pantalla.texto(window,"",1,player->getVidas(),30,0xFFFF0000FF,502,616);
            pantalla.texto(window,"normal",2,0,30,0xFFFF0000FF,250,586);
            pantalla.texto(window,"",1,player->getDisparo(),30,0xFFFF0000FF,824,588);
            pantalla.texto(window,"",1,player->getVelocidad(),30,0xFFFF0000FF,318,644);

            
            window.display();
            
            // con la funcion clock hacemos fluido el juego
            pantalla.delay();
            window.clear(Color::Black);
        }
        deInit();
    }
