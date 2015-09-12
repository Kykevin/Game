#pragma once

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Monster : public Sprite
{
public:
	virtual bool init(){
		Sprite::init();
		return true;
	}

	int getDamage();

	string name = "Dinosaur";
	int monsterId;

	int maxHealth = 7;
	int currentHealth = 7;

	int damage = 4;
	double damageMultiplier = 1;
	double criticalChance = 0;
	double criticalMultiplier = 1.5;

	int defense = 2;
	double blockChance = 0;
	double blockMultipler = 0.5;
	double dodgeChance = 0;

	int speed = 3;
	double attackInterval = 2;
	double attackSpeed = 1;

	CREATE_FUNC(Monster);
};
