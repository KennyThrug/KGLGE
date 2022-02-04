#pragma once
#include "Square.h"
#include "MultipleGameObjects.h"
#include <iostream>
namespace KGLGE {
	class LevelCreator : public MultipleGameObjects {
		public:
			// Inherited via GameObject
			void update() override;
			int getGameObjectID() override;
			float getProperty(int propertyNum) override;
			int getPropertyID(int propertyNum) override;
			int getPropertySize(int propertyNum) override;
			int getNumProperties() override;
			virtual bool respondToKey(unsigned int key) override;

			LevelCreator();
		private:
			void createWindow();
			void hideWindow();
			bool isVisable;

			KGLGE::Square* bg = new KGLGE::Square(0,0,1,1,1,0,0,1);
	};
}