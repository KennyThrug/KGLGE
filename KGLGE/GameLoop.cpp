#include "GameLoop.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#endif // !STB_IMAGE_IMPLEMENTATION

void KGLGE::GameLoop::startLoop()
{
	ShaderProgram shader;
	shader.init();
	TextureAtlas atlas;

	Batcher batcher(&shader);

	GLuint ad = loadTexture("res/sprites/Nora.png",0);

	GLuint ac = loadTexture("res/sprites/Steeler.png",1);

	GLuint ap = loadTexture("res/sprites/Hilda.png",2);
	
	GLuint aq = loadTexture("res/sprites/rowlett.png",3);
	
	DummyGO dum;
	addGameObject(&dum);

	DummyTwo dummy;
	gameObjects[0][1] = &dummy;
	m_numGameObjects[0]++;

	while (!p_Window->shouldClose()) {
		//Clean up from old stuff
		batcher.resetCounters();
		p_Window->clearWindow(1, 1, 0, 1);

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

GLuint KGLGE::GameLoop::loadTexture(const std::string& fileName, unsigned char textureSlot)
{
	glActiveTexture(GL_TEXTURE0 + textureSlot);
	int w, h, bits;
	auto* pixels = stbi_load(fileName.c_str(), &w, &h, &bits, STBI_rgb_alpha);
	GLuint textureID;
	glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	stbi_image_free(pixels);

	glActiveTexture(GL_TEXTURE0 + textureSlot);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindTextureUnit(textureSlot, textureID);

	return textureID;
}
