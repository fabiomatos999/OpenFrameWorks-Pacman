#include <iostream>
#include "PowerUp.h"

std::string dummy = "dummy";

void PowerUp::setactive()
{
    if(active == true)
    {
        setPowerUpname("");
        active = false;
        std::cout << active << std::endl;
    }
    active = true;
    std::cout << active << std::endl;
    setPowerUpname(name);
}

bool PowerUp::getactive()
{
    return active;
}
void PowerUp::keyPressed(int key)
{
    if(key == ' ' || key == 32)
    {
        setactive();
        std::cout << getactive() << std::endl;
        std::cout << "\n";
    }
}