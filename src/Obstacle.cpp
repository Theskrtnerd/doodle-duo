#include "../include/Obstacle.h"
#include <iostream>

Obstacle::Obstacle(int x, int y, GameTextures& gameTextures, std::string colour)
: Cell(x, y, gameTextures), color(colour)
{
    this->setTextureFromFile(gameTextures, "Obstacle.png");
    this->setColor(color);
}

Obstacle::~Obstacle() {}

std::string Obstacle::collisionType() { return "obstacle " + this->color; }