#ifndef __RANDOMPROPERTY_H__
#define __RANDOMPROPERTY_H__

#include "dropType.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class RamdomProperty
{
public:
	RamdomProperty();

	int getDropType();
	int getDropType(double dropRate);
	int getDropType(double dropRate, int dropType, int dropMultiplier);

	int getDropItem(int dropType);

	void newRandomSeed(unsigned long seed);

	int getRandomNumber(const unsigned int min, const unsigned int max);


private:
	default_random_engine * randomEngine = NULL;

	//see dropType
	int dropTypeRate[8];
	int dropTotal = 700;

	//item0XX
	int itemList[2];
	int itemTotal;
	//start from 101-200
	//item1XX
	int weaponList[2];
	int weaponTotal;
	//start from 201-300
	//item2XX
	int armorList[2];
	int armorTotal;
	//start from 301-400
	//item3XX
	int bookList[2];
	int bookTotal;
	//monsterXXX
	int monsterList[2];
	int monsterTotal;
	//bossXXX
	int bossList[2];
	int bossTotal;
	//trapXXX
	int trapList[2];
	int trapTotal;
};

#endif