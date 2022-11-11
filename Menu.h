#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 5

class Menu{
private:
    Texture texmapa;
    Sprite spmapa;
    int seleccionarindice;
    Font fuente;
    Text menu[MAX_NUMBER_OF_ITEMS];

public:
    Menu(float ancho, float altura);
    ~ Menu();
    void dibujar(RenderWindow &w);
    void moverarriba();
    void moverabajo();
    int presionaritem(){return seleccionarindice;}
};