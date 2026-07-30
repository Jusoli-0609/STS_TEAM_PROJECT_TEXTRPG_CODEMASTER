#pragma once
#include <string>
#include <iostream>

class Item
{
public:
    std::string _Item_Name;
    int _Item_Price;
    int _Item_Count;
    int _Item_Weight;
    bool _Item_Type_Usable;

    void PrintInfo() const;
};

