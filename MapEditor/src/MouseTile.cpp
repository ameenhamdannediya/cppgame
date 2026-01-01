#include "MouseTile.h"
#include <iostream>
#define thisIsOut

void foobar(int x, void(*onGridClick(int)))
{
	onGridClick(x);
}

MouseTile::MouseTile(const Grid& grid, const sf::Vector2i& size,
	const sf::Vector2i& scale,
	const sf::Vector2f& offset)
	: tileSize(size), tilescale(scale), tileOffset(offset),
	isMouseOnGrid(false), Tnum(11), intputTime(0), M_grid(grid)
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
	intputTime += deltatime;
	//bool isPRD = false;
	//bool isRLD = false;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key) && !isRLD) {
	//	isPRD = true;

	//}
	//else
	//{
	//	if (isPRD) {
	//		isRLD = true;
	//		return true;
	//	}

	//	isPRD = false;
	//	return false;
	//}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)&&(intputTime >= 500)) {
		Tnum -= 1 * deltatime;
		tile->setTextureRect(sf::IntRect({ tileSize.x * Tnum  , 0 }, { tileSize }));
		intputTime = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (intputTime >= 500)) {
		Tnum += 1* deltatime;
		tile->setTextureRect(sf::IntRect({ tileSize.x * Tnum  , 0 }, { tileSize }));
		intputTime = 0.0f;
	}

	const sf::Vector2f& gridPositiion = M_grid.GetPosition();
	const sf::Vector2f& gridSize= M_grid.GetSize();

	if (cursorposition.x >= gridPositiion.x && cursorposition.x < gridPositiion.x+ gridSize.x &&
		cursorposition.y >= gridPositiion.y && cursorposition.y < gridPositiion.y + gridSize.y) {


	M_tileGridPosition.x = (cursorposition.x - tileOffset.x) / (tileSize.x * tilescale.x);///tile id 
	M_tilePosition.x = M_tileGridPosition.x * (tileSize.x * tilescale.x) + tileOffset.x;
	M_tileGridPosition.y = (cursorposition.y - tileOffset.y) / (tileSize.y * tilescale.y);
	M_tilePosition.y = M_tileGridPosition.y * (tileSize.y * tilescale.y) + tileOffset.y;

	tile->setPosition(M_tilePosition);
	isMouseOnGrid = true;
	}
	else {
		isMouseOnGrid = false;
	}




}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(*tile);
}

bool MouseTile::isMOuseClickOnTile(thisIsOut sf::Vector2f& tilePosition,
		sf::Vector2i& gridPosition, 
		const  sf::Vector2f& cursorposition) const 
	{
		
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&& isMouseOnGrid) {

		tilePosition = M_tilePosition;
		gridPosition = M_tileGridPosition;
		return true;

	}
	return false;
}




