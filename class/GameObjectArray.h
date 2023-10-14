#ifndef GAME_OBJECT_ARRAY_H
#define GAME_OBJECT_ARRAY_H

#include "GameObject.h"
#include "functions.h"
#include "Background.h"
#include "Cell.h"
#include <string>
#include "GameTextures.h"
#include "ScreenButton.h"
#include "Button.h"
#include "Door.h"
#include "Lever.h"

class GameObjectArray
{
    private:
        static constexpr int max_objects = 2048;    // Can't be changed
        GameObject* objects[max_objects];
        GameTextures gameTextures;
    
    public:
        GameObjectArray();
        ~GameObjectArray();

        void clearObjects();
        void populateFromJson(std::string& json_path);

        
        void updateAll();
        void drawAll(sf::RenderWindow &window);
        void clickAll(int xPos, int yPos, GameEngine& engine);
        void tellAll(std::string channel, std::string signal);

        GameObject* findColliding(GameObject& object);
        bool isCollidingWith(GameObject& object, std::string collision_type);
        GameObject* getCollidingWith(GameObject& object, std::string collision_type);
        bool isGrounded(GameObject& object);
};

GameObject* createObjectFromJson(Json::Value root, int index, GameTextures& gameTextures);

#endif