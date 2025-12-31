#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	const static int spriteSize = 10;

	Tile* tiles;

	MapLoader mapLoader;
	MapData md;
	

	int totalTilesX;
	int totalTilesY;
	int totalTiles;



	
	
	std::optional<sf::Sprite>* map;
public:
	Map();
	~Map();
	 
	void Initialize();
	void Load(std::string filename);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};

