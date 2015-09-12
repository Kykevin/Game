#ifndef __BATTLE_LAYER_H__
#define __BATTLE_LAYER_H__

#include "cocos2d.h"
#include "Monster.h"
#include "Character.h"
USING_NS_CC;

class BattleScene : public Sprite
{
public:
	virtual bool init();
	void initGestures();

	LayerColor * mask;

	Character * character;
	Monster * Monster;

	EventListenerTouchOneByOne * touchEventListener;
	virtual bool onTouchBegan(Touch * touch, Event * event);
	virtual void onTouchMoved(Touch * touch, Event * event);
	virtual void onTouchEnded(Touch * touch, Event * event);
	virtual void onTouchCancelled(Touch * touch, Event * event);
	Vec2 touchLocation;
	Vec2 localTouchLocation;

	CREATE_FUNC(BattleScene);
private:
};

#endif