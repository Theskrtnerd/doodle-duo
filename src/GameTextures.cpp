#include "include/GameTextures.h"
#include "include/functions.h"

void GameTextures::addTexture(const std::string& file_name) {
    std::string file_path = GetParentPath() + file_name;
    
    // Check if the file exists
    if (!std::filesystem::exists(file_path)) {
        std::cout << "File not found: " << file_path << std::endl;
        return;
    }
    
    sf::Texture texture;
    if (!texture.loadFromFile(file_path)) {
        std::cout << "Error loading texture: " << file_name << std::endl;
        throw std::runtime_error("Failed to load texture: " + file_name);
    }
    texturesMap[file_name] = texture;
}

GameTextures::GameTextures() {}

GameTextures::~GameTextures() {}

sf::Texture& GameTextures::getTexture(const std::string& file_name)
{
    // If texture isn't found, add it
    if (texturesMap.find(file_name) == texturesMap.end())
    {
        addTexture(file_name);
        if (texturesMap.find(file_name) == texturesMap.end())
        {
            throw std::runtime_error("Failed to load texture: " + file_name);
        }
    }
    return texturesMap[file_name];
}
