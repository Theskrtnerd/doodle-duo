#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "MoveableObject.h"

using string = std::string;

class Player : public MoveableObject
{
    private:
        // Might be boolean for each colour 
        string colour;
    
    public:
        Player();

        Player(int x, int y, string colour);   // No need to set Velocity as it will be set to 0 be default
        

        /**
         * @brief Updates the position and game state
         * @return Returns true if the update was successful otherwise false
        */
        virtual bool update() override;

        /**
         * @brief When keyboard inputs to move left
        */
        void moveLeft();

        /**
         * @brief When keyboard input to move right
        */
       void moveRight();

        /**
        * @brief When keyboard input to jump
        */
        void jump();

        /**
         * @brief When keyboard input to interact
         */
        void interact();
    
        ~Player();
};

#endif