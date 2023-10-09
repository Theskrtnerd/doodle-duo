#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"
#include <string>

class Background : public GameObject
{
private:
    /* data */
public:
    Background(const std::string& texture_file, GameTextures& gameTextures);

    virtual void draw(sf::RenderWindow &window) override;
};


#endif