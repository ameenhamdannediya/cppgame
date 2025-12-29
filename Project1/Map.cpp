#include "Map.h"
#include <iostream>

Map::Map() : tileHeight(16), tileWidth(16) ,  totalTilesX(0), totalTilesY(0)
{
}

Map::~Map()
{
	delete[] tiles;
}

void Map::Initialize()
{
}

void Map::Load()
{
	

	if (tileSheetTexture.loadFromFile("assets/WorldMap/prison/tilesheet.png")) {

		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;
		totalTiles = totalTilesX * totalTilesY;

		tiles = new Tile[totalTiles];

		for (int mapY  = 0; mapY < totalTilesY; mapY++)
		{
			for (int mapX = 0; mapX < totalTilesX; mapX++)
			{


				int i = mapX + mapY * totalTilesX;


				tiles[i].id = i;
				tiles[i].Mposition = sf::Vector2i(mapX * tileWidth, tileHeight * mapY);
					

				//tiles[i].texture = &tileSheetTexture;
				//tiles[i].sprite.emplace(tileSheetTexture);
				//tiles[i].sprite->setScale(sf::Vector2f(2, 2));
				// //tiles[i].sprite->setTexture(tileSheetTexture);
				//tiles[i].sprite->setTextureRect(sf::IntRect({ static_cast<int>(mapX * tileWidth),   static_cast<int>(tileHeight * mapY) }, { tileWidth, tileHeight }));
				//tiles[i].sprite->setPosition(sf::Vector2f(static_cast<float>(tileWidth * 2 * mapX), static_cast<float>(tileWidth * 2 * mapY )));
			}
		}

		std::cout << "map loaded" << std::endl;


	}
	else {
		std::cout << "map not loaded" << std::endl;

	}

	// y is num of row
	for (int y = 0; y < 2; y++)
	{
		//x is num of colomns
		for (int x = 0; x < 3; x++)
		{
			int i = x + y * 3 ;
			int index = mapNums[i];
			map[i].emplace(tileSheetTexture);
			map[i]->setTextureRect(sf::IntRect({ tiles[index].Mposition.x , tiles[index].Mposition.y }, { tileWidth, tileHeight }));
			map[i]->setScale(sf::Vector2f(4, 4));
			map[i]->setPosition(sf::Vector2f(x * map[i]->getScale().x * tileWidth, y * map[i]->getScale().y * tileHeight));


		}

	}

	
}

void Map::Update(float deltatime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	//one int is 4bytes adn total size of array/4 or sizeof one elemt give the number which is 6 in this case
	//int size = sizeof(mapNums) / sizeof(mapNums[0]);
	for (int i = 0; i < 6 ; i++)
	{
		if (map[i]) window.draw(*map[i]);
	}
}
