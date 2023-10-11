#include "GameEngine.h"

// adding dependencies for the json reader
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <sstream>
#include <string>



int cellSize = 40;





GameEngine::GameEngine(int width, int height, const std::string &title)
: window(sf::VideoMode(width, height), title)
{
    int framePerSecond = 60;
    window.setFramerateLimit(framePerSecond);
    window.setPosition(sf::Vector2i(200, 200));

    gameObjects = new GameObjectArray();
    //menu = new GameObjectArray();
}





void GameEngine::run()
{
    std::string firstLevel = "example_level.json";
    ////firstLevel = "example_starting_screen.json";
    gameObjects->populateFromJson(firstLevel);

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
                    
                }
            }
        }

        // Clear the window
        window.clear();

        // Update and drawer Objects
        gameObjects->updateAll();
        gameObjects->drawAll(window);

        // Display the contents of the window
        window.display();
    }
}


GameEngine::~GameEngine()
{
    delete gameObjects;
}