#include "GameLoop.h"
void KGLGE::GameLoop::update() {
	if (getWin()->getMouseButton(GLFW_MOUSE_BUTTON_1))
		std::cout << "Mouse1";
	if (getWin()->getKey(GLFW_KEY_J, true)) {
		setWindowSize(-2, 2, -2, 2);
		setAllObjectsToRedraw();
	}
}

void KGLGE::GameLoop::startLoop()
{
	//TextureAtlas atlas("res/sprites/cats/",3);

	Batcher batcher(&shader);

	while (!p_Window->shouldClose()) {
		//Clean up from old stuff
		batcher.resetCounters();
		p_Window->clearWindow(r, g, b, a);

		//updateTime();

		//Poll Events
		p_Window->pollEvents();


		//Key Handlers
		for (int i = 0; i < handlers.size(); i++) {
			if(p_Window->getKey(handlers[i].key))
				gameObjects[handlers[i].layer][handlers[i].num]->respondToKey(handlers[i].key);
		}

		
		//Loop through all the gameObjects
		for (int i = 0; i < 3; i++) {
			char numGameObjectsLeft = m_numGameObjects[i];
			for (int j = 0; j < 32 || numGameObjectsLeft != 0; j++) {
				if (gameObjects[i][j] != nullptr && !gameObjects[i][j]->deleted) {
					//Updates
					gameObjects[i][j]->update();
					if (allObjectsRerender || gameObjects[i][j]->shouldUpdate) {
						//Set Rendering
						gameObjects[i][j]->shouldUpdate = false;
						batcher.setValues(gameObjects[i][j]->getVertexes(), gameObjects[i][j]->getNumVertex(), gameObjects[i][j]->getIndicies(batcher.getVertexPointer()), gameObjects[i][j]->getNumTriangles());
					}
					batcher.increaseCounter(gameObjects[i][j]->getNumVertex());
					batcher.increaseIndex(gameObjects[i][j]->getNumTriangles());
					numGameObjectsLeft--;
				}
			}
		}
		batcher.paint();

		//Main Update Loop
		update();

		//Ending Loop Cleanup
		p_Window->swapBuffers();
		allObjectsRerender = false;
	}
	return;
}

unsigned int KGLGE::GameLoop::addGameObject(GameObject* obj,unsigned int layer)
{
	if (stk[layer].empty()) {
		gameObjects[layer][m_numGameObjects[layer]] = obj;
		m_numGameObjects[layer]++;
	}
	else {
		gameObjects[layer][stk[layer].top()] = obj;
		stk[layer].pop();
		m_numGameObjects[layer]++;
	}
	return 0;
}

void KGLGE::GameLoop::removeGameObject(unsigned int layer,unsigned int index)
{
	gameObjects[layer][index]->deleted = true;

}

void KGLGE::GameLoop::addKeyHandler(unsigned int layer, unsigned int index, unsigned int key)
{
	handlers.push_back({ key,layer,index });
}

void KGLGE::GameLoop::setAllObjectsToRedraw()
{
	allObjectsRerender = true;
}
