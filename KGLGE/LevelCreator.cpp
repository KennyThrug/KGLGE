#include "LevelCreator.h"

void KGLGE::LevelCreator::update()
{
}

bool KGLGE::LevelCreator::respondToKey(unsigned int key)
{
	if (key == 262) { // right
		std::cout << "daper";
	}
	return false;
}
