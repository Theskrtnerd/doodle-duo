#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

/*
using isKeyPressed = sf::Keyboard::isKeyPressed;
using A_key = sf::Keyboard::A;
using W_key = sf::Keyboard::W;
using S_key = sf::Keyboard::S;
using D_key = sf::Keyboard::D;

using Up_key = sf::Keyboard::Up;
using Down_key = sf::Keyboard::Down;
using Left_key = sf::Keyboard::Left;
using Right_key = sf::Keyboard::Right;
*/






bool isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

Player::Player()
    : MoveableObject(), color("Red")
    {
        //this->setTextureFromFile("stick_figure.png");
        this->setTextureFromFile("brick.png");
    }

Player::Player(int x, int y, std::string color_)
    : MoveableObject(x, y), color(color_)
    {
        this->setTextureFromFile(color_+".png");
    }

bool Player::update()
    {
        // Gets player input and does corrsponding methods
        playerInputs();

        // This should do the movement
        if (!MoveableObject::update())
        {
            return 0;
        }

        // All good
        return 1;
    }


void Player::playerInputs()
    {
        if (color != "Red")
        {
            if (isKeyPressed(sf::Keyboard::Up)) jump();
            if (isKeyPressed(sf::Keyboard::Down)) interact();
            if (isKeyPressed(sf::Keyboard::Right)) moveRight();
            if (isKeyPressed(sf::Keyboard::Left)) moveLeft();
        }
        if (color != "Blue")
        {
            if (isKeyPressed(sf::Keyboard::W)) jump();
            if (isKeyPressed(sf::Keyboard::S)) interact();
            if (isKeyPressed(sf::Keyboard::D)) moveRight();
            if (isKeyPressed(sf::Keyboard::A)) moveLeft();
        }
    }

void Player::moveLeft()
    {
        double maxSpeed = 5.0;
        double acceleration = 2.0;
        double currentVelocity = getVelocityX();

        if (currentVelocity > -maxSpeed)
        {
            setVelocityX(currentVelocity - acceleration);
        }
    }

void Player::moveRight()
    {
        double maxSpeed = 5.0;
        double acceleration = 2.0;
        double currentVelocity = getVelocityX();

        if (currentVelocity < maxSpeed)
        {
            setVelocityX(currentVelocity + acceleration);
        }
    }

void Player::jump()
    {
        bool NotOnGround = false;
        
        if (NotOnGround) return;

        setVelocityY(-10);
    }
    
void Player::interact() {}

Player::~Player() {}
