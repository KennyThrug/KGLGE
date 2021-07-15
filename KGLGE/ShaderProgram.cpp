#include "ShaderProgram.h"

KGLGE::ShaderProgram::ShaderProgram(std::string VertexShaderFileName, std::string FragmentShaderFileName)
{
	usePrograms(VertexShaderFileName,FragmentShaderFileName);

}

void KGLGE::ShaderProgram::init()
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
	KGLGE::Vertex vert[8];
	for (int i = 0; i < 8; i++) {
		int te = i * 5;
		vert[i] = {
			vertecies[te],
			vertecies[te + 1],
			vertecies[te + 2],
			vertecies[te + 3],
			vertecies[te + 4]
		};
	}

	glCreateVertexArrays(1, &m_VA);
	glBindVertexArray(m_VA);

	glCreateBuffers(1, &m_VB);
	glBindBuffer(GL_ARRAY_BUFFER,m_VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

	glEnableVertexArrayAttrib(m_VB, 0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(KGLGE::Vertex),0);

	glEnableVertexArrayAttrib(m_VB, 1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(KGLGE::Vertex), (const void*)(offsetof(KGLGE::Vertex,texPos)));

	glEnableVertexArrayAttrib(m_VB, 2);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(KGLGE::Vertex), (const void*)(offsetof(KGLGE::Vertex,texID)));

	unsigned int indicies[] = {
		0,1,2,
		2,3,0,

		4,5,6,
		6,7,4
	};

	glCreateBuffers(1, &m_IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	setupSamplers();

}

void KGLGE::ShaderProgram::paintVerticies(float* verticies, unsigned int verteciesCount, unsigned int* indicies, unsigned int indiciesCount)
{
	glUseProgram(program);
	glBindVertexArray(m_VA);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);
}

void KGLGE::ShaderProgram::setupSamplers()
{
	glUseProgram(program);

	GLint ImageLoc = glGetUniformLocation(program, "u_Texture");

	int texID[8] = { 0,1,2,3,4,5,6,7 };

	glUniform1iv(ImageLoc, 8, texID);
}

void KGLGE::ShaderProgram::usePrograms(const std::string VertexShaderFileName, const std::string FragmentShaderFileName)
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

std::string KGLGE::ShaderProgram::readShader(const std::string& fileName)
{
	std::ifstream stream(fileName);

	std::string line;
	std::stringstream ss;
	while (getline(stream, line)) {
		ss << line << "\n";
	}
	return ss.str();
}

unsigned int KGLGE::ShaderProgram::compileShader(unsigned int type, const std::string& source)
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
