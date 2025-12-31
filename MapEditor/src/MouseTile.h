#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{
private:
	sf::Texture tilesheet;
	std::optional<sf::Sprite> tile;

	sf::Vector2i tileSize;
	sf::Vector2f tilescale;
	sf::Vector2f tileOffset;

public:
	MouseTile(const  sf::Vector2i& size,
			const sf::Vector2i& scale, const sf::Vector2f& offset
			);
	~MouseTile();
	void Initialize();
	void Load();
	void Update(float deltatime, sf::Vector2f cursorposition, void (*onGridClick)(int) );
	void Draw(sf::RenderWindow& window);

};

