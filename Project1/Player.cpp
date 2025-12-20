#include "Player.h"
#include <iostream>

void Player::Initilize()
{
}

void Player::Load()
{
	int Xindex = 0;	
	int Yindex = 0;
	if (!headleather.loadFromFile("assets/player/textures/playerheadleather.png")) {
		std::cout << "player head faild to load" << std::endl;

	}
	sf::Sprite HLsprite(headleather);
	HLsprite.setTextureRect(sf::IntRect({{Xindex * 64, Yindex * 64} , {64, 64}}));


	if (!texture.loadFromFile("assets/player/textures/playerspritesheet.png")) {
		std::cout << "player faild to load" << std::endl;
	}
	std::cout << "loading player" << std::endl;
	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect({ {Xindex * 64, Yindex * 64} , {64, 64} }));

}

void Player::Update()
{
	


	sf::Vector2f PrePOsition = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		sprite.setPosition(PrePOsition + sf::Vector2f(1, 0));
		HLsprite.setPosition(PrePOsition + sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		sprite.setPosition(PrePOsition - sf::Vector2f(1, 0));
		HLsprite.setPosition(PrePOsition - sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		sprite.setPosition(PrePOsition - sf::Vector2f(0, 1));
		HLsprite.setPosition(PrePOsition - sf::Vector2f(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		sprite.setPosition(PrePOsition + sf::Vector2f(0, 1));
		HLsprite.setPosition(PrePOsition + sf::Vector2f(0, 1));
	}


}

void Player::Draw()
{
}
