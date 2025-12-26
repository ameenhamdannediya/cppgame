#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{
	Esize = sf::Vector2i(64,64);
	int EXindex = 0;
	int EYindex = 0;

	if (!Etexture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "loading player" << std::endl;


	//sf::Sprite enemysprite(Etexture);
	Esprite.emplace(Etexture);
	Esprite->setTextureRect(sf::IntRect({EXindex * Esize.x, EYindex * Esize.y} , {Esize.x, Esize.y } ));
	Esprite->scale(sf::Vector2f(1, 1));
	Esprite->setPosition(sf::Vector2f(100, 100));




	boundingrect.setOutlineColor(sf::Color::Green);
	boundingrect.setFillColor(sf::Color::Transparent);
	boundingrect.setSize(sf::Vector2f(Esize.x * Esprite->getScale().x, Esize.y * Esprite->getScale().y));
	boundingrect.setOutlineThickness(1);
}

void Enemy::Update(float deltatime)
{
	boundingrect.setPosition(Esprite->getPosition());

}

void Enemy::Draw(sf::RenderWindow& window)
{
	if (Esprite) window.draw(*Esprite);
	window.draw(boundingrect);
}

sf::Vector2f Enemy::getPosition() const
{
	return Esprite ? Esprite->getPosition() : sf::Vector2f{};
}
