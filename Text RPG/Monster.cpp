#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

// 🌟 매개변수 맨 뒤에 int expReward 추가!
Monster::Monster
(
	string monstername,
	int monsterhp,
	int monsterpower,
	int monsterdefence,
	string dropitemname,
	int dropitemprice,
	int expReward
)
	: monstername(monstername),
	monsterhp(monsterhp),
	monsterpower(monsterpower),
	monsterdefence(monsterdefence),
	dropitemname(dropitemname),
	dropitemprice(dropitemprice),
	_exp_reward(expReward) // 🌟 멤버 변수 _exp_reward 초기화
{
}

string Monster::getName() { return monstername; }
int Monster::getHP() { return monsterhp; }
int Monster::getPower() { return monsterpower; }
int Monster::getDefence() { return monsterdefence; }
string Monster::getDropItemName() { return dropitemname; }
int Monster::getDropItemPrice() { return dropitemprice; }

int Monster::getExpReward()
{
	return _exp_reward;
}

void Monster::setHP(int hp)
{
	this->monsterhp = hp;
}

void Monster::attack(Player* player)
{
	if (player == nullptr) return;

	int damage = monsterpower - player->getDefence();
	if (damage <= 0) damage = 1;

	int nextHp = player->getHp() - damage;
	player->setHp(nextHp);

	cout << monstername << "의 공격! " << player->getName() << "에게 " << damage << " 데미지!\n";
}