#pragma once

class Player; // 전방 선언

class Level_Up
{
private:
    int _current_level;
    int _current_exp;
    int _max_exp;
    int _stat_points;

    void LevelUpProcess(Player* player);

public:
    Level_Up();
    ~Level_Up(); // <- 소멸자도 맞춰주면 좋다.

    int GetCurrentLevel() const;
    int GetCurrentExp() const;
    int GetMaxExp() const;
    int GetStatPoints() const; // <- 스탯 포인트 반환 함수 추가!

    void GainExp(Player* player, int amount);
};