#pragma once
#include <string>
class Shader {
public:
	Shader();
	~Shader();
	void usePrograms(std::string VertexShaderFileName, std::string FragmentShaderFileName);
	void paint(float* vertex, unsigned int vertexSize, unsigned int* indicies, unsigned int indiciesSize);
private:
	unsigned int vb;
	unsigned int ib;
	unsigned int vao;
	unsigned int shaderProgram;
	void readShader();
	unsigned int compileShader();
};