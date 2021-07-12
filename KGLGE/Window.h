#pragma once
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <string>
namespace KGLGE {

	class Window
	{
	public:
		Window(int x, int y, int width, int height, std::string& name);
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Whether or not the window wants to close</returns>
		bool shouldClose();
		void pollEvents();
		bool getKey(unsigned int key);
	};

}