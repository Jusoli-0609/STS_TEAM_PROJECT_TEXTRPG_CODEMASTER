#pragma once
#include "Player.h"		//나는 Player를 기반으로 만들어진 클래스라는 선언

class Warrior : public Player
{
public:
    Warrior(std::string name, int hp, int mp, int power, int defence);

    void attack() override;
};