#include "Exit.h"
#include "GameEngine.h"

void Exit::readyUp(GameObjectArray& objects)
{
    if (!ready)
    {
        objects.tellAll(color, "ready");
        ready = true;
    }
}

void Exit::unreadyUp(GameObjectArray& objects)
{
    if (ready)
    {
        objects.tellAll(color, "unready");
        ready = false;
    }
}

Exit::Exit(int x, int y, GameTextures& gameTextures, std::string colour)
: ImmoveableObject(x, y, gameTextures),
color(colour),
ready(false),
exited(false)
{
    this->setTextureFromFile(gameTextures, "Exit.png");
    this->setColor(color);
}

Exit::~Exit() {}

bool Exit::update(GameObjectArray& objects)
{
    ImmoveableObject::update(objects);

    if (objects.isCollidingWith(*this, "player "+color))
    {
        if (incoming_signals == 0)
        {
            readyUp(objects);
        } else if (!exited){
            exited = true;
            objects.getGameEngine()->nextLevel();
        }
    } else {
        unreadyUp(objects);
    }
    return false;
}

std::string Exit::collisionType()
{
    return "exit";
}

void Exit::listen(std::string channel, std::string signal)
{
    if (channel != color)
    {
        if (signal == "ready") incoming_signals++;
        if (signal == "unready") incoming_signals--;
    }
}