#include <iostream>

#include "JYJ.h"

JYJ::JYJ(const std::string& name)
	: Player(name)
{
	job = "풍둔 주둥아리술 마스터";

	// JYJ 초기 스탯
	hp = 200;
	mp = 100;
	atk = 30;
	def = 10;
	ap = 100;
	sne = 5;
	agi = 10;
}

void JYJ::Attack(Monster* monster)
{
	if (monster == nullptr)
	{
		std::cout << "공격할 대상이 없습니다.\n";
		return;
	}

	int damage = atk;

	std::cout << name << "의 기본 공격!\n";
	std::cout << "평타 대사 입력\n";

	// 몬스터 코드 완성 후 피해 처리
	// monster->Set_Hp(monster->Get_Hp() - damage);

	std::cout << damage << "의 피해를 입혔습니다.\n";
}

void JYJ::Skill1(Monster* monster)
{
	const int mpCost = 10;

	if (mp < mpCost)
	{
		std::cout << "MP가 부족합니다.\n";
		return;
	}

	if (monster == nullptr)
	{
		std::cout << "스킬을 사용할 대상이 없습니다.\n";
		return;
	}

	mp -= mpCost;

	int damage = ap;

	std::cout << name << "의 스킬 1!\n";
	std::cout << "스킬 1 대사 입력\n";

	// 스킬 1 효과
	// monster->Set_Hp(monster->Get_Hp() - damage);

	std::cout << damage << "의 피해를 입혔습니다.\n";
}

void JYJ::Skill2(Monster* monster)
{
	const int mpCost = 20;

	if (mp < mpCost)
	{
		std::cout << "MP가 부족합니다.\n";
		return;
	}

	mp -= mpCost;

	std::cout << name << "의 스킬 2!\n";
	std::cout << "스킬 2 대사 입력\n";

	// 자기 버프 예시
	int buffAmount = 10;

	ap += buffAmount;

	std::cout << "AP가 "
		<< buffAmount
		<< " 증가했습니다.\n";

	// 자기 버프라서 monster는 현재 사용하지 않음
}

void JYJ::Skill3(Monster* monster)
{
	const int mpCost = 30;

	if (mp < mpCost)
	{
		std::cout << "MP가 부족합니다.\n";
		return;
	}

	if (monster == nullptr)
	{
		std::cout << "스킬을 사용할 대상이 없습니다.\n";
		return;
	}

	mp -= mpCost;

	int damage = ap * 2;

	std::cout << name << "의 스킬 3!\n";
	std::cout << "스킬 3 대사 입력\n";

	// 스킬 3 효과
	// monster->Set_Hp(monster->Get_Hp() - damage);

	std::cout << damage << "의 피해를 입혔습니다.\n";
}

void JYJ::Groggy_Attack(Monster* monster)
{
	if (monster == nullptr)
	{
		std::cout << "공격할 대상이 없습니다.\n";
		return;
	}

	int damage = atk + ap;

	std::cout << name << "의 그로기 공격!\n";
	std::cout << "그로기 공격 대사 입력\n";

	// 몬스터 코드 완성 후 피해 처리
	// monster->Set_Hp(monster->Get_Hp() - damage);

	std::cout << damage << "의 피해를 입혔습니다.\n";
}