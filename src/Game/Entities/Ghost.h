#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include <string>
#include "PowerUp.h"

class Ghost: public Entity{
    public:
        Ghost(){}
        Ghost(int, int, int, int, ofImage, EntityManager*, string);
        ~Ghost();
        void tick();
        virtual void render();
        bool getKillable();
        void setKillable(bool);
        bool getisrandom();
        bool killable = false;
    private:
        FACING facing = UP;
        bool canMove = true;
        bool justSpawned=true;
        void checkCollisions();
        int speed=3;
        EntityManager* em;
        Animation* killableAnim;
        bool israndom = false;

};