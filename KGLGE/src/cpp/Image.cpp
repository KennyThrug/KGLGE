#include "../headers/Image.h"

KGLGE::Image::Image(float x, float y, float width, float height, std::string fileName, unsigned int texSlot)
	: GameObject()
{
	m_x = x;
	m_y = y;
	m_Height = height;
	m_Width = width;

	KGLGE::loadTexture(fileName, texSlot);
	m_vertex[0].texPos = { 0,0 };
	m_vertex[1].texPos = { 1,0 };
	m_vertex[2].texPos = { 1,1 };
	m_vertex[3].texPos = { 0,1 };

	m_vertex[0].texID = texSlot;
	m_vertex[1].texID = texSlot;
	m_vertex[2].texID = texSlot;
	m_vertex[3].texID = texSlot;
}

void KGLGE::Image::update()
{
}

KGLGE::Vertex* KGLGE::Image::getVertexes()
{
	resetTextures();
	return m_vertex;
}

unsigned int KGLGE::Image::getNumVertex()
{
	return 4;
}

KGLGE::Triangle* KGLGE::Image::getIndicies(unsigned int offset)
{
	m_Triangles[0].index1 = 0 + offset;
	m_Triangles[0].index2 = 1 + offset;
	m_Triangles[0].index3 = 2 + offset;
	m_Triangles[1].index1 = 2 + offset;
	m_Triangles[1].index2 = 3 + offset;
	m_Triangles[1].index3 = 0 + offset;
	return m_Triangles;
}

unsigned int KGLGE::Image::getNumTriangles()
{
	return 2;
}

bool KGLGE::Image::respondToKey(unsigned int key)
{
	return false;
}

void KGLGE::Image::resetTextures()
{
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
}

