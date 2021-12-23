#pragma once
#include "GameObject.h"
namespace KGLGE {
	class RedAndBlue : public KGLGE::GameObject {
		// Inherited via GameObject
		virtual void update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual bool respondToKey(unsigned int key) override;
		virtual int getGameObjectID() override;
		virtual float getProperty(int propertyNum) override;
		virtual int getPropertyID(int propertyNum) override;
		virtual int getPropertySize(int propertyNum) override;
		virtual int getNumProperties() override;
		virtual unsigned int getNumTriangles() override;
	};
}