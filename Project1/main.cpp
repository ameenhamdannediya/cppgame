#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"

sf::Vector2f normalize(sf::Vector2f vector) {
	float magnitude = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	sf::Vector2f normalised;
	normalised.x = vector.x / magnitude;
	normalised.y = vector.y / magnitude;

	return normalised ;
}


int main() {


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	//sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	window.setKeyRepeatEnabled(false);

	std::vector<sf::RectangleShape >bullet;
	float bulletspeed = 1.0f;

	Player player;
	Enemy enemy;

	//player.Initilize();
	//player.Load();
	
	



	sf::Vector2f bulletdirection;


	while (window.isOpen()) {

		while (std::optional event = window.pollEvent()) {

			if (event->is < sf::Event::Closed>())
				window.close();

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullet.push_back(sf::RectangleShape(sf::Vector2f(25,10)));
			int i = bullet.size() - 1;
			bullet[i].setPosition(player.getPosition());


		//	//sf::Vector2i cursorposition = sf::Mouse::getPosition(window);
		//	//sf::Vector2f worldPos = window.mapPixelToCoords(cursorposition);
		//	//sf::Vector2f bulletdirection = worldPos - bullet.getPosition();
		//	//bullet.setPosition(bullet.getPosition() + bulletdirection* bulletspeed);

		}
		for (size_t i = 0; i < bullet.size(); i++)
		{
			bulletdirection = enemy.getPosition() - bullet[i].getPosition();
			bulletdirection = normalize(bulletdirection);
			bullet[i].setPosition(bullet[i].getPosition() + bulletdirection * bulletspeed);

		}
		
		
		player.Update();



		





		window.clear(sf::Color::Black);
		for (size_t i = 0; i < bullet.size(); i++)
		{
			window.draw(bullet[i]);

		}


		//window.draw(player.sprite);
		//window.draw(player.HLsprite);
		
		enemy.Draw(window);
		player.Draw(window);

		window.display();
	};

	return 0;
}





