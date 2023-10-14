#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SFML/Graphics.hpp>
#include "Map.h"
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
    void nextLevel();
    void loadInNextLevel();

private:
    GameObjectArray* gameObjects;
    GameObjectArray* screen;
    std::string screen_display;
    bool screen_open;
    bool screen_moved;
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    bool loadNextLevel;
};

#endif