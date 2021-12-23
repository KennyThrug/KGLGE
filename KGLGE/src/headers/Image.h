#pragma once
#include "GameObject.h"
#include "TextureAtlas.h"
namespace KGLGE {
	class Image : public KGLGE::GameObject {
	public:
		Image(float x, float y, float width, float height, std::string fileName, unsigned int texSlot);
		// Inherited via GameObject
		
		void update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual unsigned int getNumTriangles() override;
		virtual bool respondToKey(unsigned int key) override;
	protected:
		void resetTextures();

	private:
		KGLGE::Vertex m_vertex[4];
		KGLGE::Triangle m_Triangles[2];
	};
}