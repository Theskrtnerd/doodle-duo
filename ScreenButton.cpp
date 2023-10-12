#include "ScreenButton.h"

#include "ScreenButton.h"

ScreenButton::ScreenButton(const std::string& textureFile, GameTextures& gameTextures, int xPos, int yPos)
{
    // Set the texture using the provided file
    this->setTextureFromFile(gameTextures, textureFile);

    // Optional: Position it at (0, 0) assuming it covers the entire window or screen.
    this->setPosition(xPos, yPos);
}

void ScreenButton::draw(sf::RenderWindow &window)
{
    // Just draw the sprite (you can add additional drawing logic here if needed)
    window.draw(this->getSprite());
}

void ScreenButton::click(int xPos, int yPos, GameEngine& engine)
{
    if (withinRange(xPos, yPos)) doAction(engine);
}

void ScreenButton::doAction(GameEngine& engine)
{
    if (action) action(engine);
    else
    {
        std::cout << "Function not set properly" << std::endl;
    }
}


void ScreenButton::setAction(const std::string& actionName)
{
    action = makeAction(actionName);
}

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
    int buttonX = getX();
    int buttonY = getY();
    if (buttonX+100 < xPos || buttonX-100 > xPos) return false;
    if (buttonY+100 < yPos || buttonY-100 > yPos) return false;
    return true;
}



const std::map<std::string, std::function<void(GameEngine&)>> ScreenButton::actionMap = {
    {"hello", [](GameEngine& engine)
        {
        std::cout << "Hello, how are you?" << std::endl;
        }
    },
    {"goodbye", [](GameEngine& engine)
        {
        std::cout << "Goodbye, have a good day." << std::endl;
        }
    }
};