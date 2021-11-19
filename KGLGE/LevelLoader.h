#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "Square.h"
#include "Sprite.h"
#include "Image.h"
namespace KGLGE {
	class Level {
	public:
		int numObjects;
		struct Parameters {
			//i.e. 1 = int, 2 = string, 3 = float
			unsigned int typeOfParameter; 
			float data;
		};
		struct Body {
			unsigned int id;
			unsigned int layer;
			unsigned int numParameters;
			std::vector<Parameters> parameters;
		};
		std::vector<Body> body;
		virtual KGLGE::GameObject* getGameObjectTypeFromID(KGLGE::Level::Body bd);
	};
	//Send a Level Object, it edits that object to be the loaded level
	void addCharsToBuffer(std::vector<char>* buffer, char* chars, int size);
	void loadLevel(const std::string& fileName, Level* lvl);
	void saveLevel(const std::string& fileName, Level lvl);
	Level convertAllGameObjectsToLevel(AllGameObjects* all);

}