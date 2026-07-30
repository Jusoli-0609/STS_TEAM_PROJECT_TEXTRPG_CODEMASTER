#pragma once
#include <string>

class Player
{
protected:
	std::string name;
	std::string job;
	int level;
	int hp;
	int mp;
	int power;
	int defence;

public:
	Player(std::string name, int hp, int mp, int power, int defence);		//==이름표와 능력치표를 받아서 캐릭터를 만들어 주세요

	std::string getName();
	std::string getJob();
	int getLevel();
	int getHp();
	int getMp();
	int getPower();
	int getDefence();
	
	void setName(std::string);
	void setJob(std::string);
	void setHp(int hp);
	void setMp(int mp);
	void setPower(int power);
	void setDefence(int defence);

	void printPlayerStatus();
	void levelUp();

	virtual void attack() = 0;
	virtual ~Player() = default;
};