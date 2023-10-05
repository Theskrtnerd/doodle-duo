#include "GameEngine.h"

// adding dependencies for the json reader
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <sstream>

// Function to read and parse a JSON file
Json::Value readJSONFile(const std::string& filePath) {
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::string errors;

    std::ifstream jsonFile(filePath);

    if (!jsonFile.is_open()) {
        std::cerr << "Error opening JSON file: " << filePath << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    // Parse the JSON file
    if (!Json::parseFromStream(reader, jsonFile, &root, &errors)) {
        std::cerr << "Error parsing JSON file: " << errors << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    jsonFile.close();
    return root;
}


int cellSize = 40;

GameEngine::GameEngine(int width, int height, const std::string &title)
    : window(sf::VideoMode(width, height), title), map(width / cellSize, height / cellSize, cellSize)
{
    // Set the frame rate (60 frames per second)
    window.setFramerateLimit(20);
    gameObjects = new GameObject*[2048];
}

void GameEngine::run()
{
    while (window.isOpen())
    {
        // Exit look
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update GameObjects
        for (int index = 0; index < 2048; index++)
        {
            gameObjects[index]->update();
        }

        // Clear the window
        window.clear();

        // Draw GameObjects
        for (int index = 0; index < 2048; index++)
        {
            gameObjects[index]->draw(window);
        }

        // Display the contents of the window
        window.display();
    }
}
