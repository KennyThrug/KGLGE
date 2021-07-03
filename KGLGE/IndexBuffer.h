#pragma once
#include <GLEW/GL/glew.h>
class IndexBuffer {
private:
	unsigned int m_RendererID;
public:
	IndexBuffer(const void* data, unsigned int count);
	~IndexBuffer();
	void Bind();
	void UnBind();
	void renewBuffer(const void* data, unsigned int count);
};