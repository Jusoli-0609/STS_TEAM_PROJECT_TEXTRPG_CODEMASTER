#include "DungeonManager.h"
#include "Battle_System.h"
#include <iostream>

using namespace std;

Dungeon_Manager::Dungeon_Manager()
	: _current_Chapter
	(
		Chapter_Type::VARIABLE_CONDITION_FOREST
	),
	_is_All_Chapter_Cleared(false)
{
}

void Dungeon_Manager::Open_Dungeon
(
	Player* player,
	Inventory<Item>& inventory
)
{
	if (player == nullptr)
	{
		cout << "플레이어 정보가 없습니다." << endl;

		return;
	}

	if (_is_All_Chapter_Cleared)
	{
		cout << "모든 일반 챕터를 클리어했습니다."
			<< endl;

		// TODO: 최종 보스 던전과 연결하기

		return;
	}

	Print_Current_Chapter();

	int dungeon_Choice = -1;

	cout << "1. 현재 챕터 입장" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;
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

void Dungeon_Manager::Print_Current_Chapter() const
{
	cout << "========================================"
		<< endl;

	cout << "현재 입장 가능한 던전" << endl;

	cout << Get_Chapter_Name(_current_Chapter)
		<< endl;

	cout << "========================================"
		<< endl;
}

void Dungeon_Manager::Run_Current_Chapter
(
	Player* player,
	Inventory<Item>& inventory
)
{
	Monster_Type monster_Types[MONSTERS_PER_CHAPTER];

	Get_Current_Chapter_Monsters(monster_Types);

	cout << endl;

	cout << Get_Chapter_Name(_current_Chapter)
		<< "에 입장했습니다."
		<< endl;

	for (int i = 0; i < MONSTERS_PER_CHAPTER; i++)
	{
		Monster monster(monster_Types[i]);

		cout << endl;
		cout << "========================================"
			<< endl;

		cout << i + 1
			<< "번째 몬스터 등장"
			<< endl;

		cout << monster.getName()
			<< "이(가) 나타났습니다!"
			<< endl;

		cout << "========================================"
			<< endl;

		monster.Print_Monster_Info();

		// 현재는 공격 문구가 정상적으로 저장됐는지
		// 확인하기 위한 테스트 출력임
		cout << "[공격 문구 확인]" << endl;

		monster.Print_Attack_Message();

		cout << endl;

		Battle
		(
			player,
			monster,
			inventory
		);

		if (player->getHp() <= 0)
		{
			cout << "챕터 공략에 실패했습니다."
				<< endl;

			cout << "다시 입장하면 첫 번째 몬스터부터 "
				<< "시작합니다."
				<< endl;

			return;
		}

		if (monster.getHP() > 0)
		{
			cout << "몬스터를 처치하지 못했습니다."
				<< endl;

			return;
		}

		cout << monster.getName()
			<< " 처치 완료!"
			<< endl;
	}

	// for문을 3번 모두 통과하면
	// 몬스터 3마리를 모두 처치한 상태임
	Clear_Current_Chapter();
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

void Dungeon_Manager::Clear_Current_Chapter()
{
	cout << endl;

	cout << Get_Chapter_Name(_current_Chapter)
		<< "을(를) 클리어했습니다!"
		<< endl;

	Move_Next_Chapter();

	if (_is_All_Chapter_Cleared)
	{
		cout << "모든 일반 챕터를 클리어했습니다!"
			<< endl;

		// TODO: 최종 보스 던전과 연결하기
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
		return "모든 일반 챕터 클리어";
	}
	}
}