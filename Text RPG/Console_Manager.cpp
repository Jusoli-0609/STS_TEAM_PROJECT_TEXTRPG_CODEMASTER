#include "Console_Manager.h"

Console_Manager::Console_Manager()
{
    _width = 120;
    _height = 40;
}
//임시값입니다.


Console_Manager::Console_Manager(int width, int height)
{
    _width = width;
    _height = height;
}

void Console_Manager::Set_Console_Size()
{
   
}

void Console_Manager::Set_Cursor_Position(int x, int y)
{
    COORD pos;
    //windows에서 제공하는 좌표 구조체인데
    //이 구조체에서 int가 아니라 SHORT 타입이어서 아래에서 변환
    //SHORT 쓰는 이유는 큰 숫자 들어갈 필요가 없기 때문

    pos.X = static_cast<SHORT>(x);
    pos.Y = static_cast<SHORT>(y);

    SetConsoleCursorPosition
    (
        GetStdHandle(STD_OUTPUT_HANDLE),
        pos
    );
}

void Console_Manager::Clear()
{
    system("cls");
}