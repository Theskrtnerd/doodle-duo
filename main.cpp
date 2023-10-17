#include "include/GameEngine.h"
#include <cstdlib>

int main()
{
    // Create game json from csv
    int unused = system("python3 levelCreator/levelCreator.py");

    // Create a GameE
    GameEngine game(1200, 800, "Doodle Duo");

    // Start the game loop
    game.run();

    return 0;
}
