#include "Sprite.h"

void KGLGE::Sprite::resetTextures() {
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
}

KGLGE::Sprite::Sprite(TextureAtlas* atlas, float x, float y, float width, float height,std::string fileName,unsigned int numRotations)
	:m_x(x), m_y(y), m_Width(width), m_Height(height), GameObject()
{
	std::array<KGLGE::Position,4> p = rotate90deg(atlas->getPositionsOf(fileName),numRotations);

	m_vertex[0].texPos = p[0];
	m_vertex[1].texPos = p[1];
	m_vertex[2].texPos = p[2];
	m_vertex[3].texPos = p[3];

	m_vertex[0].texID = atlas->layer;
	m_vertex[1].texID = atlas->layer;
	m_vertex[2].texID = atlas->layer;
	m_vertex[3].texID = atlas->layer;
}

void KGLGE::Sprite::update()
{
}

KGLGE::Vertex* KGLGE::Sprite::getVertexes()
{
	resetTextures();
	return m_vertex;
}

unsigned int KGLGE::Sprite::getNumVertex()
{
	return 4;
}

KGLGE::Triangle* KGLGE::Sprite::getIndicies(unsigned int offset)
{
	m_Triangles[0].index1 = 0 + offset;
	m_Triangles[0].index2 = 1 + offset;
	m_Triangles[0].index3 = 2 + offset;
	m_Triangles[1].index1 = 2 + offset;
	m_Triangles[1].index2 = 3 + offset;
	m_Triangles[1].index3 = 0 + offset;
	return m_Triangles;
}

unsigned int KGLGE::Sprite::getNumTriangles()
{
	return 2;
}

bool KGLGE::Sprite::respondToKey(unsigned int key)
{
	return false;
}
