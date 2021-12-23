#include "../headers/GameLoop.h"
void KGLGE::GameLoop::update() {
	if (getWin()->getKey(GLFW_KEY_Y, true)) {
		Level lvl = convertAllGameObjectsToLevel(allGameObjects);
		saveLevel("../../res/Zinc.lvl", lvl);
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
			for (int i = 0; i < allGameObjects->handlers.size(); i++) {
				if (p_Window->getKey(allGameObjects->handlers[i].key, allGameObjects->handlers[i].pressOnce))
					getGameObject(allGameObjects->handlers[i].layer, allGameObjects->handlers[i].num)->respondToKey(allGameObjects->handlers[i].key);
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
	allGameObjects->handlers.push_back({ key,layer,index,pressOnce });
}

void KGLGE::GameLoop::addKeyHandler(GameObjectLocation location, unsigned int key, bool pressOnce)
{
	addKeyHandler(location.layer, location.location, key, pressOnce);
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
	for (int i = 0; i < lvl->numTextureAtlas; i++) {
		addTextureAtlas(lvl->atlasNames[i],lvl->layer[i]);
	}
	for (int i = 0; i < lvl->numObjects; i++) {
		addGameObject(getGameObjectTypeFromID(lvl->body[i]),lvl->body[i].layer);
	}
	for (int i = 0; i < lvl->numHandlers; i++) {
		addKeyHandler(lvl->handlers[i].layer, lvl->handlers[i].num, lvl->handlers[i].key, lvl->handlers[i].pressOnce);
	}
	int count = -1;
	int last = -1;
	for (int i = 0; i < lvl->numProperties; i++) {
		addProperty({ lvl->properties[i].layer, lvl->properties[i].location }, lvl->propertyKey[i]);
	}
}

void KGLGE::GameLoop::addLevelCreator()
{
	GameObjectLocation loc = addGameObject(new LevelCreator(), 0);
	addKeyHandler(loc,GLFW_KEY_RIGHT,true);
}

KGLGE::GameObject* KGLGE::GameLoop::getGameObjectTypeFromID(KGLGE::Level::Body bd)
{
	//Puts all the data in an array thats easier to use
	float temp[64];
	for (int i = 0; i < bd.numParameters; i++) {
		temp[i] = bd.parameters[i].data;
	}

	switch (bd.id) {
	case 0: //Square
		return new Square(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7]);
		break;
	case 1: //Sprite
		return new Sprite(getAtlas(temp[0]),temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]);
		break;
	case 2: //image
		break;
	case 3: //Empty
		return new Empty();
		break;
	}
	
	return nullptr;
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
