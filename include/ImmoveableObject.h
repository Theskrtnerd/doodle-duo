#ifndef IMMOVEABLE_OBJECT_H
#define IMMOVEABLE_OBJECT_H

#include "GameObject.h"

/// @brief ImmovableObject represents an object that cannot be moved.
class ImmoveableObject: public GameObject{
public:
    /// @brief Constructs an ImmoveableObject. as a specific position.
    /// @param x_ The x-coordinate.
    /// @param y_ The y-coordinate.
    /// @param gameTextures A reference to the pre-loaded textures.
    ImmoveableObject(int x_, int y_, GameTextures& gameTextures);

    /// @brief Draws the object on the given window.
    /// @param window The window where the object will be drawn.
    virtual void draw(sf::RenderWindow& window) override;

    /// @brief Gets the collision type.
    /// @return A string describing the collision type, typically "immoveable".
    virtual std::string collisionType() override;
};

#endif