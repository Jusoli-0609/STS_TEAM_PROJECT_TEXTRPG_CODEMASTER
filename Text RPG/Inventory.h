#pragma once
#include "Item.h"
#include <vector>
#include <string>
#include <map>

class Inventory
{
private:
	int HPPotionCount;
	int MPPotionCount;
	std::vector<Item> inventory;

public:
	Inventory();		//인자를 받지 않기에 괄호를 비워도 됨. cpp에서 초기화 할 것이므로.==기본 지급품 세트로 그냥 만들어 주세요.

	void UseItem(int itemType);
	void AddItem(int itemType);
	void PrintItem(int itemType);

	void AddItem(const Item& item);
	void PrintInventory() const;
};