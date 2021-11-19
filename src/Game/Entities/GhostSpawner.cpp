#include "GhostSpawner.h"
#include "Ghost.h"
#include <cmath>
#include "PowerUp.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

}

void GhostSpawner::tick(){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::keyPressed(int key){
    if(key == 'g'){
    int rand_num = floor(ofRandom(4));
    switch (rand_num)
    {
        case 0:
        spawnGhost("red");
        break;
        case 1:
        spawnGhost("pink");
        break;
        case 2:
        spawnGhost("red");
        break;
        case 3:
        spawnGhost("orange");
        break;
         
      }
    }
}

int GhostSpawner::getx()
{
    return x;
}

int GhostSpawner::gety()
{
    return y;
}