#ifndef DOOR_H
#define DOOR_H

#include "ImmoveableObject.h"
#include "GameTextures.h"
#include <string>

/// @brief Door class
class Door : public ImmoveableObject
{
    private:
        std::string color;  ///< Color of the door and its associated channel.
        int incoming_signals;   ///< Number of incoming signals received basically the sum of all "on"(+1) and "off"(-1) signals.
        GameTextures textures;  ///< Pre-loaded textures for the doors open and closed states.

        /// @brief Checks if the door is open.
        /// @return Open status.
        bool isOpen();

        /// @brief Updates the texture of the door based on its state.
        void updateTexture();

    public:
        /// @brief Constructs a Door instance.
        /// @param x x-coordinate.
        /// @param y y-coordinate.
        /// @param gameTextures A reference to the pre-loaded textures.
        /// @param colour The color of the door and its associated channel.
        Door(int x, int y, GameTextures& gameTextures, std::string colour);

        /// @brief Destructs a Door instance.
        ~Door();

        /// @brief Updates Door state.
        /// @param objects Reference to GameObjectArray.
        /// @return Update status.
        virtual bool update(GameObjectArray& objects) override;\

        /// @brief Gets the collision type.
        /// @return Collision type as a string, "immovable" when closed and "passable" when open.
        virtual std::string collisionType() override;

        /// @brief Listens to incoming signals.
        /// @param channel The channel on which the signal comes.
        /// @param signal The received signal.
        virtual void listen(std::string channel, std::string signal) override;
};

#endif