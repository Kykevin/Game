#include "LibraryAPI.h"


LibraryAPI::LibraryAPI(){
	pathType = new PathType;
	randomDelegate = new RamdomProperty;
}

int LibraryAPI::getDropType(){
	return randomDelegate->getDropType();
}
int LibraryAPI::getDropType(double dropRate){
	return randomDelegate->getDropType(dropRate);
}
int LibraryAPI::getDropType(double dropRate, int dropType, int dropMultiplier){
	return randomDelegate->getDropType(dropRate, dropType, dropMultiplier);
}

int LibraryAPI::getDropItem(int dropType){
	return randomDelegate->getDropItem(dropType);
}

void LibraryAPI::newRandomSeed(const unsigned long seed){
	randomDelegate->newRandomSeed(seed);
}

int LibraryAPI::getRandomNumber(const unsigned int min, const unsigned int max){
	return randomDelegate->getRandomNumber(min, max);
}