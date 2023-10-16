#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "MoveableObject.h"

using string = std::string;

/// @brief Player class, there should be multiple instances of this class.
class Player : public MoveableObject
{
private:
    int xStart; ///< starting x position
    int yStart; ///< starting y position

public:
    /// @brief Constructor
    /// @param x x-coordinate
    /// @param y y-coordinate
    /// @param color color of the player
    /// @param gameTextures reference to pre-loaded game textures
    Player(int x, int y, string color, GameTextures& gameTextures);

    /// @brief Updates player state and checks for user input
    /// @param objects Reference to GameObjectArray
    /// @return update status
    virtual bool update(GameObjectArray& objects) override;

    /// @brief Gets the collision type of the player
    /// @return Collision type as a string "{color} player"
    virtual std::string collisionType() override;

    /// @brief Moves the player back to its starting position
    /// @param objects Reference to GameObjectArray
    virtual void reset(GameObjectArray& objects) override;

    /// @brief Checking for player inputs
    /// @param objects Reference to GameObjectArray
    void playerInputs(GameObjectArray& objects);

    /// @brief Moves the player left
    void moveLeft();

    /// @brief Moves the player right
    void moveRight();

    /// @brief Makes the player jump
    /// @param objects Reference to GameObjectArray
    void jump(GameObjectArray& objects);

    /// @brief Makes the player interact the the first intractable object it is colliding with
    /// @param objects REference to GameObjectArray
    void interact(GameObjectArray& objects);

    /// @brief Applies friction to the player
    void friction();

    /// @brief Destructs the player
    ~Player();
};

#endif