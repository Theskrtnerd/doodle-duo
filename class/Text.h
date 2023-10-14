#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include "functions.h"
#include "GameObject.h"

class Text: public GameObject{
    private:
        sf::Text text_;
    public:
        Text(int xPos, int yPos);
        void setText(int xPos, int yPos, std::string text, u_int fontSize, std::string color);
        // Other member function declarations if needed
        virtual void draw(sf::RenderWindow &window) override;
        ~Text();
};

#endif