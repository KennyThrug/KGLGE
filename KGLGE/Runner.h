#pragma once
#include "GameLoop.h"
#include "Window.h"
#include "Sprite.h"
#include "TextureAtlas.h"
	void uploop() {
		std::cout << "leka";
	}

	void runProgram() {
		KGLGE::Position pos = KGLGE::VectorToPosition({ 10,0.25f * KGLGE::PI });
		std::cout << pos.x << std::endl;
		std::cout << pos.y << std::endl;
		KGLGE::initializeGLFW();
		KGLGE::Window win(500, 500, "Game Window");
		win.display();
		KGLGE::GameLoop loop(&win);

		std::string catz = "res/sprites/CATS/";
		KGLGE::TextureAtlas cats(catz, KGLGE_BACKGROUND);

		KGLGE::Sprite sp(&cats, 0, 0, 1, 1, "rowlett.png", 2);
		unsigned int xx = loop.addGameObject(&sp, 1);

		KGLGE::Sprite kp(&cats, -1, -1, 0.5f, 0.5f, "X.png");
		loop.addGameObject(&kp, 1);

		KGLGE::Sprite nora(&cats, -0.5, 0, 1, 1, "Nora.png");
		loop.addGameObject(&nora, 0);

		loop.addKeyHandler(0, xx, GLFW_KEY_W);
		loop.addKeyHandler(0, xx, GLFW_KEY_S);
		loop.addKeyHandler(0, xx, GLFW_KEY_A);
		loop.addKeyHandler(0, xx, GLFW_KEY_D);

		//loop.setWindowSize(-2, 2, -2, 2);


		loop.startLoop();
		glfwTerminate();
	}