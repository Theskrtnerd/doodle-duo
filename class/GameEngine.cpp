#include "GameEngine.h"

// adding dependencies for the json reader
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <sstream>
#include <string>



int cellSize = 40;





GameEngine::GameEngine(int width, int height, const std::string &title)
: window(sf::VideoMode(width, height), title), screen_open(true), loadNextLevel(false), screen_display("homeScreen"), screen_moved(false)
{
    int framePerSecond = 40;
    window.setFramerateLimit(framePerSecond);
    window.setPosition(sf::Vector2i(200, 200));

    gameObjects = new GameObjectArray(this);
    screen = new GameObjectArray(this);
}





void GameEngine::run()
{
    std::string gameLevel = "assets/levels/level1.json";
    gameObjects->populateFromJson(gameLevel);

    std::string screenPath = "assets/screens/"+screen_display+".json";
    screen->populateFromJson(screenPath);
    screen->updateAll();

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
                    if (screen_open) screen->clickAll(xPos, yPos, *this);
                }
            }
        }

        // Clear the window
        window.clear();

        // Update and drawer Objects
        gameObjects->updateAll();
        gameObjects->drawAll(window);

        if (screen_moved){
            std::string screenPath = "assets/screens/"+screen_display+".json";
            screen->populateFromJson(screenPath);
            screen->updateAll();
            screen_moved = false;
        }

        // update Menu
        if (screen_open){
            screen->drawAll(window);
        }

        if (gameObjects->levelCompleted()) loadInNextLevel();

        // Display the contents of the window
        window.display();
    }
}


GameEngine::~GameEngine()
{
    delete gameObjects;
}

void GameEngine::closeScreen()
{
    screen_open = false;
}

void GameEngine::openScreen()
{
    screen_open = true;
}

void GameEngine::moveScreen(std::string screen_display_)
{
    screen_display = screen_display_;
    screen_moved = true;
}

void GameEngine::nextLevel()
{
    std::cout << "Next level Triggered" << std::endl;
    loadNextLevel = true;
}

void GameEngine::loadInNextLevel()
{
    std::string nextLevel = "assets/levels/level1.json";
    gameObjects->populateFromJson(nextLevel);
    loadNextLevel = false;
}
