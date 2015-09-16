#ifndef  _LIBRARY_API_H_
#define  _LIBRARY_API_H_

#include "cocos2d.h"
#include "PathType.h"
#include "Item.h"
#include "RamdomProperty.h"

USING_NS_CC;

class LibraryAPI {
public:
	LibraryAPI();

	static LibraryAPI * getInstance(){
		static LibraryAPI singleton = LibraryAPI();
		return &singleton;
	}

	int getDropType();
	int getDropType(double dropRate);
	int getDropType(double dropRate, int dropType, int dropMultiplier);

	int getDropItem(int dropType);

	void newRandomSeed(unsigned long seed);

	int getRandomNumber(const unsigned int min, const unsigned int max);

	////weapon
	char * getItemTypeName(int type){
		if (type == ItemType::Armor) return "armor";
		else if (type == ItemType::Boot) return "boot";
		else if (type == ItemType::Consumable) return "consumable";
		else if (type == ItemType::Helmet) return "helmet";
		else if (type == ItemType::Weapon) return "weapon";
		return "";
	}
	//void setWeaponProperties(const int weaponType){

	//}

	////trap
	//void setTrapProperties(const int TrapType){

	//}

	//path
	int getPathTypeIntWithChar(const char * type){
		return pathType->getPathTypeIntWithChar(type);
	}
	char * getPathTypeCharWithInt(const int type){
		return pathType->getPathTypeCharWithInt(type);
	}

	bool pathUpEnabled(const int type){
		return pathType->pathUpEnabled(type);
	}
	bool pathUpEnabled(const char * type){
		return pathType->pathUpEnabled(type);
	}
	bool pathLeftEnabled(const int type){
		return pathType->pathLeftEnabled(type);
	}
	bool pathLeftEnabled(const char * type){
		return pathType->pathLeftEnabled(type);
	}
	bool pathDownEnabled(const int type){
		return pathType->pathDownEnabled(type);
	}
	bool pathDownEnabled(const char * type){
		return pathType->pathDownEnabled(type);
	}
	bool pathRightEnabled(const int type){
		return pathType->pathRightEnabled(type);
	}
	bool pathRightEnabled(const char * type){
		return pathType->pathRightEnabled(type);
	}

private:
	PathType * pathType;
	RamdomProperty * randomDelegate;
};




#endif