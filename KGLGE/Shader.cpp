#include "Shader.h"

Shader::Shader()
{	
	usePrograms("VertexShader.glsl", "FragmentShader.glsl");

	setupVerticies(sizeof(Vertex) * 1000);
	glGenBuffers(1, &m_vb);

}

Shader::~Shader()
{
}

void Shader::usePrograms(std::string VertexShaderFileName, std::string FragmentShaderFileName)
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

void Shader::paint(Batcher* batch)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vb);
	glUseProgram(program);
	glBufferSubData(GL_ARRAY_BUFFER, 0,sizeof(Vertex) * batch->getNumElements(),batch->getVertexes());

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,nullptr);
}

void Shader::bindIndicies(Batcher * batch)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, batch->getNumIndicies(), batch->getIndicies() , GL_STATIC_DRAW);
}

void Shader::setupVerticies(unsigned int size)
{
	glCreateVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);


	glCreateBuffers(1, &m_vb);
	glBindBuffer(GL_ARRAY_BUFFER, m_vb);
	glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexArrayAttrib(m_vb, 0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(const  void*)(offsetof(Vertex,positions)));

	glEnableVertexArrayAttrib(m_vb, 1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const  void*)(offsetof(Vertex, texCoords)));

	glCreateBuffers(1, &m_ib);

}

std::string Shader::readShader(std::string fileName)
{
	std::ifstream stream(fileName);

	std::string line;
	std::stringstream ss;
	while (getline(stream, line)) {
		ss << line << "\n";
	}
	return ss.str();
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
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
