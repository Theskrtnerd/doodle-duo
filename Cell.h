#ifndef CELL_H
#define CELL_H

#include "ImmoveableObject.h"

class Cell : public ImmoveableObject
{
private:
    /* data */
public:
    Cell();
    Cell(int x, int y, GameTextures& gameTextures);
    ~Cell();
};

#endif