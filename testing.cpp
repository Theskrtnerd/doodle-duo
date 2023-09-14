#include <SFML/Graphics.hpp>

int main()
{
    // Create a window with dimensions 800x600
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML Works!");

    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear and display window
        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}