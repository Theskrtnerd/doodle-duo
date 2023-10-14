#ifndef SCREEN_BUTTON_H
#define SCREEN_BUTTON_H

#include "GameObject.h"
#include <string>
#include <functional>

class GameEngine;

class ScreenButton : public GameObject {
private:
    std::function<void(GameEngine&)> action;
public:
    static const std::map<std::string, std::function<void(GameEngine&)>> actionMap;
    ScreenButton(const std::string& texture_file, GameTextures& gameTextures, int xPos, int yPos);

    virtual void draw(sf::RenderWindow &window) override;
    virtual void click(int xPos, int yPos, GameEngine& engine) override;
    void doAction(GameEngine& engine);
    void setAction(const std::string& actionName);
    std::function<void(GameEngine&)> makeAction(const std::string& actionName);

    bool withinRange(int xPos, int yPos);
};


#endif