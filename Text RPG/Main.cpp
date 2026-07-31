#include "Main.h"
#include "Inventory.h"
#include "Player.h"
#include "Monster.h"
#include "Battle_System.h"
#include "Craft_Item.h"
#include "DungeonManager.h"
#include <iostream>
#include <string>

using namespace std;

void PrintLine()
{
	cout << string(50, '=') << endl;
}

void OpenInventory(const Inventory<Item>& inventory)
{
    cout << "===== 인벤토리 =====" << endl;

    inventory.PrintInventory();
}

void OpenAlchemyWorkshop(AlchemyWorkshop& workshop)
{
    int choice = -1;

    while (true)
    {
        cout << "===== 포션 제작소 =====" << endl;
        cout << "1. 레시피 전체 보기" << endl;
        cout << "2. 포션 이름으로 레시피 검색" << endl;
        cout << "3. 재료 이름으로 레시피 검색" << endl;
        cout << "0. 메인 메뉴로 돌아가기" << endl;
        cout << "선택: ";

        cin >> choice;

        if (choice == 1)
        {
            workshop.PrintAllRecipes();
        }
        else if (choice == 2)
        {
            string potionName;

            cout << "검색할 포션 이름: ";
            cin >> potionName;

            workshop.FindRecipeByPotionName(potionName);
        }
        else if (choice == 3)
        {
            string ingredientName;

            cout << "검색할 재료 이름: ";
            cin >> ingredientName;

            workshop.FindRecipesByIngredientName(ingredientName);
        }
        else if (choice == 0)
        {
            cout << "메인 메뉴로 돌아갑니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
        }
    }
}

int main()
{
    Set_Console_Size();
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    PrintLine();
    cout << "[ 던전 탈출 텍스트 RPG ]" << endl;
    PrintLine();

    CreateCharacter(name, stat);
    PrintStatus(name, stat);

    Inventory<Item> inventory(30,100);
    AlchemyWorkshop workshop;

    Dungeon_Manager dungeon_Manager;

    cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
    PrintLine();

    Upgrade(name, stat, inventory);

    Player* player = nullptr;

    ChoiceJob(name, stat, player);
    PrintLine();

    int choice = -1;
    bool is_Game_Running = true;


    while (is_Game_Running)
    {
        PrintLine();
        cout << "===== 메인 메뉴 =====" << endl;
        cout << "1. 던전 입장" << endl;
        cout << "2. 인벤토리 확인" << endl;
        cout << "3. 포션 제작소" << endl;
        cout << "0. 게임 종료" << endl;
        cout << "선택: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            dungeon_Manager.Open_Dungeon
            (
                player,
                inventory
            );

            if
                (
                    player != nullptr
                    && player->getHp() <= 0
                    )
            {
                cout << "플레이어가 쓰러져 "
                    << "게임을 종료합니다."
                    << endl;

                is_Game_Running = false;
            }

            break;
        }

        case 2:
        {
            OpenInventory(inventory);

            break;
        }

        case 3:
        {
            OpenAlchemyWorkshop(workshop);

            break;
        }

        case 0:
        {
            cout << "게임을 종료합니다."
                << endl;

            is_Game_Running = false;

            break;
        }

        default:
        {
            cout << "잘못된 입력입니다."
                << endl;

            break;
        }
        }
    }

    delete player;
    player = nullptr;

    return 0;
}