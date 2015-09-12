#include "LibraryAPI.h"


LibraryAPI::LibraryAPI(){
	pathType = new PathType;
}

void LibraryAPI::newRandomSeed(const unsigned long seed){
	unsigned long newSeed = seed;
	if (seed == 0){
		timeval now;
		gettimeofday(&now, NULL);
		newSeed = (unsigned)(now.tv_sec / 1000 + now.tv_usec * 1000);
	}
	if (randomEngine != NULL)
	{
		delete(randomEngine);
	}
	randomEngine = NULL;
	randomEngine = new default_random_engine(newSeed);
}

int LibraryAPI::getRandomNumber(const unsigned int min, const unsigned int max){
	uniform_int_distribution<unsigned> u(min, max);
	return u(*randomEngine);
}