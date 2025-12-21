#include "Math.h"


sf::Vector2f Math::normalize(sf::Vector2f vector) {
	float magnitude = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	sf::Vector2f normalised;
	normalised.x = vector.x / magnitude;
	normalised.y = vector.y / magnitude;

	return normalised;
}