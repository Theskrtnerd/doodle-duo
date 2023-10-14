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
    void closeMenu();
    void openMenu();
    void nextLevel();

private:
    GameObjectArray* gameObjects;
    GameObjectArray* menu;
    bool menu_open;
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
};

#endif