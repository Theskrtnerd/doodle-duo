#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObjectArray.h"
#include "functions.h"

/// @brief GameEngine class that runs the game loop and manages game state.
class GameEngine
{
private:
    GameObjectArray* gameObjects;   ///< Array of GameObjects that are a part of the game.
    GameObjectArray* screen;        ///< Array of GameObjects that are a part of the menu.
    std::string screen_display;     ///< The type of menu that should be displayed when open.
    bool screen_open;               ///< Whether or not the menu is open.
    bool screen_moved;              ///< Whether or not the menu has be changed to a new state.
    int max_level;                  ///< The maximum level that the player has reached so far.
    int current_level;              ///< The current level that the player is on.
    sf::RenderWindow window;        ///< The window that the game is running on.
    bool level_changed;             ///< Whether or not the player has changed levels.

public:
    /// @brief Constructs a GameEngine instance.
    /// @param width Window width.
    /// @param height Window height.
    /// @param title Window title.
    GameEngine(int width, int height, const std::string &title);

    /// @brief Runs the game loop.
    void run();

    /// @brief Destructs a GameEngine instance.
    ~GameEngine();

    /// @brief Closes the menu.
    void closeScreen();

    /// @brief Opens the menu.
    void openScreen();

    /// @brief  Changes the screen to a new state.
    /// @param screen_display The Json to load the new state from.
    void moveScreen(const std::string& screen_display_);

    /// @brief Set the game to the target level.
    /// @param target_level Target level to set.
    void setLevel(int target_level);

    /// @brief Sets the maximum level of the game.
    void setMaxLevel();

    /// @brief Resets the current level.
    void resetLevel();

    /// @brief Loads the next game level.
    void loadNextLevel();

    void updateUserCurrentLevel();
};

#endif