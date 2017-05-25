// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <string>

class Player;

class Monster
{
public:
	Monster(const std::string& name, int hp, int acc,
		int xpReward, int armor, const std::string& weaponName,
		int lowDamage, int highDamage, int gold);
	
	bool isDead();

	int getXPReward();
	int getGold();
	std::string getName();
	int getArmor();

	void attack(Player& player);
	void takeDamage(int damage);
	void displayHitPoints();

private:
	std::string mName;
	int mHitPoints;
	int mAccuracy;
	int mExpReward;
	int mArmor;
	Weapon mWeapon;
	int mGold;
};

#endif // MONSTER_H
