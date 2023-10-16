#include "Exit.h"
#include "GameEngine.h"

Exit::Exit(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
color(colour)
{
    this->setTextureFromFile(gameTextures, "Exit.png");
    this->setColor(color);
}

Exit::~Exit() {}

std::string Exit::collisionType()
{
    return "exit";
}

bool Exit::isReady(GameObjectArray& objects)
{
    bool output = true;
    int initialX = getX();
    int initialY = getY();

    this->setPosition(initialX+15, initialY);
    if (!objects.isCollidingWith(*this, "player " + color)) output = false;
    this->setPosition(initialX, initialY);
    if (!output) return false;

    this->setPosition(initialX-15, initialY);
    if (!objects.isCollidingWith(*this, "player " + color)) output = false;
    this->setPosition(initialX, initialY);
    if (!output) return false;

    this->setPosition(initialX, initialY+15);
    if (!objects.isCollidingWith(*this, "player " + color)) output = false;
    this->setPosition(initialX, initialY);
    if (!output) return false;

    this->setPosition(initialX, initialY-15);
    if (!objects.isCollidingWith(*this, "player " + color)) output = false;
    this->setPosition(initialX, initialY);
    if (!output) return false;

    return true;
}
