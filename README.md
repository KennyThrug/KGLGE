# KGLGE
KGLGE: Kenny's openGL Game Engine. A Game Engine &amp; API that is being made by me for my own personal program.

Mainly writing this guide for myself because I am forgetful. Might eventually release this, but right now it's not the most user friendly thing in the world.

Instalation:
//Write this at some point

Dependencies:
* OpenGL (Should already be installed on your system with your GPU)
* GLFW
* GLEW
* STB_IMAGE
* nlohmann/json

Usage:
1. Make a class that inherets `KGLGE::GameLoop`. This class should look something like this
```c++
#include <KGLGE/GameLoop.h>
class InheretsGameLoop : public KGLGE::GameLoop {
public:
	InheretsGameLoop(KGLGE::Window* win);
    //update loop can do anything every frame
	void update() override;
};
```
The constructor should use the constructor for GameLoop:
`GameLoop(KGLGE::Window* win)`

