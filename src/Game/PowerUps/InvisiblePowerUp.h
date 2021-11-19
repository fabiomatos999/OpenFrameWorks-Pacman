#pragma once
#include "PowerUp.h"
#include "ofMain.h"

class InvisiblePowerUp : public PowerUp
{
    private:
    bool active = false;
    double activeTime;
    bool hasEaten = false;
    std::string name = "";
    std::string PowerUpname();

    public:
    void setactive(bool active); 
    InvisiblePowerUp();
    ~InvisiblePowerUp();
    bool getHasEaten();
    void setHasEaten(bool eaten); 
    bool getactive();   
};