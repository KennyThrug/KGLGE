#pragma once
#include "Window.h"
#include "Batcher.h"
#include "ShaderProgram.h"
#include "TextureAtlas.h"
#include "DummyGO.h"
#include "DummyTwo.h"

namespace KGLGE {

	struct Level {

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
		/// <returns>The index of the object, keep if you want to access it later</returns>
		unsigned int addGameObject(GameObject* obj);
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
	private:
		/// <summary>
		/// Loads a texture, and sets it to a Sampler slot
		/// </summary>
		/// <param name="fileName"></param>
		/// <param name="textureSlot"></param>
		/// <returns></returns>
		GLuint loadTexture(const std::string& fileName, unsigned char textureSlot);
		void saveLevel();
		Window* p_Window;
		unsigned char m_numGameObjects[3];
		GameObject* gameObjects[3][32];
	};

}