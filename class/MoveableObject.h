#ifndef MOVEABLE_OBJECT_H
#define MOVEABLE_OBJECT_H

#include "GameObject.h"

class MoveableObject : public GameObject
{
    private:
        // Velocity is in Pixels per tick
        // Objects always stationary at game start
        /// @brief x Velocity
        double velocityX;
        /// @brief y Velocity
        double velocityY;
        std::string color;
        
        void updateMovement(GameObjectArray& objects);
        bool moveX(GameObjectArray& objects, int distance);
        bool moveY(GameObjectArray& objects, int distance);
        bool moveXbyOne(GameObjectArray& objects);
        bool moveYbyOne(GameObjectArray& objects);
        

        bool isStationary();
        bool isMovingHorizontally();
        bool isMovingVertically();
        int calcRise();
        int calcRun();


        void moveDiagonally(GameObjectArray& objects, int x, int y);
        void moveByRise(GameObjectArray& objects, int x, int y);
        void moveByRun(GameObjectArray& objects, int x, int y);


    
    public:
        MoveableObject();

        MoveableObject(int x, int y, GameTextures& gameTextures);   // No need to set Velocity as it will be set to 0 be default
        

        /**
         * @brief Updates the position and game state
         * @param objects The GameObjectArray that stores all the GameObjects so that collision can be checked
         * @return Returns true if the update was successful otherwise false
        */
        virtual bool update(GameObjectArray& objects) override;



        void draw(sf::RenderWindow& window) override;


        void stopMovement();
        void stopHorizontalMovement();
        void stopVerticalMovement();
        
        void setVelocityX(double speed);
        double getVelocityX();

        void setVelocityY(double speed);
        double getVelocityY();
        
        void setColorString(std::string color);
        std::string getColorString();

        void gravity(GameObjectArray& objects);


        ~MoveableObject();
};

#endif