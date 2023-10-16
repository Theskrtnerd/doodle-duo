#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include "functions.h"
#include "GameObject.h"

class Text : public GameObject {
private:
    sf::Text text_;     ///< The text to be displayed
    sf::Font font_;     ///< The font to be used

public:
    /// @brief Constructs a Text object
    /// @param xPos x-coordinate of the text
    /// @param yPos y-coordinate of the text
    /// @param gameTextures Needed for its siblings and cousins 
    Text(int xPos, int yPos, GameTextures& gameTextures);

    /// @brief Sets the text to be displayed
    /// @param text String containing the text to be displayed
    void setText(const std::string& text);

    /// @brief Sets the font size to be used
    /// @param fontSize The size of the font to be used
    void setFontSize(u_int fontSize);

    /// @brief Sets the font to be used
    /// @param fontFile The file containing the font to be used
    void setFont(const std::string& fontFile);

    /// @brief Sets the colour of the text
    /// @param colour The colour of the text
    void setColor(const std::string& colour);

    /// @brief Draws the text on the screen
    /// @param window The window on which the text will be drawn
    virtual void draw(sf::RenderWindow& window) override;

    /// @brief Destructs the Text object
    ~Text();
};

#endif