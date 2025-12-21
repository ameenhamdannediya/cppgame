#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"




int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	//sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	window.setKeyRepeatEnabled(false);

	
	Player player;
	Enemy enemy;

	//player.Initilize();
	//player.Load();




	while (window.isOpen()) {

		while (std::optional event = window.pollEvent()) {

			if (event->is < sf::Event::Closed>())
				window.close();

		}
		
		
		player.Update(enemy);





		window.clear(sf::Color::Black);
		
		enemy.Draw(window);
		player.Draw(window);

		window.display();
	};

	return 0;
}





