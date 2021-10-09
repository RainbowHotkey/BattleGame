#include "Character.h"
#include <string>
#include <iostream>

using namespace std;


character::character(string type, int hp, int b, int doge, float armor, int credits, int lvl)
{
	setClass(type);
	setHp(hp);
	setStr(b);
	setDoge(doge);
	setArmor(armor);
	setCredits(credits);
	setLvl(lvl);
}
void character::setClass(string x)
{
	pClass = x;
}
void character::setHp(int h)
{
	hp = h;
}
void character::setStr(int s)
{
	str = s;
}
void character::setDoge(int d)
{
	doge = d;
}
void character::setArmor(int arm)
{
	armor = arm;
}
void character::setCredits(int c)
{
	credits = c;
}
void character::setLvl(int l)
{
	lvl = l;
}
void character::addHp()
{
	hp++;
}
void character::minHp()
{
	hp--;
}
void character::addCredits()
{
	credits++;
}
void character::minCredits()
{
	credits--;
}
void character::addLvl()
{
	lvl++;
}
