#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

namespace
{
	constexpr int BASE_EXP_REWARD = 100;
	constexpr int BASE_SCORE_REWARD = 100;

	constexpr double CHAPTER_REWARD_MULTIPLIER = 1.3;
}

Monster::Monster()
	: _monster_Type(Monster_Type::INT_SLIME),
	_chapter_Type(Chapter_Type::VARIABLE_CONDITION_FOREST),
	_monster_Name("int 슬라임"),
	_evasion(80),
	_accuracy(20),
	_exp_Reward(0),
	_score_Reward(0),
	_attack_Message("int 슬라임이 몸을 튕겨 공격했다!!!"),
	_drop_Item_Name("보상 미정"),
	_drop_Item_Price(0)
{
	_stat[MONSTER_HP] = 3;
	_stat[MONSTER_MP] = 0;
	_stat[MONSTER_POWER] = 3;
	_stat[MONSTER_DEFENCE] = 3;
	_stat[MONSTER_SPEED] = 3;

	_exp_Reward = Calculate_Exp_Reward();
	_score_Reward = Calculate_Score_Reward();
}

Monster::Monster(Monster_Type monster_Type)
{
	Initialize_Monster(monster_Type);
}

Monster::Monster
(
	string monster_Name,
	int monster_HP,
	int monster_Power,
	int monster_Defence,
	string drop_Item_Name,
	int drop_Item_Price
)
	: _monster_Type(Monster_Type::INT_SLIME),
	_chapter_Type(Chapter_Type::VARIABLE_CONDITION_FOREST),
	_monster_Name(monster_Name),
	_evasion(80),
	_accuracy(80),
	_exp_Reward(0),
	_score_Reward(0),
	_attack_Message(monster_Name + "이(가) 공격했다!!!"),
	_drop_Item_Name(drop_Item_Name),
	_drop_Item_Price(drop_Item_Price)
{
	_stat[MONSTER_HP] = monster_HP;
	_stat[MONSTER_MP] = 0;
	_stat[MONSTER_POWER] = monster_Power;
	_stat[MONSTER_DEFENCE] = monster_Defence;
	_stat[MONSTER_SPEED] = 3;

	_exp_Reward = Calculate_Exp_Reward();
	_score_Reward = Calculate_Score_Reward();
}

