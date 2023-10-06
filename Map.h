#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "ImmoveableObject.h"

class Map
{
private:
	int width_;
	int height_;
	int cellSize_;
	std::vector<std::vector<int>> map_;
	std::vector<sf::Texture> textures_; // Store textures for each cell
	std::vector<ImmoveableObject*> cells_;		// Store sprite objects for each cell

public:
	Map(int width, int height, int cellSize);
	void draw(sf::RenderWindow &window);

};

#endif