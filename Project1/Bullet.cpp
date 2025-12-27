#include "Bullet.h"
#include "Math.h"

Bullet::Bullet() : Bspeed(0) //initialing
{
	
}

Bullet::~Bullet()
{

}

void Bullet::Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed)
{
	Bspeed = speed; 
	rectagngleshape.setSize(sf::Vector2f(25, 10));
	rectagngleshape.setPosition(position);
	direction = Math::normalize(target - position);
}

void Bullet::Update(float deltatime)
{
	rectagngleshape.setPosition(rectagngleshape.getPosition() + direction * Bspeed * deltatime);

}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectagngleshape);
}
