#include "DungeonManager.h"
#include "Battle.h"
#include <iostream>

using namespace std;

namespace
{
	constexpr int BASE_TUTOR_REQUIRED_SCORE = 300;
	constexpr double CHAPTER_SCORE_MULTIPLIER = 1.3;
}

Dungeon_Manager::Dungeon_Manager()
	: _current_Chapter
	(
		Chapter_Type::VARIABLE_CONDITION_FOREST
	),
	_is_All_Chapter_Cleared(false),
	_current_Chapter_Score(0)
{
}

void Dungeon_Manager::Open_Dungeon
(
	Player* player,
	Inventory& inventory
)
{
	if (player == nullptr)
	{
		cout << "플레이어 정보가 없습니다." << endl;

		return;
	}

	if (_is_All_Chapter_Cleared)
	{
		cout << "모든 일반 챕터를 클리어했습니다." << endl;
		return;
	}

	Print_Current_Chapter();

	int dungeon_Choice = -1;

	cout << "1. 현재 챕터 입장" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;
	cout << "2. 튜터에게 도전" << endl;
	cout << "선택: ";

	cin >> dungeon_Choice;

	switch (dungeon_Choice)
	{
	case 1:
	{
		Run_Current_Chapter
		(
			player,
			inventory
		);

		break;
	}

	case 2:
	{
		if (!Check_Tutor_Challenge_Available())
		{
			cout << "튜터에게 도전하기 위한 점수가 부족합니다." << endl;
			cout << "현재 챕터 점수: " << _current_Chapter_Score << " / " << Get_Required_Tutor_Score() << endl;

			break;
		}

		cout << "튜터 도전 조건을 달성했습니다!" << endl;
		cout << "현재 챕터 점수: " << _current_Chapter_Score << " / " << Get_Required_Tutor_Score() << endl;
		cout << "튜터 전투는 추후 연결" << endl;

		break;
	}

	case 0:
	{
		cout << "메인 메뉴로 돌아갑니다." << endl;

		break;
	}

	default:
	{
		cout << "잘못된 선택입니다." << endl;

		break;
	}
	}
}

bool Dungeon_Manager::Check_All_Chapter_Cleared() const
{
	return _is_All_Chapter_Cleared;
}

int Dungeon_Manager::Get_Current_Chapter_Score() const
{
	return _current_Chapter_Score;
}

void Dungeon_Manager::Print_Current_Chapter() const
{
	cout << "========================================" << endl;
	cout << "현재 입장 가능한 던전" << endl;
	cout << Get_Chapter_Name(_current_Chapter) << endl;
	cout << "현재 챕터 점수: " << _current_Chapter_Score << " / " << Get_Required_Tutor_Score() << endl;

	if (Check_Tutor_Challenge_Available())
	{
		cout << "튜터 도전 가능" << endl;
	}
	else
	{
		cout << "튜터 도전 불가능" << endl;
	}

	cout << "========================================" << endl;
}

void Dungeon_Manager::Run_Current_Chapter
(
	Player* player,
	Inventory& inventory
)
{
	Monster_Type monster_Types[MONSTERS_PER_CHAPTER];

	Get_Current_Chapter_Monsters(monster_Types);

	cout << endl;

	cout << Get_Chapter_Name(_current_Chapter) << "에 입장했습니다." << endl;

	for (int i = 0; i < MONSTERS_PER_CHAPTER; i++)
	{
		Monster monster(monster_Types[i]);

		cout << endl;
		cout << "========================================" << endl;
		cout << i + 1 << "번째 몬스터 등장" << endl;
		cout << monster.getName() << "이(가) 나타났습니다!" << endl;
		cout << "========================================" << endl;

		monster.Print_Monster_Info();
		Battle
		(
			player,
			monster,
			inventory
		);

		if (player->getHp() <= 0)
		{
			cout << "플레이어가 쓰러졌습니다." << endl;

			cout << "던전 공략을 종료합니다." << endl;

			return;
		}

		if (monster.getHP() > 0)
		{
			cout << monster.getName() << "을(를) 처치하지 못했습니다." << endl;

			return;
		}

		cout << monster.getName() << " 처치 완료!" << endl;

		cout << "경험치 " << monster.getExpReward() << " 획득!" << endl;

		Add_Chapter_Score
		(
			monster.getScoreReward()
		);

		if (Check_Tutor_Challenge_Available())
		{
			cout << endl;

			cout << "튜터 도전에 필요한 점수를 달성했습니다!" << endl;

			cout << "던전 메뉴에서 튜터에게 도전할 수 있습니다." << endl;

			break;
		}
	}

	cout << endl;

	cout << "현재 챕터 점수: " << _current_Chapter_Score << " / " << Get_Required_Tutor_Score() << endl;
}

