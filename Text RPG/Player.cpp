#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name, int hp, int mp, int power, int defence)
	: name(name), job("초보자"), maxHp(hp), hp(hp), maxMp(mp), mp(mp), power(power), defence(defence)
{
}

string Player::getName() { return name; }
string Player::getJob() { return job; }
int Player::getHp() { return hp; }
int Player::getMp() { return mp; }
int Player::getPower() { return power; }
int Player::getDefence() { return defence; }

int Player::getLevel()
{
	return levelSystem.GetCurrentLevel();
}

void Player::setName(string name) { this->name = name; }
void Player::setJob(string job) { this->job = job; }
void Player::setHp(int hp) { this->hp = hp; }
void Player::setMp(int mp) { this->mp = mp; }
void Player::setPower(int power) { this->power = power; }
void Player::setDefence(int defence) { this->defence = defence; }

void Player::GainExp(int amount)
{
	levelSystem.GainExp(this, amount);
}

void Player::printPlayerStatus()
{
	cout << "------------------------------------\n";
	cout << "닉네임: " << name << " | 직업: " << job << " | Lv." << getLevel() << "\n";
	cout << "HP: " << hp << " / " << maxHp << " | MP: " << mp << " / " << maxMp << "\n";
	cout << "공격력: " << power << " | 방어력: " << defence << "\n";
	cout << "------------------------------------\n";
}