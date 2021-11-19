#include "Player.h"
#include "PowerUp.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"

Player::Player(int x, int y, int width, int height, EntityManager *em) : Entity(x, y, width, height)
{
    spawnX = x;
    spawnY = y;
    sprite.load("images/pacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);

    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for (int i = 0; i < 3; i++)
    {
        temp.cropFrom(sprite, i * 16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        temp.cropFrom(sprite, i * 16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        temp.cropFrom(sprite, i * 16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        temp.cropFrom(sprite, i * 16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1, downAnimframes);
    walkUp = new Animation(1, upAnimframes);
    walkLeft = new Animation(1, leftAnimframes);
    walkRight = new Animation(1, rightAnimframes);

    this->em = em;
}
void Player::tick()
{
    canMove = true;
    checkCollisions();
    if (canMove)
    {
        if (facing == UP)
        {
            y -= speed;
            walkUp->tick();
        }
        else if (facing == DOWN)
        {
            y += speed;
            walkDown->tick();
        }
        else if (facing == LEFT)
        {
            x -= speed;
            walkLeft->tick();
        }
        else if (facing == RIGHT)
        {
            x += speed;
            walkRight->tick();
        }
    }
    if (em->entities.size() == 0 && wincounter == 0)
    {
        win.setwin(true);
        wincounter++;
    }
    spawnRandomGhost();
    teleportPlayer();
    checkCoordinates();
}

void Player::render()
{
    if (invisiblePowerUp->getactive() == true && coordinateShiftCounter < 200)
    {
    }
    else
    {
        ofSetColor(256, 256, 256);
        // ofDrawRectangle(getBounds());
        if (facing == UP)
        {
            walkUp->getCurrentFrame().draw(x, y, width, height);
        }
        else if (facing == DOWN)
        {
            walkDown->getCurrentFrame().draw(x, y, width, height);
        }
        else if (facing == LEFT)
        {
            walkLeft->getCurrentFrame().draw(x, y, width, height);
        }
        else if (facing == RIGHT)
        {
            walkRight->getCurrentFrame().draw(x, y, width, height);
        }
    }
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Tendie Meter: ", ofGetWidth() / 2 + 75, 50);

    for (unsigned int i = 0; i < health; i++)
    {
        ofDrawCircle(ofGetWidth() / 2 + 25 * i + 200, 50, 10);
    }
    ofDrawBitmapString("Good Boy Points:" + to_string(score), ofGetWidth() / 2 - 200, 50);
    ofSetColor(256, 256, 256);
    for (Entity *ghost : em->ghosts)
    {
        PeekABooGhost *peek = dynamic_cast<PeekABooGhost *>(ghost);
        if (peek == NULL)
        {
            ghost->render();
        }
        if (peek != NULL)
        {
            if ((abs(peek->getx() - this->x) <= 200) && (abs(peek->gety() - this->y) <= 200))
            {
                peek->render();
            }
        }
    }
}

void Player::keyPressed(int key)
{
    if (em->entities.size() == 0 && wincounter >= 1)
    {
        key = 'y';
    }
    switch (key)
    {
    case 'w':
        setFacing(UP);
        break;
    case 's':
        setFacing(DOWN);
        break;
    case 'a':
        setFacing(LEFT);
        break;
    case 'd':
        setFacing(RIGHT);
        break;
    case 'n':
        die();
        break;
    case 'm':
        if (getHealth() >= 3)
        {
        }
        else
        {
            health++;
        }
        break;
    case 'k':
        health--;
        break;
    case 'y':
        //setWinState();
        break;
    case 'c':
        clearem();
        break;
    case 'r':
        spawnRandomGhost();
        break;
    case ' ':
        if (randomPowerUp->getHasEaten() == true && invisiblePowerUp->getHasEaten() == true)
        {
            invisiblePowerUp->setactive(true);
            randomPowerUp->setHasEaten(false);
        }
        if (randomPowerUp->getHasEaten() == true)
        {
            randomPowerUp->setactive(true);
        }
        if (invisiblePowerUp->getHasEaten() == true)
        {
            invisiblePowerUp->setactive(true);
        }
        break;
    case '1':
        setScore(score + 1000);
        break;
    }
}

void Player::keyReleased(int key)
{
    if (key == 'w' || key == 's' || key == 'a' || key == 'd')
    {
        walking = false;
    }
    if (key == ' ' || key == 32)
    {
        PO.setactive();
    }
}
void Player::mousePressed(int x, int y, int button)
{
}

void Player::setFacing(FACING facing)
{
    this->facing = facing;
}

int Player::getHealth()
{
    return health;
}

void Player::setHealth(int h)
{
    health = h;
}
int Player::getScore()
{
    return score;
}

void Player::setScore(int h)
{
    score = h;
}

void Player::checkCollisions()
{
    for (BoundBlock *BoundBlock : em->BoundBlocks)
    {
        switch (facing)
        {
        case UP:
            if (this->getBounds(x, y - speed).intersects(BoundBlock->getBounds()))
            {
                canMove = false;
            }
            break;
        case DOWN:
            if (this->getBounds(x, y + speed).intersects(BoundBlock->getBounds()))
            {
                canMove = false;
            }
            break;
        case LEFT:
            if (this->getBounds(x - speed, y).intersects(BoundBlock->getBounds()))
            {
                canMove = false;
            }
            break;
        case RIGHT:
            if (this->getBounds(x + speed, y).intersects(BoundBlock->getBounds()))
            {
                canMove = false;
            }
            break;
        }
    }
    for (Entity *entity : em->entities)
    {
        if (collides(entity))
        {
            if (dynamic_cast<Dot *>(entity) || dynamic_cast<BigDot *>(entity))
            {
                entity->remove = true;
                score += 10;
            }
            if (dynamic_cast<BigDot *>(entity))
            {
                score += 10;
                em->setKillable(true);
            }
        }
    }
    for (Entity *entity : em->ghosts)
    {
        if (invisiblePowerUp->getactive() != true)
        {
            if (collides(entity))
            {
                Ghost *ghost = dynamic_cast<Ghost *>(entity);
                RandomGhost *rdg = dynamic_cast<RandomGhost *>(entity);
                PeekABooGhost *pbg = dynamic_cast<PeekABooGhost *>(entity);
                if (ghost->getKillable())
                {
                    ghost->remove = true;
                    if (rdg != NULL)
                    {
                        rdgcounter = 0;
                        randomPowerUp->setHasEaten(true);
                    }
                    if (pbg != NULL)
                    {
                        peekABooGhostCounter = 0;
                        invisiblePowerUp->setHasEaten(true);
                    }
                }
                else
                {
                    die();
                }
            }
        }
    }
}

void Player::die()
{
    health--;
    x = spawnX;
    y = spawnY;
}

void Player::setWinState(bool win)
{
    this->win.setwin(win);
}

void Player::clearem()
{
    em->entities.clear();
}

WinState Player::getwinstate()
{
    return win;
}

void Player::spawnRandomGhost()
{
    if (score >= 500 && rdgcounter == 0)
    {
        int randomindex = ofRandom(0, em->entities.size());
        do
        {
            if (abs(this->x - em->entities[randomindex]->getx()) >= 30 && abs(this->y - em->entities[randomindex]->gety()) >= 30 && rdgcounter == 0)
            {
                randomGhost = new RandomGhost(em->entities[randomindex]->getx(), em->entities[randomindex]->gety(), 14, 14, sprite, em, "yes");
                em->ghosts.push_back(randomGhost);
                em->entities[randomindex]->remove = true;
                rdgcounter++;
                return;
            }
        } while ((abs(this->x - em->entities[randomindex]->getx()) >= 30 || abs(this->y - em->entities[randomindex]->gety()) >= 30) == false);
    }
}

void Player ::teleportPlayer()
{
    if (randomPowerUp->getHasEaten() == true && randomPowerUp->getactive() == true)
    {
        int randomCoordinateIndex = ofRandom(0, em->entities.size());
        this->x = em->entities[randomCoordinateIndex]->getx();
        this->y = em->entities[randomCoordinateIndex]->gety();
        randomPowerUp->setactive(false);
        randomPowerUp->setHasEaten(false);
    }
}

EntityManager *Player::getem()
{
    return em;
}

int Player::getx()
{
    return x;
}

int Player::gety()
{
    return y;
}

void Player::checkCoordinates()
{
    if (previousCoordinatesX != this->x || previousCoordinatesY != this->y)
    {
        previousCoordinatesX = this->x;
        previousCoordinatesY = this->y;
        if (invisiblePowerUp->getactive() == true)
        {
            coordinateShiftCounter++;
        }
    }
    if (coordinateShiftCounter > 200)
    {
        invisiblePowerUp->setHasEaten(false);
        invisiblePowerUp->setactive(false);
        coordinateShiftCounter = 0;
    }
}

Player ::~Player()
{
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}