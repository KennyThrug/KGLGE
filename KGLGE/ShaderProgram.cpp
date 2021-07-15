#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string VertexShaderFileName, std::string FragmentShaderFileName)
{
	usePrograms(VertexShaderFileName,FragmentShaderFileName);

}

void ShaderProgram::init()
{
	float vertecies[] = {
		0,1,0,1,1,
		1,1,1,1,1,
		1,0,1,0,1,
		0,0,0,0,1,

		0,-1,0,1,0,
		-1,-1,1,1,0,
		-1,0,1,0,0,
		0,0,0,0,0
	};
	glCreateVertexArrays(1, &m_VA);
	glBindVertexArray(m_VA);

	glCreateBuffers(1, &m_VB);
	glBindBuffer(GL_ARRAY_BUFFER,m_VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

	glEnableVertexArrayAttrib(m_VB, 0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),0);

	glEnableVertexArrayAttrib(m_VB, 1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(8));

	glEnableVertexArrayAttrib(m_VB, 2);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(16));

	unsigned int indicies[] = {
		0,1,2,
		2,3,0,

		4,5,6,
		6,7,4
	};

	glCreateBuffers(1, &m_IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

}

void ShaderProgram::paintVerticies(float* verticies, unsigned int verteciesCount, unsigned int* indicies, unsigned int indiciesCount)
{
	glUseProgram(program);
	glBindVertexArray(m_VA);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);
}

void ShaderProgram::usePrograms(const std::string VertexShaderFileName, const std::string FragmentShaderFileName)
{
	program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, readShader(VertexShaderFileName));
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, readShader(FragmentShaderFileName));

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	glUseProgram(program);
}

std::string ShaderProgram::readShader(const std::string& fileName)
{
	std::ifstream stream(fileName);

	std::string line;
	std::stringstream ss;
	while (getline(stream, line)) {
		ss << line << "\n";
	}
	return ss.str();
}

unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment ") << " Shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}
