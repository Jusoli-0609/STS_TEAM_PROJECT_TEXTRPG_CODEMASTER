#pragma once
#include <string>

class Player;

class Monster
{
private:
    std::string monstername;
    int monsterhp;
    int monsterpower;
    int monsterdefence;
    std::string dropitemname;
    int dropitemprice;

public:
    Monster
    (
        std::string monstername,
        int monsterhp,
        int monsterpower,
        int monsterdefence,
        std::string dropitemname,
        int dropitemprice
    );

    std::string getName();
    int getHP();
    int getPower();
    int getDefence();
    std::string getDropItemName();
    int getDropItemPrice();

    void setHP(int hp);
    void attack(Player* player);
};