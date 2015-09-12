#ifndef _MAP_TILE_H_
#define _MAP_TILE_H_

#include "cocos2d.h"
#include "Item.h"
#include "Trap.h"
#include "Monster.h"

USING_NS_CC;

class MapTile : public Layer {
public:
	virtual bool init();

	void setProperty(
		const int pathType, const int itemId,
		const int monsterId, const int trapId,
		const Size size);

	void setPathType(const int pathType);
	
	void setSize(Size size);

	Sprite * pathIndicator = NULL;
	Sprite * path = NULL;
	Item * item = NULL;
	Monster * monster = NULL;
	Trap * trap = NULL;

	int pathType;
	int itemId;
	int monsterId;
	int trapId;

	bool upEnabled;
	bool downEnabled;
	bool leftEnabled;
	bool rightEnabled;

	CREATE_FUNC(MapTile);
};

#endif