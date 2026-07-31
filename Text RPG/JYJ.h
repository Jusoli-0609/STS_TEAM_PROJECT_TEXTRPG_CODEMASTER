#pragma once
#include "Player.h"

class JYJ : public Player
{
public:
    JYJ(const std::string& name);

    void attack(Monster* monster) override;
};