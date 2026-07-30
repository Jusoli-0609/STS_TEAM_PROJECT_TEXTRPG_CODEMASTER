#pragma once
#include <string>

class Player;

class Monster
{
private:
	std::string monstername;
	int monsterhp;
	int monsterpower;
	int monsterdefence;
	std::string dropitemname;
	int dropitemprice;

public:
	// 🌟 외부/Main.cpp 접근용 멤버 변수 (경험치 보상)
	int _exp_reward;

	// 생성자 (기본 경험치 보상 매개변수 expReward 추가, 기본값 30 지정)
	Monster
	(
		std::string monstername,
		int monsterhp,
		int monsterpower,
		int monsterdefence,
		std::string dropitemname,
		int dropitemprice,
		int expReward = 30
	);

	std::string getName();
	int getHP();
	int getPower();
	int getDefence();
	std::string getDropItemName();
	int getDropItemPrice();
	int getExpReward(); // 경험치 반환 Getter

	void setHP(int hp);
	void attack(Player* player);
};