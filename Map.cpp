#include "Map.h"
#include <cstdlib> // For generating random values
#include <iostream>

// adding dependencies for the json reader
#include <json/json.h>
#include <fstream>
#include <sstream>

// Function to read and parse a JSON file
Json::Value readJSONFile(const std::string& filePath) {
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::string errors;

    std::ifstream jsonFile(filePath);

    if (!jsonFile.is_open()) {
        std::cerr << "Error opening JSON file: " << filePath << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    // Parse the JSON file
    if (!Json::parseFromStream(reader, jsonFile, &root, &errors)) {
        std::cerr << "Error parsing JSON file: " << errors << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    jsonFile.close();
    return root;
}

Map::Map(int width, int height, int cellSize) : width_(width), height_(height), cellSize_(cellSize)
{
	// Initialize the map with random cell values (0 to 2)
	map_.resize(width_, std::vector<int>(height_, 0));
	for (int x = 0; x < width_; ++x)
	{
		for (int y = 0; y < height_; ++y)
		{
			map_[x][y] = rand() % 3; // Random value between 0 and 2
		}
	}

	// Load textures for different cell types (replace with actual image paths)
	textures_.resize(3); // Assuming you have three different cell types
	textures_[0].loadFromFile("brick.png");
	textures_[1].loadFromFile("blank.png");
	textures_[2].loadFromFile("blank.png");

	// Initialize the sprite objects for each cell
	cells_.resize(width_ * height_);
	for (int x = 0; x < width_; ++x)
	{
		for (int y = 0; y < height_; ++y)
		{
			int index = x + y * width_;
			cells_[index].setTexture(textures_[map_[x][y]]);
			cells_[index].setScale(static_cast<float>(cellSize_) / cells_[index].getTexture()->getSize().x,
								   static_cast<float>(cellSize_) / cells_[index].getTexture()->getSize().y);
			cells_[index].setPosition(static_cast<float>(x * cellSize_), static_cast<float>(y * cellSize_));
		}
	}
}

void Map::draw(sf::RenderWindow &window)
{
	for (int x = 0; x < width_; ++x)
	{
		for (int y = 0; y < height_; ++y)
		{
			int index = x + y * width_;
			window.draw(cells_[index]);
		}
	}
}
