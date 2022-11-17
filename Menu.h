#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class Juego;
using namespace std;
using namespace sf;

class Menu {
    int pos;
    bool pressed, theselect;

    RenderWindow * window;
    RectangleShape * winclose;
    Font * font;
    Texture * image;
    Sprite * bg;
    Text * text;
    Vector2i pos_mouse;
    Vector2f mouse_coord;

    vector<const char *> options;
    vector<Vector2f> coords;
    vector<Text> texts;
    vector<std::size_t> sizes;

protected:
    

public:
    Menu();
    ~Menu();
    void set_values();
    void loop_events();
    void draw_all();
    void run_menu();
};
