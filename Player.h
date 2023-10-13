#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "MoveableObject.h"

using string = std::string;

class Player : public MoveableObject
{
    private:
        // Might be boolean for each colour 
        string color;
    
    public:
        Player();

        Player(int x, int y, string color, GameTextures& gameTextures);   // No need to set Velocity as it will be set to 0 be default
        

        virtual bool update(GameObjectArray& objects) override;
        virtual std::string collisionType() override;

        void playerInputs(GameObjectArray& objects);

        void moveLeft();

       void moveRight();

        void jump(GameObjectArray& objects);

        void interact(GameObjectArray& objects);
    
        void friction();
        
        ~Player();
};

#endif