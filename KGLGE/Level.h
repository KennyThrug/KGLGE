#pragma once
#include <vector>
#include <string>
namespace KGLGE {
	class Level {
	private:
		struct Level_GameObjects {
			//Index of the atlas that will be used
			unsigned int atlas;
			//Index of the texture that will be used
			unsigned int texture;
			//x, y, width, height of the object
			float x, y, w, h;
			unsigned int layer;
		};
		unsigned int numObjects;
		std::vector<Level_GameObjects> go;
		std::vector<std::string> atlas;
	public:
		void saveLevel(const std::string& fileName);
		void loadLevel(const std::string& fileName);
	};
}