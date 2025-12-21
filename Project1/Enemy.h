#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{

private:
	sf::Texture Etexture;

	std::optional<sf::Sprite> Esprite;



public:
	Enemy();
	void Update();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;




};







