#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "LevelCreator.h"
#include "Sprite.h"
#include "TextureAtlas.h"
#include "TextRenderer.h"

	void runProgram() {
		
		KGLGE::initializeGLFW();
		KGLGE::Window win("Game Window");
		win.display();
		KGLGE::GameLoop loop(&win);

		//KGLGE::Level* lvl = new KGLGE::Level;
		//KGLGE::loadLevel("../../res/Levels/Zinc.lvl", lvl);
		//loop.LoadLevel(lvl);
		
		loop.addLevelCreator();

		KGLGE::TextureAtlas* font = new KGLGE::TextureAtlas("../../res/sprites/Fonts/BBBBixxxel/",KGLGE_FONT);
		KGLGE::TextRenderer txtRndr(font);
		KGLGE::GameObjectLocation loc = loop.addGameObject(&txtRndr,KGLGE_FOREGROUND);
		
		txtRndr.addText(-0.9f,0,0.1f,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789 .,;:$!?&()@");

		loop.addKeyHandler(loc,GLFW_KEY_Q,true);
		KGLGE::Square squr(-1,-1,2,2,0,1,0,1);
		loop.addGameObject(&squr,KGLGE_BACKGROUND);
		loop.addGameObject(&txtRndr,KGLGE_FOREGROUND);

		loop.startLoop();
		glfwTerminate();
	}