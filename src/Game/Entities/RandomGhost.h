#pragma once

#include "ofMain.h"
#include "Ghost.h"
#include "EntityManager.h"
#include <string>

class RandomGhost : public Ghost
{
    private:
        FACING facing = UP;
        bool canMove = true;
        bool justSpawned=true;
        void checkCollisions();
        int speed=3;
        bool israndom = true;
        EntityManager* em;
        Animation* killableAnim;
        ofImage sprites;
        ofImage killframe;
    public:
    RandomGhost(int,int,int,int,ofImage,EntityManager*,string);
    void render();
    ~RandomGhost();

};