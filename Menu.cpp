#include "Menu.h"

#include "Juego.h"

Menu::Menu(){
  window = new RenderWindow();
  winclose = new RectangleShape();
  font = new Font();
  image = new Texture();
  bg = new Sprite();

  set_values();
}

Menu::~Menu(){
  delete window;
  delete winclose;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  window->create(VideoMode(1024,700), "Menu SFML", Style::Titlebar | Style::Close);
  window->setPosition(Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("img/galaga.ttf");
  image->loadFromFile("img/fondoDos.jpg");

  bg->setTexture(*image);

  pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"", "Play", "Options", "About", "Quit"};
  texts.resize(5);
  coords = {{590,40},{610,191},{590,282},{600,370},{623,457}};
  sizes = {20,28,24,24,24};

  for (size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(Color::Black);
   texts[i].setPosition(coords[i]);
  }
  texts[1].setOutlineThickness(4);
  pos = 1;

  winclose->setSize(Vector2f(23,26));
  winclose->setPosition(1178,39);
  winclose->setFillColor(Color::Transparent);

}

void Menu::loop_events(){
  Event event;
  string input_text;
  Font font;
  font.loadFromFile("img/galaga.ttf");
  text= new Text("", font);
  text->setOutlineThickness(2);
  text->setFillColor(Color::Blue);
  text->setOutlineColor(Color(127,127,127));
  text->setPosition(0,650);

    
  Clock clock;
  while(window->pollEvent(event)){
    if( event.type == Event::Closed){
      window->close();
    }
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

    pos_mouse = Mouse::getPosition(*window);
    mouse_coord = window->mapPixelToCoords(pos_mouse);

    if(Keyboard::isKeyPressed(Keyboard::Down) && !pressed){
      if( pos < 4){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(Keyboard::isKeyPressed(Keyboard::Up) && !pressed){
      if( pos > 1){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }
    if(Keyboard::isKeyPressed(Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 1){
        
      }
      cout << options[pos] << '\n';
    }
    if(Keyboard::isKeyPressed(Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 4){
        window->close();
      }
      cout << options[pos] << '\n';
    }

    if(Mouse::isButtonPressed(Mouse::Left)){
      if(winclose->getGlobalBounds().contains(mouse_coord)){
        //cout << "Close the window!" << '\n';
        window->close();
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

  text->setString(input_text + (show_cursor ? '_' : ' '));
  if (event.key.code == Keyboard::Escape) {
    if (!input_text.empty())
    {
                
      
      window->clear();
      
    }
  }
  
  
  

  
}

void Menu::draw_all(){
  window->clear();
  window->draw(*bg);
  for(auto t : texts){
   window->draw(t); 
  }
  window->draw(* text);
  window->display();
}

void Menu::run_menu(){
  while(window->isOpen()){
    loop_events();
    draw_all();
  }
}