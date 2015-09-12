#pragma once

#include "cocos2d.h"
#include "MapLayer.h"
#include "MapTile.h"


class GameScene : public cocos2d::Layer
{
public:
	static  cocos2d::Scene * createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

private:

	EventListenerTouchOneByOne * touchEventListener;
	void initGestures();
	virtual bool onTouchBegan(Touch * touch, Event * event);
	virtual void onTouchMoved(Touch * touch, Event * event);
	virtual void onTouchEnded(Touch * touch, Event * event);
	virtual void onTouchCancelled(Touch * touch, Event * event);
	Vec2 touchBeginLocation;

	void buildCurrentRowToMapCallback(Ref * sender);
	void generateNewRow();

	void moveCharacterCallback(Ref * sender);
	void moveCharacter();

	void showMapTileDetailCallback(Ref * sender);

	void stepUpdate();

	void showBattleScene(Character * character, Monster * monster);

	MapLayer * mapLayer;
	map<int, MapTile*> currentRow;
};

