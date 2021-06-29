#include "Window.h"
Window::Window()
{
	if (!glfwInit()) {
		throw "Failed to initialize GLFW";
	}


	window = glfwCreateWindow(640, 480, "TestWindow", NULL, NULL);
	if (!window) {
		glfwTerminate();
		throw "Failed to create GLFW Window";
	}
}

void Window::clearWindow(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::displayWindow()
{
	glfwMakeContextCurrent(window);
	if (glewInit()) {
		throw "Failed to initialize GLEW INIT";
	}
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

int Window::getKey(unsigned int key)
{
	return glfwGetKey(window, key);
}
