// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
using namespace std;

Player::Player()
{
	mName = "Default";
	mClassName = "Default";
	mAccuracy = 0;
	mHitPoints = 0;
	mMaxHitPoints = 0;
	mExpPoints = 0;
	mNextLevelExp = 0;
	mLevel = 0;
	mArmor = 0;
	mWeapon.mName = "Default Weapon";
	mWeapon.mDamageRange.mLow = 0;
	mWeapon.mDamageRange.mHigh = 0;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

std::string Player::getName()
{
	return mName;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input character's name
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection
	cout << "Please select a character class..." << endl;
	cout << "1) Fighter 2) Wizard 3) Cleric 4) Thief : ";

	int characterNum = 1;
	cin >> characterNum;

	switch (characterNum)
	{
	case 1: // Fighter
		mClassName = "Fighter";
		mAccuracy = 10;
		mHitPoints = 20;
		mMaxHitPoints = 20;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 4;
		mGold = 10;
		mWeapon.mName = "Long Sword";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 8;
		break;
	case 2: // Wizard
		mClassName = "Wizard";
		mAccuracy = 5;
		mHitPoints = 10;
		mMaxHitPoints = 10;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 1;
		mGold = 10;
		mWeapon.mName = "Staff";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 4;
		break;
	case 3: // Cleric
		mClassName = "Cleric";
		mAccuracy = 8;
		mHitPoints = 15;
		mMaxHitPoints = 15;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 3;
		mGold = 10;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	default: // Thief
		mClassName = "Thief";
		mAccuracy = 7;
		mHitPoints = 12;
		mMaxHitPoints = 12;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 2;
		mGold = 10;
		mWeapon.mName = "Daggers";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	}
}

bool Player::attack(Monster& monster)
{
	int selection = 1;
	cout << "1) Attack 2) Run: ";
	cin >> selection;
	cout << endl;

	switch (selection)
	{
	case 1:
		cout << "You attack an " << monster.getName()
			<< " with a " << mWeapon.mName << endl;
		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mDamageRange);
			int totalDamage = damage - monster.getArmor();
			if (totalDamage <= 0)
			{
				cout << "Your attach failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage
					<< " damage!" << endl;
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		return false;
		break;
	case 2:
		// 25% chance of being able to run.
		int roll = Random(1, 4);

		if (roll == 1)
		{
			cout << "You run away!" << endl;
			return true;
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}
}

void Player::levelUp()
{
	if (mExpPoints >= mNextLevelExp)
	{
		cout << "You gained a level!" << endl;

		// Increment level
		mLevel++;

		// Set experience points required for next level
		mNextLevelExp = mLevel * mLevel * 1000;

		// Increase stats randomly
		mAccuracy += Random(1, 3);
		mMaxHitPoints += Random(2, 6);
		mArmor += Random(1, 2);

		// Give player full hitpoints when they level up
		mHitPoints = mMaxHitPoints;
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;
	mHitPoints = mMaxHitPoints;
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Name = " << mName << endl;
	cout << "Class = " << mClassName << endl;
	cout << "Accuracy = " << mAccuracy << endl;
	cout << "Hitpoints = " << mHitPoints << endl;
	cout << "MaxHitpoints = " << mMaxHitPoints << endl;
	cout << "Gold = " << mGold << endl;
	cout << "XP = " << mExpPoints << endl;
	cout << "XP for next Lvl = " << mNextLevelExp << endl;
	cout << "Level = " << mLevel << endl;
	cout << "Armor = " << mArmor << endl;
	cout << "Weapon Name = " << mWeapon.mName << endl;
	cout << "weapon Damage = " << mWeapon.mDamageRange.mLow << "-"
		<< mWeapon.mDamageRange.mHigh << endl;
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp, int gold)
{
	cout << "You won the battle!" << endl;
	cout << "You found " << gold << " gold!" << endl;
	cout << "You win " << xp << " experience points!" << endl << endl;
	mGold += gold;
	mExpPoints += xp;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}