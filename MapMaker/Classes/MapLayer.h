#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"

#include <map>

#include "MapTile.h"
#include "Character.h"

USING_NS_CC;
using namespace ui;
using namespace std;


struct MapIndexPath
{
	int row;
	int column;
	MapIndexPath(int row, int column){
		this->row = row;
		this->column = column;
	}
};

class MapLayer : public Layer
{
public:
	virtual bool init();
	void initGestures();
	void initWithFileAndCharactorType(
		string name, const int characterType);

	void setRow(map<int, MapTile *> mapRow);

	void FindPathToPosition(const int row, const int column);
	bool existInMapForPathFinding(const int row, const int column);
		
	int maxRowNumber;
	int currentRowIndex;

	ScrollView * container;

	Character * character;
	int characterRow;
	int characterColumn;

	Sprite * nextRowIndicator;

	map<int, map<int, MapTile *>> mapArray;
	map<int, map<int, int>> mapForPathFinding;
	vector<string> moveDirection;
	bool touchEnabled = true;

	EventListenerTouchOneByOne * touchEventListener;
	virtual bool onTouchBegan(Touch * touch, Event * event);
	virtual void onTouchMoved(Touch * touch, Event * event);
	virtual void onTouchEnded(Touch * touch, Event * event);
	virtual void onTouchCancelled(Touch * touch, Event * event);
	Vec2 touchLocation;
	Vec2 localTouchLocation;
	int selectedRow, selectedColumn;

	CREATE_FUNC(MapLayer);
private:


};

