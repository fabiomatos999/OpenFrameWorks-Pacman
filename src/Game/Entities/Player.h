#pragma once
#include "Animation.h"
#include "PowerUp.h"
#include "EntityManager.h"
#include "WinState.h"
#include "PauseState.h"
#include "RandomGhost.h"
#include "RandomPowerUp.h"
#include "PeekABooGhost.h"
#include "InvisiblePowerUp.h"
#include <math.h>

class Player: public Entity{

    private:
        int spawnX, spawnY;
        int health=3;
        int score=0;
        bool canMove;
        int speed = 8;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        PowerUp PO;
        WinState win;
        PauseState pause;
        RandomGhost* randomGhost;
        RandomPowerUp* randomPowerUp = new RandomPowerUp();
        InvisiblePowerUp* invisiblePowerUp = new InvisiblePowerUp();

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        void setHealth(int);
        int getScore();
        void setScore(int);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
        void die();
        void setspeed();
        int getspeed();
        void setWinState(bool win);
        void clearem();
        int wincounter = 0;
        WinState getwinstate();
        void spawnRandomGhost();
        int rdgcounter=0;
        void teleportPlayer();
        EntityManager* getem();
        int getx();
        int gety();
        int peekABooGhostCounter = 0;
        void checkCoordinates();
        int previousCoordinatesX = spawnX;
        int previousCoordinatesY = spawnY;
        int coordinateShiftCounter = 0;
        
};