#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "GameObject.h"
#include <fstream>
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

namespace KGLGE {
#define KGLGE_BACKGROUND 0
#define KGLGE_MAIN 1
#define KGLGE_FOREGROUND 2
#define KGLGE_HUD 3
#define KGLGE_FONT 4
	class ShaderProgram
	{
	public:
		ShaderProgram(std::string VertexShaderFileName = "VertexShader.glsl", std::string FragmentShaderFileName = "FragmentShader.glsl");
		void init();
		/// <summary>
		/// Paints the verticies given
		/// </summary>
		/// <param name="verticies">an array of floats in the format of Verticies</param>
		/// <param name="verteciesCount">the number of floats in the verticies array</param>
		/// <param name="indicies">Indicies for the vertex</param>
		/// <param name="indiciesCount">The number of indicies in the indicies array</param>
		void paintVerticies(unsigned int indiciesCount);
		void setVerticies(Vertex* verticies, unsigned int lengthOfVertecies, unsigned int offsetOfVerticies, Triangle* indicies, unsigned int lengthOfIndicies, unsigned int offsetOfIndicies);
		void setupSamplers();
		void setWindowSize(float x_min, float x_max, float y_min, float y_max);
	private:
		unsigned int program;
		unsigned int m_VA;
		unsigned int m_VB;
		unsigned int m_IB;

		void usePrograms(const std::string VertexShaderFileName, const std::string FragmentShaderFileName);
		std::string readShader(const std::string& fileName);
		unsigned int compileShader(unsigned int type, const std::string& source);
	};
}
