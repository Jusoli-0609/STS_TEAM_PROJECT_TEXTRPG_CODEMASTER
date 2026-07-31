#include <iostream>
#include <string>

#include "Item.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

void Item::Print_Info() const
{
	std::cout << "아이템 이름: "
		<< _Item_Name << ", 가격: "
		<< _Item_Price << ", 갯수:"
		<< _Item_Count << ", 갯수당 무게: "
		<< _Item_Weight << endl;
}

bool Item::Item_Effect(Player& player, Monster& monster)
{
    if (_Item_Name == "HP 포션") // HP 포션 이름 비교 조건
    {
        player.Set_HP(min(player.GetHP() + 300, player.getMaxHP())); // HP 회복 처리 코드 위치
        cout << "체력  회복해 현재 체력은 " << player.getHP() << "입니다." << endl;
        ItemUsedSuccessful = true;
    }


    else if (_Item_Name == "MP 포션")     //  MP 포션 이름 비교 조건
    {
        player.setMP(min(player.getMP() + 300, player.getMaxMP()));  //  MP 회복 처리 코드 위치
        cout << "마나  회복해 현재 마나는 " << player.getMP() << "입니다." << endl;
        ItemUsedSuccessful = true;
    }
}