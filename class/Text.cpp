#include "Text.h"

Text::Text(int xPos, int yPos) {
    setPosition(xPos, yPos);
}

void Text::setText(int xPos, int yPos, std::string text, u_int fontSize, std::string color){
    this->text_.setString(text);
    this->text_.setPosition(xPos, yPos);
    this->text_.setCharacterSize(fontSize);
    this->text_.setFillColor(stringToColor(color));
    sf::Font font_ = stringToFont("assets/others/FontCrayon.ttf");
    this->text_.setFont(font_);

    // Check for errors, and handle them if necessary.
    if (!this->text_.getFont()) {
        throw std::runtime_error("Font not set in Text object.");
    }
}

void Text::draw(sf::RenderWindow &window)
{
    // Just draw the sprite (you can add additional drawing logic here if needed)
    window.draw(this->text_);
}