

#include "Escena.h"

#include "Enemigo.h"
#include "Juego.h"
int main()
{
    Juego juego;
    juego.runJuego();

    return 0;
}



/*
#include "Jugador.h"
using namespace sf;


graf.SetBackgroundColor(Color(20, 20, 50));
graf.Display();#1#





//RenderWindow tata(VideoMode(1024, 720),"lara") ;
//RenderWindow window= pantalla.getWindow(1024,720);
//pantalla.render(100,100,"aaa");


Jugador *player = new Jugador(0,  0, 500, 520,   70,  70,"img/Nave.png");

//arreg
Jugador *escena = new Jugador(  0, 250, 0, 584, 1024, 120, "img/itens.png");

Enemigo * disp[3];


Enemigo * enemigo[7][5];

//Rider jetbrains

// array 30 for show names


int dir=0, outsrc=670;
void reset(bool mod);
int main()
{ graf.setInicio();   
    //creamos los objetos enemigos
    for(int i = 0; i < 6; i++)
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
    
    while(graf.isOpen()) /////// eee
    {
        
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
        graf.clear(Color::Black);
        graf.display();
    }
    player->setHit(false);
}
*/

