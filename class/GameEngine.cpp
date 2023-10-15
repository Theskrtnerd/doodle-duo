#include "GameEngine.h"

// adding dependencies for the json reader
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <sstream>
#include <string>



int cellSize = 40;





GameEngine::GameEngine(int width, int height, const std::string &title)
: window(sf::VideoMode(width, height), title), screen_open(true), level_changed(false), screen_display("homeScreen"), screen_moved(false), current_level(1), max_level(1)
{
    int framePerSecond = 40;
    window.setFramerateLimit(framePerSecond);
    window.setPosition(sf::Vector2i(200, 200));

    gameObjects = new GameObjectArray(this);
    screen = new GameObjectArray(this);
}





void GameEngine::run()
{
    if(max_level < 7){
        std::string gameLevel = "assets/levels/level"+std::to_string(max_level)+".json";
        gameObjects->populateFromJson(gameLevel);
    }
    else{
        std::string gameLevel = "assets/levels/level"+std::to_string(1)+".json";
        gameObjects->populateFromJson(gameLevel);
    }

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

        if (level_changed){
            std::string nextLevel = "assets/levels/level"+std::to_string(current_level)+".json";
            gameObjects->populateFromJson(nextLevel);
            level_changed = false;
        }

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

        if (gameObjects->levelCompleted()){
            loadNextLevel();
        }
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
    if (screen_display == "levelMenu"){
        generateLevelMenu(max_level);
    }
}

void GameEngine::loadNextLevel()
{
    if(max_level <7){
        if(max_level <6 && current_level == max_level){
            max_level++;
            current_level++;
            level_changed = true;
        }
        else{
            if(max_level == 6 && current_level == max_level){
                max_level++;
                moveScreen("levelMenu");
                gameObjects->clearObjects();
                openScreen();
                level_changed = false;
            }
            else{
                if(current_level <6){
                    current_level++;
                    level_changed = true;
                }
            }   
        }
    }
}

void GameEngine::setLevel(int target_level)
{
    if(max_level >= target_level){
        current_level = target_level;
        level_changed = true;
        closeScreen();
    }
}

void GameEngine::setMaxLevel()
{
    if(max_level < 7){
        current_level = max_level;
    }
    else{
        current_level = 1;
    }
    level_changed = true;
    closeScreen();
}

void GameEngine::resetLevel()
{
    level_changed = true;
}