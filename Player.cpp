#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

using isKeyPressed = sf::Keyboard::isKeyPressed;
using A_key = sf::Keyboard::A;
using W_key = sf::Keyboard::W;
using S_key = sf::Keyboard::S;
using D_key = sf::Keyboard::D;

using Up_key = sf::Keyboard::Up;
using Down_key = sf::Keyboard::Down;
using Left_key = sf::Keyboard::Left;
using Right_key = sf::Keyboard::Right;

Player::Player()
    : MoveableObject(), color("Red")
    {}

Player::Player(int x, int y, string color_)
    : MoveableObject(x, y), color(color_)
    {}

bool Player::update()
    {
        // Gets player input and does corrsponding methods
        playerInputs();

        // This should do the movement
        if (!MoveableObject::Update())
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
            if (isKeyPressed(Up_key)) jump();
            if (isKeyPressed(Down_key)) interact();
            if (isKeyPressed(Right_key)) moveRight();
            if (isKeyPressed(Left_key)) moveLeft();
        }
        if (color != "Blue")
        {
            if (isKeyPressed(W_key)) jump();
            if (isKeyPressed(S_key)) interact();
            if (isKeyPressed(D_key)) moveRight();
            if (isKeyPressed(A_key)) moveLeft();
        }
    }

void Player::moveLeft()
    {
        double maxSpeed = 5.0;
        double acceleration = 2.0;
        double currentVelocity getVelocityX();

        if (currentVelocity < -maxSpeed)
        {
            setVelocityX(currentVelocity - acceleration)
        }
    }

void Player::moveRight()
    {
        double maxSpeed = 5.0;
        double acceleration = 2.0;
        double currentVelocity getVelocityX();

        if (currentVelocity < maxSpeed)
        {
            setVelocityX(currentVelocity + acceleration)
        }
    }

void Player::jump()
    {
        bool NotOnGround = false;
        
        if (NotOnGround) return;

        setVelocityY(10);
    }
    
void Player::interact() {}

Player::~Player() {}
