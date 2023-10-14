#ifndef DOOR_H
#define DOOR_H

#include "ImmoveableObject.h"
#include "GameTextures.h"
#include <string>

class Door : public ImmoveableObject
{
    private:
        bool pressed;
        std::string color;
        int incoming_signals;
        GameTextures textures;

        bool isOpen();
        void updateTexture();

    public:
        Door(int x, int y, GameTextures& gameTextures, std::string colour);
        ~Door();

        virtual bool update(GameObjectArray& objects) override;
        virtual std::string collisionType() override;
        virtual void listen(std::string channel, std::string signal) override;


};

#endif