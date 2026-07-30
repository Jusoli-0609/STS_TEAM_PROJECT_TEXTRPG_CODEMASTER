#include "Battle.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

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

	// 난수 초기화는 게임 실행 중 한 번만 진행함
	static bool is_Random_Seeded = false;

	if (!is_Random_Seeded)
	{
		srand
		(
			static_cast<unsigned int>
			(
				time(nullptr)
			)
		);

		is_Random_Seeded = true;
	}

	cout << "[전투 시작!] "
		<< player->getName()
		<< " vs "
		<< monster.getName()
		<< endl;

	while
	(
		player->getHp() > 0
		&& monster.getHP() > 0
	)
	{
		// 플레이어 턴
		cout << endl;
		cout << "--- 플레이어 턴 ---"
			<< endl;

		player->attack();

		// 1부터 100까지의 회피 판정값 생성
		int evasion_Roll =
			rand() % 100 + 1;

		bool is_Monster_Evaded =
			evasion_Roll
			<= monster.getEvasion();

		if (is_Monster_Evaded)
		{
			cout << monster.getName()
				<< "이(가) 공격을 회피했습니다!"
				<< endl;

			cout << "회피 판정값: "
				<< evasion_Roll
				<< " / 회피율: "
				<< monster.getEvasion()
				<< "%"
				<< endl;
		}
		else
		{
			cout << "공격 적중 판정값: "
				<< evasion_Roll
				<< " / 회피율: "
				<< monster.getEvasion()
				<< "%"
				<< endl;

			int before_Monster_HP =
				monster.getHP();

			int player_Power =
				player->getPower();

			int monster_Defence =
				monster.getDefence();

			int damage =
				player_Power
				- monster_Defence;

			if (damage <= 0)
			{
				damage = 1;
			}

			cout << monster.getName()
				<< "에게 "
				<< damage
				<< " 데미지!"
				<< endl;

			monster.setHP
			(
				before_Monster_HP
				- damage
			);

			cout << monster.getName()
				<< " HP: "
				<< before_Monster_HP
				<< " -> "
				<< monster.getHP();

			if (monster.getHP() <= 0)
			{
				cout << " (사망)"
					<< endl
					<< endl;

				cout << "★ 전투 승리!"
					<< endl;

				cout << " -> "
					<< monster.getDropItemName()
					<< " 획득!"
					<< endl;

				cout << " (인벤토리에 저장됩니다)"
					<< endl;

				Item dropped_Item{};

				dropped_Item.name =
					monster.getDropItemName();

				dropped_Item.price =
					monster.getDropItemPrice();

				inventory.AddItem
				(
					dropped_Item
				);
				break;
			}

			cout << endl;
		}

		// 몬스터 턴
		cout << endl;
		cout << "--- 몬스터 턴 ---"
			<< endl;

		monster.attack(player);

		int before_Player_HP =
			player->getHp();

		int monster_Power =
			monster.getPower();

		int player_Defence =
			player->getDefence();

		int monster_Damage =
			monster_Power
			- player_Defence;

		if (monster_Damage <= 0)
		{
			monster_Damage = 1;
		}

		player->setHp
		(
			before_Player_HP
			- monster_Damage
		);

		cout << "플레이어 HP: "
			<< before_Player_HP
			<< " -> "
			<< player->getHp()
			<< endl;

		if (player->getHp() <= 0)
		{
			cout << "플레이어가 쓰러졌습니다."
				<< endl;

			cout << "★ 전투 패배!"
				<< endl;

			break;
		}
	}
}
