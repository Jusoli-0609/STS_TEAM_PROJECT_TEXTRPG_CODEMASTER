#include "Battle.h"
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

    while (player->getHp() > 0 && monster.getHP() > 0)
    {

        cout << "--- 플레이어 턴 ---" << endl;
        cout << "공격한다!" << endl;

        int beforeMonsterHP = monster.getHP();
        int playerPower = player->getPower();
        int monsterDefence = monster.getDefence();
        int damage = playerPower - monsterDefence;

        if (damage <= 0)
        {
            damage = 1;
        }

        cout << monster.getName() << "에게 " << damage << " 데미지!" << endl;

        int afterMonsterHP = beforeMonsterHP - damage;
        monster.setHP(afterMonsterHP);

        cout << monster.getName() << " HP: "
            << beforeMonsterHP << " -> "
            << monster.getHP();

        if (monster.getHP() <= 0)
        {
            cout << " (사망)" << endl << endl;

            cout << "★ 전투 승리!" << endl;
            cout << " -> " << monster.getDropItemName() << " 획득!" << endl;
            cout << " (인벤토리에 저장됩니다)" << endl;

            Item droppedItem;
            droppedItem.name = monster.getDropItemName();
            droppedItem.price = monster.getDropItemPrice();
            inventory.AddItem(droppedItem);
            break;
        }

        cout << endl;

        cout << "--- 몬스터 턴 ---" << endl;

        int beforePlayerHP = player->getHp();
        int monsterPower = monster.getPower();
        int playerDefence = player->getDefence();

        int monsterDamage = monsterPower - playerDefence;

        if (monsterDamage <= 0)
        {
            monsterDamage = 1;
        }

        player->setHp(player->getHp() - monsterDamage);

        cout << "플레이어 HP: "
            << beforePlayerHP << " -> "
            << player->getHp() << endl;

        if (player->getHp() <= 0)
        {
            cout << "플레이어가 쓰러졌습니다." << endl;
            cout << "★ 전투 패배!" << endl;
            break;
        }
    }
}
