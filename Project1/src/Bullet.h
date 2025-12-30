#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
private:
	sf::RectangleShape rectagngleshape;
	sf::Vector2f direction;
	float Bspeed;

public:


	Bullet();
	~Bullet();
	void Initialize(const sf::Vector2f& position , const sf::Vector2f& target, float speed);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);

	inline const sf::FloatRect& GetGlobalBounds() { return rectagngleshape.getGlobalBounds(); }
};

