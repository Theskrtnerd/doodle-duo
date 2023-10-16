#ifndef MOVEABLE_OBJECT_H
#define MOVEABLE_OBJECT_H

#include "GameObject.h"

/// @brief MoveableObject class for objects that can be moved.
class MoveableObject : public GameObject
{
private:
    double velocityX;   ///< x-axis velocity in pixels per tick
    double velocityY;   ///< y-axis velocity in pixels per tick
    std::string color;  ///< color of the object
    
    void updateMovement(GameObjectArray& objects);
    bool moveX(GameObjectArray& objects, int distance);
    bool moveY(GameObjectArray& objects, int distance);
    bool moveXbyOne(GameObjectArray& objects);
    bool moveYbyOne(GameObjectArray& objects);
    
    void moveDiagonally(GameObjectArray& objects, int x, int y);
    void moveByRise(GameObjectArray& objects, int x, int y);
    void moveByRun(GameObjectArray& objects, int x, int y);

    bool isStationary();
    bool isMovingHorizontally();
    bool isMovingVertically();

    /// @brief Calculates the rise of the velocity
    /// @return Number of pixels of rise per 1 run
    int calcRise();

    /// @brief Calculates the run of the velocity
    /// @return Number of pixels of run per 1 rise
    int calcRun();






public:
    /// @brief Constructor for MoveableObject class
    /// @param x x-coordinate
    /// @param y y-coordinate
    /// @param gameTextures Reference to pre-loaded textures.
    MoveableObject(int x, int y, GameTextures& gameTextures);

    ~MoveableObject();
    
    /// @brief Updates object state
    /// @param objects Reference to GameObjectArray
    /// @return Update status
    virtual bool update(GameObjectArray& objects) override;

    /// @brief Draws the object on the given window.
    /// @param window The window where the object will be drawn.
    void draw(sf::RenderWindow& window) override;


    /// @brief Stops all movement.
    void stopMovement();

    /// @brief Stops horizontal movement.
    void stopHorizontalMovement();

    /// @brief Stops vertical movement.
    void stopVerticalMovement();
    
    /// @brief Sets the velocity of the object on the x-axis.
    /// @param speed velocity in pixels per tick
    void setVelocityX(double speed);

    /// @brief Gets the velocity of the object on the x-axis.
    /// @return velocity in pixels per tick
    double getVelocityX();

    /// @brief Sets the velocity of the object on the y-axis.
    /// @param speed velocity in pixels per tick
    void setVelocityY(double speed);

    /// @brief gets the velocity of the object on the y-axis.
    /// @return velocity in pixels per tick
    double getVelocityY();
    
    /// @brief Sets the color of the object.
    /// @param color new color of the object
    void setColorString(std::string color);

    /// @brief Gets the color of the object.
    /// @return color of the object
    std::string getColorString();

    /// @brief Applies a force to the object on the x-axis when not grounded.
    /// @param objects Reference to GameObjectArray
    void gravity(GameObjectArray& objects);
};

#endif