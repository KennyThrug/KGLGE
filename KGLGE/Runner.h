#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "Sprite.h"
#include "TextureAtlas.h"

	void runProgram() {
		
		KGLGE::initializeGLFW();
		KGLGE::Window win(500, 500, "Game Window");
		win.display();
		KGLGE::GameLoop loop(&win);

		KGLGE::Level* lvl = new KGLGE::Level;
		KGLGE::loadLevel("Zinc.lvl", lvl);
		loop.LoadLevel(lvl);
		
		loop.addLevelCreator();

		loop.startLoop();
		glfwTerminate();
	}