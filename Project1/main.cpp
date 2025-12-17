#include <SFML/Graphics.hpp>





int main() {
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 1;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "project1", sf::State::Windowed);
	//sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "project1");
	sf::CircleShape shape(40.0f, 8);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(320, 100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Blue);

	sf::RectangleShape r1(sf::Vector2f(20.0f,200.0f));
	//r1.setOrigin(sf::Vector2f(r1.getGeometricCenter()));
	r1.setOrigin(sf::Vector2f(r1.getSize()/2.0f));
	r1.setPosition(sf::Vector2f(360 ,290));
	r1.setRotation(sf::degrees(45.0f));

	while (window.isOpen()) {
		while (std::optional event = window.pollEvent()) {
			if (event->is < sf::Event::Closed>())
				window.close();
		}
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(r1);
		window.display();
	};

	return 0;
}
