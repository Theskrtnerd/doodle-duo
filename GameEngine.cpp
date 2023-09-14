#include "GameEngine.h"

int var = 40;

GameEngine::GameEngine(int width, int height, const std::string &title)
    : window(sf::VideoMode(width, height), title), map(width / var, height / var, var)
{
    // Set the frame rate (60 frames per second)
    window.setFramerateLimit(60);
}

void GameEngine::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle game logic here

        // Clear the window
        window.clear();

        // Draw the map
        map.draw(window);

        // Other game object drawing code goes here

        // Display the contents of the window
        window.display();
    }
}
