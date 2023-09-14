#include "GameObject.h"

GameObject::GameObject()
    : x(0), y(0)
    {}

GameObject::GameObject(int x_, int y_)
    : x(x_), y(y_)
    {}

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

bool GameObject::update()
    {
        return true;
    }

GameObject::~GameObject() {}
