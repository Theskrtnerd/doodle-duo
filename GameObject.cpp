#include "GameObject.h"
#include "GameObjectArray.h"
#include "GameEngine.h"

void GameObject::setTextureFromFile(GameTextures& gameTextures, const std::string& file_name)
{
    texture = gameTextures.getTexture(file_name);

    sprite.setTexture(texture);
    
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
}

GameObject::GameObject() : x(0), y(0) {
  if (!texture.loadFromFile("brick.png")) {
    std::cout << "Error loading texture: brick.png" << std::endl;
    exit(1);
  }
  sprite.setTexture(texture);
  sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

GameObject::GameObject(int xPos, int yPos, GameTextures& gameTextures)
: x(xPos), y(yPos)
{
    texture = gameTextures.getTexture("brick.png");

    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}


void GameObject::setPosition(int x_, int y_) {
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

bool GameObject::update(GameObjectArray& objects)
    {
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        return true;
    }

sf::Sprite GameObject::getSprite(){
    return sprite;
}

sf::Texture GameObject::getTexture()
{
    return texture;
}

bool GameObject::isOverlapping(GameObject* otherObject)
{
    if (this == otherObject) return false;
    if (otherObject == nullptr) return false;

    int self_x_left = getX();
    int self_y_top = getY();
    int self_x_right = self_x_left + 40;
    int self_y_bottom = self_y_top + 40;

    int other_x_left = otherObject->getX();
    int other_y_top = otherObject->getY();
    int other_x_right = other_x_left + 40;
    int other_y_bottom = other_y_top + 40;

    bool isOverlappingHorizontally = self_x_left < other_x_right && self_x_right > other_x_left;
    bool isOverlappingVertically = self_y_top < other_y_bottom && self_y_bottom > other_y_top;
    
    bool overlapping = isOverlappingHorizontally && isOverlappingVertically;

    return overlapping;
}

void GameObject::draw(sf::RenderWindow& window)
    {
        return;             //window.draw(sprite);
    }

void GameObject::click(int xPos, int yPos, GameEngine& engine)
{
    return;
}

std::string GameObject::collisionType()
{
    return "passable";
}

void GameObject::listen(std::string channel, std::string signal) {}

void GameObject::interactWith(GameObjectArray& objects) {}

void GameObject::setColor(const std::string& color)
{
    sprite.setColor(stringToColor(color));
}

GameObject::~GameObject() {}
