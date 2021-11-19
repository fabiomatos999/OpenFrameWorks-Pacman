#pragma once
#include "Player.h"
#include "GhostSpawner.h"
#include "WinState.h"
#include "Entity.h"
#include "PeekABooGhost.h"
#include <math.h>

class Map{
    public:
      Map();
      Map(EntityManager*);
      ~Map();
      void addBoundBlock(BoundBlock*);
      void addEntity(Entity*);
      void setPlayer(Player*);
      Player* getPlayer();
      void setGhostSpawner(GhostSpawner*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);
      void setWinState();
      WinState win;
      void setplayer(Player*& player);
      PeekABooGhost* peekABooGhost = new PeekABooGhost();
      void spawnPeekABooGhost();
      ofImage sprite;
    private:
      Player *player;
      EntityManager *entityManager;
      GhostSpawner* gs;
};