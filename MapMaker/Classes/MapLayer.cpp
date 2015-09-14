#include "MapLayer.h"


bool MapLayer::init(){
	Layer::init();
	container = ScrollView::create();

	container->setContentSize(Size(800, 1080));
	container->setAnchorPoint(Vec2(0, 0));
	container->setPosition(Vec2(40, 600));
	container->addChild(this);

	return true;
}

void MapLayer::initGestures(){
	touchEventListener = EventListenerTouchOneByOne::create();
	touchEventListener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
	touchEventListener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
	touchEventListener->onTouchEnded = CC_CALLBACK_2(MapLayer::onTouchEnded, this);
	touchEventListener->onTouchCancelled = CC_CALLBACK_2(MapLayer::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		touchEventListener, this);

}

void MapLayer::initWithFileAndCharactorType(
	string name, const int characterType){
	auto background = LayerColor::create(Color4B::WHITE);
	background->setContentSize(Size(800, maxRowNumber * 160));
	background->setAnchorPoint(Vec2(0, 0));
	insertChild(background, -1);

	this->setContentSize(Size(800, maxRowNumber * 160));
	container->setInnerContainerSize(Size(800, maxRowNumber * 160));
	container->scrollToBottom(0, false);

	
	MapTile * newTile = MapTile::create();
	newTile->setProperty(3, 0, 1, 0, Size(160, 160));
	newTile->setPosition(Vec2(2 * 160, (maxRowNumber - 1) * 160));
	mapArray[maxRowNumber - 1][2] = newTile;
	this->insertChild(newTile, 0);


	newTile = MapTile::create();
	newTile->setProperty(10, 0, 1, 0, Size(160, 160));
	newTile->setPosition(Vec2(0 * 160, 0));
	mapArray[0][0] = newTile;
	this->insertChild(newTile, 0);

	newTile = MapTile::create();
	newTile->setProperty(7, 0, 0, 0, Size(160, 160));
	newTile->setPosition(Vec2(4 * 160, 0));
	mapArray[0][4] = newTile;
	this->insertChild(newTile, 0);

	for (int i = 1; i < 4; ++i){
		newTile = MapTile::create();
		newTile->setProperty(14, 0, 0, 0, Size(160, 160));
		newTile->setPosition(Vec2(i * 160, 0));
		mapArray[0][i] = newTile;
		this->insertChild(newTile, 0);
	}

	character = Character::create();
	character->setTexture("character/character001.png");
	character->setAnchorPoint(Vec2(0, 0));
	characterColumn = 2;
	characterRow = 0;
	character->setPosition(Vec2(characterColumn * 160, characterRow * 160));
	this->insertChild(character, 10);

	nextRowIndicator = Sprite::create("interface/nextRowIndicator.png");
	nextRowIndicator->setAnchorPoint(Vec2(0, 0));
	nextRowIndicator->setPosition(Vec2(0, (currentRowIndex + 1) * 160));
	this->insertChild(nextRowIndicator, 0);

	initGestures();
}

void MapLayer::setRow(map<int, MapTile *> mapRow){
	++currentRowIndex;
	if (currentRowIndex < maxRowNumber - 2) {
		nextRowIndicator->setPosition(Vec2(0, (currentRowIndex + 1) * 160));
	}
	else {
		nextRowIndicator->removeFromParent();
		nextRowIndicator = NULL;
	}
	for (int index = 0; index < 5; ++index){
		mapRow[index]->setSize(Size(160, 160));
		mapRow[index]->setPosition(Vec2(index * 160, currentRowIndex * 160));
		mapRow[index]->retain();
		mapRow[index]->removeFromParent();
		addChild(mapRow[index]);
		mapRow[index]->release();
	}
	mapArray[currentRowIndex].clear();
	mapArray[currentRowIndex] = mapRow;
}

