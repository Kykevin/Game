#include "BattleScene.h"

bool BattleScene::init(){
	Sprite::init();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mask = LayerColor::create(Color4B(0, 0, 0, 175), visibleSize.width, visibleSize.height);
	mask->setPosition(0, 0);
	mask->addChild(this);

	this->setContentSize(Size(1080, 670));
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(Vec2(0, 960));

	auto tempBattleGround = LayerColor::create(Color4B(255, 255, 255, 255), 1080, 670);
	this->addChild(tempBattleGround);

	initGestures();

	return true;
}

void BattleScene::initGestures(){
	touchEventListener = EventListenerTouchOneByOne::create();
	touchEventListener->onTouchBegan = CC_CALLBACK_2(BattleScene::onTouchBegan, this);
	touchEventListener->onTouchMoved = CC_CALLBACK_2(BattleScene::onTouchMoved, this);
	touchEventListener->onTouchEnded = CC_CALLBACK_2(BattleScene::onTouchEnded, this);
	touchEventListener->onTouchCancelled = CC_CALLBACK_2(BattleScene::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		touchEventListener, this->mask);
	touchEventListener->setSwallowTouches(true);
}


bool BattleScene::onTouchBegan(Touch * touch, Event * event){
	touchLocation = touch->getLocation();
	localTouchLocation = convertToNodeSpace(touchLocation);
	log("touch BattleScene");
	return true;
}

void BattleScene::onTouchMoved(Touch * touch, Event * event){

}

void BattleScene::onTouchEnded(Touch * touch, Event * event){

}

void BattleScene::onTouchCancelled(Touch * touch, Event * event){

}