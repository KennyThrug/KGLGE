#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "Sprite.h"
#include "TextureAtlas.h"

	void runProgram() {
		KGLGE::Position pos = KGLGE::VectorToPosition({ 10,0.25f * KGLGE::PI });
		KGLGE::initializeGLFW();
		KGLGE::Window win(500, 500, "Game Window");
		win.display();
		KGLGE::GameLoop loop(&win);

		unsigned int cats = loop.addTextureAtlas("res/sprites/CATS/", KGLGE_BACKGROUND);

		KGLGE::Sprite sp(loop.getAtlas(cats), 0, 0, 1, 1, "rowlett.png", 2);
		unsigned int xx = loop.addGameObject(&sp, 1).location;

		KGLGE::Sprite kp(loop.getAtlas(cats), -1, -1, 0.5f, 0.5f, "X.png");
		loop.addGameObject(&kp, 1);

		KGLGE::Sprite nora(loop.getAtlas(cats), -0.5, 0, 1, 1, "Nora.png");
		KGLGE::GameObjectLocation loc = loop.addGameObject(&nora, 0);
		loop.addProperty(loc, 1);
		

		loop.addKeyHandler(1, xx, GLFW_KEY_W);
		loop.addKeyHandler(1, xx, GLFW_KEY_S);
		loop.addKeyHandler(1, xx, GLFW_KEY_A);
		loop.addKeyHandler(1, xx, GLFW_KEY_D);
		
		//loop.setWindowSize(-2, 2, -2, 2);

		//KGLGE::Square sq(0, 0, 0.5f, 0.5f, 1, 1, 0, 1);
		//loop.addGameObject(&sq, 1);
		
		KGLGE::Level* lvl = new KGLGE::Level;
		KGLGE::loadLevel("Zinc.lvl", lvl);
		loop.LoadLevel(lvl);
		

		loop.startLoop();
		glfwTerminate();
	}