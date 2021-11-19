#include "PauseState.h"

PauseState::PauseState()
{
    quitbutton = new Button(ofGetWidth() / 2, ofGetHeight() / 2 -100, 64, 50, "Quit");
    resumebutton = new Button(ofGetWidth() / 2, ofGetHeight() / 2 - 200, 64, 50, "Resume");
    betty.loadImage("images/download(scaled).jpeg");
}

void PauseState::tick()
{
    quitbutton->tick();
    resumebutton->tick();
    if (resumebutton->wasPressed() == true)
    {
        setNextState("Game");
        setFinished(true);
    }
    if (quitbutton->wasPressed() == true)
    {
        setNextState("over");
        setFinished(true);
        sethasQuit(true);
    }
}

void PauseState::reset()
{
    setFinished(false);
    setNextState("");
    quitbutton->reset();
    resumebutton->reset();
    sethasQuit(false);
}

void PauseState::render()
{
    quitbutton->render();
    resumebutton->render();
    ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
    betty.draw(ofGetWidth()/2 - 200,ofGetHeight()/2 - 200);
}

void PauseState::mousePressed(int x, int y, int button)
{
    quitbutton->mousePressed(x, y);
    resumebutton->mousePressed(x, y);
}

void PauseState::keyPressed(int key)
{
}

bool PauseState::gethasQuit()
{
    return hasQuit;
}

void PauseState::sethasQuit(bool quit)
{
    this->hasQuit = quit;
}

PauseState::~PauseState()
{
}