#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"



class Player
{
private:
	sf::Texture headleather;
	sf::Texture texture;
	std::vector<Bullet>bullet;

	float maxFireRate;
	float fireRateTimer;
	float playerspeed;

	sf::RectangleShape boundingrect;
	sf::Vector2i Psize;


	std::optional<sf::Sprite> Psprite;
	std::optional<sf::Sprite> HLsprite;
	
public:
	Player();
	void Update(Enemy& enemy, float deltatime, sf::Vector2f cursorposition);
	void Draw(sf::RenderWindow& window);

	//void Initilize();
	//void Load();
	//sf::Vector2f getPosition() const;
	

};

	