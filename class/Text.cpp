#include "Text.h"

Text::Text(int xPos, int yPos, GameTextures& gameTextures)
: GameObject(xPos, yPos, gameTextures)
{
    text_.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
}

void Text::setText(const std::string& text) { text_.setString(text); }

void Text::setFontSize(u_int fontSize) { text_.setCharacterSize(fontSize); }

void Text::setColor(const std::string& colour) { text_.setFillColor(stringToColor(colour)); }

void Text::setFont(const std::string& fontFile)
{
    if (!font_.loadFromFile(fontFile))
    {
        std::cerr << "Error loading font from file: " << fontFile << std::endl;
    }
    text_.setFont(font_); // Set the loaded font for the text
}

void Text::draw(sf::RenderWindow& window) { window.draw(text_); }

Text::~Text() {}
