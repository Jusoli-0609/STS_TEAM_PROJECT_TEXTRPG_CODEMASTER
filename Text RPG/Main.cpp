#include "Main.h"
#include "Inventory.h"
#include "Player.h"
#include "Monster.h"
#include "Battle.h"
#include "AlchemyWorkshop.h"
#include <iostream>
#include <string>

using namespace std;

void PrintLine()
{
	cout << string(50, '=') << endl;
}

void OpenDungeon(Player* player, Inventory& inventory)
{
    int dungeonChoice = -1;

    cout << "===== 던전 입장 =====" << endl;
    cout << "1. 슬라임 숲" << endl;
    cout << "2. 고블린 동굴" << endl;
    cout << "0. 메인 메뉴로 돌아가기" << endl;
    cout << "선택: ";

    cin >> dungeonChoice;

    if (dungeonChoice == 1)
    {
        Monster slime("슬라임", 50, 60, 20, "슬라임 젤리", 20);

        Battle(player, slime, inventory);
    }

    else if (dungeonChoice == 2)
    {
        Monster goblin("고블린", 80, 50, 60, "고블린의 이빨", 40);

        Battle(player, goblin, inventory);
    }
    
    else if (dungeonChoice == 0)
    {
        cout << "메인 메뉴로 돌아갑니다." << endl;
    }
    
    else
    {
        cout << "잘못된 선택입니다." << endl;
    }
}

void OpenInventory(const Inventory& inventory)
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
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    PrintLine();
    cout << "[ 던전 탈출 텍스트 RPG ]" << endl;
    PrintLine();

    CreateCharacter(name, stat);
    PrintStatus(name, stat);

    Inventory inventory;
    AlchemyWorkshop workshop;

    cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
    PrintLine();

    Upgrade(name, stat, inventory);

    Player* player = nullptr;

    ChoiceJob(name, stat, player);
    PrintLine();

    int choice = -1;

    while (true)
    {
        PrintLine();
        cout << "===== 메인 메뉴 =====" << endl;
        cout << "1. 던전 입장" << endl;
        cout << "2. 인벤토리 확인" << endl;
        cout << "3. 포션 제작소" << endl;
        cout << "0. 게임 종료" << endl;
        cout << "선택: ";

        cin >> choice;

        if (choice == 1)
        {
            OpenDungeon(player, inventory);
        }

        else if (choice == 2)
        {
            OpenInventory(inventory);
        }

        else if (choice == 3)
        {
            OpenAlchemyWorkshop(workshop);
        }

        else if (choice == 0)
        {
            cout << "게임을 종료합니다." << endl;
            break;
        }

        else
        {
            cout << "잘못된 입력입니다." << endl;
        }
    }

    delete player;
    player = nullptr;

    return 0;
}