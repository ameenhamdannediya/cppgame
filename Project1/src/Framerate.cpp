#include "Framerate.h"
#include <iostream>

Framerate::Framerate() : timer(0)
{

	if (font.openFromFile("assets/fonts/Arial.ttf")) {
		std::cout << "font loaded" << std::endl;
		framerate.emplace(font);
	}
	else {
		std::cout << "font not loaded" << std::endl;

	}
}

void Framerate::Update(float deltatime, int fontsize)
{
	timer += deltatime;
	if (timer >= 500) {
	
	float fpsrate = 1000 / deltatime;
	std::string text = "FPS :" + std::to_string((int)fpsrate) + "  render time ms " + std::to_string((int)deltatime);
	framerate->setString(text);
	framerate->setCharacterSize(fontsize);
	timer = 0;

	}
}

void Framerate::Draw(sf::RenderWindow& window)
{
	if (framerate) window.draw(*framerate);

}