void Dungeon_Manager::Get_Current_Chapter_Monsters
(
	Monster_Type monster_Types[]
) const
{
	switch (_current_Chapter)
	{
	case Chapter_Type::VARIABLE_CONDITION_FOREST:
	{
		monster_Types[0] = 
			Monster_Type::INT_SLIME;

		monster_Types[1] = 
			Monster_Type::BOOL_MUSHROOM;

		monster_Types[2] = 
			Monster_Type::IF_GOBLIN;

		break;
	}

	case Chapter_Type::ARRAY_LOOP_OCEAN:
	{
		monster_Types[0] =
			Monster_Type::ARRAY_JELLYFISH;

		monster_Types[1] =
			Monster_Type::FOR_SHARK;

		monster_Types[2] =
			Monster_Type::WHILE_WHALE;

		break;
	}

	case Chapter_Type::FUNCTION_RUINS:
	{
		monster_Types[0] =
			Monster_Type::PARAMETER_GIANT_FLY;

		monster_Types[1] =
			Monster_Type::RETURN_GARGOYLE;

		monster_Types[2] =
			Monster_Type::FUNCTION_MAGE;

		break;
	}

	case Chapter_Type::POINTER_MEMORY_GRAVEYARD:
	{
		monster_Types[0] =
			Monster_Type::POINTER_GHOST;

		monster_Types[1] =
			Monster_Type::NULL_BANSHEE;

		monster_Types[2] =
			Monster_Type::MEMORY_REAPER;

		break;
	}

	case Chapter_Type::OBJECT_STL_FACTORY:
	{
		monster_Types[0] =
			Monster_Type::CLASS_MACHINE_DOLL;

		monster_Types[1] =
			Monster_Type::INHERITANCE_CHIMERA;

		monster_Types[2] =
			Monster_Type::VECTOR_DRONE;

		break;
	}

	default:
	{
		monster_Types[0] =
			Monster_Type::INT_SLIME;

		monster_Types[1] =
			Monster_Type::BOOL_MUSHROOM;

		monster_Types[2] =
			Monster_Type::IF_GOBLIN;

		break;
	}
	}
}

void Dungeon_Manager::Add_Chapter_Score
(
	int score_Reward
)
{
	if (score_Reward < 0)
	{
		cout << "잘못된 점수값입니다." << endl;

		return;
	}

	_current_Chapter_Score += score_Reward;

	cout << "처치 점수 " << score_Reward << "점을 획득했습니다." << endl;

	cout << "현재 챕터 점수: " << _current_Chapter_Score << " / " << Get_Required_Tutor_Score() << endl; 

	if (Check_Tutor_Challenge_Available())
	{
		cout << "튜터에게 도전할 수 있습니다!"
			<< endl;
	}
}

