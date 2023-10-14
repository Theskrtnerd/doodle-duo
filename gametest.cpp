#include "class/GameEngine.h"

int main()
{
    // Create a GameEngine object
    GameEngine game(1200, 800, "Doodle Duo");

    // Start the game loop
    game.run();

    return 0;
}
