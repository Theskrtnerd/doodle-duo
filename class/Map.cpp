#include "Map.h"
#include <cstdlib> // For generating random values
#include <iostream>

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

	// Initialize the sprite objects for each cell
	cells_.resize(width_ * height_);
	for (int x = 0; x < width_; ++x)
	{
		for (int y = 0; y < height_; ++y)
		{
			int index = x + y * width_;
			cells_[index] = new ImmoveableObject();
			cells_[index]->getSprite().setTexture(textures_[map_[x][y]]);
			cells_[index]->getSprite().setScale(static_cast<float>(cellSize_) / cells_[index]->getSprite().getTexture()->getSize().x,
								   static_cast<float>(cellSize_) / cells_[index]->getSprite().getTexture()->getSize().y);
			cells_[index]->getSprite().setPosition(static_cast<float>(x * cellSize_), static_cast<float>(y * cellSize_));
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
			window.draw(cells_[index]->getSprite());
		}
	}
}