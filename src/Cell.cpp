#include "../include/Cell.h"

Cell::Cell(int x, int y, GameTextures& gameTextures)
: ImmoveableObject(x, y, gameTextures)
{
    this->setTextureFromFile(gameTextures, "Cell.png");
}

Cell::~Cell() {}
