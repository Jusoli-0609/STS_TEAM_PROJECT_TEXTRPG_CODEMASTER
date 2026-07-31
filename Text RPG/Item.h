#pragma once
#include <string>
#include <iostream>

class Player;
class Monster;
class Item
{
public:
    std::string _Item_Name;
    int _Item_Price;
    int _Item_Count;
    int _Item_Weight;
    bool _Item_Type_Usable;
    bool _Item_Type_Wearable;

    void Print_Info() const;
    bool Item_Effect(Player& player, Monster& monster);
};

