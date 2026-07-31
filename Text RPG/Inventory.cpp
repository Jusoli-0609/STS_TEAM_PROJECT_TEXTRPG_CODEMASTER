#include<algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Inventory.h"
#include "Item.h"

using namespace std;

template<typename T>
Inventory<T>::Inventory(int Max_Inventory_Size,int Max_Capacity)//기본 생성자
{
    _Max_Inventory_Size = Max_Inventory_Size;
    _Max_Capacity=Max_Capacity;
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
Inventory<T>& Inventory<T>:: operator=(const Inventory& other)//대입 연산자, 다른 Inventory<T> 객체를 받아서, 현재 객체에 복사하고, 현재 객체 자신을 반환
{
    if (this == &other)
    {
        return *this;
    }
    delete[] _Inventory_Items;
    _Max_Inventory_Size = other._Max_Inventory_Size;
    _Max_Capacity = other._Max_Capacity;
    _Current_Quantity_Of_Items = other._Current_Quantity_Of_Items;
    _Inventory_Items = new T[_Max_Inventory_Size];
    for (int i = 0; i < _Current_Quantity_Of_Items; i++)
    {
        _Inventory_Items[i] = other._Inventory_Items[i];
    }
    return *this;
}
template<typename T>
int Inventory<T>::Get_Total_Weight()const // 인벤토리 총 무게 함수
{
    int Total_Weight = 0;
    for (int i = 0; i < _Current_Quantity_Of_Items; i++)
    {
        Total_Weight += _Inventory_Items[i]._Item_Weight * _Inventory_Items[i]._Item_Count;
    }
    return Total_Weight;
}
template<typename T>
T* Inventory<T>::Get_Item_By_Index(int index)//인벤토리 Index  가져오기
{
    if (index < 0 || index >= _Current_Quantity_Of_Items)
    {
        return nullptr;
    }
    return &_Inventory_Items[index];
}
template<typename T>
int Inventory<T>::GetSize()const//인벤토리 사이즈 가져오기
{
    return _Current_Quantity_Of_Items;
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

template class Inventory<Item>; // 명시적 인스턴스화


// ================== 임시구현 ================

template<typename T>
int Inventory<T>::GetCapacity() const
{
    return _Max_Capacity;
}

template<typename T>
void Inventory<T>::PrintInventory() const
{
    std::cout << "===== Inventory =====" << std::endl;

    for (int i = 0; i < _Current_Quantity_Of_Items; i++)
    {
        _Inventory_Items[i].PrintInfo();
    }
}

template<typename T>
void Inventory<T>::PrintInventoryMenu()
{
}

template<typename T>
bool Inventory<T>::AddOrIncreaseItem(const T& newItem)
{
    if (_Current_Quantity_Of_Items >= _Max_Inventory_Size)
        return false;

    _Inventory_Items[_Current_Quantity_Of_Items] = newItem;
    _Current_Quantity_Of_Items++;

    return true;
}

template<typename T>
bool Inventory<T>::UseItemByName(const std::string& ItemName)
{
    return false;
}

template<typename T>
void Inventory<T>::ThrowAwayItem()
{
}

template<typename T>
void Inventory<T>::RemoveLastItem()
{
    if (_Current_Quantity_Of_Items > 0)
        _Current_Quantity_Of_Items--;
}

template<typename T>
void Inventory<T>::SortInventory()
{
}

template<typename T>
void Inventory<T>::ChangeInventoryOrder()
{
}

template<typename T>
void Inventory<T>::FirstTimeSizeUp(int NewCapacity)
{
    _Max_Capacity = NewCapacity;
}