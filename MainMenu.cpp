#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("IMG/galaga.ttf")) {
		cout << "No font is here";
	}
	_texmapa.loadFromFile("img/bg.jpg");
	_spmapa.setTexture(_texmapa);

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Jugar");
	mainMenu[0].setCharacterSize(30);
	mainMenu[0].setOrigin(mainMenu[0].getGlobalBounds().width / 2, mainMenu[0].getGlobalBounds().height / 2);
	mainMenu[0].setPosition(510, 360);
	//Score
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Puntaje");
	mainMenu[1].setCharacterSize(30);
	mainMenu[1].setOrigin(mainMenu[1].getGlobalBounds().width / 2, mainMenu[1].getGlobalBounds().height / 2);
	mainMenu[1].setPosition(510,410);
	//About
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Acerca de");
	mainMenu[2].setCharacterSize(30);
	mainMenu[2].setOrigin(mainMenu[2].getGlobalBounds().width / 2, mainMenu[2].getGlobalBounds().height / 2);
	mainMenu[2].setPosition(510, 460);
	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Salir");
	mainMenu[3].setCharacterSize(30);
	mainMenu[3].setOrigin(mainMenu[3].getGlobalBounds().width / 2, mainMenu[3].getGlobalBounds().height / 2);
	mainMenu[3].setPosition(510, 510);

	MainMenuSelected = -1;
}
MainMenu::~MainMenu()
{}

//Draw MainMenu

void MainMenu::draw(RenderWindow * window){

	window->draw(_spmapa);
	for (int i = 0; i < Max_main_menu; ++i) {
		window->draw(mainMenu[i]);
	}
}

//MoveUp
void MainMenu::Moveup() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

//MoveDown
void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}