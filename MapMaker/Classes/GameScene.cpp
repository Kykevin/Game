#include "GameScene.h"
#include "LibraryAPI.h"
#include "BattleScene.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mapLayer = MapLayer::create();
	mapLayer->maxRowNumber = 8;
	mapLayer->currentRowIndex = 0;
	mapLayer->initWithFileAndCharactorType("level/level001", 1);
	this->addChild(mapLayer->container);

	this->generateNewRow();

	initGestures();

	LibraryAPI::getInstance()->newRandomSeed(0);

	NotificationCenter::getInstance()->addObserver(
		this, CC_CALLFUNCO_SELECTOR(GameScene::showMapTileDetailCallback), "showMapTileDetail", NULL);
	NotificationCenter::getInstance()->addObserver(
		this, CC_CALLFUNCO_SELECTOR(GameScene::buildCurrentRowToMapCallback), "buildCurrentRowToMap", NULL);
	NotificationCenter::getInstance()->addObserver(
		this, CC_CALLFUNCO_SELECTOR(GameScene::moveCharacterCallback), "moveCharacter", NULL);
	return true;
}

void GameScene::initGestures(){
	touchEventListener = EventListenerTouchOneByOne::create();
	touchEventListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchEventListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	touchEventListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	touchEventListener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		touchEventListener, this);
}

bool GameScene::onTouchBegan(Touch * touch, Event * event){
	touchBeginLocation = touch->getLocation();
	return true;
}

void GameScene::onTouchMoved(Touch * touch, Event * event){

}

void GameScene::onTouchEnded(Touch * touch, Event * event){
	if (touch->getLocation().distance(touchBeginLocation) < 10) {
		log("touchUp");
	}
}

void GameScene::onTouchCancelled(Touch * touch, Event * event){

}

void GameScene::buildCurrentRowToMapCallback(Ref * sender){
	log("buildCurrentRowToMap");
	mapLayer->setRow(currentRow);
	this->generateNewRow();
}

void GameScene::generateNewRow(){
	for (int i = 0; i < 5; ++i){ this->currentRow[i] = NULL; }

	this->currentRow[0] = MapTile::create();
	this->currentRow[0]->setProperty(15, 0, 0, 0, Size(200, 200));
	this->currentRow[0]->setPosition(Vec2(40, 370));

	this->currentRow[1] = MapTile::create();
	this->currentRow[1]->setProperty(15, 0, 0, 0, Size(200, 200));
	this->currentRow[1]->setPosition(Vec2(240, 370));

	this->currentRow[2] = MapTile::create();
	this->currentRow[2]->setProperty(15, 0, 0, 0, Size(200, 200));
	this->currentRow[2]->setPosition(Vec2(440, 370));

	this->currentRow[3] = MapTile::create();
	this->currentRow[3]->setProperty(15, 0, 0, 0, Size(200, 200));
	this->currentRow[3]->setPosition(Vec2(640, 370));

	this->currentRow[4] = MapTile::create();
	this->currentRow[4]->setProperty(15, 0, 0, 0, Size(200, 200));
	this->currentRow[4]->setPosition(Vec2(840, 370));

	this->addChild(currentRow[0]);
	this->addChild(currentRow[1]);
	this->addChild(currentRow[2]);
	this->addChild(currentRow[3]);
	this->addChild(currentRow[4]);
}

void GameScene::moveCharacterCallback(Ref * sender){
	stepUpdate();
}

void GameScene::moveCharacter(){
	if (!mapLayer->moveDirection.empty()) {
		mapLayer->touchEnabled = false;
		const string direction = mapLayer->moveDirection.back();
		mapLayer->moveDirection.pop_back();
		if (direction == "up") {
			auto move = MoveBy::create(0.4f, Vec2(0, 160));
			mapLayer->characterRow += 1;
			mapLayer->character->runAction(Sequence::create(move,
				CallFunc::create(CC_CALLBACK_0(GameScene::stepUpdate, this)),
				NULL));
		}
		else if (direction == "down") {
			auto move = MoveBy::create(0.4f, Vec2(0, -160));
			mapLayer->characterRow -= 1;
			mapLayer->character->runAction(Sequence::create(move,
				CallFunc::create(CC_CALLBACK_0(GameScene::stepUpdate, this)),
				NULL));
		}
		else if (direction == "left") {
			auto move = MoveBy::create(0.4f, Vec2(-160, 0));
			mapLayer->characterColumn -= 1;
			mapLayer->character->runAction(Sequence::create(move,
				CallFunc::create(CC_CALLBACK_0(GameScene::stepUpdate, this)),
				NULL));
		}
		else if (direction == "right") {
			auto move = MoveBy::create(0.4f, Vec2(160, 0));
			mapLayer->characterColumn += 1;
			mapLayer->character->runAction(Sequence::create(move,
				CallFunc::create(CC_CALLBACK_0(GameScene::stepUpdate, this)),
				NULL));
		}
	}
	else {
		this->mapLayer->touchEnabled = true;
	}

}


void GameScene::showMapTileDetailCallback(Ref * sender){
	auto mapTile = (MapTile *)sender;
	log("pathType:%d", mapTile->pathType);
}

void GameScene::stepUpdate(){

	if (mapLayer->mapArray[mapLayer->characterRow]
		[mapLayer->characterColumn]->monsterId != 0){
		showBattleScene(mapLayer->character,
			mapLayer->mapArray[mapLayer->characterRow][mapLayer->characterColumn]->monster);
	}
	else{
		moveCharacter();
	}
}

void GameScene::showBattleScene(Character * character, Monster * monster){
	auto battleScene = BattleScene::create(); 
	this->addChild(battleScene->mask);
}
