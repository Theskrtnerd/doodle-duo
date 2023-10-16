#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <filesystem>
#include <vector>

/// @brief Reads a JSON file and returns a JSON object.
/// @param filePath Path to the JSON file.
/// @return Contents of the JSON file as a Json::Value object.
Json::Value readJSONFile(const std::string& filePath);

/// @brief Converts a string to a sf::Color.
/// @param color Color as a string.
/// @return Converted sf::Color object.
sf::Color stringToColor(const std::string& color);

/// @brief Converts a string path to a sf::Font.
/// @param fontPath Path to the font file.
/// @return Loaded sf::Font object.
sf::Font stringToFont(const std::string& fontPath);

/// @brief Gets the parent directory path.
/// @return Parent directory path as a string.
std::string GetParentPath();

/// @brief Generates the level menu based on the current level
/// @param current_level Current level.
void generateLevelMenu(int current_level);

#endif