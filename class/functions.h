#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <unordered_map>

Json::Value readJSONFile(const std::string& filePath);

sf::Color stringToColor(const std::string& color);

sf::Font stringToFont(const std::string& fontPath);

#endif