#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "GameTextures.h"

class GameObjectArray;

class GameObject
{
    protected:
        void setTextureFromFile(GameTextures& gameTextures, const std::string& file_name);


    private:
        int x;
        int y;
        bool isInteractable;
        sf::Sprite sprite;
        sf::Texture texture;

    public:
        GameObject();
        GameObject(int x_, int y_, GameTextures& gameTextures);
        
        void setPosition(int x, int y);

        int getX();
        int getY();

        virtual bool update(GameObjectArray& objects);

        virtual void draw(sf::RenderWindow &window);
        sf::Sprite getSprite();

    
        ~GameObject();
};

#endif