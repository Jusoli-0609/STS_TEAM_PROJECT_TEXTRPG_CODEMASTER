#pragma once
#include <string>
#include <iostream>
#include "Level_Up.h" // 레벨업 컴포넌트

class Player
{
protected:
	std::string name;
	std::string job;
	int maxHp;
	int hp;
	int maxMp;
	int mp;
	int power;
	int defence;

	Level_Up levelSystem; // 레벨업 컴포넌트

public:
	Player(std::string name, int hp, int mp, int power, int defence);
	virtual ~Player() = default;

	// Getter / Setter
	std::string getName();
	std::string getJob();
	int getLevel();
	int getHp();
	int getMp();
	int getPower();
	int getDefence();

	void setName(std::string name);
	void setJob(std::string job);
	void setHp(int hp);
	void setMp(int mp);
	void setPower(int power);
	void setDefence(int defence);

	// 레벨업 및 경험치 획득
	void GainExp(int amount);
	void printPlayerStatus();

	virtual void attack() = 0;
};