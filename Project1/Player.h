#pragma once
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Texture headleather;
	sf::Texture texture;



	
public:
	sf::Sprite sprite;
	sf::Sprite HLsprite;
	void Initilize();
	void Load();
	void Update();
	void Draw();

};

	