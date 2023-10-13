#ifndef BUTTON_H
#define BUTTON_H

#include "ImmoveableObject.h"
#include <string>

class Button : public ImmoveableObject
{
    private:
        bool pressed;
        std::string color;

        void press(GameObjectArray& objects);
        void depress(GameObjectArray& objects);

    public:
        Button(int x, int y, GameTextures& gameTextures, std::string colour);
        ~Button();

        virtual bool update(GameObjectArray& objects) override;
        virtual std::string collisionType() override;


};

#endif