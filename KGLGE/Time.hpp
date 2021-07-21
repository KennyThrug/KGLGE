#pragma once
#include <time.h>
namespace KGLGE {
	static float deltaTime;
	static float prevTime;
	static void updateTime() {
		deltaTime = prevTime - clock();
		prevTime = clock();
	}
}