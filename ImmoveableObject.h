#ifndef IMMOVEABLE_OBJECT_H
#define IMMOVEABLE_OBJECT_H

#include "GameObject.h"

class ImmoveableObject: public GameObject{
  public:
    ImmoveableObject();
    ImmoveableObject(int x_, int y_);
    void draw(sf::RenderWindow& window) override;

};


#endif