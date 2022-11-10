﻿#include "Juego.h"


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
        Escena  pantalla;

        RenderWindow window(VideoMode(1024, 720), "Laraga");
        //Prepara Tablero Score
        
        
        Base escena(  0, 250, 0, 584, 1024, 120, "img/itens.png");
        Base explosion(  115, 0, 100, 100, 50, 48, "img/itens.png");
        //init();
        
        // Crea player
        Jugador player(0,  0, 500, 520,   70,  70, "img/Nave.png");
        
        
        //Disparo Player and Enemy
        Disparo disparoEnemigo(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoEnemigoDos(200, 0, -100, -100, 7,12,"img/itens.png");
        Disparo disparoNave(200, 0, -100, -100, 7,12,"img/itens.png");
        
        // crea los enemigos
        Enemigo * enemigo[7][5];
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
            pantalla.setTsort(rand() %10); 
            pantalla.getBan();
            

            //disparo del player se panda la posición del los enemigos cargados y el objeto disparo
            player.control(window, enemigo[6][4]->getY() ,  disparoNave);

            // Preparamos los enemigos para su funcion jajaj
            
            for(int i = 0; i < 7; i++)
            {
                /// prparar disparo del enemigo alternando turno de disparo
                if(i==0)
                {
                    if(disparoEnemigo.getY() < pantalla.getOutsrc())disparoEnemigo.setYacu(5);
                    disparoEnemigo.show(window);
                    
                }else if(i==1)
                {
                    if(disparoEnemigoDos.getY() < pantalla.getOutsrc())disparoEnemigoDos.setYacu(5);
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
                            explosion.setX(enemigo[i][j]->getX());
                            explosion.setY(enemigo[i][j]->getY());
                            pantalla.setTexp(10);
                            disparoNave.setY(-100) ;/// fuera
                        }

                        //movimiento <- ->
                        enemigo[i][j]->movimiento(pantalla.getStep(),pantalla.getVel(), pantalla.getDir(), pantalla.getBan());
                        //animacion
                        enemigo[i][j]->animando(pantalla.getStep(),pantalla.getVel());
                        
                        enemigo[i][j]->show(window);
                        
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
            if(pantalla.getNEnemigo()==30)pantalla.setVel(40);
            if(pantalla.getNEnemigo()==20)pantalla.setVel(35);
            if(pantalla.getNEnemigo()==10)pantalla.setVel(20);
            if(pantalla.getNEnemigo()==5)pantalla.setVel(10);

            // manejo de explosion
            if(pantalla.getTexp()){ explosion.show(window); pantalla.setTexpCont(); }
            
            player.show(window);
            
            disparoNave.show(window);
            
            escena.show(window);

            if ((pantalla.getBan() && pantalla.getVel()==pantalla.getVel()/2) || enemigo[6][4]->getY() < 300)
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

