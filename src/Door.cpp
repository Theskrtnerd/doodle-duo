#include "../include/Door.h"

bool Door::isOpen() { return incoming_signals > 0; }

void Door::updateTexture()
{
    std::string textureFile = isOpen() ? "Door_Open.png" : "Door_Closed.png";
    
    this->setTextureFromFile(textures, textureFile);

    this->setColor(color);
}

Door::Door(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
color(colour),
incoming_signals(0),
textures(gameTextures)
{
    this->updateTexture();

    this->setColor(color);
}


Door::~Door() {}

bool Door::update(GameObjectArray& objects) { return false; }

std::string Door::collisionType() { return isOpen() ? "open" : "immoveable"; }

void Door::listen(std::string channel, std::string signal)
{
    bool current = isOpen();
    if (channel == color)
    {
        if (signal == "on") incoming_signals++;
        if (signal == "off") incoming_signals--;
    }
    if (current != isOpen())
    {
        updateTexture();
    }
}