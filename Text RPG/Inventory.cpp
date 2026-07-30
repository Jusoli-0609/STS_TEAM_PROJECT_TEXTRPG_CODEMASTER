#include<algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Inventory.h"

using namespace std;

template<typename T>
Inventory<T>::Inventory(int Max_Inventory_Size)
{
    _Max_Inventory_Size = Max_Inventory_Size;
    _Current_Quantity_Of_Items = 0;
    _Inventory_Items = new T[_Max_Inventory_Size];
}
template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other) //기존 객체와 같은 상태를 가진 새 객체가 필요할 때 복사 생성자가 쓰임
{
    _Max_Inventory_Size = other._Max_Inventory_Size;
    _Current_Quantity_Of_Items = other._Current_Quantity_Of_Items;
    _Max_Capacity = other._Max_Capacity;
    _Inventory_Items = new T[_Max_Inventory_Size];
    for (int i = 0; i < _Current_Quantity_Of_Items; i++)
    {
        _Inventory_Items[i] = other._Inventory_Items[i];
    }
}

template<typename T>
int Inventory<T>::Get_Total_Weight() const // 인벤토리 총 무게 함수
{
    int Total_Weight = 0;
    for (int i = 0; i < _Current_Quantity_Of_Items; i++)
    {
        Total_Weight += _Inventory_Items[i].Item_Weight * _Inventory_Items[i].Item_Count;
    }
    return Total_Weight;
}
template<typename T>
T* Inventory<T>::GetItemByIndex(int index)//인벤토리 Index  가져오기
{
    if (index < 0 || index >= _Current_Quantity_Of_Items)
    {
        return nullptr;
    }
    return &_Inventory_Items[index];
}
template <typename T>
void Inventory<T>::Use_Item_In_Battle(Player& player)
{
    if (_Current_Quantity_Of_Items == 0)
    {
         cout << "사용할 아이템이 없다!" << endl;
         return;
    }
}
template<typename T>
Inventory<T>::~Inventory()//인벤토리 소멸자
{
    delete[] _Inventory_Items;
    _Inventory_Items = nullptr;
}
template<typename T>
template class Inventory<Item>; // 명시적 인스턴스화