void MapLayer::FindPathToPosition(const int row, const int column){
	vector<MapIndexPath> queue;
	mapForPathFinding.clear();
	//current 
	int cRow = characterRow, cColumn = characterColumn;
	MapIndexPath indexPath = MapIndexPath(characterRow, characterColumn);
	queue.push_back(indexPath);
	mapForPathFinding[cRow][cColumn] = 0;
	while (!queue.empty()){
		cRow = queue.front().row;
		cColumn = queue.front().column;
		//check up
		if (mapArray[cRow][cColumn]->upEnabled == true
			&& mapArray[cRow + 1][cColumn] != NULL
			&& !existInMapForPathFinding(cRow + 1, cColumn)){
			mapForPathFinding[cRow + 1][cColumn] = mapForPathFinding[cRow][cColumn] + 1;
			if (cRow + 1 == row  && cColumn == column){
				break;
			}
			queue.push_back(MapIndexPath(cRow + 1, cColumn));
		}
		//check down
		if (mapArray[cRow][cColumn]->downEnabled == true
			&& mapArray[cRow - 1][cColumn] != NULL
			&& !existInMapForPathFinding(cRow - 1, cColumn)){
			mapForPathFinding[cRow - 1][cColumn] = mapForPathFinding[cRow][cColumn] + 1;
			if (cRow - 1 == row && cColumn == column){
				break;
			}
			queue.push_back(MapIndexPath(cRow - 1, cColumn));
		}
		//check left
		if (mapArray[cRow][cColumn]->leftEnabled == true
			&& mapArray[cRow][cColumn - 1] != NULL
			&& !existInMapForPathFinding(cRow, cColumn - 1)){
			mapForPathFinding[cRow][cColumn - 1] = mapForPathFinding[cRow][cColumn] + 1;
			if (cRow == row && cColumn - 1 == column){
				break;
			}
			queue.push_back(MapIndexPath(cRow, cColumn - 1));
		}
		//check right
		if (mapArray[cRow][cColumn]->rightEnabled == true
			&& mapArray[cRow][cColumn + 1] != NULL
			&& !existInMapForPathFinding(cRow, cColumn + 1)){
			mapForPathFinding[cRow][cColumn + 1] = mapForPathFinding[cRow][cColumn] + 1;
			if (cRow == row && cColumn + 1 == column){
				break;
			}
			queue.push_back(MapIndexPath(cRow, cColumn + 1));
		}
		queue.erase(queue.begin());
		log("%d", queue.size());
	}
	if (existInMapForPathFinding(row, column)) {
		moveDirection.clear();
		cRow = row;
		cColumn = column;
		while (true){
			if (cRow == characterRow && cColumn == characterColumn){
				break;
			}
			if (existInMapForPathFinding(cRow - 1, cColumn)){
				if (mapForPathFinding[cRow - 1][cColumn] == mapForPathFinding[cRow][cColumn] - 1) {
					moveDirection.push_back("up");
					--cRow;
					continue;
				}
			}
			if (existInMapForPathFinding(cRow + 1, cColumn)){
				if (mapForPathFinding[cRow + 1][cColumn] == mapForPathFinding[cRow][cColumn] - 1) {
					moveDirection.push_back("down");
					++cRow;
					continue;
				}
			}
			if (existInMapForPathFinding(cRow, cColumn + 1)){
				if (mapForPathFinding[cRow][cColumn + 1] == mapForPathFinding[cRow][cColumn] - 1) {
					moveDirection.push_back("left");
					++cColumn;
					continue;
				}
			}
			if (existInMapForPathFinding(cRow, cColumn - 1)){
				if (mapForPathFinding[cRow][cColumn - 1] == mapForPathFinding[cRow][cColumn] - 1) {
					moveDirection.push_back("right");
					--cColumn;
					continue;
				}
			}
		}
		NotificationCenter::getInstance()->postNotification("moveCharacter");
	}
}

bool MapLayer::existInMapForPathFinding(const int row, const int column){
	if (mapForPathFinding.count(row) == 0){
		return false;
	}
	else if (mapForPathFinding[row].count(column) == 0){
		return false;
	}
	return true;
}

bool MapLayer::onTouchBegan(Touch * touch, Event * event){
	touchLocation = touch->getLocation();
	localTouchLocation = convertToNodeSpace(touchLocation);
	selectedColumn = localTouchLocation.x / 160;
	selectedRow = localTouchLocation.y / 160;
	//log("x:%f,y:%f", touchLocation.x, touchLocation.y);
	if (mapArray[selectedRow][selectedColumn] != NULL && touchEnabled == true){
		return true;
	}
	else if (nextRowIndicator != NULL){
		if (nextRowIndicator->getBoundingBox().containsPoint(localTouchLocation)){
			return true;
		}
	}
	return false;
}

void MapLayer::onTouchMoved(Touch * touch, Event * event){

}

void MapLayer::onTouchEnded(Touch * touch, Event * event){
	if (touch->getLocation().distance(touchLocation) < 10) {
		//log("touchUpInside");
		if (mapArray[selectedRow][selectedColumn] != NULL){
			NotificationCenter::getInstance()->postNotification(
				"showMapTileDetail", mapArray[selectedRow][selectedColumn]);
			FindPathToPosition(selectedRow, selectedColumn);
		}
		else if (nextRowIndicator != NULL){
			if (nextRowIndicator->getBoundingBox().containsPoint(localTouchLocation)){
				NotificationCenter::getInstance()->postNotification(
					"buildCurrentRowToMap");
			}
		}
	}
}

void MapLayer::onTouchCancelled(Touch * touch, Event * event){

}


