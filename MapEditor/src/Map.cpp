#include "Map.h"
#include "Grid.h"
#include <iostream>



Map::Map(const Grid& grid ,  MouseTile& mousetile) 
	: M_mousetile(mousetile) , mapSprites(nullptr), M_Grid(grid), MapSize(M_Grid.GetTotalCells().x * M_Grid.GetTotalCells().y)
{

}
Map::~Map() 
{

}

void Map::Initialize()
{
	mapSprites = new std::optional <sf::Sprite>[MapSize] ;
	
}

void Map::Load() 
{

}
void Map::Update(float deltatime, const  sf::Vector2f& cursorposition)

{
	sf::Vector2f TPosition;
	sf::Vector2i GPosition;

	
	if (M_mousetile.isMOuseClickOnTile(TPosition, GPosition, cursorposition))  {
		int index = GPosition.x + GPosition.y * M_Grid.GetTotalCells().x;

		std::cout << index << std::endl;
	
		mapSprites[index] = M_mousetile.GetTileSprite();
	}
}

void Map::Draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < MapSize; i++)
	{
		if(mapSprites[i]) window.draw(*mapSprites[i]);
	}
}


