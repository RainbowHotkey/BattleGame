#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


character::character(string name, int hp, int att, int dogge, float armor, int cred, int level)
{
    setClass(name);
    setHp(hp);
    setStr(att);
    setDoge(dogge);
    setArmor(armor);
    setCredits(cred);
    setLevel(level);
}
void character::setClass(string x)
{
    pClass = x;
}
void character::setHp(int h)
{
    health = h;
}
void character::setStr(int s)
{
    str = s;
}
void character::setDoge(int d)
{
    dex = d;
}
void character::setArmor(float arm)
{
    armor = arm;
}
void character::setCredits(int c)
{
    credits = c;
}
void character::setLevel(int l)
{
    level = l;
}
void character::addHealth()
{
    ++health;
}
void character::minHealth()
{
    --health;
}
void character::addCredits()
{
    ++credits;
}
void character::minCredits()
{
    --credits;
}
void character::addLevel()
{
    ++level;
}
