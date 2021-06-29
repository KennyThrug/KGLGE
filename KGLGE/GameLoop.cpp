#include "GameLoop.h"

GameLoop::GameLoop(Window* window) : win(window)
{
}

void GameLoop::startLoop()
{
	float x = 0.0f;
	while (!win->shouldClose()) {
		x += 0.001f;
		if (x >= 1)
			x = 0;
		win->clearWindow(x, 0, 1, 1);


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
