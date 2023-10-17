#ifndef GAME_TEXTURES_H
#define GAME_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

/// @brief Manages game textures.
class GameTextures {
private:
    std::map<std::string, sf::Texture> texturesMap; ///< Map of file names to textures.

    /// @brief Add a texture to the map.
    /// @param file_name Name of the texture file.
    void addTexture(const std::string& file_name);

public:
    /// @brief Constructor
    GameTextures();
    /// @brief Destructor
    ~GameTextures();

    /// @brief Gets a texture by file name
    /// @param file_name Name of the texture file.
    /// @return Reference to the texture.
    sf::Texture& getTexture(const std::string& file_name);
};

#endif