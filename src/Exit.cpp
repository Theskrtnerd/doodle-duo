#include "include/Exit.h"
#include "include/GameEngine.h"

bool Exit::offsetCollisionChecker(GameObjectArray& objects, int xOffset, int yOffset)
{
    int initalX = getX();
    int initalY = getY();

    setPosition(initalX + xOffset, initalY + yOffset);

    bool collision = objects.isCollidingWith(*this, "player " + color);

    setPosition(initalX, initalY);

    return collision;
}

Exit::Exit(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures), color(colour)
{
    this->setTextureFromFile(gameTextures, "Exit.png");
    this->setColor(color);
}

Exit::~Exit() {}

std::string Exit::collisionType() { return "exit"; }

bool Exit::isReady(GameObjectArray& objects)
{
    if (!offsetCollisionChecker(objects, -15, 0)) return false;
    if (!offsetCollisionChecker(objects, 15, 0)) return false;
    if (!offsetCollisionChecker(objects, 0, -15)) return false;
    if (!offsetCollisionChecker(objects, 0, 15)) return false;

    return true;
}
