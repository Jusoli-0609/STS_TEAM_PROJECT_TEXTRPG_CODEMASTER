#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

Monster::Monster
(
    string monstername,
    int monsterhp,
    int monsterpower,
    int monsterdefence,
    string dropitemname,
    int dropitemprice
)
{
    this->monstername = monstername;
    this->monsterhp = monsterhp;
    this->monsterpower = monsterpower;
    this->monsterdefence = monsterdefence;
    this->dropitemname = dropitemname;
    this->dropitemprice = dropitemprice;
}

string Monster::getName()
{
    return monstername;
}

void Monster::attack(Player* player)
{
    cout << monstername << "이(가) 공격합니다!" << endl;
}

void Monster::setHP(int hp)
{
    monsterhp = hp;
}

int Monster::getHP()
{
    return monsterhp;
}

int Monster::getDefence()
{
    return monsterdefence;
}

std::string Monster::getDropItemName()
{
    return dropitemname;
}

int Monster::getPower()
{
    return monsterpower;
}

int Monster::getDropItemPrice()
{
    return dropitemprice;
}