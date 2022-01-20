#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "LevelCreator.h"
#include "Sprite.h"
#include "TextureAtlas.h"

	void runProgram() {
		
		KGLGE::initializeGLFW();
		KGLGE::Window win("Game Window");
		win.display();
		KGLGE::GameLoop loop(&win);

		KGLGE::Level* lvl = new KGLGE::Level;
		KGLGE::loadLevel("../../res/Levels/Zinc.lvl", lvl);
		loop.LoadLevel(lvl);
		
		loop.addLevelCreator();

		loop.startLoop();
		glfwTerminate();
	}