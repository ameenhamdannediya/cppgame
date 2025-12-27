#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Framerate.h"




int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	//sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(250);


	// loaded and initialised 
	Player player;
	Enemy enemy;
	Framerate framerate;




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



		enemy.Update(deltatime);
		player.Update(enemy, deltatime, cursorposition);
		framerate.Update(deltatime, 22);






		window.clear(sf::Color::Black);

		enemy.Draw(window);
		player.Draw(window);
		framerate.Draw(window);

		window.display();
	};

	return 0;
}





