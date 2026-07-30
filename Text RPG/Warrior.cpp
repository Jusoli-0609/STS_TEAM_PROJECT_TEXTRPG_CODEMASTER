#include "Warrior.h"
#include <string>
#include <iostream>

Warrior::Warrior(std::string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    job = "전사";
    this->defence += 30;
}

void Warrior::attack()
{
    std::cout << name << "이(가) 검을 휘두른다!" << std::endl;
}