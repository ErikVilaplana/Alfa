#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "Base.h"
#include "Enemigo.h"
#include "Escena.h"
#include "Jugador.h"
using namespace sf;

RenderWindow window(VideoMode(1024,700),"Laraga");
Escena  pantalla;

Jugador *player = new Jugador(0,  0, 500, 520,   70,  70,"img/Nave.png");

//arreg
Jugador *escena = new Jugador(  0, 250, 0, 584, 1024, 120, "img/itens.png");

Enemigo * disp[3];


Enemigo * enemigo[7][5];

int dir=0, outsrc=670;
void reset(bool mod);
int main()
{
    //creamos los objetos enemigos
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
    reset(true);
    pantalla.reset(true);
    while(window.isOpen())
    {
        int t_sort= rand() %10;
        bool ban=false;

        //disparo del player se panda la posición del los enemigos cargados y el objeto disparo
        player->control(window, enemigo[6][4]->getY() ,  disp[2]);

        // Preparamos los enemigos para su funcion jajaj
        for(int i = 0; i < 7; i++)
        {
            if(i<2)
            {
                if(disp[i]->getY() < outsrc)disp[i]->setYacu(5);

                disp[i]->show(window);
            }
            
            for(int j = 4; j > 0; j--)
            {
                if(!enemigo[i][j]->getHit())
                {
                    if(enemigo[i][j]->colision(disp[2]))
                    {
                        pantalla.setNEnemigo(pantalla.getNEnemigo()-1);
                        player->setPts(15);
                        enemigo[i][j]->setHit(true);
                        disp[2]->setY(-100) ;
                    }
               
                    enemigo[i][j]->movimiento(pantalla.getStep(),pantalla.getVel(), dir, ban);
                    enemigo[i][j]->animando(pantalla.getStep(),pantalla.getVel());
                    
                    enemigo[i][j]->show(window);

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
        //manejamos la cantidad de enemigos  y aumentamos la velocidad
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
        if(pantalla.getStepCont() > pantalla.getVel())pantalla.setStep(0);

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
    
}
void reset(bool mod){
    dir=1;
    
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<5;j++)
        {
            enemigo[i][j]->setX(i*110+120);
            enemigo[i][j]->setY(j*60-500);
            enemigo[i][j]->setHit(false);
        }
        if(i<3)disp[i]->setX(-100);
        
    }
    if(mod)
    {
        player->setPts(0);
        player->setVidas(2);
        player->setX(490);
        window.clear(Color::Black);
        window.display();
    }
    player->setHit(false);
}

