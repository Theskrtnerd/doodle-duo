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

void GameObjectArray::clickAll(int xPos, int yPos, GameEngine& engine)
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->click(xPos, yPos, engine);
        }
    }
}

GameObject* GameObjectArray::findColliding(GameObject& object)
{
    GameObject* otherObject;
    for (int index = 0; index < max_objects; index++)
    {
        otherObject = objects[index];
        if (&object == otherObject) continue;
        if (otherObject == nullptr) continue;

        int self_x_left = object.getX();
        int self_y_top = object.getY();
        int self_x_right = self_x_left + 40;
        int self_y_bottom = self_y_top + 40;

        int other_x_left = otherObject->getX();
        int other_y_top = otherObject->getY();
        int other_x_right = other_x_left + 40;
        int other_y_bottom = other_y_top + 40;

        bool isOverlappingHorizontally = self_x_left < other_x_right && self_x_right > other_x_left;
        bool isOverlappingVertically = self_y_top < other_y_bottom && self_y_bottom > other_y_top;
        

        if (isOverlappingHorizontally && isOverlappingVertically)
        {
            if (otherObject->collisionType() != "immoveable") continue;
            return otherObject;
        }

    }
    return nullptr;
}

bool GameObjectArray::isGrounded(GameObject& object) {
    bool output = false;
    
    int originalX = object.getX();
    int originalY = object.getY();

    // Check just below the object
    object.setPosition(originalX, originalY + 1); 

    GameObject* collidingObject = findColliding(object);

    // Reset the object's position
    object.setPosition(originalX, originalY);

    if (collidingObject && collidingObject->collisionType() == "immoveable") {
        output = true;
    }
    
    return output;
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
            std::string texture = json_object["texture"].asString();
    
            Cell* output = new Cell(xPos, yPos, gameTextures);
            output->setTextureFromFile(gameTextures, texture);
            return output;
        }
    },
    {
        "ScreenButton",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string texture_file = json_object["texture"].asString();
            std::string action_name = json_object["action"].asString();

            ScreenButton* button = new ScreenButton(texture_file, gameTextures, xPos, yPos);
            button->setAction(action_name);

            return button;
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