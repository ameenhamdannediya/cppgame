#pragma once
#include <SFML/Graphics.hpp>

class Framerate
{
private:
	sf::Font font;
	std::optional<sf::Text> framerate;
	float timer;
public:
	Framerate();
	void Update(float deltatime, int fontsize);
	void Draw(sf::RenderWindow& window);
};

