#pragma once
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
class Window {
public:
	/// <summary>
	/// Creates a window and initializes GLFW
	/// </summary>
	Window();
	~Window();
	/// <summary>
	/// clears the windows with a certain rgba value
	/// </summary>
	void clearWindow(float r, float g, float b, float a);
	void displayWindow();
	bool shouldClose();
	void swapBuffers();
	int getKey(unsigned int key);
private:
	GLFWwindow* window;
protected:
};