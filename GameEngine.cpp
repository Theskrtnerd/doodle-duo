#include "GameEngine.h"

// adding dependencies for the json reader
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <sstream>
#include <string>



int cellSize = 40;





GameEngine::GameEngine(int width, int height, const std::string &title)
: window(sf::VideoMode(width, height), title), menu_open(false)
{
    int framePerSecond = 60;
    window.setFramerateLimit(framePerSecond);
    window.setPosition(sf::Vector2i(200, 200));

    gameObjects = new GameObjectArray();
    menu = new GameObjectArray();
}





void GameEngine::run()
{
    std::string firstLevel = "example_level.json";
    std::string menuScreen = "example_starting_screen.json";
    gameObjects->populateFromJson(firstLevel);
    menu->populateFromJson(menuScreen);
    menu->updateAll();

    while (window.isOpen())
    {
        // Exit look
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed){
                window.close();
            }

            if (windowEvent.type == sf::Event::MouseButtonPressed){
                if (windowEvent.mouseButton.button == sf::Mouse::Left) {
                    int xPos = windowEvent.mouseButton.x;
                    int yPos = windowEvent.mouseButton.y;
                    gameObjects->clickAll(xPos, yPos, *this);
                    if (menu_open) menu->clickAll(xPos, yPos, *this);

                }
            }
        }

        // Clear the window
        window.clear();

        // Update and drawer Objects
        gameObjects->updateAll();
        gameObjects->drawAll(window);

        // update Menu
        if (menu_open) menu->drawAll(window);

        // Display the contents of the window
        window.display();
    }
}


GameEngine::~GameEngine()
{
    delete gameObjects;
}

void GameEngine::closeMenu()
{
    menu_open = false;
}

void GameEngine::openMenu()
{
    menu_open = true;
}
