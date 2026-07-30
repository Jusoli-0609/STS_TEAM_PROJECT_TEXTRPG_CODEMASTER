#include "Thief.h"
#include <string>
#include <iostream>

Thief::Thief(std::string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    job = "도적";
    this->power += 30;
}

void Thief::attack()
{
    std::cout << name << "이(가) 표창을 던진다!" << std::endl;
}