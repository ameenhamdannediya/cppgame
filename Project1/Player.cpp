#include "Player.h"
#include <iostream>
#include "Math.h"





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

void Player::Update(Enemy& enemy)
{
	if (!Psprite || !HLsprite) return;

	sf::Vector2f pos = Psprite->getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) pos.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) pos.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) pos.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) pos.y += 1;

	Psprite->setPosition(pos);
	HLsprite->setPosition(pos);

	sf::Vector2f bulletdirection;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullet.push_back(sf::RectangleShape(sf::Vector2f(25, 10)));
		int i = bullet.size() - 1;
		bullet[i].setPosition(Psprite->getPosition());


		//	//sf::Vector2i cursorposition = sf::Mouse::getPosition(window);
		//	//sf::Vector2f worldPos = window.mapPixelToCoords(cursorposition);
		//	//sf::Vector2f bulletdirection = worldPos - bullet.getPosition();
		//	//bullet.setPosition(bullet.getPosition() + bulletdirection* bulletspeed);

	}
	for (size_t i = 0; i < bullet.size(); i++)
	{
		bulletdirection = enemy.getPosition() - bullet[i].getPosition();
		bulletdirection = Math::normalize(bulletdirection);
		bullet[i].setPosition(bullet[i].getPosition() + bulletdirection * bulletspeed);

	}


}



	


void Player::Draw(sf::RenderWindow& window)
{
	if (Psprite)   window.draw(*Psprite);
	if (HLsprite) window.draw(*HLsprite);
	for (size_t i = 0; i < bullet.size(); i++)
	{
		window.draw(bullet[i]);

	}
}


sf::Vector2f Player::getPosition() const
{
	return Psprite ? Psprite->getPosition() : sf::Vector2f{};
}