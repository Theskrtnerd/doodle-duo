#include "MoveableObject.h"
#include "GameObjectArray.h"

MoveableObject::MoveableObject():
    GameObject(),
    velocityX(0),
    velocityY(0)
    {}

MoveableObject::MoveableObject(int x, int y, GameTextures& gameTextures):
    GameObject(x, y, gameTextures),
    velocityX(0),
    velocityY(0)
    {}

bool MoveableObject::update(GameObjectArray& objects)
    {
        // Do parent update
        if (!GameObject::update(objects))
        {
            return false;
        }

        // Get current location
        int currentX = getX();
        int currentY = getY();

        // Update based on velocity
        int newX = currentX + velocityX;
        int newY = currentY + velocityY;

        setPosition(newX, newY);
        GameObject* collidingObject = objects.findColliding(*this);
        if (collidingObject != nullptr)
        {
            std::cout << "Collision detected with another object!" << std::endl;
        }

        return true;
    }

void MoveableObject::draw(sf::RenderWindow& window)
    {
        window.draw(this->getSprite());
    }

void MoveableObject::stopMovement() {
        velocityY = 0;
        velocityX = 0;
    }

void MoveableObject::setVelocityX(double speed)
    {
        velocityX = speed;
    }

double MoveableObject::getVelocityX()
    {
        return velocityX;
    }

void MoveableObject::setVelocityY(double speed)
    {
        velocityY = speed;
    }

double MoveableObject::getVelocityY()
    {
        return velocityY;
    }

MoveableObject::~MoveableObject() {}
