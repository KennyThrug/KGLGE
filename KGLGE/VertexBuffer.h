#pragma once
#include <GLEW/GL/glew.h>
class VertexBuffer {
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void renewBuffer(void* data, unsigned int size);
	void Bind() const;
	void UnBind() const;
};