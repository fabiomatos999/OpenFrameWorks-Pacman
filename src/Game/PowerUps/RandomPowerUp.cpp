#include "RandomPowerUp.h"

RandomPowerUp :: RandomPowerUp(){}

bool RandomPowerUp :: getHasEaten(){
    return hasEaten;
}

void RandomPowerUp :: setHasEaten(bool eaten){
    this -> hasEaten = eaten;
}

void RandomPowerUp :: setactive(bool active){
    this-> active = active;
}
RandomPowerUp :: ~RandomPowerUp(){}

bool RandomPowerUp :: getactive(){
    return active;
}