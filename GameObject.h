#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

class GameObject
{
    protected:
        /// @brief Whether the player can interact with this object (Specifically using the 'Interact' button)
        bool isInteractable;

    private:
            // TODO: mention whether this is based on middle or a specific corner
            // ? Which should it be corner or middle ?
        /// @brief x Coordinate
        int x;
        /// @brief y Coordinate
        int y;

        
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Sprite getSpite();
    
    public:
        GameObject();
        GameObject(int x_, int y_);
        
        /**
         * @brief Sets the position of the object
         * @param x The x coordinate that the object will be moved to
         * @param y The y coordinate that the object will be moved to
        */
        void setPosition(int x, int y);

        int getX();
        int getY();

        /**
         * @brief Updates the position and game state
         * @note Does nothing for GameObject
         * @return Returns true if the update was successful otherwise false
        */
        virtual bool update();

        /*
            Add getter and setter for sprite
        */
       sf::Sprite getSprite();
       void setSprite(sf::Sprite sprite);


        /**
         * @brief Draws the object on the window
        */
        virtual void draw(sf::RenderWindow &window);

        ~GameObject();
};

#endif