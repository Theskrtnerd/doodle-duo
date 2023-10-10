#ifndef GAME_OBJECT_ARRAY_H
#define GAME_OBJECT_ARRAY_H

#include "GameObject.h"
#include "functions.h"
#include "Background.h"
#include "Cell.h"
#include <string>
#include "GameTextures.h"
#include "Button.h"

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
};

GameObject* createObjectFromJson(Json::Value root, int index, GameTextures& gameTextures);

#endif