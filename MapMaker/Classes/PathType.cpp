#include "PathType.h"

PathType::PathType(){
	pathCharToInt.insert(pair<char*, int>("NONE", 0));
	pathCharToInt.insert(pair<char*, int>("W", 1));
	pathCharToInt.insert(pair<char*, int>("A", 2));
	pathCharToInt.insert(pair<char*, int>("S", 3));
	pathCharToInt.insert(pair<char*, int>("D", 4));
	pathCharToInt.insert(pair<char*, int>("WS", 5));
	pathCharToInt.insert(pair<char*, int>("AD", 6));
	pathCharToInt.insert(pair<char*, int>("WA", 7));
	pathCharToInt.insert(pair<char*, int>("AS", 8));
	pathCharToInt.insert(pair<char*, int>("SD", 9));
	pathCharToInt.insert(pair<char*, int>("WD", 10));
	pathCharToInt.insert(pair<char*, int>("WAS", 11));
	pathCharToInt.insert(pair<char*, int>("ASD", 12));
	pathCharToInt.insert(pair<char*, int>("WSD", 13));
	pathCharToInt.insert(pair<char*, int>("WAD", 14));
	pathCharToInt.insert(pair<char*, int>("WASD", 15));

	pathIntToChar.insert(pair<int, char*>(0, "NONE"));
	pathIntToChar.insert(pair<int, char*>(1, "W"));
	pathIntToChar.insert(pair<int, char*>(2, "A"));
	pathIntToChar.insert(pair<int, char*>(3, "S"));
	pathIntToChar.insert(pair<int, char*>(4, "D"));
	pathIntToChar.insert(pair<int, char*>(5, "WS"));
	pathIntToChar.insert(pair<int, char*>(6, "AD"));
	pathIntToChar.insert(pair<int, char*>(7, "WA"));
	pathIntToChar.insert(pair<int, char*>(8, "AS"));
	pathIntToChar.insert(pair<int, char*>(9, "SD"));
	pathIntToChar.insert(pair<int, char*>(10, "WD"));
	pathIntToChar.insert(pair<int, char*>(11, "WAS"));
	pathIntToChar.insert(pair<int, char*>(12, "ASD"));
	pathIntToChar.insert(pair<int, char*>(13, "WSD"));
	pathIntToChar.insert(pair<int, char*>(14, "WAD"));
	pathIntToChar.insert(pair<int, char*>(15, "WASD"));
}


bool PathType::pathUpEnabled(const int type){
	const int t = type;
	if (t == 1 || t == 5 || t == 7 || t == 10 || t == 11 || t == 13 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathUpEnabled(const char * type){
	const int t = pathCharToInt[type];
	if (t == 1 || t == 5 || t == 7 || t == 10 || t == 11 || t == 13 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathLeftEnabled(const int type){
	const int t = type;
	if (t == 2 || t == 6 || t == 7 || t == 8 || t == 11 || t == 12 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathLeftEnabled(const char * type){
	const int t = pathCharToInt[type];
	if (t == 2 || t == 6 || t == 7 || t == 8 || t == 11 || t == 12 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathDownEnabled(const int type){
	const int t = type;
	if (t == 3 || t == 5 || t == 8 || t == 9 || t == 11 || t == 12 || t == 13 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathDownEnabled(const char * type){
	const int t = pathCharToInt[type];
	if (t == 3 || t == 5 || t == 8 || t == 9 || t == 11 || t == 12 || t == 13 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathRightEnabled(const int type){
	const int t = type;
	if (t == 4 || t == 6 || t == 9 || t == 10 || t == 12 || t == 13 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}

bool PathType::pathRightEnabled(const char * type){
	const int t = pathCharToInt[type];
	if (t == 4 || t == 6 || t == 9 || t == 10 || t == 12 || t == 13 || t == 14 || t == 15) {
		return true;
	}
	else {
		return false;
	}
}
