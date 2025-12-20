#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

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

	int Xindex = 0;
	int Yindex = 0;

	sf::Texture playerheadleather;
	if (!playerheadleather.loadFromFile("assets/player/textures/playerheadleather.png")) {
		std::cout << "player head faild to load" << std::endl;

	}
	sf::Sprite playersheadleatherprite(playerheadleather);
	playersheadleatherprite.setTextureRect(sf::IntRect({ {Xindex * 64, Yindex * 64} , {64, 64} }));


	sf::Texture playertexture;

	if (!playertexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "loading player" << std::endl;
	sf::Sprite playersprite(playertexture);
	playersprite.setTextureRect(sf::IntRect({ {Xindex * 64, Yindex * 64} , {64, 64} }));

	if (!playertexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "loading player" << std::endl;
	sf::Sprite enemysprite(playertexture);
	enemysprite.setTextureRect(sf::IntRect({ {Xindex * 64, Yindex * 64} , {64, 64} }));
	enemysprite.setPosition(sf::Vector2f(100, 100));


	














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
			bullet[i].setPosition(playersprite.getPosition());



		//	//sf::Vector2i cursorposition = sf::Mouse::getPosition(window);
		//	//sf::Vector2f worldPos = window.mapPixelToCoords(cursorposition);
		//	//sf::Vector2f bulletdirection = worldPos - bullet.getPosition();
		//	//bullet.setPosition(bullet.getPosition() + bulletdirection* bulletspeed);

		}
		for (size_t i = 0; i < bullet.size(); i++)
		{
			bulletdirection = enemysprite.getPosition() - bullet[i].getPosition();
			bulletdirection = normalize(bulletdirection);
			bullet[i].setPosition(bullet[i].getPosition() + bulletdirection * bulletspeed);

		}



		sf::Vector2f PrePOsition = playersprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			playersprite.setPosition(PrePOsition + sf::Vector2f(1, 0));
			playersheadleatherprite.setPosition(PrePOsition + sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			playersprite.setPosition(PrePOsition - sf::Vector2f(1, 0));
			playersheadleatherprite.setPosition(PrePOsition - sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			playersprite.setPosition(PrePOsition - sf::Vector2f(0, 1));
			playersheadleatherprite.setPosition(PrePOsition - sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			playersprite.setPosition(PrePOsition + sf::Vector2f(0, 1));
			playersheadleatherprite.setPosition(PrePOsition + sf::Vector2f(0, 1));
		}





		window.clear(sf::Color::Black);
		for (size_t i = 0; i < bullet.size(); i++)
		{
			window.draw(bullet[i]);

		}

		window.draw(enemysprite);
		window.draw(playersprite);
		window.draw(playersheadleatherprite);

		window.display();
	};

	return 0;
}





