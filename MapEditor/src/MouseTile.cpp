#include "MouseTile.h"
#include <iostream>

void foobar(int x, void(*onGridClick(int)))
{
	onGridClick(x);
}

MouseTile::MouseTile(const sf::Vector2i& size, const sf::Vector2i& scale, const sf::Vector2f& offset)
				: tileSize(size) , tilescale(scale) , tileOffset(offset)
{

}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{
	tilesheet.loadFromFile("assets/WorldMap/prison/tilesheet.png");
	tile.emplace(tilesheet);
	tile->setTexture(tilesheet);
	tile->setTextureRect(sf::IntRect({ tileSize.x *11, 0 }, { tileSize }));
	tile->setScale(sf::Vector2f(tilescale));
}

void MouseTile::Update(float deltatime, sf::Vector2f cursorposition, void (*onGridClick)(int) )
{
	int gridX = (cursorposition.x - tileOffset.x) / (tileSize.x * tilescale.x);
	int x = gridX * (tileSize.x * tilescale.x) + tileOffset.x;
	int gridY = (cursorposition.y - tileOffset.y) / (tileSize.y * tilescale.y);
	int y = gridY * (tileSize.y * tilescale.y) + tileOffset.y;
	tile->setPosition(sf::Vector2f(x, y));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		int gridIndex = gridX + gridY * 15;
		std::cout << gridIndex << std::endl;
		onGridClick(gridIndex);
		
	}
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(*tile);
}


