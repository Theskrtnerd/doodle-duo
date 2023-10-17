#include "../include/Player.h"
#include <SFML/Window/Keyboard.hpp>
#include "../include/GameObjectArray.h"

bool isKeyPressed(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }

Player::Player(int x, int y, std::string color_, GameTextures& gameTextures)
: MoveableObject(x, y, gameTextures), xStart(x), yStart(y)
{
    this->setColorString(color_);
    this->setTextureFromFile(gameTextures, "Player.png");
    this->setColor(this->getColorString());
}

bool Player::update(GameObjectArray& objects)
{
    playerInputs(objects);

    if (!MoveableObject::update(objects)) return false;

    this->friction();

    return true;
}

std::string Player::collisionType() { return "player "+ getColorString(); }

void Player::reset(GameObjectArray& objects) { this->setPosition(xStart, yStart); }

void Player::playerInputs(GameObjectArray& objects) {
    if (getColorString() != "red")
    {
        if (isKeyPressed(sf::Keyboard::Up)) jump(objects);
        if (isKeyPressed(sf::Keyboard::Down)) interact(objects);
        if (isKeyPressed(sf::Keyboard::Right)) moveRight();
        if (isKeyPressed(sf::Keyboard::Left)) moveLeft();
    }
    if (getColorString() != "blue")
    {
        if (isKeyPressed(sf::Keyboard::W)) jump(objects);
        if (isKeyPressed(sf::Keyboard::S)) interact(objects);
        if (isKeyPressed(sf::Keyboard::D)) moveRight();
        if (isKeyPressed(sf::Keyboard::A)) moveLeft();
    }
}

void Player::moveLeft()
{
    double maxSpeed = 50.0;
    double acceleration = 2.0;
    double currentVelocity = getVelocityX();

    if (currentVelocity > -maxSpeed)
    {
        setVelocityX(currentVelocity - acceleration);
    }
}

void Player::moveRight()
{
    double maxSpeed = 50.0;
    double acceleration = 2.0;
    double currentVelocity = getVelocityX();

    if (currentVelocity < maxSpeed) setVelocityX(currentVelocity + acceleration);
}

void Player::jump(GameObjectArray& objects)
    {        
        if (!objects.isGrounded(*this)) return;

        setVelocityY(-16);
    }
    
void Player::interact(GameObjectArray& objects)
{
    GameObject* intractable = objects.getCollidingWith(*this, "intractable");

    if (intractable == nullptr) return;

    intractable->interactWith(objects);
}

void Player::friction()
{
    double frictionCoefficient = 0.25; // change this as needed
    double currentVelocityX = getVelocityX();

    // Apply friction
    currentVelocityX = currentVelocityX * (1 - frictionCoefficient);

    // Set velocity to zero if it's close enough
    if (abs(currentVelocityX) < 0.01)
    {
        currentVelocityX = 0;
    }

    setVelocityX(currentVelocityX);
}

Player::~Player() {}