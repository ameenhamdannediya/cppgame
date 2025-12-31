#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private:
	sf::RectangleShape* HLine;
	sf::RectangleShape* VLine;

	sf::Vector2i scale;
	sf::Vector2i totalCells;
	sf::Vector2i cellSize;

	sf::Vector2f position;
	sf::Vector2i totalLines;

	sf::Color gridColor;

	int LineThickness ;

public:
	Grid(const sf::Vector2i& size,
		const sf::Vector2f& pos, 
		const sf::Vector2i& cell,
		const sf::Vector2i& scale ,
		const sf::Color& color,
		int thickness);
	~Grid();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};

