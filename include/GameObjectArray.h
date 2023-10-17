#ifndef GAME_OBJECT_ARRAY_H
#define GAME_OBJECT_ARRAY_H

#include "GameObject.h"
#include "functions.h"
#include "Background.h"
#include "Cell.h"
#include <string>
#include "GameTextures.h"
#include "ScreenButton.h"
#include "Button.h"
#include "Door.h"
#include "Lever.h"
#include "Exit.h"
#include "Text.h"
#include "Obstacle.h"

class GameEngine;

class GameObjectArray
{
    private:
        GameEngine* gameEnginePtr;                  ///< Pointer to the GameEngine
        static constexpr int max_objects = 800;    ///< Max number of objects in the array. Immutable.
        GameObject* objects[max_objects];           ///< Array of GameObject
        GameTextures gameTextures;                  ///< Pre-loaded game textures
    
    public:
        /// @brief Constructor
        /// @param engine Pointer to the GameEngine
        GameObjectArray(GameEngine* engine);

        /// @brief Destructor
        ~GameObjectArray();

        /// @brief Clears all objects in the array
        void clearObjects();

        /// @brief Populates the array from a JSON file
        /// @param json_path Path to JSON file
        void populateFromJson(std::string& json_path);

        /// @brief Gets GameEngine pointer
        /// @return Pointer to the GameEngine
        GameEngine* getGameEngine();

        /// @brief Updates all game objects
        void updateAll();

        /// @brief Draws all game objects.
        /// @param window Reference to the render window.
        void drawAll(sf::RenderWindow &window);

        /// @brief Handles clicks for all objects
        /// @param xPos x-coordinate of the click
        /// @param yPos y-coordinate of the click
        /// @param engine Reference to the GameEngine
        void clickAll(int xPos, int yPos, GameEngine& engine);
        
        /// @brief Broadcasts a signal to all objects
        /// @param channel Channel to send signal
        /// @param signal Signal to send
        void tellAll(std::string channel, std::string signal);

        /// @brief Resets all objects to their initial state
        void resetAll();

        /// @brief Prints debug information for all objects
        void debugAll();

        /// @brief Finds colliding object.
        /// @param object Object to test collision
        /// @return Pointer to colliding object. Null if no collision.
        GameObject* findColliding(GameObject& object);

        /// @brief Checks for specific collision.
        /// @param object Object to test collision
        /// @param collision_type Type of collision to test for
        /// @return Collision status
        bool isCollidingWith(GameObject& object, std::string collision_type);

        /// @brief Checks for specific collision.
        /// @param object Object to test collision
        /// @param collision_type Type of collision to test for
        /// @return Pointer to colliding object. Null if no collision.
        GameObject* getCollidingWith(GameObject& object, std::string collision_type);

        /// @brief Checks if object is grounded.
        /// @param object Object to test
        /// @return Grounded status
        bool isGrounded(GameObject& object);

        /// @brief Checks if the level is completed
        /// @return Level completion status
        bool levelCompleted();
};

/// @brief Creates a GameObject from JSON data
/// @param root JSON data for all objects
/// @param index Index of the object in the array and of the JSON file
/// @param gameTextures Pre-loaded game textures
/// @return Pointer to created GameObject
GameObject* createObjectFromJson(Json::Value root, int index, GameTextures& gameTextures);

#endif