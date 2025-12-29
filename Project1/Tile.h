#pragma once
#include <SFML/Graphics.hpp>

struct Tile
{
	int id = -1;
	
	sf::Texture* texture = nullptr;
	//std::optional <sf::Sprite> sprite;
	
	sf::Vector2i Mposition;
};