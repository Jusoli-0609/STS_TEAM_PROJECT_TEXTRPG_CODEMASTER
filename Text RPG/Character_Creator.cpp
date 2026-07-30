#include <iostream>
#include <string>
#include "Character_Creator.h"
#include "Player.h"
#include "Job_Selection.h"
using namespace std;

Player* Character_Creator()
{	
	string name;
	cout << "캐릭터의 이름을 정해주세요: ";
	cin >> name;
	Job_Selection(name, stat);

}