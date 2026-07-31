#include "Warrior.h"
#include <string>
#include <iostream>

Warrior::Warrior(std::string name, const int stat[])
    : Player(name, stat)
{
    job = "전사";
    def += 30;
}

void Warrior::attack()
{
    std::cout << name << "이(가) 검을 휘두른다!" << std::endl;
}