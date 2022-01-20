#pragma once
#include "Square.h"
#include <iostream>
namespace KGLGE {
	class LevelCreator : public GameObject {
		public:
			// Inherited via GameObject
			void update() override;
			Vertex* getVertexes() override;
			unsigned int getNumVertex() override;
			Triangle* getIndicies(unsigned int offset) override;
			int getGameObjectID() override;
			float getProperty(int propertyNum) override;
			int getPropertyID(int propertyNum) override;
			int getPropertySize(int propertyNum) override;
			int getNumProperties() override;
			unsigned int getNumTriangles() override;
			virtual bool respondToKey(unsigned int key) override;

			LevelCreator();
		private:
			void createWindow();
			bool isVisable;

			KGLGE::Square* bg = new KGLGE::Square(0,0,1,1,1,0,0,1);
	};
}