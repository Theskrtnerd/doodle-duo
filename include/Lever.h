#ifndef LEVER_H
#define LEVER_H

#include "ImmoveableObject.h"
#include <string>

/// @brief Lever class for controlling in-game mechanisms
class Lever : public ImmoveableObject
{
private:
    bool isOn;                  ///< Lever state (on/off)
    std::string color;          ///< color of the lever and its associated channel
    GameTextures& gameTextures; ///< pre loaded textures for lever states
    int cooldown;               ///< Cooldown time between toggles

    /// @brief Turns the lever on
    /// @param objects Reference to the GameObjectArray
    void turnOn(GameObjectArray& objects);

    /// @brief Turns the lever off
    /// @param objects Reference to the GameObjectArray
    void turnOff(GameObjectArray& objects);

    /// @brief Updates the lever texture based on its state
    void updateTexture();

public:
    /// @brief Constructs a lever instance
    /// @param x x-coordinate
    /// @param y y-coordinate
    /// @param gameTextures Reference to pre-loaded textures
    /// @param colour color of the lever and its associated channel
    Lever(int x, int y, GameTextures& gameTextures, std::string colour);

    /// @brief Destructs the lever instance
    ~Lever();

    /// @brief Interacts with the lever
    /// @param objects Reference to the GameObjectArray
    virtual void interactWith(GameObjectArray& objects) override;

    /// @brief Updates the lever state
    /// @param object Reference to the GameObjectArray
    /// @return Update status
    virtual bool update(GameObjectArray& object) override;

    /// @brief Gets the collision type
    /// @return Collision type as a string, "Lever"
    virtual std::string collisionType() override;

    /// @brief Resets the lever to its default state
    /// @param objects Reference to the GameObjectArray
    virtual void reset(GameObjectArray& objects) override;

    /// @brief Print the debug information about the given object.
    /// @param objects Reference to the array of objects.
    void debug(GameObjectArray& objects) override;
};

#endif