#include "Square.h"

KGLGE::Square::Square(float x, float y, float w, float h, float red, float green, float blue, float alpha)
{
	m_x = x;
	m_y = y;
	m_Height = h;
	m_Width = w;

	m_vertex[0].red = red;
	m_vertex[0].green = green;
	m_vertex[0].blue = blue;
	m_vertex[0].alpha = alpha;
	m_vertex[1].red = red;
	m_vertex[1].green = green;
	m_vertex[1].blue = blue;
	m_vertex[1].alpha = alpha;
	m_vertex[2].red = red;
	m_vertex[2].green = green;
	m_vertex[2].blue = blue;
	m_vertex[2].alpha = alpha;
	m_vertex[3].red = red;
	m_vertex[3].green = green;
	m_vertex[3].blue = blue;
	m_vertex[3].alpha = alpha;

	m_vertex[0].texID = -1;
	m_vertex[1].texID = -1;
	m_vertex[2].texID = -1;
	m_vertex[3].texID = -1;
}

void KGLGE::Square::update()
{
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
	int k = allGameObjects->getNumGameObjects(0);
	int d = allGameObjects->getNumGameObjects(1);
	int a = allGameObjects->getNumGameObjects(2);
}

KGLGE::Vertex* KGLGE::Square::getVertexes()
{
	return m_vertex;
}

unsigned int KGLGE::Square::getNumVertex()
{
	return 4;
}

KGLGE::Triangle* KGLGE::Square::getIndicies(unsigned int offset)
{
	m_Triangles[0].index1 = 0 + offset;
	m_Triangles[0].index2 = 1 + offset;
	m_Triangles[0].index3 = 2 + offset;
	m_Triangles[1].index1 = 2 + offset;
	m_Triangles[1].index2 = 3 + offset;
	m_Triangles[1].index3 = 0 + offset;
	return m_Triangles;
}

bool KGLGE::Square::respondToKey(unsigned int key)
{
	return false;
}

unsigned int KGLGE::Square::getNumTriangles()
{
	return 2;
}
