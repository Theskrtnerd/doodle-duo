#include "GameObjectArray.h"
#include "Player.h"



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
        objects[index] = createObjectFromJson(json_file, index);
    }
}





void GameObjectArray::updateAll()
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->update();
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








GameObject* createObjectFromJson(Json::Value root, int index)
{
    GameObject* output = nullptr;

    if (index < root.size())
    {
        Json::Value& json_object = root[index];

        std::string object_type = json_object["type"].asString();

        if (object_type == "Player")
            output = createPlayerFromJson(json_object);
    }

    return output;
}


GameObject* createPlayerFromJson(Json::Value& jsonObject)
{
    int x = jsonObject["x"].asInt();
    int y = jsonObject["y"].asInt();
    std::string color = jsonObject["colour"].asString();
    return new Player(x, y, color);
}