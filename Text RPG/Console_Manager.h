#pragma once
#include <windows.h>
#include <cstdlib>

class Console_Manager
//콘솔 화면 기능을 모아둔 클래스 
{
private:
    int _width;
    int _height;
//콘솔의 가로, 세로 크기 저장


public:
    Console_Manager();
    //생성자
    Console_Manager(int width, int height);

    void Set_Console_Size();
    void Set_Cursor_Position(int x, int y);
    //커서 위치 이동 함수
    //windows에서 꺼내온 함수라 네이밍 수정 불가

    void Clear();
    //콘솔화면 지우는 함수
};