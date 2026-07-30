#include "Inventory.h"
#include <vector>
#include <iostream>

using namespace std;

Inventory::Inventory()
{
	HPPotionCount = 5;
	MPPotionCount = 5;
}		//생성자 초기화

void Inventory::UseItem(int itemType)
{
	if (itemType == 1 && HPPotionCount > 0)
	{
		HPPotionCount--;
		cout << "HP가 20 증가했습니다. (HP 포션 차감 - 남은 포션 " << HPPotionCount << "개)" << endl;
	}
	else if (itemType == 2 && MPPotionCount > 0)
	{
		MPPotionCount--;
		cout << "MP가 20 증가했습니다. (MP 포션 차감 - 남은 포션 " << MPPotionCount << "개)" << endl;
	}

	else if (itemType == 1 && HPPotionCount <= 0)
	{
		cout << "HP 포션 부족" << endl;
	}

	else if (itemType == 2 && MPPotionCount <= 0)
	{
		cout << "MP 포션 부족" << endl;
	}
}

void Inventory::AddItem(int itemType)
{
	if (itemType == 1)
	{
		HPPotionCount++;
		cout << "HP 포션을 획득했습니다. (현재 HP 포션 " 
		<< HPPotionCount << "개)" << endl;
	}
	else if (itemType == 2)
	{
		MPPotionCount++;
		cout << "MP 포션을 획득했습니다. (현재 MP 포션 "
		<< MPPotionCount << "개)" << endl;
	}
	else
	{
		cout << "잘못된 아이템 타입입니다." << endl;
	}
}

void Inventory::PrintItem(int itemType)
{
	if (itemType == 1)
	{
		cout << "현재 HP 포션 " << HPPotionCount << "개" << endl;
	}
	else if (itemType == 2)
	{
		cout << "현재 MP 포션 " << MPPotionCount << "개" << endl;
	}
	else
	{
		cout << "현재 HP 포션 " << HPPotionCount << "개" << endl;
		cout << "현재 MP 포션 " << MPPotionCount << "개" << endl;
	}
}

void Inventory::AddItem(const Item& item)
{
	inventory.push_back(item);

	std::cout << "  -> 인벤토리에 저장되었습니다." << std::endl;
}

void Inventory::PrintInventory() const
{
	std::cout << "[ 인벤토리 (" << inventory.size() << "/10) ]" << std::endl;

	if (inventory.empty())
	{
		std::cout << "인벤토리가 비어 있습니다." << std::endl;
		return;
	}

	int index = 1;

	for (const Item& item : inventory)
	{
		std::cout << index << ". ";
		item.PrintInfo();

		index++;
	}
}