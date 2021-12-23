#include "Sprite.h"

void KGLGE::Sprite::resetTextures() {
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
}

int KGLGE::Sprite::getGameObjectID()
{
	return 1;
}

float KGLGE::Sprite::getProperty(int propertyNum)
{
	switch (propertyNum) {
	case 0:
		return m_indexAtlas;
		break;
	case 1:
		return m_x;
		break;
	case 2:
		return m_y;
		break;
	case 3:
		return m_Width;
		break;
	case 4:
		return m_Height;
		break;
	case 5:
		return m_fileName;
		break;
	case 6:
		return m_numRotations;
		break;
	default:
		return -1;
	}
}

int KGLGE::Sprite::getPropertyID(int propertyNum)
{
	if (propertyNum == 0)
		return 1;
	return 3;
}

int KGLGE::Sprite::getPropertySize(int propertyNum)
{
	return (propertyNum == 0) ? sizeof(int) : sizeof(float);
}

int KGLGE::Sprite::getNumProperties()
{
	return 7;
}

KGLGE::Sprite::Sprite(TextureAtlas* atlas, float x, float y, float width, float height,std::string fileName,unsigned int numRotations)
	: GameObject(), m_fileName(atlas->findIndexOf(fileName)),m_numRotations(numRotations), m_indexAtlas(atlas->getIndex())
{

	m_x = x;
	m_y = y;
	m_Height = height;
	m_Width = width;

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

KGLGE::Sprite::Sprite(TextureAtlas* atlas, float x, float y, float width, float height, int fileIndex, unsigned int numRotations)
	: GameObject(), m_fileName(fileIndex), m_numRotations(numRotations), m_indexAtlas(atlas->getIndex())
{

	m_x = x;
	m_y = y;
	m_Height = height;
	m_Width = width;

	std::array<KGLGE::Position, 4> p = rotate90deg(atlas->getPositionsOf(fileIndex), numRotations);

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
	if (key == GLFW_KEY_W) {
		m_x += 0.01;
		shouldUpdate = true;
	}
	if (key == GLFW_KEY_S) {
		std::vector<GameObjectLocation> sq = allGameObjects->getAllObjectsWithProperty(1);
		for (int i = 0; i < sq.size(); i++) {
			allGameObjects->getGameObject(sq[i])->m_x += 0.01;
			allGameObjects->getGameObject(sq[i])->shouldUpdate = true;
		}
	}
	return false;
}
