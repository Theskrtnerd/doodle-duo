#ifndef GAME_TEXTURES_H
#define GAME_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class GameTextures {
private:
    std::map<std::string, sf::Texture> texturesMap;
    void addTexture(const std::string& file_name);

public:
    GameTextures();
    ~GameTextures();

    sf::Texture& getTexture(const std::string& file_name);
};

#endif