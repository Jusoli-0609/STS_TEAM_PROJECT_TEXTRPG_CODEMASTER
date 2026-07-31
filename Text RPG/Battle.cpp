#include "Battle.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include <cstdlib>
#include <iostream>

using namespace std;

namespace
{
	int Calculate_Damage
	(
		int attack,
		int defence
	)
	{
		int damage =
			attack - defence;

		if (damage < 1)
		{
			damage = 1;
		}

		return damage;
	}
}

void Battle
(
	Player* player,
	Monster& monster,
	Inventory& inventory
)
{
	if (player == nullptr)
	{
		cout << "플레이어 정보가 없습니다."
			<< endl;

		return;
	}
	(void)inventory;

	cout << "\n========================================\n";
	cout << "[ 전투 시작 ]\n";
	cout << player->getName()
		<< " VS "
		<< monster.getName()
		<< "\n";
	cout << "========================================\n";

	while
		(
			player->getHp() > 0
			&& monster.getHP() > 0
			)
	{
		cout << "\n--- 플레이어 턴 ---\n";

		int evasion_Roll =
			rand() % 100 + 1;

		if
			(
				evasion_Roll
				<= monster.getEvasion()
				)
		{
			cout << monster.getName()
				<< "이(가) 공격을 회피했습니다!\n";
		}
		else
		{
			int player_Damage =
				Calculate_Damage
				(
					player->getPower(),
					monster.getDefence()
				);

			int before_Monster_HP =
				monster.getHP();

			int after_Monster_HP =
				before_Monster_HP
				- player_Damage;

			if (after_Monster_HP < 0)
			{
				after_Monster_HP = 0;
			}
			monster.setHP
			(
				after_Monster_HP
			);

			cout << monster.getName()
				<< "에게 "
				<< player_Damage
				<< " 데미지!\n";

			cout << monster.getName()
				<< " HP: "
				<< before_Monster_HP
				<< " -> "
				<< after_Monster_HP;

			if (after_Monster_HP <= 0)
			{
				cout << " (사망)";
			}

			cout << "\n";
		}

		if (monster.getHP() <= 0)
		{
			break;
		}

		cout << "\n--- 몬스터 턴 ---\n";

		monster.Print_Attack_Message();

		int accuracy_Roll =
			rand() % 100 + 1;

		if
			(
				accuracy_Roll
			> monster.getAccuracy()
				)
		{
			cout << monster.getName()
				<< "의 공격이 빗나갔습니다!\n";
		}
		else
		{
			int monster_Damage =
				Calculate_Damage
				(
					monster.getPower(),
					player->getDefence()
				);

			int before_Player_HP =
				player->getHp();

			int after_Player_HP =
				before_Player_HP
				- monster_Damage;

			if (after_Player_HP < 0)
			{
				after_Player_HP = 0;
			}

			player->setHp
			(
				after_Player_HP
			);

			cout << player->getName()
				<< "에게 "
				<< monster_Damage
				<< " 데미지!\n";

			cout << player->getName()
				<< " HP: "
				<< before_Player_HP
				<< " -> "
				<< after_Player_HP;

			if (after_Player_HP <= 0)
			{
				cout << " (사망)";
			}

			cout << "\n";
		}
	}

	if
		(
			player->getHp() > 0
			&& monster.getHP() <= 0
			)
	{
		cout << "\n========================================\n";
		cout << "★ 전투 승리!\n";
		cout << monster.getName()
			<< "을(를) 처치했습니다.\n";
		cout << "========================================\n";

		monster.Generate_Drop_Reward();

		cout << "\n[ 몬스터 처치 보상 ]\n";

		cout << "획득 아이템: "
			<< monster.getDropItemName()
			<< " "
			<< monster.getDropItemCount()
			<< "개\n";

		cout << "훈련장려금: "
			<< monster.getGoldReward()
			<< " 원\n";

		cout << "처치 경험치: "
			<< monster.getExpReward()
			<< "\n";

		cout << "처치 점수: "
			<< monster.getScoreReward()
			<< "\n";
	}
	else
	{
		cout << "\n========================================\n";
		cout << "★ 전투 패배\n";
		cout << player->getName()
			<< "이(가) 쓰러졌습니다.\n";
		cout << "========================================\n";
	}
}