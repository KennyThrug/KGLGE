#pragma once
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
class Window {
public:
	Window();
	~Window();
	bool shouldClose();
	void setShouldClose();
private:
	GLFWwindow * window;
	void init();
};