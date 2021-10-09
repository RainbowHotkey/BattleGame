#pragma once
#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H

class character
{
public:
	character(string type, int a, int b, int c, float i, int e, int f);
	void setClass(string x);
	void setHp(int h);
	void setStr(int s);
	void setDoge(int d);
	void setArmor(int arm);
	void setCredits(int c);
	void setLvl(int lvl);
	void addHp();
	void minHp();
	void addCredits();
	void minCredits();
	void addLvl();
	string getClass()
	{
		return pClass;
	}
	int getHp() 
	{
		return hp;
	}
	int getStr()
	{
		return str;
	}
	int getDoge()
	{
		return doge;
	}
	int getArmor()
	{
		return armor;
	}
	int getCredits()
	{
		return credits;
	}
	int getLvl()
	{
		return lvl;
	}
private:
	string pClass;
	int hp;
	int str;
	int doge;
	int armor;
	int credits;
	int lvl;
};

character Hero();

#endif // CHARACTER_H

