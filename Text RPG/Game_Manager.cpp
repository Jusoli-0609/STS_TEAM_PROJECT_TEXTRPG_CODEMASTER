#include "Game_Manager.h"
#include "Console_Manager.h"
#include <iostream>

void Game_Manager::Run()
{
    Console_Manager Console(120, 40);

    Console.Set_Console_Size();
    Console.Clear();
    Console.Set_Cursor_Position(10, 5);
    std::cout << "눈 떠보니 코드 마스터";

    Intro();
    Console.Clear();
    Character_Creator();

    Tutorial();
    Console.Clear();

    Job_Selection();
    Console.Clear();

    Main_Menu();
    Console.Clear();

    Ending();
}