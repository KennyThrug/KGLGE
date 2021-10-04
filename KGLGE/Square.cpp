#include "Square.h"

Square::Square(float x, float y, float w, float h, float red, float green, float blue, float alpha) : m_Height(h), m_Width(w), m_y(y), m_x(x)
{
	for (int i = 0; i < 3; i++) {
		m_vertex[i].red = red;
		m_vertex[i].green = green;
		m_vertex[i].blue = blue;
		m_vertex[i].alpha = alpha;
		m_vertex[0].texID = -1;
	}
}

void Square::update()
{
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
}

KGLGE::Vertex* Square::getVertexes()
{
	return m_vertex;
}

unsigned int Square::getNumVertex()
{
	return 4;
}

KGLGE::Triangle* Square::getIndicies(unsigned int offset)
{
	m_Triangles[0].index1 = 0 + offset;
	m_Triangles[0].index2 = 1 + offset;
	m_Triangles[0].index3 = 2 + offset;
	m_Triangles[1].index1 = 2 + offset;
	m_Triangles[1].index2 = 3 + offset;
	m_Triangles[1].index3 = 0 + offset;
	return m_Triangles;
}

bool Square::respondToKey(unsigned int key)
{
	return false;
}

unsigned int Square::getNumTriangles()
{
	return 2;
}
