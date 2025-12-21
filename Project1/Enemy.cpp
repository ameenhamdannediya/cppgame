#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{
	int EXindex = 0;
	int EYindex = 0;

	if (!Etexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "loading player" << std::endl;


	//sf::Sprite enemysprite(Etexture);
	Esprite.emplace(Etexture);
	Esprite->setTextureRect(sf::IntRect({ {EXindex * 64, EYindex * 64} , {64, 64} }));
	Esprite->setPosition(sf::Vector2f(100, 100));

}

void Enemy::Update()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
	if (Esprite) window.draw(*Esprite);
}

sf::Vector2f Enemy::getPosition() const
{
	return Esprite ? Esprite->getPosition() : sf::Vector2f{};
}
