#include "../include/GameObjectArray.h"
#include "../include/Player.h"
#include "../include/GameEngine.h"
#include "../include/functions.h"

typedef GameObject* (*CreateFunction)(Json::Value&, GameTextures& gameTextures);
extern std::map<std::string, CreateFunction> createGameObject;

GameObjectArray::GameObjectArray(GameEngine* engine)
: gameEnginePtr(engine)
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

GameEngine* GameObjectArray::getGameEngine()
{
    return gameEnginePtr;
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

void GameObjectArray::tellAll(std::string channel, std::string signal)
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->listen(channel, signal);
        }
    }
}

void GameObjectArray::resetAll()
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] != nullptr)
        {
            objects[index]->reset(*this);
        }    
    }
}

void GameObjectArray::debugAll()
{
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index]!= nullptr)
        {
            objects[index]->debug(*this);
        }
    }
}

GameObject* GameObjectArray::findColliding(GameObject& object)
{
    GameObject* otherObject;
    for (int index = 0; index < max_objects; index++)
    {
        otherObject = objects[index];
        if (otherObject == nullptr) continue;

        if (object.isOverlapping(otherObject))
        {
            if (otherObject->collisionType() != "immoveable") continue;
            return otherObject;
        }
    }
    return nullptr;
}

bool GameObjectArray::isCollidingWith(GameObject& object, std::string collision_type)
{
    GameObject* otherObject;
    for (int index = 0; index < max_objects; index++)
    {
        otherObject = objects[index];
        if (otherObject == nullptr) continue;

        if (otherObject->collisionType() != collision_type) continue;

        if (object.isOverlapping(otherObject)) return true;
    }
    return false;
}

GameObject* GameObjectArray::getCollidingWith(GameObject& object, std::string collision_type)
{
    GameObject* otherObject;
    for (int index = 0; index < max_objects; index++)
    {
        otherObject = objects[index];
        if (otherObject == nullptr) continue;

        if (otherObject->collisionType() != collision_type) continue;

        if (object.isOverlapping(otherObject)) return otherObject;
    }
    return nullptr;
}

bool GameObjectArray::isGrounded(GameObject& object) {
    bool output = false;
    
    int originalX = object.getX();
    int originalY = object.getY();

    // Check just below the object
    object.setPosition(originalX, originalY + 1); 

    if (isCollidingWith(object, "immoveable")) output = true;
    if (isCollidingWith(object, "obstacle blue")) output = true;
    if (isCollidingWith(object, "obstacle red")) output = true;

    object.setPosition(originalX, originalY);

    
    return output;
}

bool GameObjectArray::levelCompleted()
{
    int nullCount = 0;
    for (int index = 0; index < max_objects; index++)
    {
        if (objects[index] == nullptr) {nullCount++; continue;};
        if (!objects[index]->isReady(*this)) return false;
    }
    if (nullCount == max_objects) return false;
    std::cout << "Level completed!" << std::endl;
    return true;
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
        "Button",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();

            return new Button(xPos, yPos, gameTextures, colour);

        }
    },
    {
        "Door",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();

            return new Door(xPos, yPos, gameTextures, colour);
        }
    },
    {
        "Lever",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();

            return new Lever(xPos, yPos, gameTextures, colour);
        }
    },
    {
        "Exit",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();

            return new Exit(xPos, yPos, gameTextures, colour);
        }
    },
    {
        "Text",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();
            int fontSize = json_object["fontSize"].asUInt();
            std::string text = json_object["text"].asString();

            Text* myText = new Text(xPos, yPos, gameTextures);
            myText->setFont(GetParentPath() + "assets/others/FontCrayon.ttf");
            myText->setText(text);
            myText->setColor(colour);
            myText->setFontSize(fontSize);

            return myText;
        }
    },
    {
        "Obstacle",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            int xPos = json_object["x"].asInt();
            int yPos = json_object["y"].asInt();
            std::string colour = json_object["colour"].asString();
    
            return new Obstacle(xPos, yPos, gameTextures, colour);
        }
    },
    {
        "empty",
        [](Json::Value& json_object, GameTextures& gameTextures) -> GameObject*
        {
            return new GameObject(0, 0, gameTextures);
        }
    }
};