#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"
#include <string>

class Button : public GameObject {
private:
    /* data */
public:
    Button(const std::string& texture_file, GameTextures& gameTextures, int xPos, int yPos);

    virtual void draw(sf::RenderWindow &window) override;
};


#endif