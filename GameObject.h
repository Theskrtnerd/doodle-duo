#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "GameTextures.h"

class GameObject
{
    protected:
        void setTextureFromFile(GameTextures& gameTextures, const std::string& file_name);


    private:
            // TODO: mention whether this is based on middle or a specific corner
            // ? Which should it be corner or middle ?
        int x;
        int y;

        /// @brief Whether the player can interact with this object (Specifically using the 'Interact' button)
        bool isInteractable;

        sf::Sprite sprite;
        sf::Texture texture;

    
    public:
        GameObject();
        GameObject(int x_, int y_, GameTextures& gameTextures);
        
        void setPosition(int x, int y);

        int getX();
        int getY();

        virtual bool update();

        virtual void draw(sf::RenderWindow &window);
        sf::Sprite getSprite();

    
        ~GameObject();
};

#endif