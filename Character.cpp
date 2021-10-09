#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


character::character(string z, int a, int b, int c, float i, int e, int f)
{
    setClass(z);
    setHp(a);
    setStr(b);
    setDoge(c);
    setArmor(i);
    setCredits(e);
    setLevel(f);
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
