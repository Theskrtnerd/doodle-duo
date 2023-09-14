#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "MoveableObject.h"

using string = std::string;

class MoveableObject : public MoveableObject
{
    private:
        string colour
    
    public:
        MoveableObject();

        MoveableObject(int x, int y);   // No need to set Velocity as it will be set to 0 be default
        

        /**
         * @brief Updates the position and game state
         * @return Returns true if the update was successful otherwise false
        */
        virtual bool update() override;


        /// @brief Used to stop all movement
        void stopMovement();
        

        /**
         * @brief Sets the velocity of the object on the x axis
         * @param speed The velocity to be set
        */
        void setVelocityX(double speed);

        /**
         * @brief Gets the velocity of the object on the x axis
         * @return The velocity on the x axis
        */
        double getVelocityX();


        /**
         * @brief Sets the velocity of the object on the y axis
         * @param speed The velocity to be set
        */
        void setVelocityY(double speed);

        /**
         * @brief Gets the velocity of the object on the y axis
         * @return The velocity on the y axis
        */
        double getVelocityY();


        ~MoveableObject();
};

#endif