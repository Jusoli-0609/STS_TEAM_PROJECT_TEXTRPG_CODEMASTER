#include "Player.h"
#include <iostream>


using namespace std;

void PrintLine();

Player::Player(std::string name, int hp, int mp, int power, int defence)
{
	level = 1;
	this->name = name;
	this->hp = hp;
	this->mp = mp;
	this->power = power;
	this->defence = defence;
}		//생성자, 직업은 자식 클래스에서 초기화

string Player::getName()
{
	return name;
}

string Player::getJob()
{
	return job;
}

int Player::getHp()
{
	return hp;
}

int Player::getMp()
{
	return mp;
}

int Player::getPower()
{
	return power;
}

int Player::getDefence()
{
	return defence;
}

int Player::getLevel()
{
	return level;
}



void Player::setName(std::string name)
{
	this->name = name;
}

void Player::setJob(std::string job)
{
	this->job = job;
}

void Player::setHp(int hp)
{
	this->hp = hp;
}

void Player::setMp(int mp)
{
	this->mp = mp;
}

void Player::setPower(int power)
{
	this->power = power;
}

void Player::setDefence(int defence)
{
	this->defence = defence;
}

void Player::printPlayerStatus()
{
	PrintLine();
	cout << "닉네임: " << name << "  |  직업: " << job << "  |  Lv." << level << endl;
	cout << "HP: " << hp << "  |  MP: " << mp << "  |  공격력: " << power << "  |  방어력: " << defence << endl;
	PrintLine();
}

void Player::levelUp()
{
	level++;
}
