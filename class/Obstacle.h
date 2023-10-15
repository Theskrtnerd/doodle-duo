#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Cell.h"

class Obstacle : public Cell
{
    private:
    std::string color;

    public:
    Obstacle(int x, int y, GameTextures& gameTextures, std::string colour);
    ~Obstacle();

    virtual std::string collisionType() override;
};

#endif