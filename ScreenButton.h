#ifndef SCREEN_BUTTON_H
#define SCREEN_BUTTON_H

#include "GameObject.h"
#include <string>

class ScreenButton : public GameObject {
private:
    /* data */
public:
    ScreenButton(const std::string& texture_file, GameTextures& gameTextures, int xPos, int yPos);

    virtual void draw(sf::RenderWindow &window) override;

    virtual bool update(GameObjectArray& objects) override;
    
    bool checkClick();
};


#endif