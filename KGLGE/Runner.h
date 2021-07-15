#pragma once
#include "GameLoop.h"
#include "Window.h"
void runProgram() {
	KGLGE::Position pos = KGLGE::VectorToPosition({ 10,0.25f * KGLGE::PI });
	std::cout << pos.x << std::endl;
	std::cout << pos.y << std::endl;
	KGLGE::initializeGLFW();
	KGLGE::Window win(500,500,"Game Window");
	win.display();
	KGLGE::GameLoop loop(&win);
	loop.startLoop();
	glfwTerminate();
}