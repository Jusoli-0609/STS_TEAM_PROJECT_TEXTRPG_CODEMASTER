#include "Magician.h"
#include <string>
#include <iostream>

Magician::Magician(std::string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    job = "마법사";
    this->mp += 30;
}

void Magician::attack()
{
    std::cout << name << "이(가) 파이어볼을 발사한다!" << std::endl;
}