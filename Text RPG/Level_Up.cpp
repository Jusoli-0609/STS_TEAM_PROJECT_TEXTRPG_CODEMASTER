#include "Level_Up.h"
#include "Player.h"
#include <iostream>

using namespace std;

// 1. _stat_points 초기화 추가
Level_Up::Level_Up()
	: _current_level(1), _current_exp(0), _max_exp(100), _stat_points(0)
{
}

// 2. 소멸자 구현부 추가 (★ 이 부분이 없어서 LNK 오류가 난 것)
Level_Up::~Level_Up()
{
}

int Level_Up::GetCurrentLevel() const
{
	return _current_level;
}

int Level_Up::GetCurrentExp() const
{
	return _current_exp;
}

int Level_Up::GetMaxExp() const
{
	return _max_exp;
}

void Level_Up::GainExp(Player* player, int amount)
{
	if (player == nullptr || amount <= 0) return;

	_current_exp += amount;
	cout << "-> 경험치 +" << amount << " 획득! (현재 경험치: " << _current_exp << " / " << _max_exp << ")\n";

	while (_current_exp >= _max_exp && _max_exp > 0)
	{
		LevelUpProcess(player);
	}
}

void Level_Up::LevelUpProcess(Player* player)
{
	if (player == nullptr) return;

	_current_exp -= _max_exp;

	int prevLevel = _current_level;
	_current_level++;

	_max_exp = static_cast<int>(_max_exp * 1.5);

	int hpBonus = 20;
	int mpBonus = 10;
	int powerBonus = 5;
	int defenceBonus = 3;

	player->setHp(player->getHp() + hpBonus);
	player->setMp(player->getMp() + mpBonus);
	player->setPower(player->getPower() + powerBonus);
	player->setDefence(player->getDefence() + defenceBonus);

	cout << "\n★====================================★\n";
	cout << "  [ 레벨 업! ] Lv." << prevLevel << " -> Lv." << _current_level << "\n";
	cout << "  HP +" << hpBonus << ", MP +" << mpBonus
		<< ", 공격력 +" << powerBonus << ", 방어력 +" << defenceBonus << " 상승!\n";
	cout << "★====================================★\n\n";
}