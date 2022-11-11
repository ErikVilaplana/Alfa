#include "Menu.h"


Menu::Menu(float ancho, float altura){
    texmapa.loadFromFile("img/fondo.jpg");
    spmapa.setTexture(texmapa);
    if(!fuente.loadFromFile("img/galaga.ttf")){

    }
    menu[0].setFont(fuente);
    menu[0].setScale(1.5,1.5);
    
    menu[0].setString("1 Jugador");
    menu[0].setPosition(Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*1.5));

    menu[1].setFont(fuente);
    menu[1].setScale(1.5,1.5);
    
    menu[1].setString("2 Jugadores");
    menu[1].setPosition(Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*2.5));

    menu[2].setFont(fuente);
    menu[2].setScale(1.5,1.5);
    
    menu[2].setString("Dificultad");
    menu[2].setPosition(Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*3.5));

    menu[3].setFont(fuente);
    
    menu[3].setString("Salir");
    menu[3].setScale(1.5,1.5);
    menu[3].setPosition(Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*4.5));

    menu[4].setFont(fuente);
    
    menu[4].setString("RETURN FROM HELL");
    menu[4].setScale(2,2);
    menu[4].setPosition(Vector2f(ancho/2.7, altura/(MAX_NUMBER_OF_ITEMS+1)*0.2));

    seleccionarindice = 0;
}

Menu::~Menu(){
}

void Menu::dibujar(RenderWindow &window){
    window.draw(spmapa);
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }

}
void Menu::moverarriba(){

    if(seleccionarindice -1 >= 0 & seleccionarindice <4){
    
        seleccionarindice--;
    
    }

}

void Menu::moverabajo(){
    if(seleccionarindice +1 < MAX_NUMBER_OF_ITEMS-1){
    
        seleccionarindice++;
    
    }
}