#pragma once
#include "Console_Manager.h"

class Game_Manager
{
private:
    Console_Manager Console;

    bool IsRunning;

private:
    void Intro();
    void Tutorial();

    void Character_Creator();
    //¿µºó´Ô
    void Job_Selection();
    //¿µºó´Ô

    void Main_Menu();
    //while µ¹¸®±â
    void Ending();

public:
    Game_Manager();

    void Run();
};