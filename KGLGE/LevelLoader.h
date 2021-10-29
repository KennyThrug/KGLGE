#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
namespace KGLGE {
	struct Level {
		int numObjects;
		struct Parameters {
			unsigned int typeOfParameter; //i.e. 1 = int, 2 = string, etc...
			unsigned int numBytes; //Number of bytes this parameter takes (not including these two variables)
			char* data;
		};
		struct Body {
			unsigned int id;
			unsigned int numParameters;
			std::vector<Parameters> parameters;
		};
		std::vector<Body> body;
	};
	Level loadLevel(const std::string& fileName);
	void saveLevel(const std::string& fileName, Level lvl);
	Level convertAllGameObjectsToLevel(AllGameObjects* all);
}