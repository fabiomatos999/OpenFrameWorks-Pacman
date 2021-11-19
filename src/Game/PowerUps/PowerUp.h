#pragma once
#include <iostream>
#include <string>
class PowerUp
{
    private:
    bool active = false;
    double activeTime;
    std::string name = "";
    std::string PowerUpname();

    public:
    PowerUp(){}
    void setPowerUpname(std::string name)
    {
        this->name = name;
    }
    std::string getPowerUpname()
    {
        return PowerUpname();
    }
    virtual bool getactive();
    virtual void setactive();
    int counter=0;
    void keyPressed(int); 
};