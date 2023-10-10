#include "GameObjectArray.h"
#include "Player.h"


typedef GameObject* (*CreateFunction)(Json::Value&, GameTextures& gameTextures);
extern std::map<std::string, CreateFunction> createGameObject;





GameObjectArray::GameObjectArray()
{
    this->clearObjects();
}





GameObjectArray::~GameObjectArray()
{
    for (int index = 0; index < max_objects; index++)
    {
        delete objects[index];
    }
}





void GameObjectArray::clearObjects()
{
    for (int index = 0; index < max_objects; index++)
    {
        delete objects[index];
        objects[index] = nullptr;
    }
}





void GameObjectArray::populateFromJson(std::string& json_path)
{
    Json::Value json_file = readJSONFile(json_path);

    for (int index = 0; index < max_objects; index++)
    {
        delete objects[index];
        

        
        objects[index] = createObjectFromJson(json_file, index, gameTextures);
    }
}





void GameObjectArray::updateAll()
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->update(*this);
        }    
    }
}




void GameObjectArray::drawAll(sf::RenderWindow &window)
{
    for (int index = max_objects-1; index >= 0; index--)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->draw(window);
        }
    }
}








GameObject* createObjectFromJson(Json::Value root, int index, GameTextures& gameTextures)
{
    GameObject* output = nullptr;

    if (index < root.size())
    {
        Json::Value& json_object = root[index];

        std::string object_type = json_object["type"].asString();

        bool factory_found = createGameObject.find(object_type) != createGameObject.end();

        if (factory_found) {
            output = createGameObject[object_type](json_object, gameTextures);
        } else {
            std::cout << object_type << " factory not found" << std::endl;
        }
    }

    return output;
}








std::map<std::string, CreateFunction> createGameObject = {
    {
        "Player",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();
            
            return new Player(xPos, yPos, colour, gameTextures);
        }
    },
    {
        "Background",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            std::string texture_file = json_object["texture"].asString();

            return new Background(texture_file, gameTextures);
        }
    },
    {
        "Cell",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();

            return new Cell(xPos, yPos, gameTextures);
        }
    },
    {
        "Button",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string texture_file = json_object["texture"].asString();

            return new Button(texture_file, gameTextures, xPos, yPos);
        }
    },
    {
        "empty",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            return new GameObject();
        }
    }
};