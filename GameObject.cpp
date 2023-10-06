#include "GameObject.h"

sf::Sprite GameObject::getSpite()
{
    return sf::Sprite();
}

GameObject::GameObject() : x(0), y(0) {
  if (!texture.loadFromFile("brick.png")) {
    std::cout << "Error loading texture: brick.png" << std::endl;
    exit(1);
  }
  sprite.setTexture(texture);
  sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

GameObject::GameObject(int xPos, int yPos)
    : x(xPos), y(yPos)
    {
        if(!texture.loadFromFile("brick.png"))
        {
            std::cout << "Error loading texture: brick.png" << std::endl;
            exit(1);
        }
        sprite.setTexture(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

void GameObject::setPosition(int x_, int y_) 
    {
        x = x_;
        y = y_;
    }

int GameObject::getX()
    {
        return x;
    }

int GameObject::getY()
    {
        return y;
    }

bool GameObject::update()
    {
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        return true;
    }

// add getter & setter for sprite
sf::Sprite GameObject::getSprite(){
    return sprite;
}

void GameObject::setSprite(sf::Sprite sprite){
    this->sprite = sprite;
}

void GameObject::draw(sf::RenderWindow& window)
    {
        return;             //window.draw(sprite);
    }

GameObject::~GameObject(){}
