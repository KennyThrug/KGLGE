#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "GameObject.h"
#include <fstream>
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

namespace KGLGE {
#define KGLGE_FONT 1
#define KGLGE_BACKGROUND 2
#define KGLGE_HUD 3
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
		void paintVerticies(float* verticies, unsigned int verteciesCount, unsigned int* indicies, unsigned int indiciesCount);
		void setupSamplers();
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
