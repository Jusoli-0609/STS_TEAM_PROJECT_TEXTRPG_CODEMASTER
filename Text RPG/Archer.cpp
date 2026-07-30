#include "Archer.h"
#include <string>
#include <iostream>

Archer::Archer(std::string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    job = "궁수";
    this->hp += 30;
}

void Archer::attack()
{
    std::cout << name << "이(가) 화살을 발사한다!" << std::endl;
}