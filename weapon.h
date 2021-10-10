#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class weapon
{
public: 
	weapon(std::string name, float multiplier, float c);
	weapon(std::string name, float multiplier);
	void setWeaponName(std::string x);
	void setDamageMultiplier(float y);
	void WeaponUpgrade1();
	void WeaponUpgrade2();
	void WeaponUpgrade3();
	std::string getWeaponName()
	{
		return weaponName;
	}
	float getDamageMultiplier()
	{
		return damageMultiplier;
	}
private:
	std::string weaponName;
	float damageMultiplier;
};

#endif // WEAPON_H


