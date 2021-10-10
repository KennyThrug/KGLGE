#include "GameLoop.h"
void KGLGE::GameLoop::update() {
	if (getWin()->getKey(GLFW_KEY_SPACE, true)) {
		removeGameObject(KGLGE_MAIN, 0);
	}
	if (getWin()->getKey(GLFW_KEY_P, true)) {
		Square* sq = new Square(-1, -1, 2, 2, 1, 1, 0, 1);
		addGameObject(sq, KGLGE_MAIN);
		allObjectsRerender = true;
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

		updateTime();

		//Poll Events
		p_Window->pollEvents();


		//Key Handlers
		for (int i = 0; i < handlers.size(); i++) {
			if(p_Window->getKey(handlers[i].key,handlers[i].pressOnce))
				gameObjects[handlers[i].layer][handlers[i].num]->respondToKey(handlers[i].key);
		}

		
		//Loop through all the gameObjects
		for (int i = 0; i < 3; i++) {
			char numGameObjectsLeft = m_numGameObjects[i];
			for (int j = 0; j < 4096 && numGameObjectsLeft != 0; j++) {
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
		allObjectsRerender = false;
		batcher.paint();

		//Main Update Loop
		update();

		//Ending Loop Cleanup
		p_Window->swapBuffers();
	}
	return;
}

unsigned int KGLGE::GameLoop::addGameObject(GameObject* obj,unsigned int layer)
{
	if (stk[layer].empty()) {
		gameObjects[layer][m_numGameObjects[layer]] = obj;
		m_numGameObjects[layer]++;
		return m_numGameObjects[layer] - 1;
	}
	else {
		int re = stk[layer].top();
		delete gameObjects[layer][re];
		gameObjects[layer][re] = obj;
		stk[layer].pop();
		m_numGameObjects[layer]++;
		return re;
	}
	return 0;
}

void KGLGE::GameLoop::removeGameObject(unsigned int layer,unsigned int index)
{
	gameObjects[layer][index]->deleted = true;
	stk[layer].push(index);
	m_numGameObjects[layer]--;
}

void KGLGE::GameLoop::addKeyHandler(unsigned int layer, unsigned int index, unsigned int key,bool pressOnce)
{
	handlers.push_back({ key,layer,index,pressOnce });
}

void KGLGE::GameLoop::setAllObjectsToRedraw()
{
	allObjectsRerender = true;
}

int KGLGE::GameLoop::getFPS()
{
	return FPS;
}

int KGLGE::GameLoop::getNumTicks()
{
	return ticks;
}

double KGLGE::GameLoop::getTimeSinceProgramStart()
{
	return glfwGetTime() - timeProgramStarted;
}

void KGLGE::GameLoop::updateTime()
{
	double currentTime = glfwGetTime();
	ticks++;
	if (currentTime - prevTime >= 1.0) {
		FPS = ticks;
		ticks = 0;
		prevTime += 1.0;
	}
}
