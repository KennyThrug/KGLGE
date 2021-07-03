#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "BufferLayout.h"
#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



struct shaderReturnVal {
	std::string vertex;
	std::string fragment;
};


class Shader {
public:
	Shader(std::string fileName = "Basic_Shader.glsl");
	~Shader();
	void addObject(VertexBuffer*& vb, IndexBuffer*& ib, int sizeofPositions, float* positions, int sizeofIndicies, unsigned int indicies[], bool hasTex);
	void paintObject(VertexBuffer* vb, IndexBuffer* ib, unsigned int elementNum, float r, float g, float b, float a, bool hasTex);
	void renewObject(VertexBuffer* vb, IndexBuffer* ib, int sizeofPositions, float* positions, int sizeofIndicies, unsigned int indicies[]);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniform1i(const std::string& name, float value);
	void setUniform1b(const std::string& name, bool value);
private:
	unsigned int vao;
	unsigned int program;
	VertexArray va;
	BufferLayout layout;
	void createShaderProgram(const std::string& source);
	unsigned int compileShader(unsigned int type, const std::string& source);
	shaderReturnVal readShader(const std::string& filepath);
};