#ifndef SCREEN_BUTTON_H
#define SCREEN_BUTTON_H

#include "GameObject.h"
#include <string>
#include <functional>

class GameEngine;

/// @brief ScreenButton class used for player interactions using the mouse.
class ScreenButton : public GameObject {
private:
    std::function<void(GameEngine&)> action;    ///< Action that will be performed when the button is pressed.

public:
    static const std::map<std::string, std::function<void(GameEngine&)>> actionMap;     ///< Mapping of action names to actions.

    /// @brief Constructs a ScreenButton instance.
    /// @param texture_file Path to texture file.
    /// @param gameTextures Reference to pre-loaded textures.
    /// @param xPos x-coordinate
    /// @param yPos y-coordinate
    ScreenButton(const std::string& texture_file, GameTextures& gameTextures, int xPos, int yPos);

    /// @brief Draws the button to the screen.
    /// @param window Reference to the SFML window.
    virtual void draw(sf::RenderWindow &window) override;

    /// @brief Handles button click events.
    /// @param xPos x-coordinate of the mouse click.
    /// @param yPos y-coordinate of the mouse click.
    /// @param engine Reference to the game engine.
    virtual void click(int xPos, int yPos, GameEngine& engine) override;

    /// @brief Executes the action associated with the button.
    /// @param engine Reference to the game engine.
    void doAction(GameEngine& engine);

    /// @brief Sets the action of the button.
    /// @param actionName The name of the action to set.
    void setAction(const std::string& actionName);

    /// @brief Makes an action from a given name
    /// @param actionName The name of the action
    /// @return The corresponding action
    std::function<void(GameEngine&)> makeAction(const std::string& actionName);

    /// @brief Checks if a point in within range of the button
    /// @param xPos x-coordinate of the mouse click.
    /// @param yPos y-coordinate of the mouse click.
    /// @return True if within range, false otherwise.
    bool withinRange(int xPos, int yPos);
};


#endif