#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#define mapsize 50
class Map
{
private:
	MouseTile& M_mousetile;
	std::optional <sf::Sprite>* mapSprites;

public:
	Map( MouseTile& mousetile);
	~Map();

	void Initialize();
	void Load();
	void Update(float deltatime, const  sf::Vector2f& cursorposition);
	void Draw(sf::RenderWindow& window);

};

