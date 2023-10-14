#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include "functions.h"
#include "GameObject.h"

class Text : public GameObject {
private:
    sf::Text text_;
    sf::Font font_;

public:
    Text(int xPos, int yPos, GameTextures& gameTextures);
    void setText(const std::string& text);
    void setFontSize(u_int fontSize);
    void setFont(const std::string& fontFile);
    void setColor(const std::string& colour);
    virtual void draw(sf::RenderWindow& window) override;
    ~Text();
};

#endif