void Monster::Initialize_Monster(Monster_Type monster_Type)
{
	_monster_Type = monster_Type;

	_stat[MONSTER_MP] = 0;
	_stat[MONSTER_SPEED] = 3;

	_evasion = 80;
	_accuracy = 20;

	// 아이템관련 : 윤재님이랑 연결한 후 수정하기
	_drop_Item_Name = "보상 미정";
	_drop_Item_Price = 0;

	switch (monster_Type)
	{
	case Monster_Type::INT_SLIME:
	{
		_chapter_Type =
			Chapter_Type::VARIABLE_CONDITION_FOREST;

		_monster_Name = "int 슬라임";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 3;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"int 슬라임이 몸을 튕겨 공격했다!!!";

		break;
	}

	case Monster_Type::BOOL_MUSHROOM:
	{
		_chapter_Type =
			Chapter_Type::VARIABLE_CONDITION_FOREST;

		_monster_Name = "bool 버섯";

		_stat[MONSTER_HP] = 4;
		_stat[MONSTER_POWER] = 2;
		_stat[MONSTER_DEFENCE] = 4;
		_stat[MONSTER_SPEED] = 1;

		_attack_Message =
			"bool 버섯이 갓으로 밀어붙였다!!!";

		break;
	}

	case Monster_Type::IF_GOBLIN:
	{
		_chapter_Type =
			Chapter_Type::VARIABLE_CONDITION_FOREST;

		_monster_Name = "if 고블린";

		_stat[MONSTER_HP] = 2;
		_stat[MONSTER_POWER] = 4;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 4;

		_attack_Message =
			"if 고블린이 빠르게 검을 휘둘렀다!!!";

		break;
	}

	case Monster_Type::ARRAY_JELLYFISH:
	{
		_chapter_Type =
			Chapter_Type::ARRAY_LOOP_OCEAN;

		_monster_Name = "array 해파리";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 3;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"array 해파리가 촉수를 휘둘렀다!!!";

		break;
	}

	case Monster_Type::FOR_SHARK:
	{
		_chapter_Type =
			Chapter_Type::ARRAY_LOOP_OCEAN;

		_monster_Name = "for 상어";

		_stat[MONSTER_HP] = 2;
		_stat[MONSTER_POWER] = 4;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 5;

		_attack_Message =
			"for 상어가 빠른 속도로 돌진했다!!!";

		break;
	}

	case Monster_Type::WHILE_WHALE:
	{
		_chapter_Type =
			Chapter_Type::ARRAY_LOOP_OCEAN;

		_monster_Name = "while 고래";

		_stat[MONSTER_HP] = 5;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 4;
		_stat[MONSTER_SPEED] = 1;

		_attack_Message =
			"while 고래가 꼬리로 내려쳤다!!!";

		break;
	}

	case Monster_Type::PARAMETER_GIANT_FLY:
	{
		_chapter_Type =
			Chapter_Type::FUNCTION_RUINS;

		_monster_Name = "parameter 거대파리";

		_stat[MONSTER_HP] = 2;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 5;

		_attack_Message =
			"parameter 거대파리가 빠르게 날아와 들이받았다!!!";

		break;
	}

	case Monster_Type::RETURN_GARGOYLE:
	{
		_chapter_Type =
			Chapter_Type::FUNCTION_RUINS;

		_monster_Name = "return 가고일";

		_stat[MONSTER_HP] = 4;
		_stat[MONSTER_POWER] = 2;
		_stat[MONSTER_DEFENCE] = 5;
		_stat[MONSTER_SPEED] = 1;

		_attack_Message =
			"return 가고일이 날개를 펼쳐 내리쳤다!!!";

		break;
	}

	case Monster_Type::FUNCTION_MAGE:
	{
		_chapter_Type =
			Chapter_Type::FUNCTION_RUINS;

		_monster_Name = "function 마도사";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 5;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"function 마도사가 마력을 발사했다!!!";

		break;
	}

	case Monster_Type::POINTER_GHOST:
	{
		_chapter_Type =
			Chapter_Type::POINTER_MEMORY_GRAVEYARD;

		_monster_Name = "pointer 유령";

		_stat[MONSTER_HP] = 2;
		_stat[MONSTER_POWER] = 4;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 5;

		_attack_Message =
			"pointer 유령이 순식간에 접근해 할퀴었다!!!";

		break;
	}

	case Monster_Type::NULL_BANSHEE:
	{
		_chapter_Type =
			Chapter_Type::POINTER_MEMORY_GRAVEYARD;

		_monster_Name = "null 밴시";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 5;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 5;

		_attack_Message =
			"null 밴시가 날카로운 비명으로 공격했다!!!";

		break;
	}

	case Monster_Type::MEMORY_REAPER:
	{
		_chapter_Type =
			Chapter_Type::POINTER_MEMORY_GRAVEYARD;

		_monster_Name = "memory 사신";

		_stat[MONSTER_HP] = 4;
		_stat[MONSTER_POWER] = 4;
		_stat[MONSTER_DEFENCE] = 4;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"memory 사신이 낫을 휘둘렀다!!!";

		break;
	}

	case Monster_Type::CLASS_MACHINE_DOLL:
	{
		_chapter_Type =
			Chapter_Type::OBJECT_STL_FACTORY;

		_monster_Name = "class 기계인형";

		_stat[MONSTER_HP] = 4;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 4;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"class 기계인형이 주먹을 휘둘렀다!!!";

		break;
	}

	case Monster_Type::INHERITANCE_CHIMERA:
	{
		_chapter_Type =
			Chapter_Type::OBJECT_STL_FACTORY;

		_monster_Name = "inheritance 키메라";

		_stat[MONSTER_HP] = 4;
		_stat[MONSTER_POWER] = 5;
		_stat[MONSTER_DEFENCE] = 3;
		_stat[MONSTER_SPEED] = 2;

		_attack_Message =
			"inheritance 키메라가 여러 기계팔로 공격했다!!!";

		break;
	}

	case Monster_Type::VECTOR_DRONE:
	{
		_chapter_Type =
			Chapter_Type::OBJECT_STL_FACTORY;

		_monster_Name = "vector 드론";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 2;
		_stat[MONSTER_SPEED] = 5;

		_attack_Message =
			"vector 드론이 기관총 세례를 퍼부었다!!!";

		break;
	}

	default:
	{
		_monster_Type =
			Monster_Type::INT_SLIME;

		_chapter_Type =
			Chapter_Type::VARIABLE_CONDITION_FOREST;

		_monster_Name = "int 슬라임";

		_stat[MONSTER_HP] = 3;
		_stat[MONSTER_POWER] = 3;
		_stat[MONSTER_DEFENCE] = 3;
		_stat[MONSTER_SPEED] = 3;

		_attack_Message =
			"int 슬라임이 몸을 튕겨 공격했다!!!";

		break;
	}
	}

	_exp_Reward = Calculate_Exp_Reward();
	_score_Reward = Calculate_Score_Reward();
}

