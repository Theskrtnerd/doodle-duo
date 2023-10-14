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
    return objects.isCollidingWith(*this, "player "+color);
}
