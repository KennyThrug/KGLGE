#include "Runner.h"
void setupGLFWStuff() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void runGameInGameMode()
{
	Window* win = new Window();
	setupGLFWStuff();
	win->displayWindow();	
	float x = 0.0f;
	while (!win->shouldClose()) {
		x += 0.001f;
		if (x >= 1)
			x = 0;
		win->clearWindow(x, 0, 1, 1);
		win->swapBuffers();
	}
	glfwTerminate();
}
