#pragma once
#include <string>

class Monster;

class Player
{
protected:
    std::string name;
    std::string job;

    int hp;
    int mp;
    int atk;
    int def;
    int ap;
    int sne;
    int agi;

    int level;
    int maxexp;
    int exp;

    void Set_Start_Stat(
        int hp,
        int mp,
        int atk,
        int def,
        int ap,
        int sne,
        int agi
    );


public:
    Player(const std::string& name);

    virtual ~Player() {}

    virtual void Attack(Monster* monster) = 0;

    virtual void Skill1(Monster* monster) = 0;
    virtual void Skill2(Monster* monster) = 0;
    virtual void Skill3(Monster* monster) = 0;

    virtual void Groggy_Attack(Monster* monster) = 0;

    void Print_Status() const;


    std::string Get_Name() const;
    std::string Get_Job() const;

    int Get_Level() const;
    int Get_Hp() const;
    int Get_Mp() const;
    int Get_ATK() const;
    int Get_DEF() const;
    int Get_AP() const;
    int Get_SNE() const;
    int Get_AGI() const;
    int Get_Exp() const;

    void Set_Hp(int hp);
    void Set_Mp(int mp);
    void Set_ATK(int atk);
    void Set_DEF(int def);
    void Set_AP(int ap);
    void Set_SNE(int sne);
    void Set_AGI(int agi);
    void Set_Level(int level);
    void Set_Exp(int exp);

    void Gain_Exp(int amount);
    void Level_Up();
};