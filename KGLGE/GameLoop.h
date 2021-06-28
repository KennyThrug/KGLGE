#pragma once
#include "GameObject.h"
class GameLoop {
public:
	GameLoop();
	void startLoop();
private:
	void drawElements();
	GameObject * gameObjects;
};