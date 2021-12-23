#pragma once
#include "Empty.h"
#include <iostream>
namespace KGLGE {
	class LevelCreator : public Empty {
		// Inherited via GameObject
		
		void update() override;
		virtual bool respondToKey(unsigned int key) override;
	};
}