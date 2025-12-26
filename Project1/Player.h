#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"






class Player
{
private:
	sf::Texture headleather;
	sf::Texture texture;
	std::vector<sf::RectangleShape >bullet;
	float bulletspeed = 1.0f;
	float playerspeed = 1.0f;

	sf::RectangleShape boundingrect;
	sf::Vector2i Psize;


	std::optional<sf::Sprite> Psprite;
	std::optional<sf::Sprite> HLsprite;
	
public:
	Player();
	//void Initilize();
	//void Load();

	void Update(Enemy& enemy, float deltatime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	

};

	