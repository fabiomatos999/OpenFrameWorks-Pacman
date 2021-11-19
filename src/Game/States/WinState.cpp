#include "WinState.h"
#include "Map.h"


bool WinState::getwin()
{
    return win;
}

void WinState::setwin(bool tf)
{
    win = tf;
    setFinished(true);
}

void WinState::tick()
{

}

void WinState::render()
{
    ofSetColor(256,256,256);
    tendie.loadImage("images/tendie.jpg");
    tendie.draw(ofGetWidth()/2 - 100, ofGetHeight()/2);
    ofDrawBitmapString("UwU you Won", ofGetWidth()/2, ofGetHeight()/2 -300);
    ofDrawBitmapString("Here you go king, your forbindden chicken tendie", ofGetWidth()/2 - 100, ofGetHeight()/2 -50);
    ofSetBackgroundColor(0,0,0);
    ofSetColor(256,256,256);
}

void WinState::reset()
{
    setFinished(false);
    setNextState("Menu");
}

void WinState::keyPressed(int key)
{
    if(getwin()==true)
    {
        key = 'y';
    }

}

void WinState::mousePressed(int x, int y, int button)
{

}

WinState::~WinState()
{

}