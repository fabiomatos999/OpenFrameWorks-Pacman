#include "RandomGhost.h"

RandomGhost::RandomGhost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em, string color): Ghost(x,y,width,height,spriteSheet,em,color)
{
    this->em = em;
    sprites.loadImage("images/Background.png");
    vector<ofImage> killableFrames;
    ofImage temp;
    temp.cropFrom(sprites,584,50,16,16);
    for(int i =0 ; i<4 ;i++)
    {
    killableFrames.push_back(temp);
    }
    killableAnim = new Animation(10, killableFrames);
    sprite.cropFrom(sprites,570,52,16,16);
}

void RandomGhost::checkCollisions(){
    for(BoundBlock* BoundBlock: em->BoundBlocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(BoundBlock->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(BoundBlock->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(BoundBlock->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(BoundBlock->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
}

void RandomGhost::render(){
    if(killable){
        killableAnim->getCurrentFrame().draw(x,y,width,height);
    }else{
        Entity::render();
    }
}

RandomGhost::~RandomGhost()
{
    delete killableAnim;
}