#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
    protected:
        /// @brief Whether the player can interact with this object (Specifically using the 'Interact' button)
        bool isInteractable;

        /// @brief Whether this object is triggered, default objects are triggered
        bool isTriggered;

    private:
            // TODO: mention whether this is based on middle or a specific corner
            // ? Which should it be corner or middle ?
        /// @brief x Coordinate
        int x;
        /// @brief y Coordinate
        int y;
    
    public:
        GameObject();
        GameObject(int x_, int y_);
        
        /**
         * @brief Sets the position of the object
         * @param x The x coordinate that the object will be moved to
         * @param y The y coordinate that the object will be moved to
        */
        void setPosition(int x, int y);

        int getX();
        int getY();

        /**
         * @brief Updates the position and game state
         * @note Does nothing for GameObject
         * @return Returns true if the update was successful otherwise false
        */
        virtual bool update();

        ~GameObject();
};

#endif