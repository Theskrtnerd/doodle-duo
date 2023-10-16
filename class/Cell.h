#ifndef CELL_H
#define CELL_H

#include "ImmoveableObject.h"

/// @brief Cell class, mainly used as a building block in the game grid.
class Cell : public ImmoveableObject
{
public:
    /// @brief Constructs a Cell instance.
    /// @param x x-coordinate.
    /// @param y y-coordinate.
    /// @param gameTextures A reference to pre-loaded textures.
    Cell(int x, int y, GameTextures& gameTextures);

    /// @brief Destructs a Cell instance.
    ~Cell();
};

#endif