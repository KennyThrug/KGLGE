#include "GameLoop.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#endif // !STB_IMAGE_IMPLEMENTATION

void KGLGE::GameLoop::startLoop()
{
	Batcher batcher;
	ShaderProgram shader;
	shader.init();
	TextureAtlas atlas;


	GLuint ad = loadTexture("res/sprites/Nora.png",0);

	GLuint ac = loadTexture("res/sprites/Steeler.png",1);
	
	

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
