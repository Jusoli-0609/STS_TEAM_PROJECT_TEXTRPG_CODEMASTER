#pragma once
#include "Inventory.h"
#include "Monster.h"
#include "Player.h"

#include <string>

constexpr int MONSTERS_PER_CHAPTER = 3;

class Dungeon_Manager
{
public:
	Dungeon_Manager();

	void Open_Dungeon
	(
		Player* player,
		Inventory& inventory
	);

	bool Check_All_Chapter_Cleared() const;

private:
	void Print_Current_Chapter() const;

	void Run_Current_Chapter
	(
		Player* player,
		Inventory& inventory
	);

	void Get_Current_Chapter_Monsters
	(
		Monster_Type monster_Types[]
	) const;

	void Clear_Current_Chapter();
	void Move_Next_Chapter();

	std::string Get_Chapter_Name
	(
		Chapter_Type chapter_Type
	) const;

	Chapter_Type _current_Chapter;
	bool _is_All_Chapter_Cleared;
};