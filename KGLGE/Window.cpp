#include "Window.h"

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
}

bool KGLGE::Window::getKey(unsigned int key)
{
	return glfwGetKey(window, key);
}
bool KGLGE::Window::getMouseButton(unsigned int button) {
	return glfwGetMouseButton(window,button);
}
