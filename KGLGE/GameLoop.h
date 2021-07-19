#pragma once
#include "Window.h"
#include "Batcher.h"
#include "ShaderProgram.h"
#include "TextureAtlas.h"
#include "DummyGO.h"
#include "DummyTwo.h"
#include "Time.hpp"

namespace KGLGE {

	struct Level {

	};
	struct KeyHandler {
		unsigned int key;
		unsigned int layer;
		unsigned int num;
	};

	class GameLoop
	{
	public:
		GameLoop(Window* win) : p_Window(win) {}
		/// <summary>
		/// Starts the loop and runs it until Window.shouldClose() returns false 
		/// at this point you will lose control and everything will most likely need to happen in a GameObject's update loop
		/// </summary>
		void startLoop();
		/// <summary>
		/// Adds a gameObject to the list of gameObjects.
		/// </summary>
		/// <param name="obj">The object you want to add</param>
		/// <param name="layer"> layer of the object, options are KGLGE_Background, KGLGE_Foreground, and KGLGE_MainGround
		/// <returns>The index of the object, keep if you want to access it later</returns>
		unsigned int addGameObject(GameObject* obj,unsigned int layer);
		/// <summary>
		/// Sets a gameObject to a specific index. Will override that object. Use if you want it to replace that index.
		/// </summary>
		/// <param name="obj">the object to be added</param>
		/// <param name="index">the index to set the object in</param>
		/// <returns>the index of the object, will be the same thing as index</returns>
		unsigned int setGameObject(GameObject* obj, unsigned int index);
		/// <summary>
		/// removes a game object and allows that memory to be used
		/// </summary>
		/// <param name="index"></param>
		void removeGameObject(unsigned int index);
		void addKeyHandler(unsigned int layer, unsigned int index,unsigned int key);
	private:
		void saveLevel();
		Window* p_Window;
		unsigned char m_numGameObjects[3];
		std::vector<KeyHandler> handlers;
		GameObject* gameObjects[3][32];
	};

}