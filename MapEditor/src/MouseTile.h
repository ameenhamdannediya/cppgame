#pragma once
#include <SFML/Graphics.hpp>
class MouseTile
{
private:
	sf::Texture tilesheet;
	std::optional<sf::Sprite> tile;

	sf::Vector2i tileSize;
	sf::Vector2f tilescale;

public:
	MouseTile(const  sf::Vector2i& size,
			const sf::Vector2f& scale
			);
	~MouseTile();
	void Initialize();
	void Load();
	void Update(float deltatime, sf::Vector2f cursorposition);
	void Draw(sf::RenderWindow& window);

};

