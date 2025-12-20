#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>





int main() {
	std::vector<std::string> games ;
	games.push_back("gta4");
	games.push_back("gta5");
	games.push_back("gta san andreas");
	games.push_back("far cry");

	for (int i = 0; i < games.size(); i++) {
		std::cout << games[i] << std::endl;
	
	}




	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	//sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	window.setKeyRepeatEnabled(false);


	//sf::CircleShape shape(40.0f, 8);
	//shape.setFillColor(sf::Color::Red);
	//shape.setPosition(sf::Vector2f(320, 100));
	//shape.setOutlineThickness(10);
	//shape.setOutlineColor(sf::Color::Blue);

	//sf::RectangleShape r1(sf::Vector2f(20.0f,200.0f));
	////r1.setOrigin(sf::Vector2f(r1.getGeometricCenter()));
	//r1.setOrigin(sf::Vector2f(r1.getSize()/2.0f));
	//r1.setPosition(sf::Vector2f(360 ,290));
	//r1.setRotation(sf::degrees(45.0f));


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



	int enemyXindex = 2;
	int enemyYindex = 4			;

	if (!playertexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "enymy loading player" << std::endl;
	sf::Sprite enemysprite(playertexture);
	enemysprite.setTextureRect(sf::IntRect({ {enemyXindex * 64, enemyYindex * 64} , {64, 64} }));



















	while (window.isOpen()) {
		while (std::optional event = window.pollEvent()) {
			if (event->is < sf::Event::Closed>())
				window.close();
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
		window.draw(enemysprite);

		window.draw(playersprite);
		window.draw(playersheadleatherprite);
		
		window.display();
	};

	return 0;
}
