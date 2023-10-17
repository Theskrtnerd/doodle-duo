#include <iostream>
#include "../include/ImmoveableObject.h"

ImmoveableObject::ImmoveableObject(int x_, int y_, GameTextures& gameTextures): GameObject(x_, y_, gameTextures){};

void ImmoveableObject::draw(sf::RenderWindow& window) { window.draw(this->getSprite()); }

std::string ImmoveableObject::collisionType() { return "immoveable"; }