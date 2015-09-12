#pragma once

#include <map>

using namespace std;

//enum TileType
//{
//	// W: 1 5 7 10 11 13 14 15
//	// A: 2 6 7 8 11 12 14 15
//	// S: 3 5 8 9 11 12 13 15
//	// D: 4 6 9 10 12 13 14 15
//	NONE = 0,
//	W = 1,
//	A = 2,
//	S = 3,
//	D = 4,
//	WS = 5,
//	AD = 6,
//	WA = 7,
//	AS = 8,
//	SD = 9,
//	WD = 10,
//	WAS = 11,
//	ASD = 12,
//	WSD = 13,
//	WAD = 14,
//	WASD = 15
//};

class PathType
{
public:
	PathType();
	~PathType();

	int getPathTypeIntWithChar(const char * type){
		return pathCharToInt[type];
	}
	char * getPathTypeCharWithInt(const int type){
		return pathIntToChar[type];
	}

	bool pathUpEnabled(const int type);
	bool pathUpEnabled(const char * type);
	bool pathLeftEnabled(const int type);
	bool pathLeftEnabled(const char * type);
	bool pathDownEnabled(const int type);
	bool pathDownEnabled(const char * type);
	bool pathRightEnabled(const int type);
	bool pathRightEnabled(const char * type);

private:
	map<const char*, int> pathCharToInt;
	map<int, char*> pathIntToChar;
};