int Monster::Get_Chapter_Number() const
{
	switch (_chapter_Type)
	{
	case Chapter_Type::VARIABLE_CONDITION_FOREST:
	{
		return 1;
	}

	case Chapter_Type::ARRAY_LOOP_OCEAN:
	{
		return 2;
	}

	case Chapter_Type::FUNCTION_RUINS:
	{
		return 3;
	}

	case Chapter_Type::POINTER_MEMORY_GRAVEYARD:
	{
		return 4;
	}

	case Chapter_Type::OBJECT_STL_FACTORY:
	{
		return 5;
	}

	default:
	{
		return 1;
	}
	}
}

int Monster::Calculate_Exp_Reward() const
{
	double exp_Reward =
		static_cast<double>(BASE_EXP_REWARD);

	int chapter_Number =
		Get_Chapter_Number();

	for (int i = 1; i < chapter_Number; i++)
	{
		exp_Reward *=
			CHAPTER_REWARD_MULTIPLIER;
	}

	return static_cast<int>
		(
			exp_Reward + 0.5
			);
}

int Monster::Calculate_Score_Reward() const
{
	double score_Reward =
		static_cast<double>(BASE_SCORE_REWARD);

	int chapter_Number =
		Get_Chapter_Number();

	for (int i = 1; i < chapter_Number; i++)
	{
		score_Reward *=
			CHAPTER_REWARD_MULTIPLIER;
	}

	return static_cast<int>
		(
			score_Reward + 0.5
			);
}

string Monster::getName() const
{
	return _monster_Name;
}

int Monster::getHP() const
{
	return _stat[MONSTER_HP];
}

int Monster::getPower() const
{
	return _stat[MONSTER_POWER];
}

int Monster::getDefence() const
{
	return _stat[MONSTER_DEFENCE];
}

int Monster::getSpeed() const
{
	return _stat[MONSTER_SPEED];
}

int Monster::getEvasion() const
{
	return _evasion;
}

int Monster::getAccuracy() const
{
	return _accuracy;
}

int Monster::getExpReward() const
{
	return _exp_Reward;
}

int Monster::getScoreReward() const
{
	return _score_Reward;
}

string Monster::getDropItemName() const
{
	return _drop_Item_Name;
}

int Monster::getDropItemPrice() const
{
	return _drop_Item_Price;
}

Monster_Type Monster::getMonsterType() const
{
	return _monster_Type;
}

Chapter_Type Monster::getChapterType() const
{
	return _chapter_Type;
}

string Monster::getAttackMessage() const
{
	return _attack_Message;
}

void Monster::setHP(int hp)
{
	_stat[MONSTER_HP] = hp;

	if (_stat[MONSTER_HP] < 0)
	{
		_stat[MONSTER_HP] = 0;
	}
}

void Monster::attack(Player* player) const
{
	// 현재는 Player의 값을 직접 사용하지 않음
	(void)player;

	Print_Attack_Message();
}

void Monster::Print_Monster_Info() const
{
	cout << "========================================"
		<< endl;

	cout << "몬스터 이름: "
		<< _monster_Name
		<< endl;

	cout << "HP: "
		<< _stat[MONSTER_HP]
		<< endl;

	cout << "공격력: "
		<< _stat[MONSTER_POWER]
		<< endl;

	cout << "방어력: "
		<< _stat[MONSTER_DEFENCE]
		<< endl;

	cout << "스피드: "
		<< _stat[MONSTER_SPEED]
		<< endl;

	cout << "회피율: "
		<< _evasion
		<< "%"
		<< endl;

	cout << "명중률: "
		<< _accuracy
		<< "%"
		<< endl;

	cout << "처치 경험치: "
		<< _exp_Reward
		<< endl;

	cout << "처치 점수: "
		<< _score_Reward
		<< endl;

	cout << "========================================"
		<< endl;
}

void Monster::Print_Attack_Message() const
{
	cout << _attack_Message
		<< endl;
}