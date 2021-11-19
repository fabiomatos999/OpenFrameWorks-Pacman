#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"
#include "EntityManager.h"
#include "ofMain.h"
#include "ofMain.h"

class WinState : public State
{
private:
    bool win = false;
public:
    ofImage tendie;
    WinState() {}
    ~WinState();
    void tick();
    void render();
    void reset();
    void setScore(int);
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    bool getwin();
    void setwin(bool tf);
   
};
