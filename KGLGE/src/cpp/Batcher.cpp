#include "../headers/Batcher.h"

void KGLGE::Batcher::setValues(KGLGE::Vertex* verticies, unsigned int numVerticies, KGLGE::Triangle* indicies, unsigned int numTriangles)
{
	p_Shader->setVerticies(verticies,numVerticies,m_Vertex_pointer,indicies,numTriangles,m_Index_pointer);
}
void KGLGE::Batcher::paint() {
	p_Shader->paintVerticies(m_Index_pointer);
}
