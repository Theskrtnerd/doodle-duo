#ifndef EXIT_H
#define EXIT_H

#include "ImmoveableObject.h"
#include "GameObjectArray.h"
#include <string>

class Exit : public ImmoveableObject
{
    private:
        bool ready;
        bool exited;
        std::string color;
        int incoming_signals;

        void readyUp(GameObjectArray& objects);
        void unreadyUp(GameObjectArray& objects);

    public:
        Exit(int x, int y, GameTextures& gameTextures, std::string colour);
        ~Exit();

        virtual bool update(GameObjectArray& objects) override;
        virtual std::string collisionType() override;
        virtual void listen(std::string channel, std::string signal) override;

};

#endif