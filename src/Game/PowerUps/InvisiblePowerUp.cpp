#include "InvisiblePowerUp.h"

InvisiblePowerUp::InvisiblePowerUp()
{

}

void InvisiblePowerUp::setactive(bool active)
{
    this->active = active;
}

bool InvisiblePowerUp::getHasEaten()
{
    return hasEaten;
}

void InvisiblePowerUp::setHasEaten(bool eaten)
{
    this-> hasEaten = eaten;
}

bool InvisiblePowerUp::getactive()
{
    return active;
}