#pragma once

#include <string>

class Player;
class Monster;

struct TutorStatBonus
{
    int hp = 0;
    int mp = 0;
    int atk = 0;
    int def = 0;
    int ap = 0;
    int sne = 0;
    int agi = 0;
};

class Tutor
{
protected:
    std::string name;
    std::string description;

    TutorStatBonus statBonus;

public:
    Tutor(
        const std::string& name,
        const std::string& description,
        const TutorStatBonus& statBonus
    );

    virtual ~Tutor() = default;

    std::string Get_Name() const;
    std::string Get_Description() const;
    TutorStatBonus Get_Stat_Bonus() const;

    // 상시 스탯 적용 및 해제
    void Apply_Stat_Bonus(Player* player);
    void Remove_Stat_Bonus(Player* player);

    // 조건부 패시브
    virtual void On_Battle_Start(Player* player, Monster* monster);
    virtual void On_Turn_Start(Player* player, Monster* monster);
    virtual void On_Player_Attack(
        Player* player,
        Monster* monster,
        int& damage
    );
    virtual void On_Player_Hit(
        Player* player,
        Monster* monster,
        int& damage
    );
    virtual void On_Battle_End(Player* player, Monster* monster);
};