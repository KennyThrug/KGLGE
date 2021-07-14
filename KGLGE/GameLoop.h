#pragma once
#include "Window.h"
#include "Batcher.h"
#include "GameObject.h"

namespace KGLGE {

	struct Level {

	};

	class GameLoop
	{
	public:
		GameLoop(Window* win) : p_Window(win) {}
		void startLoop();
		void loadLevel();
		unsigned int addGameObject(GameObject* obj);
		unsigned int setGameObject(GameObject* obj, unsigned int index);
		void removeGameObject(unsigned int index);
	private:
		GLuint loadTexture(const std::string& fileName);
		void saveLevel();
		Window* p_Window;
		unsigned char m_numGameObjects[3];
		GameObject* gameObjects[3][32];
	};

}