#pragma once
#include <SFML/Graphics.hpp>





class Player
{
private:
	sf::Texture headleather;
	sf::Texture texture;



	std::optional<sf::Sprite> Psprite;
	std::optional<sf::Sprite> HLsprite;
	
public:
	Player();
	//void Initilize();
	//void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	

};

	