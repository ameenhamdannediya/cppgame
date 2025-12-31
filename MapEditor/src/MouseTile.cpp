#include "MouseTile.h"
#include <iostream>
#define thisIsOut

void foobar(int x, void(*onGridClick(int)))
{
	onGridClick(x);
}

MouseTile::MouseTile(const sf::Vector2i& size, 
	const sf::Vector2i& scale, 
	const sf::Vector2f& offset)
	: tileSize(size) , tilescale(scale) , tileOffset(offset), 
	isMouseOnGrid(false), Tnum(11)
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
	tile->setTextureRect(sf::IntRect({ tileSize.x *Tnum, 0 }, { tileSize }));
	tile->setScale(sf::Vector2f(tilescale));

}
void MouseTile::Update(float deltatime, const  sf::Vector2f& cursorposition)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)&&(Tnum > 0)) {
		Tnum -= 1;
		tile->setTextureRect(sf::IntRect({ tileSize.x * Tnum  , 0 }, { tileSize }));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (Tnum < 20)) {
		Tnum += 1;
		tile->setTextureRect(sf::IntRect({ tileSize.x * Tnum  , 0 }, { tileSize }));
	}
	M_tileGridPosition.x = (cursorposition.x - tileOffset.x) / (tileSize.x * tilescale.x);///tile id 
	M_tilePosition.x = M_tileGridPosition.x * (tileSize.x * tilescale.x) + tileOffset.x;
	M_tileGridPosition.y = (cursorposition.y - tileOffset.y) / (tileSize.y * tilescale.y);
	M_tilePosition.y = M_tileGridPosition.y * (tileSize.y * tilescale.y) + tileOffset.y;

	tile->setPosition(M_tilePosition);
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(*tile);
}

bool MouseTile::isMOuseClickOnTile(thisIsOut sf::Vector2f& tilePosition,
		sf::Vector2i& gridPosition, 
		const  sf::Vector2f& cursorposition) const 
	{


	bool isOnGrid = true;

		

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&& isOnGrid) {

		tilePosition = M_tilePosition;
		gridPosition = M_tileGridPosition;
		return true;

	}
	return false;
}


