#pragma once

#include "EntityManager.h"
#include "PowerUp.h"

class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void keyPressed(int);
        void tick();
        int getx();
        int gety();
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
};