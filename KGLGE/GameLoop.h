#pragma once
#include "Window.h"
#include "Batcher.h"
#include "GameObject.h"
struct Level {

};

namespace KGLGE {

	class GameLoop
	{
	public:
		GameLoop(Window* win) : m_Window(win) {}
		void startLoop();
		void loadLevel();
		unsigned int addGameObject(GameObject* obj);
		unsigned int setGameObject(GameObject* obj, unsigned int index);
		void removeGameObject(unsigned int index);
	private:
		void saveLevel();
		Window* m_Window;
		unsigned char m_numGameObjects[3];
		GameObject* gameObjects[3][32];
	};

}