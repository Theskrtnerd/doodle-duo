#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "GameTextures.h"

class GameObjectArray;
class GameEngine;

class GameObject
{
    public:
        void setTextureFromFile(GameTextures& gameTextures, const std::string& file_name);


    private:
        int x;
        int y;
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
        virtual void click(int xPos, int yPos, GameEngine& engine);
        virtual std::string collisionType();
        virtual void listen(std::string channel, std::string signal);
        virtual void interactWith(GameObjectArray& objects);

        sf::Sprite getSprite();
        sf::Texture getTexture();

        bool isOverlapping(GameObject* otherObject);

    
        ~GameObject();
};

#endif