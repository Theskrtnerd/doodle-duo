#include "MoveableObject.h"

MoveableObject::MoveableObject()
    : GameObject(), velocityX(0), velocityY(0)
    {}

MoveableObject::MoveableObject(int x, int y)
    : GameObject(x, y), velocityX(0), velocityY(0)
    {}

bool MoveableObject::update()
    {
        int currentX = getX();
        int currentY = getY();

        // Update based on velocity
        int newX = currentX + velocityX;
        int newY = currentY + velocityY;

        setPosition(newX, newY);
    }


void MoveableObject::stopMovement()
    {
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
