#include "Player.h"
#include <iostream>
#include "Math.h"





Player::Player() : playerspeed (1.0f) , fireRateTimer(0) , maxFireRate(100)
{
	Psize = sf::Vector2i(64,64);

	
	
    int Xindex = 0;
    int Yindex = 0;

    // Load body texture
    if (!texture.loadFromFile("assets/player/textures/playerspritesheet.png"))
        std::cout << "player failed to load\n";

    // CREATE sprite INSIDE optional
    Psprite.emplace(texture);
	Psprite->scale(sf::Vector2f(1,1));
    Psprite->setTextureRect(sf::IntRect({ Xindex * Psize.x , Yindex * Psize.y}, { Psize.x, Psize.y }));
    Psprite->setPosition({ 400.f, 300.f }); // start position

    // Load head texture 
    if (!headleather.loadFromFile("assets/player/textures/playerheadleather.png"))
        std::cout << "player head failed to load\n";

    // CREATE head sprite INSIDE optional
    HLsprite.emplace(headleather);
    HLsprite->setTextureRect(sf::IntRect({ Xindex * Psize.x, Yindex * Psize.y }, { Psize.x, Psize.y }));
    HLsprite->setPosition(Psprite->getPosition());



	boundingrect.setOutlineColor(sf::Color::Red);
	boundingrect.setFillColor(sf::Color::Transparent);
	boundingrect.setSize(sf::Vector2f(Psize.x * Psprite->getScale().x, Psize.y* Psprite->getScale().y));
	boundingrect.setOutlineThickness(1);

}







//void Player::Initilize()
//{
//}
//
//void Player::Load()
//{
//}

void Player::Update(Enemy& enemy, float deltatime, sf::Vector2f cursorposition)
{
	if (!Psprite || !HLsprite) return;

	sf::Vector2f pos = Psprite->getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) pos.x += 1 * playerspeed * deltatime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) pos.x -= 1 * playerspeed * deltatime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) pos.y -= 1 * playerspeed * deltatime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) pos.y += 1 * playerspeed * deltatime;

	Psprite->setPosition(pos );
	HLsprite->setPosition(pos );


	//bullet
	fireRateTimer += deltatime;
	sf::Vector2f bulletdirection;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
	{
		bullet.push_back(Bullet());
		int i = bullet.size() - 1;
		bullet[i].Initialize(Psprite->getPosition(), cursorposition, 1.0f);

		//bullet[i].setPosition(Psprite->getPosition());
		fireRateTimer = 0;

		//	//sf::Vector2f bulletdirection = worldPos - bullet.getPosition();
		//	//bullet.setPosition(bullet.getPosition() + bulletdirection* bulletspeed);

	}
	for (size_t i = 0; i < bullet.size(); i++)
	{
		
		//bulletdirection = cursorposition - bullet[i].getPosition();
		//bulletdirection = Math::normalize(bulletdirection);
		//bullet[i].setPosition(bullet[i].getPosition() + bulletdirection * bulletspeed * deltatime);

		bullet[i].Update(deltatime);
		if (enemy.health > 0) {

			if (Math::IsCollision(bullet[i].GetGlobalBounds(), enemy.Esprite->getGlobalBounds())) {

				bullet.erase(bullet.begin() + i);
				enemy.changeHealth(-5);



			}
		}
	}

	boundingrect.setPosition(Psprite->getPosition());
	if (Math::IsCollision(Psprite->getGlobalBounds(), enemy.Esprite->getGlobalBounds())) {
		printf("colided");
	
	
	};
	


}



	


void Player::Draw(sf::RenderWindow& window)
{
	if (Psprite)   window.draw(*Psprite);
	if (HLsprite) window.draw(*HLsprite);
	window.draw(boundingrect);
	for (size_t i = 0; i < bullet.size(); i++)
	{
		bullet[i].Draw(window);

	}
}


//sf::Vector2f Player::getPosition() const
//{
//	return Psprite ? Psprite->getPosition() : sf::Vector2f{};
//}