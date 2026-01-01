#pragma once
#include <SFML/Graphics.hpp>

namespace GUI {

	class Button
	{
	private:
		std::optional<sf::Sprite> M_sprite;
		sf::Texture M_texture;
		const sf::Vector2f& M_position;
		const sf::Vector2f& M_scale;

		const sf::Vector2f* mousePOS;

		bool isMousePressed;
		bool isMouseReleased;

	public:
		Button(const sf::Vector2f& position, const sf::Vector2f& scale);
		~Button();
		void Initialize();
		void Load();
		void Update(float deltatime, const  sf::Vector2f& cursorposition);
		void Draw(sf::RenderWindow& window);

		bool isPressed();
	};
}


