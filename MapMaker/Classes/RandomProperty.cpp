#include "RamdomProperty.h"


RamdomProperty::RamdomProperty(){
	dropTypeRate[0] = 0;
	dropTypeRate[DropType::item] = 100;
	dropTypeRate[DropType::weapon] = 100;
	dropTypeRate[DropType::armor] = 100;
	dropTypeRate[DropType::book] = 100;
	dropTypeRate[DropType::monster] = 100;
	dropTypeRate[DropType::boss] = 100;
	dropTypeRate[DropType::trap] = 100;


	int i;
	//item
	itemList[1] = 0;

	itemTotal = 0;
	for (i = 1; i < 2; ++i){
		itemTotal += itemList[i];
	}

	//weapon
	weaponList[1] = 100000;

	weaponTotal = 0;
	for (i = 1; i < 2; ++i){
		weaponTotal += weaponList[i];
	}

	//armor
	armorList[1] = 0;

	armorTotal = 0;
	for (i = 1; i < 2; ++i){
		armorTotal += armorList[i];
	}

	//book
	bookList[1] = 0;

	bookTotal = 0;
	for (i = 1; i < 2; ++i){
		bookTotal += bookList[i];
	}

	//monster
	monsterList[1] = 100000;

	monsterTotal = 0;
	for (i = 1; i < 2; ++i){
		monsterTotal += monsterList[i];
	}
	//boss
	bossList[1] = 0;

	bossTotal = 0;
	for (i = 1; i < 2; ++i){
		bossTotal += bossList[i];
	}
	//trap
	trapList[1] = 100000;

	trapTotal = 0;
	for (i = 1; i < 2; ++i){
		trapTotal += trapList[i];
	}
}

int RamdomProperty::getDropType(){
	int noDrop = 2100;
	int num = getRandomNumber(0, noDrop + dropTotal);
	if (num < dropTotal){
		for (int i = 1; i < 8; ++i){
			num -= dropTypeRate[i];
			if (num <= 0){
				return i;
			}
		}
	}
	return 0;
}

int RamdomProperty::getDropType(double dropRate){
	int noDrop = dropTotal / dropRate;
	int num = getRandomNumber(0, noDrop + dropTotal);
	if (num < dropTotal){
		for (int i = 1; i < 8; ++i){
			num -= dropTypeRate[i];
			if (num <= 0){
				return i;
			}
		}
	}
	return 0;
}

int RamdomProperty::getDropType(double dropRate, int dropType, int dropMultiplier){
	int temp = dropTotal + dropTypeRate[dropType] * (dropMultiplier - 1);
	int noDrop = temp / dropRate;
	int num = getRandomNumber(0, noDrop + temp);
	if (num < temp){
		for (int i = 1; i < 8; ++i){
			if (i == dropType){
				num -= dropTypeRate[i] * dropMultiplier;
				if (num <= 0){
					return i;
				}
			}
		}
	}
	return 0;
}

int RamdomProperty::getDropItem(int dropType){
	if (dropType == DropType::item){
		int t = getRandomNumber(0, itemTotal);
		for (int i = 1; i < 2; ++i){
			t -= itemList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::weapon){
		int t = getRandomNumber(0, weaponTotal);
		for (int i = 1; i < 2; ++i){
			t -= weaponList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::armor){
		int t = getRandomNumber(0, armorTotal);
		for (int i = 1; i < 2; ++i){
			t -= armorList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::book){
		int t = getRandomNumber(0, bookTotal);
		for (int i = 1; i < 2; ++i){
			t -= bookList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::monster){
		int t = getRandomNumber(0, monsterTotal);
		for (int i = 1; i < 2; ++i){
			t -= monsterList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::boss){
		int t = getRandomNumber(0, bossTotal);
		for (int i = 1; i < 2; ++i){
			t -= bossList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	if (dropType == DropType::trap){
		int t = getRandomNumber(0, trapTotal);
		for (int i = 1; i < 2; ++i){
			t -= trapList[i];
			if (t <= 0){
				return i;
			}
		}
	}
	return 0;
}

void RamdomProperty::newRandomSeed(const unsigned long seed){
	unsigned long newSeed = seed;
	if (seed == 0) {
		timeval now;
		gettimeofday(&now, NULL);
		newSeed = (unsigned)(now.tv_sec / 1000 + now.tv_usec * 1000);
	}
	if (randomEngine != NULL) {
		delete(randomEngine);
	}
	randomEngine = NULL;
	randomEngine = new default_random_engine(newSeed);
}

int RamdomProperty::getRandomNumber(const unsigned int min, const unsigned int max){
	uniform_int_distribution<unsigned> u(min, max);
	return u(*randomEngine);
}