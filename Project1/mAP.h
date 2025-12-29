#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
class Map
{
private:
	sf::Texture tileSheetTexture;
	const static int spriteSize = 10;

	Tile* tiles;

	int tileHeight;
	int tileWidth;
	int totalTilesX;
	int totalTilesY;
	int totalTiles;



	int mapNums[6] = {
		1,3,5, 
		12,13,30
	};
	
	std::optional <sf::Sprite > map[6];
public:
	Map();
	~Map();
	 
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};

