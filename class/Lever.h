#ifndef LEVER_H
#define LEVER_H

#include "ImmoveableObject.h"
#include <string>

class Lever : public ImmoveableObject
{
    private:
        bool isOn;
        std::string color;
        GameTextures& gameTextures;
        int cooldown;

        void turnOn(GameObjectArray& objects);
        void turnOff(GameObjectArray& objects);
        void updateTexture();

    public:
        Lever(int x, int y, GameTextures& gameTextures, std::string colour);
        ~Lever();

        virtual void interactWith(GameObjectArray& objects) override;
        virtual bool update(GameObjectArray& object) override;
        virtual std::string collisionType() override;
};

#endif