#include "GameLoop.h"

void KGLGE::GameLoop::startLoop()
{
	ShaderProgram shader;
	shader.init();
	TextureAtlas atlas("res/sprites/cats/",3);

	Batcher batcher(&shader);

	/*GLuint ad = loadTexture("res/sprites/Nora.png", 0);

	GLuint ac = loadTexture("res/sprites/Steeler.png",1);

	GLuint ap = loadTexture("res/sprites/Hilda.png",2);
	
	GLuint aq = loadTexture("res/sprites/rowlett.png",3);*/
	
	DummyGO dum;
	addGameObject(&dum);

	DummyTwo dummy;
	gameObjects[0][1] = &dummy;
	m_numGameObjects[0]++;

	while (!p_Window->shouldClose()) {
		//Clean up from old stuff
		batcher.resetCounters();
		p_Window->clearWindow(1, 1, 0, 1);
		//updateTime();

		//Poll Events
		p_Window->pollEvents();

		//Loop through all the gameObjects
		for (int i = 0; i < 3; i++) {
			char numGameObjectsLeft = m_numGameObjects[i];
			for (int j = 0; j < 32 || numGameObjectsLeft != 0; j++) {
				if (gameObjects[i][j] != nullptr) {
					//Updates
					if (gameObjects[i][j]->update()) {
						//Set Rendering
						batcher.setValues(gameObjects[i][j]->getVertexes(), gameObjects[i][j]->getNumVertex(), gameObjects[i][j]->getIndicies(), gameObjects[i][j]->getNumTriangles());
					}
					batcher.increaseCounter(gameObjects[i][j]->getNumVertex());
					batcher.increaseIndex(gameObjects[i][j]->getNumTriangles());
					numGameObjectsLeft--;
				}
			}
		}
		batcher.paint();

		//Ending Loop Cleanup
		p_Window->swapBuffers();

	}
	return;
}

unsigned int KGLGE::GameLoop::addGameObject(GameObject* obj)
{
	gameObjects[0][0] = obj;
	m_numGameObjects[0]++;
	return 0;
}
