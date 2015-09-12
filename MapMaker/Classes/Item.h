#pragma once

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

enum ItemType
{
	Consumable = 1, //1
	Weapon,			//2
	Armor,			//3
	Helmet,			//4
	Boot			//5
};

class Item : public Sprite
{
public:
	virtual bool init(){
		Sprite::init();
		return true;
	}

	string name = "Common Sword";
	int itemId; 
	int itemType = ItemType::Weapon;


	//weapon
	bool ranged = false;
	int damageModifier = 3;
	double damageMultiplier = 1;
	double criticalChance = 0;
	double criticalMultiplier = 1.5;

	CREATE_FUNC(Item);
};


