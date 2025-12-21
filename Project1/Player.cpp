#include "Player.h"
#include <iostream>





Player::Player()
{
    int Xindex = 0;
    int Yindex = 0;

    // Load body texture
    if (!texture.loadFromFile("assets/player/textures/playerspritesheet.png"))
        std::cout << "player failed to load\n";

    // CREATE sprite INSIDE optional
    Psprite.emplace(texture);
    Psprite->setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
    Psprite->setPosition({ 400.f, 300.f }); // start position

    // Load head texture
    if (!headleather.loadFromFile("assets/player/textures/playerheadleather.png"))
        std::cout << "player head failed to load\n";

    // CREATE head sprite INSIDE optional
    HLsprite.emplace(headleather);
    HLsprite->setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
    HLsprite->setPosition(Psprite->getPosition());
}







//void Player::Initilize()
//{
//}
//
//void Player::Load()
//{
//}

void Player::Update()
{
	if (!Psprite || !HLsprite) return;

	sf::Vector2f pos = Psprite->getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) pos.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) pos.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) pos.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) pos.y += 1;

	Psprite->setPosition(pos);
	HLsprite->setPosition(pos);
}



	


void Player::Draw(sf::RenderWindow& window)
{
	if (Psprite)   window.draw(*Psprite);
	if (HLsprite) window.draw(*HLsprite);
}


sf::Vector2f Player::getPosition() const
{
	return Psprite ? Psprite->getPosition() : sf::Vector2f{};
}