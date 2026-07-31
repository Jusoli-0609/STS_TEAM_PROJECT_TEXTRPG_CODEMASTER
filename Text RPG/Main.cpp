#include <iostream> 
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Main.h"

using namespace std;

void PrintLine()
{
    cout << string(50, '=') << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Console_Manager Console(120, 40);

    Console.Set_Console_Size();
    Console.Clear();
    Console.Set_Cursor_Position(10, 5);
    std::cout << "눈 떠보니 코드 마스터";

    //직업 선택
    PrintLine();

    return 0;
