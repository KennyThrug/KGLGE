#pragma once
#include "GameObject.h"
#include "Window.h"
#include "Batcher.h"
class GameLoop {
public:
	GameLoop(Window * window);
	void startLoop();
	virtual void runAtLoop();
private:
	Window* win;
	Batcher* batcher;
	void drawElements();
	GameObject * gameObjects;
};