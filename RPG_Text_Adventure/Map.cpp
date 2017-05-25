#include <iostream>
#include "Random.h"
#include "Map.h"
using namespace std;

Map::Map()
{
	// Player starts at origin (0, 0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}

int Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map::movePlayer()
{
	int selection = 1;
	cout << "1) North 2) East 3) South 4) West: ";
	cin >> selection;

	// Update coordinates based on selection
	switch (selection)
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	case 4: // West
		mPlayerXPos--;
		break;
	}
	cout << endl;
}

Monster* Map::checkRandomEndounter()
{
	int roll = Random(0, 20);
	Monster* monster = 0;

	if (roll <= 5)
	{
		// No encounter, return a null pointer
		return 0;
	}
	else if (roll >= 6 && roll <= 10)
	{
		monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7, Random(0, 4));
		cout << "You encountered an Orc!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (roll >= 11 && roll <= 15)
	{
		monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5, Random(0, 2));
		cout << "You encountered a Goblin!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (roll >= 16 && roll <= 19)
	{
		monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8, Random(0, 6));
		cout << "You encountered an Ogre!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (roll == 20)
	{
		monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20, Random(5, 25));
		cout << "You encountered an Orc Lord!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	return monster;
}

void Map::printPlayerPos()
{
	cout << "Player Position = (" << mPlayerXPos << ", "
		<< mPlayerYPos << ")" << endl << endl;
}