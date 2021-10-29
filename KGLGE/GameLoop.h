#pragma once
#include "Window.h"
#include "Batcher.h"
#include "ShaderProgram.h"
#include "TextureAtlas.h"
#include "Square.h"
#include "LevelLoader.h"

namespace KGLGE {

	class GameLoop
	{
	public:
		float aa = 0;
		float bb = 0;
		virtual void update();
		GameLoop(Window* win) : p_Window(win) {
			allGameObjects = new AllGameObjects();
			shader.init();
			setWindowSize(-1, 1, -1, 1);
		}
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
		GameObjectLocation addGameObject(GameObject* obj,unsigned int layer);
		/// <summary>
		/// Sets a gameObject to a specific index. Will override that object. Use if you want it to replace that index.
		/// </summary>
		/// <param name="obj">the object to be added</param>
		/// <param name="index">the index to set the object in</param>
		/// <returns>the index of the object, will be the same thing as index</returns>
		void setWindowSize(float min_x,float max_x, float min_y, float max_y) {
			shader.setWindowSize(min_x, max_x, min_y, max_y);
			setAllObjectsToRedraw();
		}
		/// <summary>
		/// removes a game object and allows that memory to be used
		/// </summary>
		/// <param name="index"></param>
		void removeGameObject(unsigned int layer, unsigned int index);
		void addKeyHandler(unsigned int layer, unsigned int index,unsigned int key,bool pressOnce = false);
		//Unimplemented
		void removeTexture(unsigned int index);
		void setAllObjectsToRedraw();
		Window* getWin() { return p_Window; }
		GameObject* getGameObject(int layer, int num) { return allGameObjects->getGameObject(layer, num); }
		/// <summary>
		/// Gets actual FPS of the computer
		/// </summary>
		/// <returns></returns>
		int getActualFPS();
		int getFPS();
		void setFPS(int framesPerSec);
		int framesPerSecond;
		int getNumTicks();
		bool nextFrame = false;
		/// <summary>
		/// Returns Time, in seconds that the program has been running
		/// </summary>
		/// <returns></returns>
		double getTimeSinceProgramStart();
		bool checkCollision(int indexOneLayer, int indexOne, int indexTwoLayer, int indexTwo,float xDiff = 0, float yDiff = 0);
	
		void addProperty(GameObjectLocation loc, int prop) {
			allGameObjects->addProperty(loc, prop);
		}
		void addProperty(int layer, int loc, int prop) {
			allGameObjects->addProperty(layer, loc, prop);
		}

		void LoadLevel(Level* lvl);
	protected:
		AllGameObjects* allGameObjects;
		float r, g, b, a;
	private:
		int ticks;
		double timeProgramStarted = glfwGetTime();
		double prevTime = glfwGetTime();
		int FPS = 0;
		void updateTime();
		bool allObjectsRerender = false;
		struct KeyHandler {
			unsigned int key;
			unsigned int layer;
			unsigned int num;
			bool pressOnce;
		};
		Window* p_Window;
		std::vector<KeyHandler> handlers;
		ShaderProgram shader;
	};

}