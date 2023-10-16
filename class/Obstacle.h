#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Cell.h"

/// @brief Obstacle class
class Obstacle : public Cell
{
private:
    std::string color;  ///< Color of the obstacle, "red" killing the "blue player", and "blue" killing the "red player"

public:
    /// @brief Constructs an obstacle instance
    /// @param x x-coordinate
    /// @param y y-coordinate
    /// @param gameTextures Reference to pre-loaded game textures
    /// @param colour The colour of the obstacle
    Obstacle(int x, int y, GameTextures& gameTextures, std::string colour);

    /// @brief Destructor
    ~Obstacle();

    /// @brief Gets the collision type of the obstacle
    /// @return Collision type as a string, "obstacle {color}".
    virtual std::string collisionType() override;
};

#endif