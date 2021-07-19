#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "Sprite.h"
#include "TextureAtlas.h"
void runProgram() {
	KGLGE::Position pos = KGLGE::VectorToPosition({ 10,0.25f * KGLGE::PI });
	std::cout << pos.x << std::endl;
	std::cout << pos.y << std::endl;
	KGLGE::initializeGLFW();
	KGLGE::Window win(500,500,"Game Window");
	win.display();
	KGLGE::GameLoop loop(&win);
	
	std::string catz = "res/sprites/CATS/";
	KGLGE::TextureAtlas cats(catz,KGLGE_BACKGROUND);

	KGLGE::Sprite sp(&cats,0,0,1,1,"rowlett.png",2);
	loop.addGameObject(&sp,0);

	KGLGE::Sprite kp(&cats, -1, -1, 0.5f, 0.5f, "X.png");
	loop.addGameObject(&kp, 0);

	loop.startLoop();
	glfwTerminate();
}