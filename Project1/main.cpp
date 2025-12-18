#include <SFML/Graphics.hpp>
#include <iostream>





int main() {
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


	sf::Texture playertexture;
	if (!playertexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
	
	
		std::cout << "faild to load" << std::endl;
		return -1;
	}
	
	std::cout << "loading" << std::endl;
	sf::Sprite playersprite(playertexture);
	int Xindex = 0;
	int Yindex = 0;
	playersprite.setTextureRect(sf::IntRect({ {Xindex*64, Yindex*64} , {64, 64} }));

	


	while (window.isOpen()) {
		while (std::optional event = window.pollEvent()) {
			if (event->is < sf::Event::Closed>())
				window.close();

			
			
			
			
		}


		sf::Vector2f PrePOsition = playersprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			playersprite.setPosition(PrePOsition + sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			playersprite.setPosition(PrePOsition - sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			playersprite.setPosition(PrePOsition - sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			playersprite.setPosition(PrePOsition + sf::Vector2f(0, 1));
		}
		window.clear(sf::Color::Black);
		//window.draw(shape);
		//window.draw(r1);
		window.draw(playersprite);
		window.display();
	};

	return 0;
}
