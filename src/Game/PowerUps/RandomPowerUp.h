#pragma once
#include "PowerUp.h"
#include "ofMain.h"

class RandomPowerUp : public PowerUp{
    private:
    bool active = false;
    double activeTime;
    bool hasEaten = false;
    std::string name = "";
    std::string PowerUpname();

    public:
    void setactive(bool active); 
    RandomPowerUp();
    ~RandomPowerUp();
    bool getHasEaten();
    void setHasEaten(bool eaten); 
    bool getactive();
};
