#pragma once

#include <string>
#include "cocos2d.h"

using namespace std;

class Character : public Sprite
{
public:
	virtual bool init(){
		Sprite::init();
		return true;
	}

	int getDamage();

	string name = "";
	int characterId;
	
	int maxHealth = 10;
	int currentHealth = 10;

	int damage = 5;
	double damageMultiplier = 1;
	double criticalChance = 0;
	double criticalMultiplier = 1.5;
	
	int defense = 5;
	double blockChance = 0;
	double blockMultipler = 0.5;
	double dodgeChance = 0.1;
	
	int speed = 5;
	double attackInterval = 1.5;
	double attackSpeed = 1;

	CREATE_FUNC(Character);
};
