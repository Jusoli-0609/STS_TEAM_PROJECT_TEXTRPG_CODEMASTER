#pragma once
#include "Player.h"	

class Archer : public Player
{
public:
    Archer(std::string name, int hp, int mp, int power, int defence);

    void attack() override;
};