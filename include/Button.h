#ifndef BUTTON_H
#define BUTTON_H

#include "ImmoveableObject.h"
#include <string>

/// @brief Button class for the Player object to interact with in the game.
class Button : public ImmoveableObject
{
private:
    bool pressed; ///< Flag to check if button is pressed.
    std::string color; ///< Color of the button and its associated channel.

    /// @brief Executes actions when button should be in the pressed state.
    /// @param objects Reference to GameObjectArray.
    void press(GameObjectArray& objects);

    /// @brief Executes actions when button should be in the unpressed state.
    /// @param objects Reference to GameObjectArray.
    void depress(GameObjectArray& objects);

public:
    /// @brief Constructs a Button instance.
    /// @param x x-coordinate.
    /// @param y y-coordinate.
    /// @param gameTextures A reference to the pre-loaded textures.
    /// @param colour The color of the button and its associated channel.
    Button(int x, int y, GameTextures& gameTextures, std::string colour);

    /// @brief Destructs Button instance.
    ~Button();

    /// @brief Updates button state based on objects in GameObjectArray.
    /// @param objects Reference to GameObjectArray.
    /// @return Returns true if successful, false otherwise.
    virtual bool update(GameObjectArray& objects) override;

    /// @brief Gets the collision type of the GameObject.
    /// @return A string, typically "button".
    virtual std::string collisionType() override;
};

#endif