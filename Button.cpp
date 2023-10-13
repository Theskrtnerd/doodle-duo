#include "Button.h"
#include <string>
#include "GameObjectArray.h"


void Button::press(GameObjectArray& objects)
{
    if (!pressed)
    {
        objects.tellAll(color, "on");
        pressed = true;
    }
}

void Button::depress(GameObjectArray& objects)
{
    if (pressed)
    {
        objects.tellAll(color, "off");
        pressed = false;
    }
}

Button::Button(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
color(colour),
pressed(false)
{
    this->setTextureFromFile(gameTextures, "Button.png");
}

Button::~Button() {}

bool Button::update(GameObjectArray& objects) {
    ImmoveableObject::update(objects);

    if (objects.isCollidingWith(*this, "player"))
    {
        press(objects);
    } else {
        depress(objects);
    }
    return false;
}

std::string Button::collisionType()
{
    return "Button";
}
