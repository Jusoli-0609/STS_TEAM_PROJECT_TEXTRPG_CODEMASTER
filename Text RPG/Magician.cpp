#include "Magician.h"
#include <string>
#include <iostream>

Magician(std::string name, const int stat[])
    : Player(name, stat)
{
    job = "마법사";
    mp += 30;
}

void Magician::attack()
{
    std::cout << name << "이(가) 파이어볼을 발사한다!" << std::endl;
}