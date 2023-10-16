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
    std::string textureFile = isOn ? "lever_on.png" : "lever_off.png";
    this->setTextureFromFile(gameTextures, textureFile);

    this->setColor(color);
}

Lever::Lever(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
isOn(false),
color(colour),
gameTextures(gameTextures),
cooldown(0)
{
    updateTexture();
}

Lever::~Lever() {}

void Lever::interactWith(GameObjectArray& objects)
{
    if (cooldown > 0) return;
    
    isOn ? turnOff(objects) : turnOn(objects);

    updateTexture();

    cooldown = 30;
}

bool Lever::update(GameObjectArray& object)
{
    ImmoveableObject::update(object);

    if (cooldown > 0) cooldown--;

    return false;
}

std::string Lever::collisionType() { return "intractable"; }

void Lever::reset(GameObjectArray& objects) { turnOff(objects); }
