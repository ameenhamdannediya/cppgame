#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"




int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	//sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(250);

	Player player;
	Enemy enemy;

	//player.Initilize();
	//player.Load();


	sf::Clock clock;

	while (window.isOpen()) {
	sf::Time deltatimer = clock.restart();
	float deltatime = deltatimer.asMilliseconds();	

		while (std::optional event = window.pollEvent()) {

			if (event->is < sf::Event::Closed>())
				window.close();

		}

		enemy.Update(deltatime);
		player.Update(enemy, deltatime);






		window.clear(sf::Color::Black);

		enemy.Draw(window);
		player.Draw(window);

		window.display();
	};

	return 0;
}





