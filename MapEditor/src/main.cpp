#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Map.h"
#include "MouseTile.h"
#include "GUI/Button.h"



using namespace GUI;
int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	//sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Map Editor");
	
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(250);

	sf::Vector2i TSize = sf::Vector2i(16, 16);
	sf::Vector2f TOffset = sf::Vector2f(200, 20);
	sf::Vector2i TScale = sf::Vector2i(4, 4);

	Grid grid(
		TSize,
		TOffset , 
		sf::Vector2i(15,10), //grid
		TScale,
		sf::Color(255, 0, 0, 255), 
		2 //thickness
		);
	MouseTile mouseTile(grid,
		TSize,
		TScale,
		TOffset 

		);
	Map map(grid, mouseTile);
	Button button(sf::Vector2f(100,25), sf::Vector2f(3,3));

	grid.Initialize();
	mouseTile.Initialize();
	map.Initialize();
	button.Initialize();
	// loaded and initialised 
	grid.Load();
	mouseTile.Load();
	map.Load();
	button.Load();




	sf::Clock clock;

	while (window.isOpen()) {


		sf::Time deltatimer = clock.restart();
		float deltatime = deltatimer.asMilliseconds();


		//std::cout <<  << std::endl;
		while (std::optional event = window.pollEvent()) {

			if (event->is < sf::Event::Closed>())
				window.close();

		}

		sf::Vector2f cursorposition = sf::Vector2f(sf::Mouse::getPosition(window));

		mouseTile.Update(deltatime, cursorposition);

		grid.Update(deltatime);
		map.Update(deltatime, cursorposition);
		button.Update(deltatime, cursorposition);

		if (button.isPressed()) {
			std::cout << "asdfwdasd" << std::endl;
		}

	





		window.clear(sf::Color::Black);
		grid.Draw(window);
		mouseTile.Draw(window);
		map.Draw(window);
		button.Draw(window);

		window.display();
	};

	return 0;
}





