#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{

private:
	sf::Texture Etexture;

	sf::RectangleShape boundingrect;
	sf::Vector2i Esize;

	sf::Font font;
	std::optional<sf::Text> healthtext;

public:
	int health;
	Enemy();
	void changeHealth(int hp);

	std::optional<sf::Sprite> Esprite;
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	//sf::Vector2f getPosition() const;




};







