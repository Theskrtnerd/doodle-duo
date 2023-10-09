#include "Button.h"

#include "Button.h"

Button::Button(const std::string& textureFile, GameTextures& gameTextures, int xPos, int yPos)
{
    // Set the texture using the provided file
    this->setTextureFromFile(gameTextures, textureFile);

    // Optional: Position it at (0, 0) assuming it covers the entire window or screen.
    this->setPosition(xPos, yPos);
}

void Button::draw(sf::RenderWindow &window)
{
    // Just draw the sprite (you can add additional drawing logic here if needed)
    window.draw(this->getSprite());
}