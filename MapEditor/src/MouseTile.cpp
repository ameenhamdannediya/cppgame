#include "MouseTile.h"

MouseTile::MouseTile(const sf::Vector2i& size, const sf::Vector2f& scale) 
				: tileSize(size) , tilescale(scale) 
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

void MouseTile::Update(float deltatime, sf::Vector2f cursorposition)
{
	int x = (int)(cursorposition.x / (tileSize.x * tilescale.x)) * (tileSize.x * tilescale.x);
	int y = (int)(cursorposition.y / (tileSize.y * tilescale.y)) * (tileSize.y * tilescale.y);
	tile->setPosition(sf::Vector2f(x, y));
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(*tile);
}


