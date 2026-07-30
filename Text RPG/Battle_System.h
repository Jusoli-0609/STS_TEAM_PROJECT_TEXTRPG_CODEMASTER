#pragma once

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

enum Battle_Menu
{
	ATTACK = 1,
	SKILL,
	ITEM
};

void Battle(Player* player, Monster& monster, Inventory& inventory);

void Show_Battle_Menu(); //제거 예정

void Player_Turn(Player* player, Monster& monster, Inventory& inventory);

void Monster_Turn(Player* player, Monster& monster);

void Attack(Player* player, Monster& monster);

void Skill(Player* player, Monster& monster);

bool Check_Battle_End(Player* player, Monster& monster, Inventory& inventory);