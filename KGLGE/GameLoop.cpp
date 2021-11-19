#include "GameLoop.h"
void KGLGE::GameLoop::update() {
	if (getWin()->getKey(GLFW_KEY_Y, true)) {
		Level lvl = convertAllGameObjectsToLevel(allGameObjects);
		saveLevel("Zinc.lvl", lvl);
	}
}

void KGLGE::GameLoop::startLoop()
{
	if(framesPerSecond == 0)
		framesPerSecond = 60;

	Batcher batcher(&shader);

	while (!p_Window->shouldClose()) {
		updateTime();
		if (nextFrame) {
			//Clean up from old stuff
			batcher.resetCounters();
			p_Window->clearWindow(r, g, b, a);

			//Poll Events
			p_Window->pollEvents();


			//Key Handlers
			for (int i = 0; i < handlers.size(); i++) {
				if (p_Window->getKey(handlers[i].key, handlers[i].pressOnce))
					getGameObject(handlers[i].layer,handlers[i].num)->respondToKey(handlers[i].key);
			}


			//Loop through all the gameObjects
			for (int i = 0; i < NumLayers; i++) {
				char numGameObjectsLeft = allGameObjects->getNumGameObjects(i);
				for (int j = 0; j < 4096 && numGameObjectsLeft != 0; j++) {
					if (getGameObject(i,j) != nullptr && !getGameObject(i,j)->deleted) {
						//Updates
						getGameObject(i,j)->update();
						if (allObjectsRerender || getGameObject(i,j)->shouldUpdate) {
							//Set Rendering
							getGameObject(i,j)->shouldUpdate = false;
							batcher.setValues(getGameObject(i,j)->getVertexes(), getGameObject(i,j)->getNumVertex(), getGameObject(i,j)->getIndicies(batcher.getVertexPointer()), getGameObject(i,j)->getNumTriangles());
						}
						batcher.increaseCounter(getGameObject(i,j)->getNumVertex());
						batcher.increaseIndex(getGameObject(i,j)->getNumTriangles());
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
			nextFrame = false;
		}
	}
	return;
}

KGLGE::GameObjectLocation KGLGE::GameLoop::addGameObject(GameObject* obj,unsigned int layer)
{
	obj->setAllGameObjects(allGameObjects);
	return allGameObjects->addGameObject(obj, layer);
}

void KGLGE::GameLoop::removeGameObject(unsigned int layer,unsigned int index)
{
	allGameObjects->removeGameObject(layer, index);
}

void KGLGE::GameLoop::addKeyHandler(unsigned int layer, unsigned int index, unsigned int key,bool pressOnce)
{
	handlers.push_back({ key,layer,index,pressOnce });
}

void KGLGE::GameLoop::setAllObjectsToRedraw()
{
	allObjectsRerender = true;
}

int KGLGE::GameLoop::getActualFPS()
{
	return FPS;
}

int KGLGE::GameLoop::getFPS()
{
	return framesPerSecond;
}

void KGLGE::GameLoop::setFPS(int framesPerSec)
{
	framesPerSecond = framesPerSec;
}

int KGLGE::GameLoop::getNumTicks()
{
	return ticks;
}

double KGLGE::GameLoop::getTimeSinceProgramStart()
{
	return glfwGetTime() - timeProgramStarted;
}

bool KGLGE::GameLoop::checkCollision(int indexOneLayer, int indexOne, int indexTwoLayer, int indexTwo, float xDiff, float yDiff)
{
	GameObject* one = getGameObject(indexOneLayer, indexOne);
	GameObject * two = getGameObject(indexTwoLayer, indexTwo);
	bool collisionX = (one->getX() + xDiff) + one->getWidth() >= two->getX() &&
		two->getX() + two->getWidth() >= (one->getX() + xDiff);

	bool collisionY = (one->getY() + yDiff) + one->getHeight() >= two->getY() &&
		two->getY() + two->getHeight() >= one->getY() + yDiff;

	return collisionX && collisionY;
}

void KGLGE::GameLoop::LoadLevel(Level* lvl)
{
	for (int i = 0; i < lvl->numObjects; i++) {
		addGameObject(lvl->getGameObjectTypeFromID(lvl->body[i]),lvl->body[i].layer);
	}
}

void KGLGE::GameLoop::updateTime()
{
	double currentTime = glfwGetTime();
	ticks++;
	if (currentTime - prevTime >= (1.0 / framesPerSecond)) {
		nextFrame = true;
		FPS = (ticks * 30);
		ticks = 0;
		prevTime += (1.0 / 60);
	}
}
