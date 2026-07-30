#include "Battle_System.h"
#include <iostream>

using namespace std;

void Battle(Player* player, Monster& monster, Inventory& inventory)
{

    if (player == nullptr)
    {
        cout << "플레이어 정보가 없습니다." << endl;
        return;
    }

    cout << "[전투 시작!] "
        << player->getName()
        << "(" << player->getJob() << ") vs "
        << monster.getName()
        << endl;

    while (true)
    {
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
}

void Show_Battle_Menu()
{
    // 나중에 UI 디자인 정해지면 변경예정

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

void Player_Turn(Player* player, Monster& monster, Inventory& inventory)
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
        cout << "아이템 기능은 준비 중입니다." << endl;
        break;
    }

    default:
    {
        cout << "잘못된 입력입니다." << endl;
        break;
    }
    }
}

void Attack(Player* player, Monster& monster)
{
    //플레이어 공격

    cout << endl;
    cout << "공격!" << endl;

    int Before_Monster_HP = monster.getHP();

    int Damage = player->getPower() - monster.getDefence();

    if (Damage < 1)
    {
        Damage = 1;
    }

    monster.setHP(Before_Monster_HP - Damage);
    
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

void Skill(Player* player, Monster& monster)
{
    //플레이어 스킬 (아직 확정아님 의견 필요)

    cout << endl;
    cout << "======================" << endl;
    cout << "스킬 시스템 (임시)" << endl;
    cout << "======================" << endl;

    cout << "준비 중입니다." << endl;
}

void Monster_Turn(Player* player, Monster& monster) 
{
    // 몬스터 차례

    cout << endl;
    cout << "------ 몬스터 턴 ------" << endl;


    //몬스터 기믹 발동 조건
    
    int before_Player_HP = player->getHp();

    int Damage = monster.getPower() - player->getDefence();

    if (Damage < 1)
    {
        Damage = 1;
    }

    player->setHp(before_Player_HP - Damage);

    cout << monster.getName()
        << "의 공격!" << endl;

    cout << "플레이어 HP : "
        << before_Player_HP
        << " -> "
        << player->getHp()
        << endl;
}

bool Check_Battle_End(Player* player, Monster& monster, Inventory& inventory)
{
    // 전투 확인 (아직 임시로 만듬)
    if (monster.getHP() <= 0)
    {
        cout << endl;
        cout << "★ 전투 승리!" << endl;
        cout << monster.getDropItemName() << " 획득!" << endl;

        Item droppedItem;
        droppedItem.name = monster.getDropItemName();
        droppedItem.price = monster.getDropItemPrice();

        inventory.AddItem(droppedItem);

        return true;
    }

    if (player->getHp() <= 0)
    {
        cout << endl;
        cout << "★ 전투 패배!" << endl;

        return true;
    }

    return false;
} 