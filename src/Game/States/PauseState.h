#pragma once
#include "ofMain.h"
#include "State.h"
#include "Button.h"


class PauseState : public State
{
private:
    Button *quitbutton;
    Button *resumebutton;
    bool hasQuit = false;
    ofImage betty;

public:
    PauseState();
    ~PauseState();
    void reset();
    void tick();
    void render();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    bool gethasQuit();
    void sethasQuit(bool quit);
};