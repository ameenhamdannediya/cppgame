#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{
private:
	sf::Texture tilesheet;
	std::optional<sf::Sprite> tile;

	sf::Vector2f M_tilePosition;
	sf::Vector2i M_tileGridPosition;
	int Tnum;

	sf::Vector2i tileSize;
	sf::Vector2f tilescale;
	sf::Vector2f tileOffset;

	bool isMouseOnGrid;
public:

	MouseTile(const  sf::Vector2i& size,
			const sf::Vector2i& scale, const sf::Vector2f& offset
			);
	~MouseTile();


	void Initialize();
	void Load();
	void Update(float deltatime, const  sf::Vector2f& cursorposition);
	void Draw(sf::RenderWindow& window);

	///<summary> return if the mouse is clicked on a tileor not and position vector </summary>
	///<param name ="tileposition">out data, returens the position of the tile thats clicked on </param>
	///<returns>bool</returns>
	bool isMOuseClickOnTile( sf::Vector2f& tilePosition, sf::Vector2i& gridPosition,  const  sf::Vector2f& cursorposition) const;

	inline const std::optional<sf::Sprite>&  GetTileSprite() const { return tile; }

};

