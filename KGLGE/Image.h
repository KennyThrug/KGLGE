#pragma once
#include "GameObject.h"
#include "TextureAtlas.h"
namespace KGLGE {
	class Image : KGLGE::GameObject {
	public:
		Image(float x, float y, float width, float height, std::string fileName, unsigned int texSlot);
		// Inherited via GameObject
		virtual void update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual unsigned int getNumTriangles() override;
		virtual bool respondToKey(unsigned int key) override;
	protected:
		void resetTextures();
		float m_x;
		float m_y;
		float m_Width;
		float m_Height;
	private:
		KGLGE::Vertex m_vertex[4];
		KGLGE::Triangle m_Triangles[2];
	};
}