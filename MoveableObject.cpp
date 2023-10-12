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
        if (!objects.isGrounded(*this)) gravity();

        int newX = currentX + velocityX;
        int newY = currentY + velocityY;

        setPosition(newX, newY);



        GameObject* collidingObject = objects.findColliding(*this);
        if (collidingObject != nullptr)
        {
            std::string response = collidingObject->collisionType();

            if (response == "immoveable") {
                setPosition(currentX, currentY);
                stopMovement();
            }
            //address collision
            collidingObject = objects.findColliding(*this);
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

void MoveableObject::gravity()
{
    setVelocityY(getVelocityY()+1);
    std::cout << "Speed : " << getVelocityY() << std::endl;
}

MoveableObject::~MoveableObject() {}
