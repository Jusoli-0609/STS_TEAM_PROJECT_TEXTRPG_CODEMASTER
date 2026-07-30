#pragma once
#include <string>
#include "Inventory.h"
#include "Player.h"

void PrintStatus(std::string& name, int stat[]);
void InputHPMP(int stat[]);
void Inputstats(int stat[]);
void CreateCharacter(std::string& name, int stat[]);
void PrintLine();
void Upgrade(std::string& name, int stat[], Inventory& inventory);
void ChoiceJob(std::string& name, int stat[], Player*& player);