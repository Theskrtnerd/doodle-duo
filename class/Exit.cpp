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

    this->setPosition(getX()+15, getY());
    output &= objects.isCollidingWith(*this, "player "+color);
    this->setPosition(initialX, initialY);

    this->setPosition(getX()-15, getY());
    output &= objects.isCollidingWith(*this, "player "+color);
    this->setPosition(initialX, initialY);

    this->setPosition(getX(), getY()+15);
    output &= objects.isCollidingWith(*this, "player "+color);
    this->setPosition(initialX, initialY);

    this->setPosition(getX(), getY()-15);
    output &= objects.isCollidingWith(*this, "player "+color);
    this->setPosition(initialX, initialY);

    return output;
}
