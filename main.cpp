#include <SFML/Graphics.hpp>

int main()
{

    //Inicializacion Ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba jueguito v0");
    window.setFramerateLimit(60);
    sf::Sprite NaveProta;
    sf::Texture NaveProta_Text;

    NaveProta_Text.loadFromFile("IMG/Nave.png");
    NaveProta.setTexture(NaveProta_Text);



    //Game loop
    while (window.isOpen())
    {
        //Read input, perifericos
        // 
        //Leer cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //CMD -ejecutar comandos leidos..
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            NaveProta.move(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            NaveProta.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            NaveProta.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            NaveProta.move(0, 1);
        }

        //Update -Actualiza estados del juego

        //Draw -

        window.clear();
        window.draw(NaveProta);
        window.display();
    }

    //Liberacion juego

    return 0;
}