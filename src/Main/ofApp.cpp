#include "ofApp.h"
#include "Images.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetWindowTitle("Tendies Fun House");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	winState = new WinState();
	pauseState = new PauseState();
	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (currentState != nullptr)
	{
		currentState->tick();
		if (currentState->hasFinished())
		{
			if (currentState->getNextState() == "Menu")
			{
				currentState = menuState;
			}
			else if (currentState->getNextState() == "Game")
			{
				if (currentState == pauseState)
				{
					pauseState->reset();
				}
				if(currentState != pauseState)
				{
					gameState->reset();
				}
				currentState = gameState;
				
			}
			else if (currentState->getNextState() == "over")
			{
				if (currentState == pauseState)
				{
					pauseState->reset();
					gameState->reset();
				}
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
				gameOverState->reset();
			}
		}
		wstatewait = ofGetElapsedTimeMillis();
		if (currentState == winState && ifcounter == 0)
		{
			currenttime = ofGetElapsedTimeMillis();
			ifcounter++;
		}
		if (gameState->getmap()->getPlayer()->getwinstate().getwin() == true)
		{
			currentState = winState;
			if ((wstatewait - currenttime) > 4000 && ifcounter >= 1)
			{
				currentState->reset();
				menuState->reset();
				currentState = menuState;
				ifcounter = 0;
				gameState->getmap()->getPlayer()->setWinState(false);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (currentState != nullptr)
		currentState->keyPressed(key);
	if (key == 'y')
	{
		currentState = winState;
	}
	if (key == 'p')
	{
		currentState = pauseState;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (currentState != nullptr)
		currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (currentState != nullptr)
		currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
