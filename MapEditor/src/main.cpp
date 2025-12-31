#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Map.h"
#include "MouseTile.h"


void r(int z) {
	std::cout << "callack" << z << std::endl;
}


int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	//sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Map Editor");
	
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(250);

	sf::Vector2i TSize = sf::Vector2i(16, 16);
	sf::Vector2f TOffset = sf::Vector2f(0, 0);
	sf::Vector2i TScale = sf::Vector2i(4, 4);

	Grid grid(
		TSize,
		TOffset , 
		sf::Vector2i(15,8), //grid
		TScale,
		sf::Color(255, 0, 0, 255), 
		2 //thickness
		);
	MouseTile mouseTile(
		TSize,
		TScale,
		TOffset 

		);



	grid.Initialize();
	mouseTile.Initialize();
	// loaded and initialised 
	grid.Load();
	mouseTile.Load();




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
		grid.Update(deltatime);

		mouseTile.Update(deltatime, cursorposition, &r);

	





		window.clear(sf::Color::Black);
		grid.Draw(window);
		mouseTile.Draw(window);

		window.display();
	};

	return 0;
}





