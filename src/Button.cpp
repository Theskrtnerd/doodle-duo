#include "../include/Button.h"
#include <string>
#include "../include/GameObjectArray.h"

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
    this->setColor(color);
}

Button::~Button() {}

bool Button::update(GameObjectArray& objects) {
    ImmoveableObject::update(objects);

    // Check if button is being pressed by either player
    bool buttonPressed = (objects.isCollidingWith(*this, "player red") || objects.isCollidingWith(*this, "player blue"));

    // Update button state button state based on whether it's being pressed
    buttonPressed ? press(objects) : depress(objects);

    return false;
}

std::string Button::collisionType() { return "button"; }

void Button::debug(GameObjectArray& objects)
{
    std::cout << "A button exists" << std::endl;
    std::cout << "Position: " << this->getX() << ", " << this->getY() << std::endl;
    std::cout << "Channel: " << color << std::endl;
    std::cout << "Signal type: 'on', 'off'" << std::endl;
    std::cout << "is pressed: " << pressed << std::endl;
    std::cout << "Collision type: " << collisionType() << std::endl;
    std::cout << std::endl;
}
