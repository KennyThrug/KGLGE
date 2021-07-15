#include "GameLoop.h"


void KGLGE::GameLoop::startLoop()
{
	Batcher batcher;
	ShaderProgram shader;
	shader.init();
	TextureAtlas atlas;
	atlas.addTextureToCache(2);
	atlas.addTextureToCache(3);
	atlas.createTextureAtlas("res/SpriteIndex.txt");
	//loadTexture("res/texture-atlas-generator/textureAtlas.png");

	while (!p_Window->shouldClose()) {
		//Clean up from old stuff
		batcher.resetCount();
		p_Window->clearWindow(1, 1, 0, 1);

		//Poll Events
		p_Window->pollEvents();

		//Loop through all the gameObjects
		for (int i = 0; i < 3; i++) {
			char numGameObjectsLeft = m_numGameObjects[i];
			for (int j = 0; j < 32 || numGameObjectsLeft != 0; j++) {
				if (gameObjects[i][j] != nullptr) {
					//Updates
					gameObjects[i][j]->update();


					//Rendering

					if (gameObjects[i][j]->shouldUpdateVertex()) {
						//If a change has happened to the vertex, recalculate and redraw
						for (int k = 0; k < gameObjects[i][j]->getNumVertex(); k++) {
							batcher.addToBatcher(*gameObjects[i][j]->getVertexAtPos(k));
						}
					}
					else {
						//If not, skip the number of lines that correspond to that vertex
						batcher.addByCount(gameObjects[i][j]->getSizeOfVertexs());
					}
					numGameObjectsLeft--;
				}
			}
		}
		shader.paintVerticies(NULL,1,NULL,2);

		//Ending Loop Cleanup
		p_Window->swapBuffers();

	}
	return;
}
