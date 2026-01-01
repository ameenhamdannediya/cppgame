#include "Grid.h"

#include <iostream>

Grid::Grid(const sf::Vector2i& size,
			const sf::Vector2f& pos ,
			const sf::Vector2i& cell,
			const sf::Vector2i& scale,
			const sf::Color& color ,
			int thickness) 
			: scale(scale), totalCells(cell),cellSize(size),LineThickness(thickness) ,
			position(pos), gridColor(color)


{
	totalLines =  sf::Vector2i(totalCells.x+ 1, totalCells.y + 1);

	HLine = new sf::RectangleShape[totalLines.y ];
	VLine = new sf::RectangleShape[totalLines.x ];
}

Grid::~Grid()
{
	delete[] HLine;
	delete[] VLine;
}

void Grid::Initialize()
{
	M_size = sf::Vector2f(totalCells.x * cellSize.x * scale.x , totalCells.y * cellSize.y * scale.y);
	

	for (int  i = 0; i < totalLines.y ; i++)
	{
		HLine[i].setSize(sf::Vector2f(M_size.x + LineThickness, LineThickness));
		HLine[i].setPosition(position + sf::Vector2f(0, cellSize.y*i* scale.y));
		HLine[i].setFillColor(gridColor);


	}
	for (int i = 0; i < totalLines.x; i++)
	{
		VLine[i].setSize(sf::Vector2f( LineThickness, M_size.y));
		VLine[i].setPosition(position + sf::Vector2f(cellSize.x* i* scale.x, 0));
		VLine[i].setFillColor(gridColor);


	}


}

void Grid::Load()
{
}

void Grid::Update(float deltatime )
{
	
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < totalLines.y; i++)
	{
		window.draw(HLine[i]);
	}

	for (size_t i = 0; i < totalLines.x ; i++)
	{
		window.draw(VLine[i]);
	}
}
