#ifndef EXIT_H
#define EXIT_H

#include "ImmoveableObject.h"
#include "GameObjectArray.h"
#include <string>

/// @brief  Exit class
class Exit : public ImmoveableObject
{
    private:
        std::string color; ///< Color of the exit, corresponding to the two player's colors

        /// @brief Move the exit by the offset and checks if the player is present
        /// @param objects Reference to GameObjectArray
        /// @param xOffset x offset
        /// @param yOffset y offset
        /// @return If the player is present
        bool offsetCollisionChecker(GameObjectArray& objects, int xOffset, int yOffset);

    public:
        /// @brief Constructs an Exit instance.
        /// @param x x-coordinate
        /// @param y y-coordinate
        /// @param gameTextures A reference to the pre-loaded textures.
        /// @param colour The color of the exit, corresponding to the two player's colors.
        Exit(int x, int y, GameTextures& gameTextures, std::string colour);

        /// @brief Destructs an Exit instance.
        ~Exit();

        /// @brief Gets the collision type.
        /// @return Collision type as a string, "passable"
        virtual std::string collisionType() override;

        /// @brief Checks if a player is present and ready to finish the level.
        /// @param objects Reference to the GameObjectArray.
        /// @return True if the player is ready, false otherwise.
        bool isReady(GameObjectArray& objects) override;

        /// @brief Print the debug information about the given object.
        /// @param objects Reference to the array of objects.
        void debug(GameObjectArray& objects) override;
};

#endif