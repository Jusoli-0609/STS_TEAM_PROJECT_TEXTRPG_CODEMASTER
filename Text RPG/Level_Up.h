#pragma once

class Player; // ���� ����

class Level_Up
{
private:
    int _current_level;
    int _current_exp;
    int _max_exp;
    int _stat_points;

    void LevelUpProcess(Player* player);

public:
private:
    int _current_level;
    int _current_exp;
    int _max_exp;
    int _stat_points;

    void LevelUpProcess(Player* player);

public:
    void levelup(Player* player);
    Level_Up();
    ~Level_Up(); // <- �Ҹ��ڵ� �����ָ� ����.

    int GetCurrentLevel() const;
    int GetCurrentExp() const;
    int GetMaxExp() const;
    int GetStatPoints() const; // <- ���� ����Ʈ ��ȯ �Լ� �߰�!

    void GainExp(Player* player, int amount);
<<<<<<< HEAD
>>>>>>> Battle_System
=======
>>>>>>> Development_0730_V2
};