#include "Main.h"
#include <iostream>
#include <string>

using namespace std;

void PrintLine()
{
	cout << string(50, '=') << endl;
}

int main()
{
    Console_Manager Console(120, 40);

    Console.Set_Console_Size();
    Console.Clear();
    Console.Set_Cursor_Position(10, 5);
    std::cout << "눈 떠보니 코드 마스터";

    //직업 선택
    PrintLine();

    return 0;
}