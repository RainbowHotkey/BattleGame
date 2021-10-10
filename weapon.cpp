#include "weapon.h"
#include <iostream>
#include <string>

weapon::weapon(std::string name, float multiplier)
{
	setWeaponName(name);
	setDamageMultiplier(multiplier);
}
void weapon::setWeaponName(std::string x)
{
	weaponName = x;
}
void weapon::setDamageMultiplier(float y)
{
	damageMultiplier = y;
}
void weapon::WeaponUpgrade1()
{
	damageMultiplier += 0.28;
}
void weapon::WeaponUpgrade2()
{
	damageMultiplier += 0.32;
}
void weapon::WeaponUpgrade3()
{
	damageMultiplier += 0.40;
}
