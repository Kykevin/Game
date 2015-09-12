#pragma once

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Trap : public Sprite
{
public:
	virtual bool init(){
		Sprite::init();
		return true;
	}

	string name = "Spike Trap";
	int trapId;
	int stepDelay = 0;
	int healthModifier = -2;

	CREATE_FUNC(Trap);
};
