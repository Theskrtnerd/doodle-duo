#ifndef GAMEENGINE_H
#define GAMEENGINE_H
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

private:
    GameObjectArray* gameObjects;
    // GameObjectArray* menu;
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
};

#endif