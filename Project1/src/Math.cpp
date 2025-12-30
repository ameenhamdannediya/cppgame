#include "Math.h"


sf::Vector2f Math::normalize(sf::Vector2f vector) {
	float magnitude = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	sf::Vector2f normalised;
	normalised.x = vector.x / magnitude;
	normalised.y = vector.y / magnitude;

	return normalised;
}

bool Math::IsCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	
	if (rect1.position.x + rect1.size.x > rect2.position.x &&
		rect2.position.x + rect2.size.x > rect1.position.x &&
		rect1.position.y + rect1.size.y > rect2.position.y &&
		rect2.position.y + rect2.size.y > rect1.position.y
		) {
		return true;
	}


	return false;
}
