#pragma once
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <string>
namespace KGLGE {
	void initializeGLFW();
	class Window
	{
	public:
		Window(int width, int height, const char* name);
		/// <summary>
		/// Displays the window
		/// </summary>
		void display();
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Whether or not the window wants to close</returns>
		bool shouldClose();
		void swapBuffers();
		void clearWindow(float r, float g, float b, float a);
		void pollEvents();
		bool getKey(unsigned int key);
	private:
		GLFWwindow* window;
	};

}