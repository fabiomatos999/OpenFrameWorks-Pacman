#pragma once

#include "ofMain.h"
#include "Ghost.h"
#include "GhostSpawner.h"
#include <string>

class PeekABooGhost : public Ghost
{
private:
    FACING facing = UP;
    bool canMove = true;
    bool justSpawned = true;
    void checkCollisions();
    int speed = 3;
    EntityManager *em;
    Animation *killableAnim;
    bool israndom = false;
    ofImage sprites;

public:
    PeekABooGhost();
    PeekABooGhost(int, int, int, int, ofImage, EntityManager *, string);
    int getx();
    int gety();
    ~PeekABooGhost();
    void render();
};