int Dungeon_Manager::Get_Required_Tutor_Score() const
{
	double required_Score = static_cast<double> (BASE_TUTOR_REQUIRED_SCORE);

	int chapter_Number = 1;

	switch (_current_Chapter)
	{
	case Chapter_Type::VARIABLE_CONDITION_FOREST:
	{
		chapter_Number = 1;

		break;
	}

	case Chapter_Type::ARRAY_LOOP_OCEAN:
	{
		chapter_Number = 2;

		break;
	}

	case Chapter_Type::FUNCTION_RUINS:
	{
		chapter_Number = 3;

		break;
	}

	case Chapter_Type::POINTER_MEMORY_GRAVEYARD:
	{
		chapter_Number = 4;

		break;
	}

	case Chapter_Type::OBJECT_STL_FACTORY:
	{
		chapter_Number = 5;

		break;
	}

	default:
	{
		chapter_Number = 1;

		break;
	}
	}

	for (int i = 1; i < chapter_Number; i++)
	{
		required_Score *=
			CHAPTER_SCORE_MULTIPLIER;
	}

	return static_cast<int>
		(
			required_Score + 0.5
			);
}

bool Dungeon_Manager::Check_Tutor_Challenge_Available() const
{
	return
		_current_Chapter_Score
		>= Get_Required_Tutor_Score();
}

void Dungeon_Manager::Clear_Current_Chapter()
{
	cout << endl;

	cout << Get_Chapter_Name(_current_Chapter)
		<< "의 튜터를 처치했습니다!"
		<< endl;

	cout << Get_Chapter_Name(_current_Chapter)
		<< "을(를) 클리어했습니다!"
		<< endl;

	Move_Next_Chapter();

	if (_is_All_Chapter_Cleared)
	{
		cout << "모든 챕터를 클리어했습니다!"
			<< endl;

		// TODO: 최종 보스 또는 엔딩 시스템과 연결
	}
	else
	{
		cout << Get_Chapter_Name(_current_Chapter)
			<< "이(가) 열렸습니다!"
			<< endl;
	}
}

void Dungeon_Manager::Move_Next_Chapter()
{
	switch (_current_Chapter)
	{
	case Chapter_Type::VARIABLE_CONDITION_FOREST:
	{
		_current_Chapter =
			Chapter_Type::ARRAY_LOOP_OCEAN;

		break;
	}

	case Chapter_Type::ARRAY_LOOP_OCEAN:
	{
		_current_Chapter =
			Chapter_Type::FUNCTION_RUINS;

		break;
	}

	case Chapter_Type::FUNCTION_RUINS:
	{
		_current_Chapter =
			Chapter_Type::POINTER_MEMORY_GRAVEYARD;

		break;
	}

	case Chapter_Type::POINTER_MEMORY_GRAVEYARD:
	{
		_current_Chapter =
			Chapter_Type::OBJECT_STL_FACTORY;

		break;
	}

	case Chapter_Type::OBJECT_STL_FACTORY:
	{
		_current_Chapter =
			Chapter_Type::ALL_CHAPTER_CLEARED;

		_is_All_Chapter_Cleared = true;

		break;
	}

	default:
	{
		_is_All_Chapter_Cleared = true;

		break;
	}
	}
	_current_Chapter_Score = 0;
}

string Dungeon_Manager::Get_Chapter_Name
(
	Chapter_Type chapter_Type
) const
{
	switch (chapter_Type)
	{
	case Chapter_Type::VARIABLE_CONDITION_FOREST:
	{
		return "챕터 1 - 변수·조건문 숲";
	}

	case Chapter_Type::ARRAY_LOOP_OCEAN:
	{
		return "챕터 2 - 배열·반복문 바다";
	}

	case Chapter_Type::FUNCTION_RUINS:
	{
		return "챕터 3 - 함수 유적";
	}

	case Chapter_Type::POINTER_MEMORY_GRAVEYARD:
	{
		return "챕터 4 - 포인터·메모리 묘지";
	}

	case Chapter_Type::OBJECT_STL_FACTORY:
	{
		return "챕터 5 - 객체지향·STL 공장";
	}

	default:
	{
		return "모든 챕터 클리어";
	}
	}
}