#include "Map.h"
#include <iostream>



Map::Map(const MouseTile& mousetile) : M_mousetile(mousetile	)
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
void Map::Update(float deltatime)
{

}

void Map::Draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < mapsize; i++)
	{
		window.draw(*mapSprites[i]);
	}
}

void Map::grid(int x)
{
}
