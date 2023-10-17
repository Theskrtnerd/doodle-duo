#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

#include "GameTextures.h"
#include "functions.h"

class GameObjectArray;
class GameEngine;

/// @brief GameObject serves as an abstract base class for all game objects.
class GameObject
{
private:
    int x;  ///< The x-coordinate of the GameObject.
    int y;  ///< The y-coordinate of the GameObject.
    sf::Sprite sprite;  ///< The sprite for rendering.
    sf::Texture texture;    ///< The texture of the sprite.

public:
    /// @brief Constructs a GameObject instance, abstract class.
    /// @param x_ x-coordinate.
    /// @param y_ y-coordinate.
    /// @param gameTextures A reference to the pre-loaded textures.
    GameObject(int x_, int y_, GameTextures& gameTextures);

    /// @brief Changes texture.
    /// @param gameTextures A reference to the pre-loaded textures.
    /// @param file_name Texture file name.
    void setTextureFromFile(GameTextures& gameTextures, const std::string& file_name);

    /// @brief Sets position.
    /// @param x x-coordinate.
    /// @param y y-coordinate.
    void setPosition(int x, int y);

    /// @brief Gets x-coordinate.
    /// @return x-coordinate.
    int getX();

    /// @brief Gets y-coordinate.
    /// @return y-coordinate.
    int getY();

    /// @brief Updates GameObject state. Abstract class; does nothing.
    /// @param objects Reference to GameObjectArray.
    /// @return Update status.
    virtual bool update(GameObjectArray& objects);

    /// @brief Draws GameObject. Abstract class; does nothing.
    /// @param window Reference to window.
    virtual void draw(sf::RenderWindow &window);

    /// @brief Handles click events on the GameObject. Abstract class; does nothing.
    /// @param xPos The x-coordinate of the click event.
    /// @param yPos The y-coordinate of the click event.
    /// @param engine Reference to the game engine that may be affected by the click event.
    virtual void click(int xPos, int yPos, GameEngine& engine);

    /// @brief Gets the collision type of the GameObject.
    /// @return A string describing the collision type. By default, returns "passable".
    virtual std::string collisionType();

    /// @brief Listens for signals on a given channel. Abstract class; does nothing.
    /// @param channel The Channel on which to the signal is coming along. (Typically these are colours.)
    /// @param signal The signal that has been sent on the channel.
    virtual void listen(std::string channel, std::string signal);

    /// @brief Used when Player is interacting with the GameObject. Abstract class; does nothing.
    /// @param objects Reference to GameObjectArray.
    virtual void interactWith(GameObjectArray& objects);

    /// @brief Checks if the GameObject is ready to finish the level. Abstract class; returns true.
    /// @param objects Reference to GameObjectArray.
    /// @return Returns true if the GameObject is ready to finish the level, false otherwise.
    virtual bool isReady(GameObjectArray& objects);

    /// @brief Resets objects to their initial state. Abstract class; does nothing.
    /// @param objects Reference to GameObjectArray.
    virtual void reset(GameObjectArray& objects);

    /// @brief prints debug information. Abstract class; does nothing.
    virtual void debug(GameObjectArray& objects);

    /// @brief Sets Color.
    /// @param color Desired color.
    void setColor(const std::string& color);

    /// @brief Gets Sprite
    /// @return Sprite Object
    sf::Sprite getSprite();

    /// @brief Gets Texture
    /// @return Texture Object
    sf::Texture getTexture();

    /// @brief Checks overlap with another GameObject.
    /// @param otherObject Other GameObject to check overlap with.
    /// @return Overlap status.
    bool isOverlapping(GameObject* otherObject);

    /// @brief Destructs GameObject.
    ~GameObject();
};

#endif