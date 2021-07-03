#include "GameLoop.h"

GameLoop::GameLoop(Window* window) : win(window)
{
}

void GameLoop::startLoop()
{
	Shader* shader = new Shader();
	float x = 0.0f;
	batcher = new Batcher();
	batcher->addGameObject(nullptr);
	shader->bindIndicies(batcher);
	while (!win->shouldClose()) {
		x += 0.001f;
		if (x >= 1)
			x = 0;
		win->clearWindow(x, 0, 1, 1);

		shader->paint(batcher);

		runAtLoop();
		glfwPollEvents();
		win->swapBuffers();
	}
}

void GameLoop::runAtLoop()
{
}

void GameLoop::drawElements()
{
}
