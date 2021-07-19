#pragma once
#include "Math.hpp"
#include "GameObject.h"
namespace KGLGE {
	class Sprite : public GameObject {
		// Inherited via GameObject
		virtual bool update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual unsigned int getNumTriangles() override;

		// Inherited via GameObject
		virtual bool respondToKey(unsigned int key) override;
	};
}