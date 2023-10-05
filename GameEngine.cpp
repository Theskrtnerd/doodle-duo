#include "GameEngine.h"

int var = 40;

GameEngine::GameEngine(int width, int height, const std::string &title)
    : window(sf::VideoMode(width, height), title), map(width / var, height / var, var)
{
    // Set the frame rate (60 frames per second)
    window.setFramerateLimit(20);
    gameObjects = new gameObjects[128];
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
        for (int index = 0; index < 128; index++)
        {
            gameObjects[index]->update();
        }

        // Clear the window
        window.clear();

        // Draw GameObjects
        for (int index = 0; index < 128; index++)
        {
            gameObjects[index]->draw(&window);
        }

        // Display the contents of the window
        window.display();
    }
}
