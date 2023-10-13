#include "Lever.h"
#include <string>
#include "GameObjectArray.h"

void Lever::turnOn(GameObjectArray& objects)
{
    if (!isOn)
    {
        objects.tellAll(color, "on");
        isOn = true;
    }
}

void Lever::turnOff(GameObjectArray& objects)
{
    if (isOn)
    {
        objects.tellAll(color, "off");
        isOn = false;
    }
}

void Lever::updateTexture()
{
    if(isOn)
    {
        this->setTextureFromFile(gameTextures, "Lever_On.png");
    } else {
        this->setTextureFromFile(gameTextures, "Lever_Off.png");
    }
}

Lever::Lever(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
isOn(false),
color(colour),
gameTextures(gameTextures),
cooldown(0)
{
    this->setTextureFromFile(gameTextures, "Lever_Off.png");
    updateTexture();
}

Lever::~Lever() {}

void Lever::interactWith(GameObjectArray& objects)
{
    if (cooldown > 0) return;
    if (isOn)
    {
        turnOff(objects);
    } else {
        turnOn(objects);
    }
    updateTexture();
    cooldown = 30;
}

bool Lever::update(GameObjectArray& object)
{
    ImmoveableObject::update(object);

    if (cooldown > 0) cooldown--;

    return false;
}

std::string Lever::collisionType()
{
    return "intractable";
}
