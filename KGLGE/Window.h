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
		Window(const char* name);
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

		/// <summary>
		/// 
		/// </summary>
		/// <param name="key">ID of the key to be checked</param>
		/// <param name="pressOnce">If pressOnce is true, then it will only return true on the first press</param>
		/// <returns></returns>
		bool getKey(unsigned int key,bool pressOnce = false);
		bool getMouseButton(unsigned int button,bool pressOnce = false);
		void getSize(int* width, int* height) {
			glfwGetWindowSize(window, width, height);
		}
		void getMousePosition(double *xPos, double *yPos) {
			glfwGetCursorPos(window,xPos,yPos);
		}
	private:
		bool checkIfUsedLastFrame(int key, int frame);

		GLFWwindow* window;
		int lastFrameValue[2][64];
		int curNum = 0;
		bool One = 0;
	};

}