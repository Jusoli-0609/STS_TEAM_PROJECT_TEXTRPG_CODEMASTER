#include "Battle_System.h"
#include "Item.h"
#include <iostream>

using namespace std;

//======================================================
// 전투 시작
//======================================================

void Battle(Player* player, Monster& monster, Inventory<Item>& inventory)
{

    if (player == nullptr)
    {
        return;
    }

    Show_Battle_Start(player, monster);

    while (true)
    {
        Show_Battle_Status(player, monster);

        Player_Turn(player, monster, inventory);

        if (Check_Battle_End(player, monster, inventory))
        {
            break;
        }

        Monster_Turn(player, monster);

        if (Check_Battle_End(player, monster, inventory))
        {
            break;
        }
    }

    Show_Battle_End(player, monster);
}

//======================================================
// UI (UI 담당)
//======================================================

void Show_Battle_Start(Player* player, Monster& monster)
{
    // UI 전투 시작
}

void Show_Battle_Status(Player* player, Monster& monster)
{
    // UI 전투 기록
}

void Show_Battle_Menu()
{
    // UI 선택지

    cout << endl;
    cout << "==============================" << endl;
    cout << "        플레이어 턴" << endl;
    cout << "==============================" << endl;
    cout << "1. 공격" << endl;
    cout << "2. 스킬" << endl;
    cout << "3. 아이템" << endl;
    cout << "==============================" << endl;
    cout << "선택 : ";
}

void Show_Battle_End(Player* player, Monster& monster)
{
    // UI 전투 종료
}

//======================================================
// 플레이어 턴
//======================================================

void Player_Turn(Player* player, Monster& monster, Inventory<Item>& inventory)
{
    //플레이어 차례 (JRPG 턴 개념)

    int menu;

    Show_Battle_Menu();

    cin >> menu;

    switch (menu)
    {
    case ATTACK:
    {
        Attack(player, monster);
        break;
    }

    case SKILL:
    {
        Skill(player, monster);
        break;
    }

    case ITEM:
    {
        Use_Item(player, inventory);
        break;
    }



    default:
    {
        cout << "잘못된 입력입니다." << endl;
        break;
    }
    }
}

void Use_Item(Player* player, Inventory<Item>& inventory)
{
    // 인벤토리 아이템

    cout << "아이템 기능 준비 중입니다." << endl;
}

//======================================================
// 플레이어 공격
//======================================================

void Attack(Player* player, Monster& monster)
{

    int Before_Monster_HP = monster.getHP();

    int Damage = player->Get_ATK() - monster.getDefence();

    if (Damage < 1)
    {
        Damage = 1;
    }

    monster.setHP(Before_Monster_HP - Damage);

    cout << endl;
    cout << "공격!" << endl;

    cout << monster.getName()
        << "에게 "
        << Damage
        << " 데미지!" << endl;

    cout << monster.getName()
        << " HP : "
        << Before_Monster_HP
        << " -> "
        << monster.getHP()
        << endl;
}

//======================================================
// 플레이어 스킬
//======================================================

void Skill(Player* player, Monster& monster)
{
    // 직업 스킬
}

//======================================================
// 몬스터 턴
//======================================================

void Monster_Turn(Player* player, Monster& monster)
{
    // 몬스터 차례

    cout << endl;
    cout << "------ 몬스터 턴 ------" << endl;

    // TODO : 몬스터 행동 패턴
    Monster_Attack(player, monster);


}

//======================================================
// 몬스터 공격
//======================================================

void Monster_Attack(Player* player, Monster& monster)
{
    int Before_Player_HP = player->Get_Hp();

    int Damage = monster.getPower() - player->Get_DEF();

    if (Damage < 1)
    {
        Damage = 1;
    }

    player->Set_Hp(Before_Player_HP - Damage);

    cout << monster.getName()
        << "의 공격!" << endl;

    cout << "플레이어 HP : "
        << Before_Player_HP
        << " -> "
        << player->Get_Hp()
        << endl;
}


//======================================================
// 몬스터 스킬
//======================================================

void Monster_Skill(Player* player, Monster& monster)
{
    // TODO : 몬스터 담당

    cout << monster.getName()
        << "이(가) 특수 스킬을 사용했다!" << endl;
}

//======================================================
// 전투 종료
//======================================================

bool Check_Battle_End(Player* player, Monster& monster, Inventory<Item>& inventory)
{
    if (monster.getHP() <= 0)
    {
        cout << endl;
        cout << "전투 승리!" << endl;
        cout << monster.getDropItemName() << " 획득!" << endl;

        return true;
    }

    if (player->Get_Hp() <= 0)
    {
        cout << endl;
        cout << "전투 패배!" << endl;

        return true;
    }

    return false;
}