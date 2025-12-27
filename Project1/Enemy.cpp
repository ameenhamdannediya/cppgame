#include "Enemy.h"
#include <iostream>


Enemy::Enemy() : health(100)
{

	Esize = sf::Vector2i(64,64);
	int EXindex = 0;
	int EYindex = 0;



	if (font.openFromFile("assets/fonts/Arial.ttf")) {
		std::cout << "font loaded" << std::endl;
		healthtext.emplace(font);
		healthtext->setCharacterSize(16);
		


	}
	else {
		std::cout << "font not loaded" << std::endl;
	}


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


	healthtext->setString(std::to_string(health));

}

void Enemy::changeHealth(int hp)
{
	health += hp;
	healthtext->setString(std::to_string(health));
}



void Enemy::Update(float deltatime)
{
	if (health > 0) {
		boundingrect.setPosition(Esprite->getPosition());
		healthtext->setPosition(Esprite->getPosition());
	}


}

void Enemy::Draw(sf::RenderWindow& window)
{
	if (health > 0) {
	if (Esprite) window.draw(*Esprite);
	window.draw(boundingrect);
	if (healthtext) window.draw(*healthtext);
	}

}

//sf::Vector2f Enemy::getPosition() const
//{
//	return Esprite ? Esprite->getPosition() : sf::Vector2f{};
//}
