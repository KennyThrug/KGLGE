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
	GameLoop loop(win);
	loop.startLoop();
	glfwTerminate();
}
