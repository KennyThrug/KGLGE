#pragma once
#include "Math.hpp"
#include "GameObject.h"
#include "TextureAtlas.h"
namespace KGLGE {
	/// <summary>
	/// Sprite that uses a TextureAtlas, instead of a single img
	/// </summary>
	class Sprite : public GameObject {
	public:
		Sprite(TextureAtlas* atlas,float x, float y, float width, float height,std::string fileName,unsigned int numRotations = 0);
		// Inherited via GameObject
		virtual void update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual unsigned int getNumTriangles() override;
		virtual bool respondToKey(unsigned int key) override;
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