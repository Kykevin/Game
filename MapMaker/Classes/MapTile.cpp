#include "MapTile.h"
#include "LibraryAPI.h"

/*
zOrder
path 0
pathIndicator 5
trap 10
item armor buff 15
monster 20

*/

bool MapTile::init(){
	Layer::init();
	return true;
}

void MapTile::setProperty(
	const int pathType, const int itemId,
	const int monsterId, const int trapId,
	const Size size){

	//auto temp = LayerColor::create(Color4B(random(0, 255), random(0, 255), random(0, 255), 255));
	//temp->setContentSize(size);
	//addChild(temp);

	setContentSize(size);

	this->pathType = pathType;
	this->itemId = itemId;
	this->monsterId = monsterId;
	this->trapId = trapId;

	if (pathType != 0){
		setPathType(pathType);
	}

	if (trapId != 0){
		trap = Trap::create();
		trap->setTexture("item/trap001.png");
		trap->setContentSize(size);
		trap->setScale(size.height / 200);
		trap->setAnchorPoint(Vec2(0, 0));
		insertChild(trap, 10);
	}

	if (itemId != 0){
		string itemType = LibraryAPI::getInstance()->getItemTypeName(ItemType::Weapon);
		item = Item::create();
		item->setTexture("item/" + itemType + "001.png");
		item->setContentSize(size);
		item->setScale(size.height / 200);
		item->setAnchorPoint(Vec2(0, 0));
		insertChild(item, 15);
	}

	if (monsterId != 0){
		monster = Monster::create();
		monster->setTexture("item/monster001.png");
		monster->setContentSize(size);
		monster->setScale(size.height / 200);
		monster->setAnchorPoint(Vec2(0, 0));
		insertChild(monster, 20);
	}

}

void MapTile::setPathType(const int pathType){
	string pathString = LibraryAPI::getInstance()->getPathTypeCharWithInt(pathType);
	path = Sprite::create("path/path" + pathString + "001.png");
	path->setContentSize(this->getContentSize());
	path->setScale(this->getContentSize().height / 200);
	path->setAnchorPoint(Vec2(0, 0));
	insertChild(path, 0);
	upEnabled = LibraryAPI::getInstance()->pathUpEnabled(pathType);
	leftEnabled = LibraryAPI::getInstance()->pathLeftEnabled(pathType);
	downEnabled = LibraryAPI::getInstance()->pathDownEnabled(pathType);
	rightEnabled = LibraryAPI::getInstance()->pathDownEnabled(pathType);
}

void MapTile::setSize(Size size){
	if (path != NULL){
		path->setContentSize(size);
		path->setScale(size.height / 200);
	}
	if (monster != NULL){
		monster->setContentSize(size);
		monster->setScale(size.height / 200);
	}
	if (item != NULL){
		item->setContentSize(size);
		item->setScale(size.height / 200);
	}
	if (trap != NULL){
		trap->setContentSize(size);
		trap->setScale(size.height / 200);
	}
	this->setContentSize(size);
}