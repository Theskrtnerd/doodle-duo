#include "Background.h"

#include "Background.h"

Background::Background(const std::string& textureFile)
{
    // Set the texture using the provided file
    this->setTextureFromFile(textureFile);

    // Optional: Position it at (0, 0) assuming it covers the entire window or screen.
    this->setPosition(0, 0);
}

void Background::draw(sf::RenderWindow &window)
{
    // Just draw the sprite (you can add additional drawing logic here if needed)
    window.draw(this->getSprite());
}