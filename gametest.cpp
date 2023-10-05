#include "GameEngine.h"

int main()
{
    // Create a GameEngine object
    GameEngine game(1200, 800, "SFML Game");

    // Start the game loop
    game.run();

    return 0;
}
