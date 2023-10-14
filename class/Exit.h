#ifndef EXIT_H
#define EXIT_H

#include "ImmoveableObject.h"
#include "GameObjectArray.h"
#include <string>

class Exit : public ImmoveableObject
{
    private:
        std::string color;

    public:
        Exit(int x, int y, GameTextures& gameTextures, std::string colour);
        ~Exit();

        virtual std::string collisionType() override;

        bool isReady(GameObjectArray& objects) override;

};

#endif