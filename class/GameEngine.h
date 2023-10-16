#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObjectArray.h"
#include "functions.h"

class GameEngine
{
public:
    GameEngine(int width, int height, const std::string &title);
    void run();
    ~GameEngine();
    void closeScreen();
    void openScreen();
    void moveScreen(std::string screen_display);
    void setLevel(int target_level);
    void setMaxLevel();
    void resetLevel();
    void loadNextLevel();

private:
    GameObjectArray* gameObjects;
    GameObjectArray* screen;
    std::string screen_display;
    bool screen_open;
    bool screen_moved;
    int max_level;
    int current_level;
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    bool level_changed;
};

#endif