#include "../include/Background.h"

Background::Background(const std::string& textureFile, GameTextures& gameTextures)
: GameObject(0, 0, gameTextures)
{
    this->setTextureFromFile(gameTextures, textureFile);

    this->setPosition(0, 0);
}

void Background::draw(sf::RenderWindow &window)
{
    window.draw(this->getSprite());
}

void Background::debug(GameObjectArray& objects)
{
    std::cout << "The background exists" << std::endl;
    std::cout << "Position: " << this->getX() << ", " << this->getY() << std::endl;
    std::cout << std::endl;
}