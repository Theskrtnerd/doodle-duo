#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"
#include <string>

/// @brief Background serves as the visual backdrop in the game.
class Background : public GameObject {
private:
    // No additional data members, using base class members.
public:
    /// @brief Constructs a Background instance
    /// @param texture_file The file for background.
    /// @param gameTextures A reference to the pre-loaded textures.
    Background(const std::string& texture_file, GameTextures& gameTextures);

    /// @brief Draws the background on the given window.
    /// @param window The window where the background will be drawn.
    virtual void draw(sf::RenderWindow &window) override;
};

#endif