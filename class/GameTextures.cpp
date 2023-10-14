#include "GameTextures.h"

void GameTextures::addTexture(const std::string& file_name) {
    sf::Texture texture;
    if (!texture.loadFromFile(file_name)) {
        std::cout << "Error loading texture: " << file_name << std::endl;
        exit(1);
    }
    texturesMap[file_name] = texture;
}

GameTextures::GameTextures() {}

GameTextures::~GameTextures() {}

sf::Texture& GameTextures::getTexture(const std::string& file_name)
{
    // If texture isn't found, add it
    if (texturesMap.find(file_name) == texturesMap.end()) {
        addTexture(file_name);
    }
    return texturesMap[file_name];
}
