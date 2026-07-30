#pragma once
#include <string>

class Monster;
class Level_Up;
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
	int stat[7]; // 0: HP, 1: MP, 2: ATK, 3: AP, 4: DEF, 5: SNE, 6: AGI
public:
	Player(std::string name, int stat[]);

	virtual ~Player() {}

	virtual void attack(Monster* monster) = 0;

	void Print_Status() const;

	void Set_Start_Stat();

	std::string Get_Name() const;
	std::string Get_Job() const;

	int Get_Level() const;
	int Get_Hp() const;
	int Get_Mp() const;
	int Get_ATK() const;
	int Get_DEF() const;
	int Get_AP() const;
	int Get_Exp() const;
	
	void Set_Hp(int hp);
	void Set_Mp(int mp);
	void Set_ATK(int atk);
	void Set_DEF(int def);
	void Set_AP(int ap);
	void Set_Level(int level);
	void Set_Exp(int exp);
	void Gain_Exp(int amount);
	void Level_Up();




};



