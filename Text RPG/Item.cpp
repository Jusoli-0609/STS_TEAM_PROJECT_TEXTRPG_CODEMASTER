#include <iostream>
#include <string>
#include <algorithm>

#include "Item.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

void Item::Print_Info() const
{
    cout << "아이템 이름: "
        << _Item_Name << ", 가격: "
        << _Item_Price << ", 갯수:"
        << _Item_Count << ", 갯수당 무게: "
        << _Item_Weight << endl;
}

bool Item::Item_Effect(Player& player, Monster& monster)
{
    if (_Item_Name == "HP 포션")
    {
        player.Set_Hp(min(player.Get_Hp() + 300, player.Get_Max_Hp()));

        cout << "체력을 회복해 현재 체력은 "
            << player.Get_Hp()
            << "입니다."
            << endl;

        return true;
    }
    else if (_Item_Name == "MP 포션")
    {
        player.Set_Mp(min(player.Get_Mp() + 300, player.Get_Max_Mp()));

        cout << "마나를 회복해 현재 마나는 "
            << player.Get_Mp()
            << "입니다."
            << endl;

        return true;
    }

    return false;
}