#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
//#define mapsize 150
class Map
{
private:
	 MouseTile& M_mousetile;
	const Grid& M_Grid ;

	int MapSize;

	std::optional <sf::Sprite>* mapSprites;
	std::vector<sf::Sprite> map;

public:
	Map(const Grid& grid,   MouseTile& mousetile);
	~Map();

	void Initialize();
	void Load();
	void Update(float deltatime, const  sf::Vector2f& cursorposition);
	void Draw(sf::RenderWindow& window);

};

