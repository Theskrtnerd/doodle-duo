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
        GameObject::update(objects);

        gravity(objects);

        updateMovement(objects);

/*//
        GameObject* collidingObject = objects.findColliding(*this);
        if (collidingObject != nullptr)
        {
            std::string response = collidingObject->collisionType();

            if (response == "immoveable") {
                int dx = getX() - collidingObject->getX();
                int dy = getY() - collidingObject->getY();
                
                if (std::abs(dx) > std::abs(dy)) {
                    setPosition(currentX, currentY);
                    stopMovement();
                } else {
                    setPosition(currentX, currentY);
                    stopMovement();
                }

            }
            //address collision
            collidingObject = objects.findColliding(*this);
        }*/

        return true;
    }

void MoveableObject::draw(sf::RenderWindow& window)
{
    window.draw(this->getSprite());
}

void MoveableObject::stopMovement()
{
    stopHorizontalMovement();
    stopVerticalMovement();
}

void MoveableObject::stopHorizontalMovement()
{
    velocityX = 0;
}

void MoveableObject::stopVerticalMovement()
{
    velocityY = 0;
}

void MoveableObject::setVelocityX(double speed)
{ velocityX = speed; }

double MoveableObject::getVelocityX()
{ return velocityX; }

void MoveableObject::setVelocityY(double speed)
{ velocityY = speed; }

double MoveableObject::getVelocityY()
{ return velocityY; }

void MoveableObject::gravity(GameObjectArray& objects) {
    if (!objects.isGrounded(*this)) setVelocityY(getVelocityY() + 1);
}

MoveableObject::~MoveableObject() {}

// Private Methods
void MoveableObject::updateMovement(GameObjectArray& objects)
{
    if (isStationary()) return;

    int remainingX = static_cast<int>(abs(velocityX));
    int remainingY = static_cast<int>(abs(velocityY));

    if (remainingX == remainingY)
    {
        moveDiagonally(objects, remainingX, remainingY);
        return;
    }

    if (calcRise()) // calcRise returns int >= 0
    {
        moveByRise(objects, remainingX, remainingY);
        return;
    }
    else
    {
        moveByRun(objects, remainingX, remainingY);
        return;
    }
}

bool MoveableObject::moveX(GameObjectArray& objects, int distance)
{
    // stop if distance is zero
    if (distance == 0) return false;

    // attempt to move by one unit
    bool collisionOccurred = moveXbyOne(objects);

    // If a collision occurred, stop further movement
    if (collisionOccurred) return true;

    // otherwise, move further by (distance - 1)
    return moveX(objects, distance - 1);
}

bool MoveableObject::moveY(GameObjectArray& objects, int distance)
{
    // stop if distance is zero
    if (distance == 0) return false;

    // attempt to move by one unit
    bool collisionOccurred = moveYbyOne(objects);

    // If a collision occurred, stop further movement
    if (collisionOccurred) return true;

    // otherwise, move further by (distance - 1)
    return moveY(objects, distance - 1);
}

bool MoveableObject::moveXbyOne(GameObjectArray& objects)
{
    // Get current x and y coordinates
    int currentX = getX();
    int currentY = getY();

    // Calculate new x-coordinate based on velocity
    int newX = currentX + ((velocityX > 0) ? 1 : -1);
    setPosition(newX, currentY);

    // Check for Collision with immovable object
    if (objects.isCollidingWith(*this, "immoveable"))
    {
        stopHorizontalMovement();
        setPosition(currentX, currentY);
        return true;    // Collision detected
    }
    return false;       // No collision
}

bool MoveableObject::moveYbyOne(GameObjectArray& objects)
{
    // Get current x and y coordinates
    int currentX = getX();
    int currentY = getY();

    // Calculate new y-coordinate based on velocity
    int newY = currentY + ((velocityY > 0) ? 1 : -1);
    setPosition(currentX, newY);

    // Check for collision with immovable objects
    if (objects.isCollidingWith(*this, "immoveable"))
    {
        stopVerticalMovement();
        setPosition(currentX, currentY);
        return true;  // Collision detected
    }
    return false;  // No collision
}

bool MoveableObject::isStationary()
{
    return (velocityX == 0 && velocityY == 0);
}

bool MoveableObject::isMovingHorizontally()
{
    return (velocityX != 0 && velocityY == 0);
}

bool MoveableObject::isMovingVertically()
{
    return (velocityX == 0 && velocityY != 0);
}

int MoveableObject::calcRise()
{
    // Check if 0
    if (velocityX == 0) {
        return 1000000;
    }

    // return rise
    int rise = velocityY / velocityX;
    return abs(rise);
}

int MoveableObject::calcRun()
{
    // Check if 0
    if (velocityY == 0) {
        return 1000000;
    }

    // return rise
    int run = velocityX / velocityY;
    return abs(run);
}

void MoveableObject::moveDiagonally(GameObjectArray& objects, int x, int y)
{
    int remainingX = x;
    int remainingY = y;

    while (remainingX || remainingY)
    {
        if (remainingX)
        {
            bool xCollisionOccurred = moveXbyOne(objects);
            remainingX = (xCollisionOccurred) ? 0 : remainingX - 1;
        }
        if (remainingY)
        {
            bool yCollisionOccurred = moveYbyOne(objects);
            remainingY = (yCollisionOccurred) ? 0 : remainingY - 1;
        }
    }
}

void MoveableObject::moveByRise(GameObjectArray& objects, int x, int y)
{
    int remainingX = x;
    int remainingY = y;
    int rise = calcRise();

    while (remainingX || remainingY)
    {
        if (remainingY)
        {
            int stepsY = std::min(rise, remainingY);
            bool yCollisionOccurred = moveY(objects, stepsY);
            remainingY = (yCollisionOccurred) ? 0 : remainingY - stepsY;
        }
        if (remainingX)
        {
            bool xCollisionOccurred = moveXbyOne(objects);
            remainingX = (xCollisionOccurred) ? 0 : remainingX - 1;
        }
    }
}

void MoveableObject::moveByRun(GameObjectArray& objects, int x, int y)
{
    int remainingX = x;
    int remainingY = y;
    int run = calcRun();

    while (remainingX || remainingY)
    {
        if (remainingX)
        {
            int stepsX = std::min(run, remainingX);
            bool xCollisionOccurred = moveX(objects, stepsX);
            remainingX = (xCollisionOccurred) ? 0 : remainingX - stepsX;
        }
        if (remainingY)
        {
            bool yCollisionOccurred = moveYbyOne(objects);
            remainingY = (yCollisionOccurred) ? 0 : remainingY - 1;
        }
    }
}
