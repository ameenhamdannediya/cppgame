#include "Map.h"
#include <iostream>



Map::Map( MouseTile& mousetile) : M_mousetile(mousetile) , mapSprites(nullptr)
{

}
Map::~Map() 
{

}

void Map::Initialize()
{
	mapSprites = new std::optional <sf::Sprite>[mapsize] ;
}

void Map::Load() 
{

}
void Map::Update(float deltatime, const  sf::Vector2f& cursorposition)
{
	sf::Vector2f TPosition;
	if (M_mousetile.isMOuseClickOnTile(TPosition, cursorposition)) {
		std::cout << TPosition.x << std::endl;
		std::cout << TPosition.y << std::endl;
	}
}

void Map::Draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < mapsize; i++)
	{
		if(mapSprites[i]) window.draw(*mapSprites[i]);
	}
}


