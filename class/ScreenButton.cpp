#include "ScreenButton.h"
#include "GameEngine.h"
#include "GameObjectArray.h"

ScreenButton::ScreenButton(const std::string& textureFile, GameTextures& gameTextures, int xPos, int yPos)
: GameObject(xPos, yPos, gameTextures)
{
    this->setTextureFromFile(gameTextures, textureFile);

    this->setPosition(xPos, yPos);
}

void ScreenButton::draw(sf::RenderWindow &window) { window.draw(this->getSprite()); }

void ScreenButton::click(int xPos, int yPos, GameEngine& engine) { if (withinRange(xPos, yPos)) doAction(engine); }

void ScreenButton::doAction(GameEngine& engine)
{
    if (action) action(engine);
    else
    {
        std::cout << "Function not set properly" << std::endl;
    }
}


void ScreenButton::setAction(const std::string& actionName) { action = makeAction(actionName); }

std::function<void(GameEngine&)> ScreenButton::makeAction(const std::string& actionName)
{
    if (actionMap.find(actionName) != actionMap.end())
    {
        return actionMap.at(actionName);
    } else {
        std::cout << "Action:(" << actionName << ") not found" << std::endl;
        return
        [](GameEngine& engine)
        {
            std::cout << "Default action, Action not found." << std::endl;
        };
    }
        
}

bool ScreenButton::withinRange(int xPos, int yPos)
{
    sf::Vector2f mouse(xPos, yPos);
    sf::FloatRect bounds = this->getSprite().getGlobalBounds();
    if (bounds.contains(mouse))
    {
        return true;
    }
    return false;
}



const std::map<std::string, std::function<void(GameEngine&)>> ScreenButton::actionMap = {
    {"closeScreen", [](GameEngine& engine)
        {
            engine.closeScreen();
        }
    },
    {"howToPlay", [](GameEngine& engine)
        {
        engine.moveScreen("howToPlay");
        }
    },
    {"homeScreen", [](GameEngine& engine)
        {
        engine.moveScreen("homeScreen");
        }
    },
    {"levelMenu", [](GameEngine& engine)
        {
        engine.moveScreen("levelMenu");
        }
    },
    {"restartLevel", [](GameEngine& engine)
        {
        engine.resetLevel();
        engine.closeScreen();
        }
    },
    {"openSettings", [](GameEngine& engine)
        {
        engine.moveScreen("settingsMenu");
        engine.openScreen();
        }
    },
    {"toMaxLevel", [](GameEngine& engine)
        {
        engine.setMaxLevel();
        }
    },
    {"setLevel1", [](GameEngine& engine)
        {
        engine.setLevel(1);
        }
    },
    {"setLevel2", [](GameEngine& engine)
        {
        engine.setLevel(2);
        }
    },
    {"setLevel3", [](GameEngine& engine)
        {
        engine.setLevel(3);
        }
    },
    {"setLevel4", [](GameEngine& engine)
        {
        engine.setLevel(4);
        }
    },
    {"setLevel5", [](GameEngine& engine)
        {
        engine.setLevel(5);
        }
    },
    {"setLevel6", [](GameEngine& engine)
        {
        engine.setLevel(6);
        }
    },
    {"doNothing", [](GameEngine& engine)
        {
        }
    },
    {"EASTER", [](GameEngine& engine)
        {
        std::cout << "Fireboy and Watergirl" << std::endl;
        }
    }
};