	#pragma once
	#include<algorithm>
	#include <map>
	#include <string>
	#include <vector>

	#include "Item.h"
	#include "Player.h"

	template <typename T>
	class Inventory
	{
	private:
		T* _Inventory_Items;
		int _Max_Inventory_Size;
		int _Max_Capacity;
		int _Current_Quantity_Of_Items;
	public:
		//1.인벤토리 생성 파트
		Inventory(int Max_Inventory_Size, int Max_Capacity);//1-1 인벤토리 기본 생성자
		Inventory(const Inventory<T>& other); //1-2.인벤토리 복사 생성자(새로 만들면서 복사 → 복사 생성자)
		//2.인벤토리 대입 연산자 파트
		Inventory& operator=(const Inventory& other);
		//3.인벤토리 조회 함수 파트
		int Get_Total_Weight() const;
		T* Get_Item_By_Index(int index);
		int GetSize() const;
		int GetCapacity() const;
		//4.인벤토리 출력 관련 함수 파트
		void PrintInventory() const;
		void PrintInventoryMenu();
		//5.
		bool AddOrIncreaseItem(const T& newItem);
		bool UseItemByName(const std::string& ItemName);
		void Use_Item_In_Battle(Player& player);
		void ThrowAwayItem();
		void RemoveLastItem();
		// 7. 정렬 / 순서 변경
	    void SortInventory();
	    void ChangeInventoryOrder();
	    // 8. 용량 확장
		void FirstTimeSizeUp(int NewCapacity);
	    // 9. 소멸자
		~Inventory();
	};
