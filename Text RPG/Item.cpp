#include <iostream>
#include <string>

#include "Item.h"

void Item::PrintInfo() const
{
	std::cout << "아이템 이름: "
		<< _Item_Name << ", 가격: "
		<< _Item_Price << ", 갯수:"
		<< _Item_Count << ", 갯수당 무게: "
		<< _Item_Weight << std::endl;
}
