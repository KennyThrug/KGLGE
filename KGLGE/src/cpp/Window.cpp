#include "../headers/Window.h"

void KGLGE::initializeGLFW()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

KGLGE::Window::Window(int width, int height, const char* name)
{
	if (!glfwInit()) {
		throw "Failed to initialize GLFW";
	}


	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (!window) {
		glfwTerminate();
		throw "Failed to create GLFW Window";
	}

}

KGLGE::Window::Window(const char* name)
{
	if (!glfwInit()) {
		throw "Failed to initialize GLFW";
	}


	window = glfwCreateWindow(glfwGetVideoMode(glfwGetPrimaryMonitor())->width, glfwGetVideoMode(glfwGetPrimaryMonitor())->height, name, NULL, NULL);
	if (!window) {
		glfwTerminate();
		throw "Failed to create GLFW Window";
	}
}

void KGLGE::Window::display()
{
	glfwMakeContextCurrent(window);
	if (glewInit()) {
		throw "Failed to initialize GLEW INIT";
	}
	for (int i = 0; i < 64; i++) {
		lastFrameValue[0][i] = -1;
		lastFrameValue[1][i] = -1;
	}
}

bool KGLGE::Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void KGLGE::Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

void KGLGE::Window::clearWindow(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void KGLGE::Window::pollEvents()
{
	glfwPollEvents();

	unsigned int count = 0;
	while(count < 32 && lastFrameValue[(One ? 1 : 0)][count] != -1) {
		lastFrameValue[(One ? 1 : 0)][count] = -1;
		count++;
	}
	curNum = 0;
	One = !One;
}

bool KGLGE::Window::getKey(unsigned int key,bool pressOnce)
{
	if (!glfwGetKey(window, key))
		return false;
	lastFrameValue[One ? 0 : 1][curNum] = key;
	curNum++;
	if (!pressOnce)
		return true;
	return !checkIfUsedLastFrame(key, One ? 1 : 0);
}

bool KGLGE::Window::getMouseButton(unsigned int button,bool pressOnce) {
	if (!glfwGetMouseButton(window, button))
		return false;
	lastFrameValue[One ? 0 : 1][curNum] = button;
	curNum++;
	if (!pressOnce)
		return true;
	return !checkIfUsedLastFrame(button, One ? 1 : 0);
}

bool KGLGE::Window::checkIfUsedLastFrame(int key, int frame)
{
	int i = 0;
	while (lastFrameValue[frame][i] != -1 && i <= 64) {
		if (lastFrameValue[frame][i] == key)
			return true;
		i++;
	}
	return false;
}
