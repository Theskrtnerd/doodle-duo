#include "Cell.h"

Cell::Cell() {}

Cell::Cell(int x, int y)
: ImmoveableObject(x, y)
{
    this->setTextureFromFile("Cell.png");
}

Cell::~Cell() {}
