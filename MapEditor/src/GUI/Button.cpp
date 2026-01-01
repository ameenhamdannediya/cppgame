#include "Button.h"
#include <iostream>
namespace GUI
{
    Button::Button(const sf::Vector2f& position, const sf::Vector2f& scale)
        : M_position(position), M_scale(scale), mousePOS(nullptr) ,
        isMousePressed(false), isMouseReleased(false)
    {

    }
    Button::~Button() {}

    void Button::Initialize()
    {
        M_texture.loadFromFile("assets/GUI/button.png");

        M_sprite.emplace(M_texture);
        M_sprite->setPosition(M_position);
        M_sprite->setScale(M_scale);


    }
    void Button::Load() {}
    void Button::Update(float deltatime, const  sf::Vector2f& cursorposition)
    {
        mousePOS = &cursorposition;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&& !isMouseReleased) {
            isMousePressed = true;
        }
        else {
            if (isMousePressed) {
                isMouseReleased = true;
            };

            isMousePressed = false;
        }


    }

    bool Button::isPressed() {

        if (isMouseReleased) {
            isMouseReleased = false;

            const sf::Vector2u& size = M_sprite->getTexture().getSize();

            sf::Vector2f endPOs = sf::Vector2f(
                M_position.x + size.x * M_scale.x,
                M_position.y + size.y * M_scale.y);

            if (mousePOS->x >= M_position.x && mousePOS->x <= endPOs.x &&
                mousePOS->y >= M_position.y && mousePOS->y <= endPOs.y)
            {
                return true;
            };
            return false;

        }

    }
    void Button::Draw(sf::RenderWindow& window)
    {
        window.draw(*M_sprite);
    }
}
