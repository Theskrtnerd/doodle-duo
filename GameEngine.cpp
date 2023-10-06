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
    int framePerSecond = 20;
    window.setFramerateLimit(framePerSecond);

    gameObjects = new GameObjectArray();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("GameBackground.png")) {
        std::cout << "Error loading background texture: GameBackground.png" << std::endl;
        exit(1);
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
    static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
    static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y
    );
    backgroundSprite.setPosition(0, 0);
}





void GameEngine::run()
{
    std::string firstLevel = "testing.json";
    gameObjects->populateFromJson(firstLevel);

    while (window.isOpen())
    {
        // Exit look
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear();
        window.draw(backgroundSprite);


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