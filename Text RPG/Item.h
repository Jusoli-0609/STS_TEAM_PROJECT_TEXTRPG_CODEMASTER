#pragma once
#include <string>
#include <iostream>

class Item
{
    public:
    std::string name;
    int price;

    void PrintInfo() const
    {
        std::cout << name << " (" << price << "G)" << std::endl;
    }
};